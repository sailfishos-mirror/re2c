#include <stddef.h>
#include "src/util/c99_stdint.h"
#include <algorithm>
#include <ostream>
#include <string>
#include <vector>

#include "src/adfa/adfa.h"
#include "src/ast/ast.h"
#include "src/ast/parser.h"
#include "src/ast/scanner.h"
#include "src/code/label.h"
#include "src/code/output.h"
#include "src/compile.h"
#include "src/conf/opt.h"
#include "src/debug/debug.h"
#include "src/dfa/dfa.h"
#include "src/nfa/nfa.h"
#include "src/re/encoding/range_suffix.h"
#include "src/re/re.h"
#include "src/re/rule.h"
#include "src/skeleton/skeleton.h"
#include "src/util/counter.h"
#include "src/util/free_list.h"
#include "src/util/range.h"
#include "src/util/smart_ptr.h"

namespace re2c {

class Warn;

static std::string make_name(const std::string &cond, uint32_t line)
{
    std::ostringstream os;
    os << "line" << line;
    std::string name = os.str();
    if (!cond.empty ())
    {
        name += "_";
        name += cond;
    }
    return name;
}

static smart_ptr<DFA> ast_to_dfa(const spec_t &spec, Output &output)
{
    const opt_t *opts = output.block().opts;
    Warn &warn = output.warn;
    const std::vector<ASTRule> &rules = spec.rules;
    const size_t defrule = spec.defs.empty() ? Rule::NONE : rules.size() - 1;
    const Code *eof = spec.eofs.empty() ? NULL : spec.eofs.front();
    const uint32_t line = output.block().line;
    const std::string
        &cond = spec.name,
        name = make_name(cond, line),
        &setup = spec.setup.empty() ? "" : spec.setup[0]->text;

    RESpec re(rules, opts, warn);
    split_charset(re);
    find_fixed_tags(re);
    insert_default_tags(re);
    warn_nullable(re, cond);

    nfa_t nfa(re);
    DDUMP_NFA(opts, nfa);

    dfa_t dfa(nfa, opts, cond, warn);
    DDUMP_DFA_DET(opts, dfa);

    // skeleton must be constructed after DFA construction
    // but prior to any other DFA transformations
    Skeleton skeleton(dfa, opts, defrule, name, cond, line);
    warn_undefined_control_flow(skeleton, warn);
    if (opts->target == TARGET_SKELETON) {
        emit_data(skeleton);
    }

    cutoff_dead_rules(dfa, defrule, cond, warn);

    insert_fallback_tags(dfa);

    // try to minimize the number of tag variables
    compact_and_optimize_tags(opts, dfa);
    DDUMP_DFA_TAGOPT(opts, dfa);

    freeze_tags(dfa);

    minimization(dfa, opts->dfa_minimization);
    DDUMP_DFA_MIN(opts, dfa);

    // find strongly connected components and calculate argument to YYFILL
    std::vector<size_t> fill;
    fillpoints(dfa, fill);

    // ADFA stands for 'DFA with actions'
    DFA *adfa = new DFA(dfa, fill, defrule, skeleton.sizeof_key,
        name, cond, line, setup, eof, opts);

    // see note [reordering DFA states]
    adfa->reorder();

    // skeleton is constructed, do further DFA transformations
    adfa->prepare(opts);
    DDUMP_ADFA(opts, *adfa);

    // finally gather overall DFA statistics
    adfa->calc_stats(line, opts->tags);

    // accumulate global statistics from this particular DFA
    output.max_fill = std::max(output.max_fill, adfa->max_fill);
    output.max_nmatch = std::max(output.max_nmatch, adfa->max_nmatch);
    if (adfa->need_accept) {
        output.block().used_yyaccept = true;
    }

    return make_smart_ptr(adfa);
}

void compile(Scanner &input, Output &output, Opt &opts)
{
    specs_t rspecs;
    symtab_t symtab;
    const conopt_t *globopts = &opts.glob;
    const opt_t *ropts = NULL;
    typedef std::vector<smart_ptr<DFA> > dfas_t;

    output.header_mode(1);
    output.new_block(opts);
    output.wversion_time();

    output.header_mode(0);
    output.new_block(opts);
    output.wversion_time();
    output.wdelay_line_info_input(input.get_line(), input.get_fname());

    if (globopts->target == TARGET_SKELETON) {
        emit_prolog(output);
    }

    for (;;) {
        // parse everything up to the next re2c block
        Scanner::ParseMode mode = input.echo(output);
        if (mode == Scanner::Stop) break;
        validate_mode(mode, globopts->rFlag, ropts, input);

        // parse the next re2c block
        specs_t specs;
        if (mode == Scanner::Reuse) {
            specs = rspecs;
            opts.restore(ropts);
            opts.reset_mapCodeName();
            output.label_counter.reset();
            output.fill_index = 0;
            output.state_goto = false;
            output.cond_goto = false;
        }
        parse(input, specs, symtab, opts);

        // start new output block with accumulated options
        output.new_block(opts);

        if (mode == Scanner::Rules) {
            // save AST and options for future use
            rspecs = specs;
            ropts = output.block().opts;
        } else {
            validate_ast(specs, output.block().opts);
            normalize_ast(specs);

            // compile AST to DFA
            output.block().line = input.get_line();
            dfas_t dfas;
            for (specs_t::const_iterator i = specs.begin(); i != specs.end(); ++i) {
                dfas.push_back(ast_to_dfa(*i, output));
            }

            // compile DFA to code
            bool prolog = false;
            uint32_t ind = output.block().opts->topIndent;
            for (dfas_t::const_iterator i = dfas.begin(); i != dfas.end(); ++i) {
                (*i)->emit(output, ind, (i + 1) == dfas.end(), prolog);
            }
        }

        output.wdelay_line_info_input(input.get_line(), input.get_fname());
    }

    if (globopts->target == TARGET_SKELETON) {
        emit_epilog (output, output.skeletons);
    }

    AST::flist.clear();
    Code::flist.clear();
    Range::vFreeList.clear();
    RangeSuffix::freeList.clear();
}

} // namespace re2c

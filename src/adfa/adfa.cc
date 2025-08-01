#include <stdint.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#include "src/adfa/adfa.h"
#include "src/codegen/output.h"
#include "src/dfa/dfa.h"
#include "src/dfa/tcmd.h"
#include "src/options/opt.h"
#include "src/regexp/rule.h"
#include "src/util/check.h"
#include "src/util/containers.h"

namespace re2c {

class Msg;

static bool is_eof(const opt_t* opts, uint32_t ub) {
    return opts->fill_eof != NOEOF && static_cast<uint32_t>(opts->fill_eof) == ub;
}

Adfa::Adfa(Tdfa&& dfa,
    const std::vector<size_t>& fill,
    size_t key,
    const loc_t& loc,
    const std::string& name,
    const std::string& cond,
    const opt_t* opts,
    Msg& msg,
    const SemAct* entry_action,
    const SemAct* pre_rule_action,
    const SemAct* post_rule_action)
        // Move ownership from TDFA to ADFA.
        : charset(std::move(dfa.charset))
        , rules(std::move(dfa.rules))
        , tags(std::move(dfa.tags))
        , mtagvers(std::move(dfa.mtagvers))
        , tcpool(std::move(dfa.tcpool))
        , finvers(dfa.finvers)
        , maxtagver(dfa.maxtagver)
        , loc(loc)
        , name(name)
        , cond(cond)
        , msg(msg)
        , accepts()
        , lower_char(0)
        , upper_char(charset.back())
        , state_count(0)
        , head(nullptr)
        , default_state(nullptr)
        , start_state(nullptr)
        , finstates(rules.size(), nullptr)
        , custom_start_label(nullptr)
        , stagnames()
        , stagvars()
        , mtagnames()
        , mtagvars()
        , def_rule(dfa.def_rule)
        , key_size(key)
        , max_fill(0)
        , max_nmatch(0)
        , need_backup(false)
        , need_accept(false)
        , oldstyle_ctxmarker(false)
        , bitmap(nullptr)
        , entry_action(entry_action)
        , pre_rule_action(pre_rule_action)
        , post_rule_action(post_rule_action) {

    const size_t nstates = dfa.states.size();

    State** i2s = new State*[nstates];
    for (size_t i = 0; i < nstates; ++i) {
        i2s[i] = new State;
    }

    State** p = &head;
    for (size_t i = 0; i < nstates; ++i) {
        size_t nchars = dfa.nchars;

        TdfaState* t = dfa.states[i];
        State* s = i2s[i];

        ++state_count;
        *p = s;
        p = &s->next;

        s->rule = t->rule;
        s->rule_tags = t->tcid[nchars];
        s->fall_tags = t->tcid[nchars + 1];
        s->fill = fill[i];
        s->fallthru = t->fallthru;
        s->fallback = t->fallback; // see note [fallback states]

        if (opts->fill_eof != NOEOF) {
            // Get rid of the pseudo-transitions on fake end-of-input symbol,
            // but store a link to the final state and tags.
            size_t eof_state = t->arcs[nchars - 1];
            if (eof_state != Tdfa::NIL) {
                TdfaState* e = dfa.states[eof_state];
                s->eof_state = i2s[eof_state];
                s->eof_tags = t->tcid[nchars - 1];
                // There should be no final / fallback tags ($ must be at the end).
                CHECK(e->tcid[nchars] == TCID0 && e->tcid[nchars + 1] == TCID0);
            }
            --nchars;
        }

        bool end = true;
        for (uint32_t c = 0; end && c < nchars; ++c) {
            end &= t->arcs[c] == Tdfa::NIL;
        }

        s->go.span = allocate<Span>(nchars);
        uint32_t j = 0;
        for (uint32_t c = 0; c < nchars; ++j) {
            const size_t to = t->arcs[c];
            const tcid_t tc = t->tcid[c];
            const bool ie = is_eof(opts, charset[c]);
            for (; ++c < nchars
                    && t->arcs[c] == to
                    && t->tcid[c] == tc
                    && (end || is_eof(opts, charset[c]) == ie)
                    ;);
            s->go.span[j].to = to == Tdfa::NIL ? nullptr : i2s[to];
            s->go.span[j].ub = charset[c];
            s->go.span[j].tags = tc;
        }
        s->go.span_count = j;
    }
    *p = nullptr;

    delete[] i2s;
}

Adfa::~Adfa() {
    State* s;

    while ((s = head)) {
        head = s->next;
        delete s;
    }
}

// note [reordering DFA states]
//
// re2c-generated code depends on the order of states in DFA: simply flipping two states may change
// the output significantly. The order of states is affected by many factors, e.g.:
//   - flipping left and right subtrees of alternative when constructing AST (also applies to
//     iteration and counted repetition)
//   - changing the order in which graph nodes are visited (applies to any intermediate
//     representation: bytecode, NFA, DFA, etc.)
// 
// To make the resulting code independent of such changes, we reorder DFA states. The ordering
// scheme is very simple. Starting with DFA root, walk DFA nodes in breadth-first order. Child nodes
// are ordered accoding to the (alphabetically) first symbol leading to each node. Each node must be
// visited exactly once. Default state (NULL) is always the last state.

void Adfa::reorder() {
    std::vector<State*> ord;
    ord.reserve(state_count);

    std::queue<State*> todo;
    todo.push(head);

    std::set<State*> done;
    done.insert(head);

    for (; !todo.empty();) {
        State* s = todo.front();
        todo.pop();
        ord.push_back(s);
        s->linked = true;
        for (uint32_t i = 0; i < s->go.span_count; ++i) {
            State* q = s->go.span[i].to;
            if (q && done.insert(q).second) {
                todo.push(q);
            }
        }
    }

    for (State* s = head; s; s = s->next) {
        // Must be a final state reachable only over removed end-of-input transition.
        if (!s->linked) ord.push_back(s);
    }

    DCHECK(state_count == ord.size());

    ord.push_back(nullptr);
    for (uint32_t i = 0; i < state_count; ++i) {
        ord[i]->next = ord[i + 1];
    }
}

// ... x -> y ...
// ... x -> s -> y ...
void Adfa::add_state_after(State* s, State* x) {
    ++state_count;
    State* y = x->next;
    if (y) y->prev = s;
    s->next = y;
    s->prev = x;
    x->next = s;
}

// ... y -> x ...
// ... y -> s -> x ...
void Adfa::add_state_before(State* s, State* x) {
    ++state_count;
    State* y = x->prev;
    if (y) y->next = s;
    s->prev = y;
    s->next = x;
    x->prev = s;
}

void Adfa::add_single_trans(State* s, State* x) {
    Span* p = allocate<Span>(1);
    p->ub = upper_char;
    p->to = x;
    p->tags = TCID0;
    s->go.span = p;
    s->go.span_count = 1;
}

void Adfa::split(State* s) {
    // If a split state has a rule, both parts should keep it. Codegen checks it when generating
    // fallback transition on YYFILL failure, either in state dispatch or on a regular transition.
    State* move = new State;
    add_state_after(move, s);
    move->kind = StateKind::MOVE;
    move->rule = s->rule;
    move->fill_state = s->fill_state;
    move->fill = s->fill; // used by tunneling, ignored by codegen
    move->go = s->go;
    move->go.tags = TCID0; // drop hoisted tags
    move->rule_tags = s->rule_tags;
    move->fall_tags = s->fall_tags;
    move->eof_state = s->eof_state;
    move->eof_tags = s->eof_tags;
    add_single_trans(s, move);
}

static uint32_t merge(Span* x, State* fg, State* bg, const opt_t* opts) {
    Span* f = fg->go.span;
    Span* b = bg->go.span;
    Span* const fe = f + fg->go.span_count;
    Span* const be = b + bg->go.span_count;
    Span* const x0 = x;
    const uint32_t eofub = opts->fill_eof + 1;

    for (; !(f == fe && b == be);) {
        if (f->to == b->to
                && f->tags == b->tags
                && f->ub != eofub
                && b->ub != eofub) {
            x->to = bg;
            x->tags = TCID0;
        } else {
            x->to = f->to;
            x->tags = f->tags;
            x->ub = f->ub;
        }
        if (x == x0
                || x[-1].to != x->to
                || x[-1].tags != x->tags
                || x[-1].ub == eofub
                || f->ub == eofub
                || b->ub == eofub) {
            ++x;
        }
        x[-1].ub = std::min(f->ub, b->ub);

        if (f->ub < b->ub) {
            ++f;
        } else if(f->ub > b->ub) {
            ++b;
        } else {
            ++f;
            ++b;
        }
    }

    return static_cast<uint32_t>(x - x0);
}

void Adfa::find_base_state(const opt_t* opts) {
    Span* span = allocate<Span>(upper_char - lower_char);

    for (State* s = head; s; s = s->next) {
        if (s->fill == 0) {
            for (uint32_t i = 0; i < s->go.span_count; ++i) {
                State* to = s->go.span[i].to;

                if (to->is_base) {
                    to = to->go.span[0].to;
                    uint32_t span_count = merge(span, s, to, opts);

                    if (span_count < s->go.span_count) {
                        operator delete(s->go.span);
                        s->go.span_count = span_count;
                        s->go.span = allocate<Span>(span_count);
                        memcpy(s->go.span, span, span_count * sizeof(Span));
                        break;
                    }
                }
            }
        }
    }

    operator delete(span);
}

// note [tag hoisting, skip hoisting and tunneling]
//
// Tag hoisting is simple: if all transitions have the same commands, they can be hoisted out of
// conditional branches.
//
// Skip hoisting is only relevant with `--eager-skip` option. Normally this option is off and skip
// is lazy: it happens after transition to the next state, if this state is consuming. However, with
// `--eager-skip` skip happens before transition to the next state. Different transitions may
// disagree: some of them go to consuming states, others don't. If they agree, skip can be hoisted
// (just like tags).
//
// Tunneling splits base states in two parts: head and body. Body has all the conditional branches
// (transitions on symbols), while head has just one unconditional jump to body.
//
// Normally tag hoisting should go before tunneling: hoisting may add new candidates to be merged by
// tunneling. However, with `--eager-skip` tag hoisting is interwined with skip hoisting, and the
// latter needs to know which states are consuming. This is not possible if tunneling is still to be
// done, because it may turn consuming states into non-consuming ones. Another option is to disallow
// splitting states with non-hoisted skip in the presence of `--eager-skip` (this way skip hoisting
// wouldn't need to know tunneling results), but it's much worse for tunneling.

void Adfa::prepare(const opt_t* opts) {
    // create rule states
    for (State* s = head; s; s = s->next) {
        if (s->rule != Rule::NONE) {
            if (!finstates[s->rule]) {
                State* n = new State;
                n->kind = StateKind::RULE;
                n->rule = s->rule;
                finstates[s->rule] = n;
                add_state_after(n, s);
            }
            for (uint32_t i = 0; i < s->go.span_count; ++i) {
                if (!s->go.span[i].to) {
                    s->go.span[i].to = finstates[s->rule];
                    s->go.span[i].tags = s->rule_tags;
                }
            }
        }

        State* e = s->eof_state;
        if (e != nullptr && !finstates[e->rule]) {
            e->kind = StateKind::RULE;
            finstates[e->rule] = e;
            e->go.span_count = 0;
        }
    }

    // create default state (if needed)
    for (State* s = head; s; s = s->next) {
        for (uint32_t i = 0; i < s->go.span_count; ++i) {
            if (!s->go.span[i].to) {
                if (!default_state) {
                    default_state = new State;
                    add_state_after(default_state, s);
                }
                s->go.span[i].to = default_state;
            }
        }
    }

    // With end-of-input rule $ there is a default quasi-transition on YYFILL failure, so the
    // default state is needed if there are any "fallthrough" states.
    if (!default_state && opts->fill_eof != NOEOF) {
        bool have_fallthru = false;

        for (State* s = head; s; s = s->next) {
            have_fallthru |= s->fallthru;

            if (!s->next && have_fallthru) {
                default_state = new State;
                add_state_after(default_state, s);
                break;
            }
        }
    }

    // bind save actions to fallback states and create accept state (if needed)
    if (default_state) {
        for (State* s = head; s; s = s->next) {
            if (s->fallback) {
                s->save = accepts.find_or_add({finstates[s->rule], s->fall_tags});
            }
        }
        default_state->kind = StateKind::ACCEPT;
        default_state->accepts = &accepts;
    }

    start_state = head;

    // Entry action cannot be part of the start state, as there might be a nullable loop through
    // it that would execute the action multiple times. Using a DFA pseudo-state simplifies codegen
    // a lot: it automatically adds a separate case in loop/switch mode, or a separate function in
    // rec/func mode, which would otherwise require a lot of special handling.
    if (entry_action != nullptr) {
        State* s = new State;
        add_state_before(s, head);
        add_single_trans(s, head);
        s->kind = StateKind::ENTRY;
        head = s;
    }

    // Tag hoisting should be done after binding default arcs, which may introduce new tags.
    // See note [tag hoisting, skip hoisting and tunneling].
    if (!opts->eager_skip) {
        hoist_tags(opts);
    }

    // Find states that require an YYFILL label. Do this before splitting, as the move part of the
    // split states needs to keep a pointer to the match part.
    for (State* s = head; s; s = s->next) {
        if (opts->fill_enable && consume(s) && !endstate(s) &&
                (opts->fill_eof != NOEOF ||
                (s->fill > 0 &&
                        (opts->storable_state || opts->code_model != CodeModel::GOTO_LABEL)))) {
            s->fill_state = s;
        }
    }

    // split ``base'' states into two parts
    for (State* s = head; s; s = s->next) {
        s->is_base = false;

        if (s->fill != 0) {
            for (uint32_t i = 0; i < s->go.span_count; ++i) {
                if (s->go.span[i].to == s) {
                    s->is_base = true;
                    split(s);
                    s = s->next;
                    break;
                }
            }
        }
    }
    // find ``base'' state, if possible
    find_base_state(opts);

    // see note [tag hoisting, skip hoisting and tunneling]
    if (opts->eager_skip) {
        hoist_tags_and_skip(opts);
    }
}

Ret Adfa::calc_stats(OutputBlock& out) {
    const opt_t* opts = out.opts;

    // calculate `YYMAXFILL`
    max_fill = 0;
    for (State* s = head; s; s = s->next) {
        if (max_fill < s->fill) {
            max_fill = s->fill;
        }
    }

    // calculate ``YYMAXNMATCH`
    max_nmatch = 0;
    for (const Rule& rule : rules) {
        max_nmatch = std::max(max_nmatch, rule.ncap);
    }

    // determine if `YYMARKER` or `YYBACKUP`/`YYRESTORE` pair is used
    need_backup = accepts.size() > 0;

    // determine if `yyaccept` variable is used
    need_accept = accepts.size() > 1;

    // Determine if re2c should use `YYCTXMARKER` (`YYBACKUPCTX`/`YYRESTORECTX` in the case of
    // generic API) instead of tag variables. This is needed for backwards compatibility with the
    // code that predates tags. Note that in some cases trailing contexts overlap and a single
    // variable is not enough to hold them all -- in these cases autogenerated code was incorrect,
    // so it is ok to break backwards compatibility. Note that with generic API fixed-length
    // contexts are forbidden, which may cause additional overlaps.
    oldstyle_ctxmarker = !opts->tags && maxtagver == 1;

    // error if tags are not enabled, but we need them
    if (!opts->tags && maxtagver > 1) {
        RET_FAIL(msg.error(loc, "overlapping trailing contexts need multiple context markers"
                ", use --tags option and `stags` block"));
    }

    if (!oldstyle_ctxmarker) {
        for (const Tag& tag : tags) {
            if (history(tag)) {
                mtagvars.insert(tag.name);
            } else if (tag.name) {
                stagvars.insert(tag.name);
            } else if (capture(tag) && !fictive(tag) && !opts->captures_array) {
                for (size_t i = tag.lsub; i <= tag.hsub; i += 2) {
                    stagvars.insert(captvar_name(i, opts));
                }
            }
        }
        for (tagver_t v = 1; v <= maxtagver; ++v) {
            bool is_mtag = mtagvers.find(v) != mtagvers.end();
            const std::string s = vartag_name(v, opts, is_mtag);
            if (is_mtag) {
                mtagnames.insert(s);
            } else {
                stagnames.insert(s);
            }
        }
        out.stags.insert(stagnames.begin(), stagnames.end());
        out.mtags.insert(mtagnames.begin(), mtagnames.end());
        out.svars.insert(stagvars.begin(), stagvars.end());
        out.mvars.insert(mtagvars.begin(), mtagvars.end());
    }

    return Ret::OK;
}

static bool can_hoist_tags(const State* s, const opt_t* opts) {
    Span* span = s->go.span;
    const size_t nspan = s->go.span_count;
    DCHECK(nspan != 0);

    if (nspan == 1 && s->rule != Rule::NONE) return false;

    // check that all transitions agree on tags
    tcid_t tags = span[0].tags;
    for (uint32_t i = 1; i < nspan; ++i) {
        if (span[i].tags != tags) {
            return false;
        }
    }

    // If end-of-input rule $ is used, check that final/fallback tags agree with other tags, as the
    // lexer may follow the final/fallback transition.
    if (opts->fill_eof != NOEOF
            && tags != (s->rule == Rule::NONE ? s->fall_tags : s->rule_tags)) {
        return false;
    }

    // No need to check idempotence of tag operations in case of the end-of-input rule $, as they
    // are applied before YYFILL label and there is no risk of re-application if the current input
    // character is re-scanned after YYFILL.
    return true;
}

static bool can_hoist_skip(const State* s, const opt_t* opts) {
    Span* span = s->go.span;
    const size_t nspan = s->go.span_count;

    // If the end-of-input rule $ is used, skip cannot be hoisted because the lexer may need to
    // rescan the current input character after YYFILL, and skip operation will be applied twice.
    if (opts->fill_eof != NOEOF) return false;

    // Transition fromm the entry state to the start state is non-consuming.
    if (s->kind == StateKind::ENTRY) return false;

    // All spans must agree on skip, and they all must be consuming.
    for (uint32_t i = 0; i < nspan; ++i) {
        if (!consume(span[i].to)) return false;
    }

    return true;
}

void Adfa::hoist_tags(const opt_t* opts) {
    for(State* s = head; s; s = s->next) {
        Span* span = s->go.span;
        const size_t nspan = s->go.span_count;
        if (nspan == 0) continue;

        if (can_hoist_tags(s, opts)) {
            s->go.tags = span[0].tags;
            for (uint32_t i = 0; i < nspan; ++i) {
                span[i].tags = TCID0;
            }
        }
    }
}

void Adfa::hoist_tags_and_skip(const opt_t* opts) {
    DCHECK(opts->eager_skip);

    for (State* s = head; s; s = s->next) {
        Span* span = s->go.span;
        const size_t nspan = s->go.span_count;
        if (nspan == 0) continue;

        // hoist tags if possible
        if (can_hoist_tags(s, opts)) {
            s->go.tags = span[0].tags;
            for (uint32_t i = 0; i < nspan; ++i) {
                span[i].tags = TCID0;
            }
            // hoist skip if possible (it cannot be done without hoisting tags)
            s->go.skip = can_hoist_skip(s, opts);
        }
    }
}

} // namespace re2c


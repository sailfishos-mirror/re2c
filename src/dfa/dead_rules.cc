#include <stdint.h>
#include <string.h>
#include <set>
#include <string>
#include <vector>

#include "src/adfa/adfa.h"
#include "src/dfa/dfa.h"
#include "src/msg/msg.h"
#include "src/msg/location.h"
#include "src/msg/warn.h"
#include "src/regexp/rule.h"
#include "src/options/opt.h"
#include "src/util/check.h"
#include "src/util/forbid_copy.h"

// note [unreachable rules]
//
// TDFA may contain useless final states. Such states may appear as a result of:
//   - (Part of) one rule being shadowed by another rule, e.g. rule `[ab]` partially shadows `[ac]`
//     and completely shadows `[a]`.
// 
//   - Infinite rules that greedily eat all input characters and never stop (they either fail on
//     YYFILL or crash), e.g. `[^]*`. This does not occur when the end-of-input rule $ is used,
//     because in that case YYFILL returns on failure.
// 
//   - Rules that contain never-matching link, e.g. `[]` with option --empty-class match-none.
//
// Useless final states should be eliminated so that they don't interfere with further analysis and
// optimizations. If all final states of a rule are useless, then the whole rule is unreachable and
// should be reported.
//
// In order to find out if a given final state is useless, we have to find out if all outgoing paths
// from this state match longer rules (otherwise, some paths go to default state and fallback to
// this state). We do this by finding all states that have transitions to default state and backward
// propagation of "none-rule" from these states. As the backward propagation meets the first final
// state on its way, it substitutes "none-rule" with the corresponding rule, which is further
// propagated back to the start state of DFA.

// note [fallback states]
//
// Find states that are accepting, but may be shadowed by other accepting states: when the short
// rule matches, lexer must try to match longer rules; if this attempt is unsuccessful it must
// fallback to the short match.
//
// In order to find fallback states we need to know if "none-rule" is reachable from the given
// state, the information we have after rule liveness analysis. Fallback states are needed at
// different points in time (both before and after certain transformations on DFA). Fortunately,
// fallback states are not affected by these transformations, so we can calculate them here and save
// for future use.

namespace re2c {
namespace {

struct tcmd_t;

// reversed DFA
struct RevDfa {
    struct arc_t {
        size_t dest;
        arc_t* next;
    };

    struct state_t {
        arc_t* arcs;
        size_t rule;
        bool fallthru;
    };

    size_t nstates;
    size_t nrules;
    state_t* states;
    arc_t* arcs;

    RevDfa(const Tdfa& dfa, const opt_t* opts)
        : nstates(dfa.states.size()),
          nrules(dfa.rules.size()),
          states(new state_t[nstates]()),
          arcs(new arc_t[nstates * dfa.nchars]) {
        // init states
        for (size_t i = 0; i < nstates; ++i) {
            state_t& s = states[i];
            s.arcs = nullptr;
            const size_t r = dfa.states[i]->rule;
            s.rule = r == Rule::NONE ? nrules : r;
            s.fallthru = false;
        }
        if (opts->fill_eof != NOEOF) {
            // End-of-input rules may be shadowed by normal rules with a smaller rule index.
            // However, TDFA structure obscurs this fact due to the fake end-of-input transitions.
            // To fix this, we overwrite the shadowed end-of-input rules in the reversed TDFA.
            for (TdfaState* s : dfa.states) {
                size_t e = s->arcs[dfa.nchars - 1];
                if (e != Tdfa::NIL && dfa.states[e]->rule > s->rule && s->rule != Rule::NONE) {
                    states[e].rule = s->rule;
                }
            }
        }
        // init arcs
        arc_t* a = arcs;
        for (size_t i = 0; i < nstates; ++i) {
            TdfaState* s = dfa.states[i];
            for (size_t c = 0; c < dfa.nchars; ++c) {
                const size_t j = s->arcs[c];
                if (j != Tdfa::NIL) {
                    a->dest = i;
                    a->next = states[j].arcs;
                    states[j].arcs = a++;
                } else {
                    states[i].fallthru = true;
                }
            }
        }
    }

    ~RevDfa() {
        delete[] states;
        delete[] arcs;
    }

    FORBID_COPY(RevDfa);
};

struct DfsBackprop {
    size_t state;
    size_t rule;
    const RevDfa::arc_t* arc;
};

static void liveness_analysis(const RevDfa& rdfa, bool* live) {
    std::vector<DfsBackprop> stack;
    for (size_t i = 0; i < rdfa.nstates; ++i) {
        const RevDfa::state_t& s = rdfa.states[i];
        if (!s.fallthru) continue;

        // Backward-propagate liveness from fallthrough state, following reversed DFA arcs.
        stack.push_back({i, s.rule, nullptr});
        while (!stack.empty()) {
            // Ensure that the reference to stack top won't be accidentally invalidated on push.
            if (stack.size() == stack.capacity()) stack.reserve(stack.size() * 2);
            DfsBackprop& x = stack.back();

            const RevDfa::state_t& t = rdfa.states[x.state];

            if (x.arc == nullptr) {
                // "none-rule" is unreachable from final states: mask it before propagating.
                if (x.rule == rdfa.nrules) {
                    x.rule = t.rule;
                }
                // If the rule has already been set, than either it's a loop, or another branch of
                // backward propagation has already been here, in both cases we should stop: there's
                // nothing new to propagate.
                bool& l = live[x.rule * rdfa.nstates + x.state];
                if (!l) {
                    l = true;
                    x.arc = t.arcs;
                }
            } else {
                x.arc = x.arc->next;
            }

            if (x.arc == nullptr) {
                stack.pop_back(); // all arcs followed, this state is finished
            } else {
                stack.push_back({x.arc->dest, x.rule, nullptr}); // follow next arc
            }
        }
    }
}

// <*> rules are only reported if they are unreachable in all conditions, so the diagnostics
// must be delayed until all conditions are processed.
//
// There's one exception: standalone end-of-input rule `$ { ... }` is reported if it's shadowed
// in any condition. This is to catch behavioral changes caused by the introduction of generalized
// $ (which used to be a special rule like default rule *, but now is part of a normal rule with
// the usual precedence).
//
// An exception from exception: the error is not enforced in cases that did not change behavior:
// if a standalone end-of-input rule is shadowed by another end-of-input rule or a non-<*> rule.
//
static bool delay_reporting(const Rule& r) {
    if (!r.semact->is_star) {
        return false;
    } else if (r.is_oldstyle_eof) {
        CHECK(r.shadow.size() == 1);
        const Rule* s = *r.shadow.begin();
        return (s->is_oldstyle_eof && !s->semact->is_star);
    } else {
        return true;
    }
}

static void warn_dead_rules(Tdfa& dfa, const std::string& cond, const bool* live, Msg& msg) {
    const size_t nstates = dfa.states.size();
    const size_t nrules = dfa.rules.size();

    for (size_t i = 0; i < nstates; ++i) {
        const size_t r = dfa.states[i]->rule;
        if (r != Rule::NONE && !live[r * nstates + i]) {
            // skip last rule (it's the NONE-rule)
            for (size_t j = 0; j < nrules; ++j) {
                if (live[j * nstates + i]) {
                    dfa.rules[r].shadow.insert(&dfa.rules[j]);
                }
            }
        }
    }

    for (size_t i = 0; i < nrules; ++i) {
        Rule& r = dfa.rules[i];
        if (live[i * nstates] || i == dfa.def_rule) { // default rule '*' should not be reported
            r.semact->is_used = true;
        } else if (!delay_reporting(r)) {
            msg.warn.unreachable_rule(cond, r);
        }
    }
}

static void warn_sentinel_in_midrule(
        const Tdfa& dfa, const opt_t* opts, const std::string& cond, const bool* live, Msg& msg) {
    // perform check only in case sentinel method is used
    if (opts->fill_enable || opts->fill_eof != NOEOF) return;

    const size_t nstates = dfa.states.size();
    const size_t nsym = dfa.nchars;
    const size_t nrules = dfa.rules.size();
    bool* bad = new bool[nrules];
    memset(bad, 0, nrules);

    // find character class that contains sentinel symbol
    const uint32_t sentsym = opts->fill_sentinel == NOEOF ? 0 : opts->fill_sentinel;
    uint32_t sentcls = 0;
    DCHECK(dfa.charset.size() == nsym + 1);
    for (; sentcls < nsym && sentsym >= dfa.charset[sentcls + 1]; ++sentcls)
        ;
    DCHECK(sentcls < nsym);

    // Check that every transition on sentinel symbol goes to an end state that has no further
    // transitions; otherwise, give a warning or an error if `re2c:sentinel` configuration is used.
    for (size_t i = 0; i < nstates; ++i) {
        const size_t j = dfa.states[i]->arcs[sentcls];
        if (j == Tdfa::NIL) continue;

        const size_t* arcs = dfa.states[j]->arcs;
        for (size_t c = 0; c < nsym; ++c) {
            const size_t k = arcs[c];
            if (k == Tdfa::NIL) continue;

            for (size_t r = 0; r < nrules; ++r) {
                bad[r] |= live[r * nstates + k];
            }
        }
    }

    for (size_t r = 0; r < nrules; ++r) {
        if (bad[r]) {
            msg.warn.sentinel_in_midrule(dfa.rules[r].semact->loc, cond, opts->fill_sentinel);
        }
    }

    delete[] bad;
}

static void remove_dead_final_states(Tdfa& dfa, const opt_t* opts, const bool* fallthru) {
    const size_t nsym = dfa.nchars;

    // Find final states with shadowed rules and remove the rule. The state itself is still
    // connected as there are other paths through it.
    for (TdfaState* s : dfa.states) {
        if (s->rule == Rule::NONE) continue;

        // final state is useful iff there is at least one non-accepting path from this state
        bool shadowed = true;
        for (size_t c = 0; c < nsym; ++c) {
            const size_t j = s->arcs[c];
            if (j == Tdfa::NIL || fallthru[j]) {
                shadowed = false;
                break;
            }
        }

        if (shadowed) {
            s->rule = Rule::NONE;
            s->tcmd[nsym] = nullptr;
        }
    }

    // Find final states with shadowed end-of-input rules and disconnect them.
    // Unlike shadowed normal rules, final states for end-of-input rules become unreachable.
    if (opts->fill_eof != NOEOF) {
        for (TdfaState* s : dfa.states) {
            size_t e = s->arcs[dfa.nchars - 1];
            if (e != Tdfa::NIL && dfa.states[e]->rule > s->rule
                    // TODO: remove after deperecating old-style $
                    && dfa.states[e]->rule != dfa.eof_rule) {
                s->arcs[dfa.nchars - 1] = Tdfa::NIL;
                dfa.states[e]->deleted = true;
            }
        }
    }
}

static void find_fallback_states(Tdfa& dfa, const bool* fallthru) {
    const size_t nstate = dfa.states.size();
    const size_t nsym = dfa.nchars;

    for (size_t i = 0; i < nstate; ++i) {
        TdfaState* s = dfa.states[i];
        s->fallthru = fallthru[i]; // fallthrough state is a state where none-rule is reachable
        if (s->rule == Rule::NONE) continue;

        // A final state is a fallback state if there are non-accepting paths from it (i.e. paths
        // that end with a transition to default state).
        for (size_t c = 0; c < nsym; ++c) {
            const size_t j = s->arcs[c];
            if (j != Tdfa::NIL && fallthru[j]) {
                s->fallback = true;
                break;
            }
        }
    }
}

// Enforce old-style end-of-input rule. It used to be a special rule, similar to the default
// rule *, and it had different inheritance and precedence order compared to normal rules.
// Now with the introduction of generalized $ it can be used anywhere in a regexp, and it's
// part of a normal rule with normal precedence. This breaks backwards compatibility, so for
// the time being we enforce the old order.
static void enforce_oldstyle_eof_rule(Tdfa& dfa, const opt_t* opts) {
    if (opts->fill_eof != NOEOF && !dfa.states.empty()) {
        size_t e = dfa.states[0]->arcs[dfa.nchars - 1];
        if (e != Tdfa::NIL) {
            dfa.states[e]->rule = dfa.eof_rule;
        }
    }
}

} // anonymous namespace

void cutoff_dead_rules(Tdfa& dfa, const opt_t* opts, const std::string& cond, Msg& msg) {
    if (cond == ZERO_COND) {
        // Skip zero condition `<>`, it's a special case that doesn't need end-of-input checks.
    } else {
        const RevDfa rdfa(dfa, opts);
        const size_t ns = rdfa.nstates;
        const size_t nl = (rdfa.nrules + 1) * ns;
        bool* live = new bool[nl];
        bool* fallthru = live + nl - ns;
        memset(live, 0, nl * sizeof(bool));

        liveness_analysis(rdfa, live);

        warn_dead_rules(dfa, cond, live, msg);
        enforce_oldstyle_eof_rule(dfa, opts); // TODO: remove after deprecating old-style $
        remove_dead_final_states(dfa, opts, fallthru);
        warn_sentinel_in_midrule(dfa, opts, cond, live, msg);
        find_fallback_states(dfa, fallthru);

        delete[] live;
    }
}

void warn_dead_star_rules(const std::vector<std::unique_ptr<Adfa>>& dfas, Msg& msg) {
    for (const std::unique_ptr<Adfa>& dfa : dfas) {
        for (Rule& r : dfa->rules) {
            if (!r.semact->is_used && delay_reporting(r)) {
                msg.warn.unreachable_rule(dfa->cond, r);
            }
        }
    }
    // clear reachability info, as this action might be reused in another block
    for (const std::unique_ptr<Adfa>& dfa : dfas) {
        for (Rule& r : dfa->rules) {
            if (r.semact && r.semact->is_star) {
                r.semact->is_used = false;
            }
        }
    }
}

} // namespace re2c


#include <algorithm>

#include "src/options/opt.h"
#include "src/skeleton/skeleton.h"
#include "src/util/check.h"

namespace re2c {

struct opt_t;
struct tcmd_t;

Node::Node(): arcs(), rule(Rule::NONE), eof_rule(Rule::NONE), cmd(nullptr) {}

void Node::init(Tdfa& dfa, const TdfaState* s, const std::vector<uint32_t>& charset,
        const opt_t* opts, size_t nil, IrAllocator& ir_alc) {
    // Exclude fake end-of-input symbol $ and omit all transitions on it from skeleton.
    // These are not real transitions, so they would interfere with path cover, undefined
    // control flow analysis, maximal path length etc.
    const size_t nchars_no_eof = dfa.nchars - (opts->fill_eof != NOEOF ? 1 : 0);

    for (uint32_t c = 0, l = 0; c < nchars_no_eof;) {
        size_t j = s->arcs[c];
        const tcmd_t* t = s->tcmd[c];
        for (; ++c < nchars_no_eof && s->arcs[c] == j && s->tcmd[c] == t;);

        if (j == Tdfa::NIL) j = nil;

        // All arcs go to default node => this node is final. Note the use of `nchars`
        // (including EOF) to hanlde correctly the case of a single `$ { ... }` rule,
        if (l == 0 && c == dfa.nchars && j == nil) break;

        const uint32_t u = charset[c];
        Node::range_t* r = ir_alc.alloct<Node::range_t>(1);
        r->lower = l;
        r->upper = u - 1;
        r->cmd = t;

        // insert range at the end of a circular list
        if (arcs[j] == nullptr) {
            arcs[j] = r->next = r;
        } else {
            range_t* p0 = arcs[j], *p = p0;
            for (; p->next != p0; p = p->next);
            p->next = r;
            r->next = p0;
        }

        l = u;
    }

    rule = s->rule;
    eof_rule = opts->fill_eof != NOEOF && s->arcs[dfa.nchars - 1] != Tdfa::NIL
        ? dfa.states[s->arcs[dfa.nchars - 1]]->rule : Rule::NONE;
    cmd = s->tcmd[dfa.nchars];
}

bool Node::end() const {
    return arcs.size() == 0;
}

Skeleton::Skeleton(Tdfa& dfa,
                   const opt_t* opts,
                   const std::string& name,
                   const std::string& cond,
                   const loc_t& loc,
                   Msg& msg)
    : dfa(dfa),
      opts(opts),
      name(name),
      cond(cond),
      loc(loc),
      msg(msg),
      nodes_count(dfa.states.size() + 1), // +1 for default state
      nodes(new Node[nodes_count]),
      sizeof_key(8),
      ntagver(static_cast<size_t>(dfa.maxtagver) + 1),
      tagvals(new uint32_t[ntagver]),
      tagtrie(),
      mtagval(),
      arc_iters(),
      char_iters(),
      buf_data(),
      buf_keys() {}

Ret Skeleton::init() {
    // initialize nodes
    const size_t nil = nodes_count - 1;
    for (size_t i = 0; i < nil; ++i) {
        nodes[i].init(dfa, dfa.states[i], dfa.charset, opts, nil, dfa.ir_alc);
    }

    // initialize size of key
    uint32_t maxlen;
    CHECK_RET(maxpath(*this, maxlen));
    uint32_t maxrule = static_cast<uint32_t>(dfa.rules.size()) + 1; // +1 for none-rule
    uint32_t max = std::max(maxlen, maxrule);
    if (max <= std::numeric_limits<uint8_t>::max()) {
        sizeof_key = 1;
    } else if (max <= std::numeric_limits<uint16_t>::max()) {
        sizeof_key = 2;
    } else {
        sizeof_key = 4;
    }

    mtag_trie_init(tagtrie);
    arc_iters.init(256);
    char_iters.init(256);
    buf_data.init(opts->encoding.cunit_size());
    buf_keys.init(sizeof_key);

    return Ret::OK;
}

Skeleton::~Skeleton() {
    delete[] nodes;
    delete[] tagvals;
    mtag_trie_free(tagtrie);
    arc_iters.free();
    char_iters.free();
    buf_data.free(opts->encoding.cunit_size());
    buf_keys.free(sizeof_key);
}

uint64_t rule2key(size_t rule, size_t key, size_t def) {
    switch (key) {
    case 8:
        return rule2key<uint64_t>(rule, def);
    case 4:
        return rule2key<uint32_t>(rule, def);
    case 2:
        return rule2key<uint16_t>(rule, def);
    case 1:
        return rule2key<uint8_t>(rule, def);
    }
    UNREACHABLE();
}

// C++11 requres outer decl for ODR-used static constexpr data members (not needed in C++17).
constexpr uint32_t Skeleton::DEFTAG;

} // namespace re2c

#ifndef _RE2C_SKELETON_SKELETON_
#define _RE2C_SKELETON_SKELETON_

#include <stdint.h>
#include <stdio.h>
#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <string>
#include <valarray>
#include <vector>

#include "src/codegen/code.h"
#include "src/msg/location.h"
#include "src/regexp/rule.h"
#include "src/regexp/tag.h"
#include "src/skeleton/mtag_trie.h"
#include "src/util/containers.h"
#include "src/util/forbid_copy.h"
#include "src/util/local_increment.h"
#include "src/util/fixed_allocator.h"

namespace re2c {

class bitmaps_t;
class Msg;
class path_t;
struct DFA;
struct dfa_state_t;
struct dfa_t;
struct opt_t;
struct tcmd_t;

struct OutBuf {
    FILE* file;
    size_t size;
    union {
        membuf_t<uint8_t>  buf8;
        membuf_t<uint16_t> buf16;
        membuf_t<uint32_t> buf32;
        membuf_t<uint64_t> buf64;
    };

    void init(size_t selector);
    void free(size_t selector);
    template<typename T> membuf_t<T>& select();
    template<typename T> T* alloc(size_t n);
    template<typename T> void flush();
};

template<> inline membuf_t<uint8_t>&  OutBuf::select() { return buf8; }
template<> inline membuf_t<uint16_t>& OutBuf::select() { return buf16; }
template<> inline membuf_t<uint32_t>& OutBuf::select() { return buf32; }
template<> inline membuf_t<uint64_t>& OutBuf::select() { return buf64; }

inline void OutBuf::init(size_t selector) {
    static constexpr size_t KB = 1024 * 1024;
    switch (selector) {
    case 1: buf8.init(KB);  break;
    case 2: buf16.init(KB); break;
    case 4: buf32.init(KB); break;
    case 8: buf64.init(KB); break;
    default:
        DASSERT(false);
    }
    size = 0;
    file = nullptr;
}

inline void OutBuf::free(size_t selector) {
    switch (selector) {
    case 1: buf8.free();  break;
    case 2: buf16.free(); break;
    case 4: buf32.free(); break;
    case 8: buf64.free(); break;
    default:
        DASSERT(false);
    }
    size = 0;
}

template<typename T> inline void OutBuf::flush() {
    membuf_t<T>& buf = select<T>();
    fwrite(buf.ptr_, sizeof(T), size, file);
    size = 0;
}

template<typename T> inline T* OutBuf::alloc(size_t n) {
    membuf_t<T>& buf = select<T>();

    if (size + n >= buf.size_) {
        flush<T>();
        buf.grow(n);
        size = 0;
    }

    T* ptr = buf.ptr_ + size;
    size += n;

    return ptr;
}

using local_inc = local_increment_t<uint8_t>;

struct Node {
    struct range_t {
        uint32_t lower;
        uint32_t upper;
        const tcmd_t* cmd;
        range_t* next;
    };

    using arcs_t = std::map<size_t, range_t*>;
    using range_allocator_t = fixed_allocator_t<Node::range_t>;

    arcs_t arcs;
    size_t rule;
    const tcmd_t* cmd;

    Node();
    void init(const dfa_state_t* s,
              const std::vector<uint32_t>& charset,
              size_t nil,
              range_allocator_t& allocator);
    bool end() const;

    FORBID_COPY(Node);
};

struct Skeleton {
    static constexpr uint32_t DEFTAG = std::numeric_limits<uint32_t>::max();

    const opt_t* opts;
    const std::string name;
    const std::string cond;
    const loc_t loc;
    Msg& msg;

    Node::range_allocator_t range_allocator;

    const size_t nodes_count;
    Node* nodes;

    size_t sizeof_key;
    size_t def_rule;
    size_t eof_rule;
    size_t ntagver;
    const std::vector<uint32_t>& charset;
    const std::valarray<Rule>& rules;
    const std::vector<Tag>& tags;
    const tagver_t* finvers;

    uint32_t* tagvals;
    mtag_trie_t tagtrie;
    std::vector<uint32_t> mtagval;
    membuf_t<const Node::range_t*> arc_iters;
    membuf_t<size_t> char_iters;
    OutBuf buf_data;
    OutBuf buf_keys;

    Skeleton(const dfa_t& dfa,
             const opt_t* opts,
             const std::string& name,
             const std::string& cond,
             const loc_t& loc,
             Msg& msg);
    ~Skeleton ();
    FORBID_COPY(Skeleton);
};

template<typename key_t> key_t rule2key(size_t r, size_t def) {
    if (r == Rule::NONE) {
        return std::numeric_limits<key_t>::max();
    } else if (r == def) {
        key_t k = std::numeric_limits<key_t>::max();
        return --k;
    } else {
        return static_cast<key_t>(r);
    }
}

uint64_t rule2key(size_t rule, size_t key, size_t def);
uint32_t maxpath(const Skeleton& skel);
void warn_undefined_control_flow(const Skeleton& skel);
void fprint_default_path(FILE* f, const Skeleton& skel, const path_t& p);
void emit_data(Skeleton& skel);
Code* emit_skeleton_prolog(Output& output);
Code* emit_skeleton_epilog(Output& output);
void emit_skeleton(Output& output, CodeList* code, DFA& dfa);
void emit_skeleton_action(Output& output, CodeList* code, const DFA& dfa, size_t rid);

} // namespace re2c

#endif // _RE2C_SKELETON_SKELETON_

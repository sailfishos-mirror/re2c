#ifndef _RE2C_AST_UNESCAPE_
#define _RE2C_AST_UNESCAPE_

#include <stdint.h>

namespace re2c {

uint32_t unesc_hex (const char* s, const char* s_end);
uint32_t unesc_oct (const char* s, const char* s_end);

} // namespace re2c

#endif // _RE2C_AST_UNESCAPE_

/* Generated by re2c */
#line 1 "c/eof/04_fake_sentinel.re"
// re2c $INPUT -o $OUTPUT
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static int lex(const char *str, unsigned int len) {
    // For the sake of example create a string without terminating null.
    char *buf = (char*) malloc(len);
    memcpy(buf, str, len);

    const char *cur = buf, *lim = buf + len;
    int count = 0;

    for (;;) {
    
#line 19 "c/eof/04_fake_sentinel.c"
{
	char yych;
	yych = cur < lim ? *cur : 0;
	switch (yych) {
		case 0x00: goto yy1;
		case ' ': goto yy3;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z': goto yy5;
		default: goto yy2;
	}
yy1:
	++cur;
#line 24 "c/eof/04_fake_sentinel.re"
	{ break;; }
#line 58 "c/eof/04_fake_sentinel.c"
yy2:
	++cur;
#line 23 "c/eof/04_fake_sentinel.re"
	{ count = -1; break; }
#line 63 "c/eof/04_fake_sentinel.c"
yy3:
	++cur;
	yych = cur < lim ? *cur : 0;
	switch (yych) {
		case ' ': goto yy3;
		default: goto yy4;
	}
yy4:
#line 26 "c/eof/04_fake_sentinel.re"
	{ continue; }
#line 74 "c/eof/04_fake_sentinel.c"
yy5:
	++cur;
	yych = cur < lim ? *cur : 0;
	switch (yych) {
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
		case 'k':
		case 'l':
		case 'm':
		case 'n':
		case 'o':
		case 'p':
		case 'q':
		case 'r':
		case 's':
		case 't':
		case 'u':
		case 'v':
		case 'w':
		case 'x':
		case 'y':
		case 'z': goto yy5;
		default: goto yy6;
	}
yy6:
#line 25 "c/eof/04_fake_sentinel.re"
	{ ++count; continue;; }
#line 110 "c/eof/04_fake_sentinel.c"
}
#line 27 "c/eof/04_fake_sentinel.re"

    }

    free(buf);
    return count;
}

#define TEST(s, r) assert(lex(s, sizeof(s) - 1) == r)
int main() {
    TEST("", 0);
    TEST("one two three ", 3);
    TEST("f0ur", -1);
    return 0;
}
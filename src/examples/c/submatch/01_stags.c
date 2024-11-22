/* Generated by re2c */
#line 1 "c/submatch/01_stags.re"
// re2c $INPUT -o $OUTPUT
#include <assert.h>
#include <stddef.h>

struct SemVer { int major, minor, patch; };

static int s2n(const char *s, const char *e) { // pre-parsed string to number
    int n = 0;
    for (; s < e; ++s) n = n * 10 + (*s - '0');
    return n;
}

static bool lex(const char *str, SemVer &ver) {
    const char *YYCURSOR = str, *YYMARKER;

    // User-defined tag variables that are available in semantic action.
    const char *t1, *t2, *t3, *t4, *t5;

    // Autogenerated tag variables used by the lexer to track tag values.
    
#line 24 "c/submatch/01_stags.c"
const char *yyt1;
const char *yyt2;
const char *yyt3;
const char *yyt4;
#line 20 "c/submatch/01_stags.re"


    
#line 33 "c/submatch/01_stags.c"
{
	char yych;
	yych = *YYCURSOR;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			yyt1 = YYCURSOR;
			goto yy3;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
yy2:
#line 35 "c/submatch/01_stags.re"
	{ return false; }
#line 57 "c/submatch/01_stags.c"
yy3:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
		case '.': goto yy4;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy6;
		default: goto yy2;
	}
yy4:
	yych = *++YYCURSOR;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			yyt2 = YYCURSOR;
			goto yy7;
		default: goto yy5;
	}
yy5:
	YYCURSOR = YYMARKER;
	goto yy2;
yy6:
	yych = *++YYCURSOR;
	switch (yych) {
		case '.': goto yy4;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy6;
		default: goto yy5;
	}
yy7:
	yych = *++YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt3 = YYCURSOR;
			yyt4 = NULL;
			goto yy8;
		case '.':
			yyt3 = YYCURSOR;
			goto yy9;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy7;
		default: goto yy5;
	}
yy8:
	++YYCURSOR;
	t1 = yyt1;
	t3 = yyt2;
	t4 = yyt3;
	t5 = yyt4;
	t2 = yyt2;
	t2 -= 1;
#line 29 "c/submatch/01_stags.re"
	{
            ver.major = s2n(t1, t2);
            ver.minor = s2n(t3, t4);
            ver.patch = t5 != NULL ? s2n(t5, YYCURSOR - 1) : 0;
            return true;
        }
#line 147 "c/submatch/01_stags.c"
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			yyt4 = YYCURSOR;
			goto yy10;
		default: goto yy5;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
		case 0x00: goto yy8;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy10;
		default: goto yy5;
	}
}
#line 36 "c/submatch/01_stags.re"

}

int main() {
    SemVer v;
    assert(lex("23.34", v) && v.major == 23 && v.minor == 34 && v.patch == 0);
    assert(lex("1.2.999", v) && v.major == 1 && v.minor == 2 && v.patch == 999);
    assert(!lex("1.a", v));
    return 0;
}

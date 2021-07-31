/* Generated by re2c */
#line 1 "ctx.re"
// re2c $INPUT -o $OUTPUT 
#include <cstring>
#include <iostream>

struct Scanner
{
	Scanner(char *txt)
		: cur(txt), lim(txt + strlen(txt))
	{
	}
	
	char    *cur;
	char    *lim;
	char	*ptr;
	char	*ctx;
	char    *tok;
};

#define	YYCTYPE		char
#define	YYCURSOR	s.cur
#define	YYLIMIT		s.lim
#define	YYMARKER	s.ptr
#define	YYCTXMARKER	s.ctx
#define	YYFILL(n)	

enum What
{
	UNEXPECTED,
	KEYWORD,
	NUMBER,
	EOI
};

char * tokens[] = { "UNEXPECTED", "KEYWORD", "NUMBER", "EOI" };


int scan(Scanner &s)
{
	YYCTYPE *cursor = s.cur;

	if(cursor == s.lim)
		return EOI;
	
std:
	s.tok = cursor;


#line 51 "ctx.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case ' ':	goto yy4;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':	goto yy6;
	case 'a':
	case 'b':	goto yy9;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
#line 61 "ctx.re"
	{
		return UNEXPECTED;
	}
#line 81 "ctx.c"
yy4:
	++YYCURSOR;
#line 54 "ctx.re"
	{
		if(s.cur == s.lim)
			return EOI;
		cursor = s.cur;
		goto std;
	}
#line 91 "ctx.c"
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
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
	case '9':	goto yy6;
	default:	goto yy8;
	}
yy8:
#line 51 "ctx.re"
	{ return NUMBER;  }
#line 112 "ctx.c"
yy9:
	yych = *++YYCURSOR;
	switch (yych) {
	case '0':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		YYCTXMARKER = YYCURSOR;
		goto yy10;
	case '1':
		YYCTXMARKER = YYCURSOR;
		goto yy13;
	default:	goto yy3;
	}
yy10:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
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
	case '9':	goto yy10;
	default:	goto yy12;
	}
yy12:
	YYCURSOR = YYCTXMARKER;
#line 50 "ctx.re"
	{ return KEYWORD; }
#line 153 "ctx.c"
yy13:
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
	case '9':	goto yy10;
	default:	goto yy14;
	}
yy14:
	YYCURSOR -= 1;
#line 49 "ctx.re"
	{ return KEYWORD; }
#line 173 "ctx.c"
}
#line 64 "ctx.re"

}

#line 179 "ctx.c"
#define YYMAXFILL 3
#line 67 "ctx.re"


int main(int,char**)
{
	Scanner s("a77 a1 b8 b1");
	
	int t, n = 0;
	while ((t = scan(s)) != EOI)
	{
		std::cout << (++n) << ": " << tokens[t] << " = \""; std::cout.write(s.tok, s.cur-s.tok); std::cout << "\"" << std::endl;
	}
}
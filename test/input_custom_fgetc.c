/* Generated by re2c */
#line 1 "input_custom_fgetc.re"
// re2c $INPUT -o $OUTPUT  --input custom
#include <stdio.h>

char peek (FILE * f)
{
    char c = fgetc (f);
    ungetc (c, f);
    return c;
}

bool lex (FILE * f, const long limit)
{
    long marker;
    long ctxmarker;
#   define YYCTYPE        char
#   define YYPEEK()       peek (f)
#   define YYSKIP()       fgetc (f)
#   define YYBACKUP()     marker = ftell (f)
#   define YYBACKUPCTX()  ctxmarker = ftell (f)
#   define YYRESTORE()    fseek (f, marker, SEEK_SET)
#   define YYRESTORECTX() fseek (f, ctxmarker, SEEK_SET)
#   define YYLESSTHAN(n)  limit - ftell (f) < n
#   define YYFILL(n)      {}
    
#line 28 "input_custom_fgetc.c"
{
	YYCTYPE yych;
	if (YYLESSTHAN(13)) YYFILL(13);
	yych = YYPEEK();
	switch (yych) {
		case 'i': goto yy3;
		default: goto yy1;
	}
yy1:
	YYSKIP();
yy2:
#line 26 "input_custom_fgetc.re"
	{ return false; }
#line 42 "input_custom_fgetc.c"
yy3:
	YYSKIP();
	YYBACKUP();
	yych = YYPEEK();
	switch (yych) {
		case 'n': goto yy4;
		default: goto yy2;
	}
yy4:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 't': goto yy6;
		default: goto yy5;
	}
yy5:
	YYRESTORE();
	goto yy2;
yy6:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case ' ': goto yy7;
		default: goto yy5;
	}
yy7:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'b': goto yy8;
		default: goto yy5;
	}
yy8:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'u': goto yy9;
		default: goto yy5;
	}
yy9:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'f': goto yy10;
		default: goto yy5;
	}
yy10:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'f': goto yy11;
		default: goto yy5;
	}
yy11:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'e': goto yy12;
		default: goto yy5;
	}
yy12:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'r': goto yy13;
		default: goto yy5;
	}
yy13:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case ' ': goto yy14;
		default: goto yy5;
	}
yy14:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case '[':
			YYBACKUPCTX();
			goto yy15;
		default: goto yy5;
	}
yy15:
	YYSKIP();
	yych = YYPEEK();
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
		case '9': goto yy16;
		default: goto yy5;
	}
yy16:
	YYSKIP();
	if (YYLESSTHAN(1)) YYFILL(1);
	yych = YYPEEK();
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
		case '9': goto yy16;
		case ']': goto yy17;
		default: goto yy5;
	}
yy17:
	YYSKIP();
	YYRESTORECTX();
#line 25 "input_custom_fgetc.re"
	{ return true; }
#line 165 "input_custom_fgetc.c"
}
#line 27 "input_custom_fgetc.re"

}

int main ()
{
    const char buffer [] = "int buffer [1024]";
    const char fn [] = "input.txt";

    FILE * f = fopen (fn, "w");
    fwrite (buffer, 1, sizeof (buffer), f);
    fclose (f);

    f = fopen (fn, "rb");
    int result = !lex (f, sizeof (buffer));
    fclose (f);

    return result;
}

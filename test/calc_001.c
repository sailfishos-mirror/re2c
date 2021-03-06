/* Generated by re2c */
#line 1 "calc_001.re"
// re2c $INPUT -o $OUTPUT 
/* re2c lesson 001_upn_calculator, calc_001, (c) M. Boerger 2006 - 2007 */
#line 43 "calc_001.re"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int scan(char *s, int l)
{
	char *p = s;
	char *q = 0;
#define YYCTYPE         char
#define YYCURSOR        p
#define YYLIMIT         (s+l)
#define YYMARKER        q
#define YYFILL(n)
	
	for(;;)
	{

#line 26 "calc_001.c"
		{
			YYCTYPE yych;
			if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
			yych = *YYCURSOR;
			switch (yych) {
				case 0x00: goto yy1;
				case '+': goto yy3;
				case '-': goto yy4;
				case '0': goto yy5;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9': goto yy7;
				default: goto yy2;
			}
yy1:
			++YYCURSOR;
#line 68 "calc_001.re"
			{ printf("EOF\n");	return 0; }
#line 51 "calc_001.c"
yy2:
			++YYCURSOR;
#line 69 "calc_001.re"
			{ printf("ERR\n");	return 1; }
#line 56 "calc_001.c"
yy3:
			++YYCURSOR;
#line 66 "calc_001.re"
			{ printf("+\n");	continue; }
#line 61 "calc_001.c"
yy4:
			++YYCURSOR;
#line 67 "calc_001.re"
			{ printf("-\n");	continue; }
#line 66 "calc_001.c"
yy5:
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
				case '9': goto yy9;
				default: goto yy6;
			}
yy6:
#line 65 "calc_001.re"
			{ printf("Num\n");	continue; }
#line 85 "calc_001.c"
yy7:
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
				case '9': goto yy7;
				default: goto yy8;
			}
yy8:
#line 64 "calc_001.re"
			{ printf("Num\n");	continue; }
#line 106 "calc_001.c"
yy9:
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
				case '9': goto yy9;
				default: goto yy10;
			}
yy10:
#line 63 "calc_001.re"
			{ printf("Oct\n");	continue; }
#line 127 "calc_001.c"
		}
#line 70 "calc_001.re"

	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		return scan(argv[1], strlen(argv[1]));
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 1;
	}
}

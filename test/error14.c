/* Generated by re2c */
#line 1 "error14.re"

#line 5 "<stdout>"
{
	YYCTYPE yych;

	if((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch(yych){
	case 'A':	goto yy2;
	default:	goto yy4;
	}
yy2:
	yych = *(YYMARKER = ++YYCURSOR);
	switch(yych){
	case 'B':	goto yy5;
	default:	goto yy3;
	}
yy3:
#line 4 "error14.re"
	{ return 0; }
#line 24 "<stdout>"
yy4:
	yych = *++YYCURSOR;
	goto yy3;
yy5:
	yych = *++YYCURSOR;
	switch(yych){
	case 'C':	goto yy7;
	case 'D':	goto yy9;
	default:	goto yy6;
	}
yy6:
	YYCURSOR = YYMARKER;
	goto yy3;
yy7:
	++YYCURSOR;
#line 2 "error14.re"
	{ return 1; }
#line 42 "<stdout>"
yy9:
	++YYCURSOR;
#line 3 "error14.re"
	{ return 2; }
#line 47 "<stdout>"
}
#line 5 "error14.re"


#define YYMAXFILL 3

re2c: error: line 5, column 1: cannot generate YYMAXFILL twice

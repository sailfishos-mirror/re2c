/* Generated by re2c */
#line 1 "reuse/inline_use_merge_blocks.re"
// re2c $INPUT -o $OUTPUT

// This test is for merging blocks with inline !use directive.
// It checks that overlapping configurations and rules are merged with correct
// priority (the first rule wins, and the last configuration wins).

#line 12 "reuse/inline_use_merge_blocks.re"


#line 20 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:xchar, return:a, fill:no, ifs:no

#line 18 "reuse/inline_use_merge_blocks.c"
{
	xchar yych;
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy2;
		case 'c': goto yy3;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
#line 27 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 31 "reuse/inline_use_merge_blocks.c"
yy2:
	++YYCURSOR;
#line 25 "reuse/inline_use_merge_blocks.re"
	{ return a; }
#line 36 "reuse/inline_use_merge_blocks.c"
yy3:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 41 "reuse/inline_use_merge_blocks.c"
}
#line 28 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:char, return:xa, fill:no, ifs:no

#line 48 "reuse/inline_use_merge_blocks.c"
{
	char yych;
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy6;
		case 'c': goto yy7;
		default: goto yy5;
	}
yy5:
	++YYCURSOR;
#line 35 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 61 "reuse/inline_use_merge_blocks.c"
yy6:
	++YYCURSOR;
#line 10 "reuse/inline_use_merge_blocks.re"
	{ return xa; }
#line 66 "reuse/inline_use_merge_blocks.c"
yy7:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 71 "reuse/inline_use_merge_blocks.c"
}
#line 36 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:ychar, return:a, fill:yes, ifs:yes

#line 78 "reuse/inline_use_merge_blocks.c"
{
	ychar yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') goto yy9;
	if (yych <= 'a') goto yy10;
	if (yych <= 'b') goto yy11;
yy9:
	++YYCURSOR;
#line 43 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 90 "reuse/inline_use_merge_blocks.c"
yy10:
	++YYCURSOR;
#line 41 "reuse/inline_use_merge_blocks.re"
	{ return a; }
#line 95 "reuse/inline_use_merge_blocks.c"
yy11:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 100 "reuse/inline_use_merge_blocks.c"
}
#line 44 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:char, return:ya, fill:yes, ifs:yes

#line 107 "reuse/inline_use_merge_blocks.c"
{
	char yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') goto yy13;
	if (yych <= 'a') goto yy14;
	if (yych <= 'b') goto yy15;
yy13:
	++YYCURSOR;
#line 51 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 119 "reuse/inline_use_merge_blocks.c"
yy14:
	++YYCURSOR;
#line 18 "reuse/inline_use_merge_blocks.re"
	{ return ya; }
#line 124 "reuse/inline_use_merge_blocks.c"
yy15:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 129 "reuse/inline_use_merge_blocks.c"
}
#line 52 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:ychar, return:a, fill:yes, ifs:yes

#line 136 "reuse/inline_use_merge_blocks.c"
{
	ychar yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') goto yy17;
	if (yych <= 'a') goto yy18;
	if (yych <= 'b') goto yy19;
	if (yych <= 'c') goto yy20;
yy17:
	++YYCURSOR;
#line 60 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 149 "reuse/inline_use_merge_blocks.c"
yy18:
	++YYCURSOR;
#line 57 "reuse/inline_use_merge_blocks.re"
	{ return a; }
#line 154 "reuse/inline_use_merge_blocks.c"
yy19:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 159 "reuse/inline_use_merge_blocks.c"
yy20:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 164 "reuse/inline_use_merge_blocks.c"
}
#line 61 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:xchar, return:a, fill:no, ifs:yes

#line 171 "reuse/inline_use_merge_blocks.c"
{
	xchar yych;
	yych = *YYCURSOR;
	if (yych <= '`') goto yy22;
	if (yych <= 'a') goto yy23;
	if (yych <= 'b') goto yy24;
	if (yych <= 'c') goto yy25;
yy22:
	++YYCURSOR;
#line 69 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 183 "reuse/inline_use_merge_blocks.c"
yy23:
	++YYCURSOR;
#line 66 "reuse/inline_use_merge_blocks.re"
	{ return a; }
#line 188 "reuse/inline_use_merge_blocks.c"
yy24:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 193 "reuse/inline_use_merge_blocks.c"
yy25:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 198 "reuse/inline_use_merge_blocks.c"
}
#line 70 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:ychar, return:xa, fill:yes, ifs:yes

#line 205 "reuse/inline_use_merge_blocks.c"
{
	ychar yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') goto yy27;
	if (yych <= 'a') goto yy28;
	if (yych <= 'b') goto yy29;
	if (yych <= 'c') goto yy30;
yy27:
	++YYCURSOR;
#line 78 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 218 "reuse/inline_use_merge_blocks.c"
yy28:
	++YYCURSOR;
#line 10 "reuse/inline_use_merge_blocks.re"
	{ return xa; }
#line 223 "reuse/inline_use_merge_blocks.c"
yy29:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 228 "reuse/inline_use_merge_blocks.c"
yy30:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 233 "reuse/inline_use_merge_blocks.c"
}
#line 79 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:xchar, return:ya, fill:no, ifs:yes

#line 240 "reuse/inline_use_merge_blocks.c"
{
	xchar yych;
	yych = *YYCURSOR;
	if (yych <= '`') goto yy32;
	if (yych <= 'a') goto yy33;
	if (yych <= 'b') goto yy34;
	if (yych <= 'c') goto yy35;
yy32:
	++YYCURSOR;
#line 87 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 252 "reuse/inline_use_merge_blocks.c"
yy33:
	++YYCURSOR;
#line 18 "reuse/inline_use_merge_blocks.re"
	{ return ya; }
#line 257 "reuse/inline_use_merge_blocks.c"
yy34:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 262 "reuse/inline_use_merge_blocks.c"
yy35:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 267 "reuse/inline_use_merge_blocks.c"
}
#line 88 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:char, return:xa, fill:yes, ifs:yes

#line 274 "reuse/inline_use_merge_blocks.c"
{
	char yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '`') goto yy37;
	if (yych <= 'a') goto yy38;
	if (yych <= 'b') goto yy39;
	if (yych <= 'c') goto yy40;
yy37:
	++YYCURSOR;
#line 96 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 287 "reuse/inline_use_merge_blocks.c"
yy38:
	++YYCURSOR;
#line 10 "reuse/inline_use_merge_blocks.re"
	{ return xa; }
#line 292 "reuse/inline_use_merge_blocks.c"
yy39:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 297 "reuse/inline_use_merge_blocks.c"
yy40:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 302 "reuse/inline_use_merge_blocks.c"
}
#line 97 "reuse/inline_use_merge_blocks.re"


// expect: YYCTYPE:char, return:ya, fill:no, ifs:yes

#line 309 "reuse/inline_use_merge_blocks.c"
{
	char yych;
	yych = *YYCURSOR;
	if (yych <= '`') goto yy42;
	if (yych <= 'a') goto yy43;
	if (yych <= 'b') goto yy44;
	if (yych <= 'c') goto yy45;
yy42:
	++YYCURSOR;
#line 105 "reuse/inline_use_merge_blocks.re"
	{ return -1; }
#line 321 "reuse/inline_use_merge_blocks.c"
yy43:
	++YYCURSOR;
#line 18 "reuse/inline_use_merge_blocks.re"
	{ return ya; }
#line 326 "reuse/inline_use_merge_blocks.c"
yy44:
	++YYCURSOR;
#line 19 "reuse/inline_use_merge_blocks.re"
	{ return yb; }
#line 331 "reuse/inline_use_merge_blocks.c"
yy45:
	++YYCURSOR;
#line 11 "reuse/inline_use_merge_blocks.re"
	{ return xc; }
#line 336 "reuse/inline_use_merge_blocks.c"
}
#line 106 "reuse/inline_use_merge_blocks.re"

reuse/inline_use_merge_blocks.re:10:8: warning: unreachable rule (shadowed by rule at line 25) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:34:8: warning: unreachable rule (shadowed by rule at line 10) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:18:8: warning: unreachable rule (shadowed by rule at line 41) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:50:8: warning: unreachable rule (shadowed by rule at line 18) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:10:8: warning: unreachable rule (shadowed by rule at line 57) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:18:8: warning: unreachable rule (shadowed by rule at line 57) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:18:8: warning: unreachable rule (shadowed by rule at line 66) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:10:8: warning: unreachable rule (shadowed by rule at line 66) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:76:8: warning: unreachable rule (shadowed by rule at line 10) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:18:8: warning: unreachable rule (shadowed by rule at line 10) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:85:8: warning: unreachable rule (shadowed by rule at line 18) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:10:8: warning: unreachable rule (shadowed by rule at line 18) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:18:8: warning: unreachable rule (shadowed by rule at line 10) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:95:8: warning: unreachable rule (shadowed by rule at line 10) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:10:8: warning: unreachable rule (shadowed by rule at line 18) [-Wunreachable-rules]
reuse/inline_use_merge_blocks.re:104:8: warning: unreachable rule (shadowed by rule at line 18) [-Wunreachable-rules]
/* Generated by re2c */
#line 1 "input10_b.re"
// re2c $INPUT -o $OUTPUT -b

#line 6 "input10_b.c"
{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'E') {
		if (yych <= '@') goto yy1;
		if (yych <= 'D') goto yy2;
	} else {
		if (yych <= 'G') goto yy2;
		if (yych <= '`') goto yy1;
		if (yych <= 'g') goto yy2;
	}
yy1:
	++YYCURSOR;
#line 11 "input10_b.re"
	{ return -1; }
#line 23 "input10_b.c"
yy2:
	++YYCURSOR;
#line 9 "input10_b.re"
	{ return 1; }
#line 28 "input10_b.c"
}
#line 13 "input10_b.re"


/* Generated by re2c */
#line 1 "encodings/range_neg_lf_x.re"
// re2c $INPUT -o $OUTPUT -x

#line 6 "encodings/range_neg_lf_x.c"
{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy1;
	if (yych <= 0xD7FF) goto yy2;
	if (yych <= 0xDBFF) goto yy4;
	goto yy2;
yy1:
yy2:
	++YYCURSOR;
yy3:
#line 3 "encodings/range_neg_lf_x.re"
	{return 0;}
#line 21 "encodings/range_neg_lf_x.c"
yy4:
	yych = *++YYCURSOR;
	if (yych <= 0xDBFF) goto yy3;
	if (yych <= 0xDFFF) goto yy2;
	goto yy3;
}
#line 4 "encodings/range_neg_lf_x.re"

encodings/range_neg_lf_x.re:2:0: warning: control flow is undefined for strings that match '\xA', use default rule '*' [-Wundefined-control-flow]

/* Generated by re2c */


// QUOTE rule is shadowed by the greedy STRING rule, which keeps
// consuming symbols until either it matches the final quote, or
// YYFILL fails and does not return (then it is a no-match).

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\'':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
	{ /* DEFAULT */ }
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case '\'':	goto yy6;
	default:	goto yy4;
	}
yy6:
	++YYCURSOR;
	{ /* STRING  */ }
}


// The same situation, but with EOF rule: now when YYFILL fails
// in the middle of the STRING rule, it returns and it is posible
// to match the shorter QUOTE rule.

{
	YYCTYPE yych;
yy9_:
	yych = *YYCURSOR;
	switch (yych) {
	case '\'':	goto yy12;
	default:
		if (YYLIMIT <= YYCURSOR) {
			if (YYFILL () == 0) goto yy9_;
			goto yyeofrule3;
		}
		goto yy10;
	}
yy10:
	++YYCURSOR;
yy11:
	{ /* DEFAULT */ }
yy12:
	++YYCURSOR;
yy12_:
	yych = *YYCURSOR;
	if (yych <= 0x00) {
		if (YYLIMIT <= YYCURSOR) {
			if (YYFILL () == 0) goto yy12_;
			goto yy13;
		}
		goto yy14;
	}
	goto yy15;
yy13:
	{ /* QUOTE   */ }
yy14:
	++YYCURSOR;
yy14_:
	yych = *YYCURSOR;
yy15:
	switch (yych) {
	case '\'':	goto yy16;
	default:
		if (YYLIMIT <= YYCURSOR) {
			if (YYFILL () == 0) goto yy14_;
			goto yy11;
		}
		goto yy14;
	}
yy16:
	++YYCURSOR;
	{ /* STRING  */ }
yyeofrule3:
	{ /* EOF     */ }
}

eof/shadowrule_01.i.re:10:6: warning: unreachable rule (shadowed by rule at line 11) [-Wunreachable-rules]
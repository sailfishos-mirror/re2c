/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i
// rules block disables YYFILL


// use block has no YYFILL

{
	YYCTYPE yych;
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy2;
		default: goto yy1;
	}
yy1:
	++YYCURSOR;
	{ xa }
yy2:
	++YYCURSOR;
	{ a }
}


// normal block still has YYFILL

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'b': goto yy5;
		default: goto yy4;
	}
yy4:
	++YYCURSOR;
	{ xb }
yy5:
	++YYCURSOR;
	{ b }
}


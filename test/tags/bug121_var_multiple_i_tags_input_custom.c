/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --tags --input custom
// overlapping trailing contexts of variable length:
// we need multiple tags and we cannot deduplicate them


{
	YYCTYPE yych;
	if (YYLESSTHAN(4)) YYFILL(4);
	yych = YYPEEK();
	switch (yych) {
		case 'a': goto yy2;
		default: goto yy1;
	}
yy1:
	YYSKIP();
	{ d }
yy2:
	YYSKIP();
	yych = YYPEEK();
	YYSTAGP(yyt2);
	switch (yych) {
		case 'b': goto yy4;
		default: goto yy3;
	}
yy3:
	YYRESTORETAG(yyt2);
	{ 1 }
yy4:
	YYSKIP();
	YYBACKUP();
	yych = YYPEEK();
	switch (yych) {
		case 'c':
			YYSTAGP(yyt1);
			goto yy7;
		default: goto yy6;
	}
yy5:
	YYSKIP();
	if (YYLESSTHAN(1)) YYFILL(1);
	yych = YYPEEK();
yy6:
	switch (yych) {
		case 'b': goto yy5;
		default: goto yy3;
	}
yy7:
	YYSKIP();
	yych = YYPEEK();
	switch (yych) {
		case 'c': goto yy9;
		default: goto yy8;
	}
yy8:
	YYRESTORE();
	goto yy3;
yy9:
	YYSKIP();
	if (YYLESSTHAN(1)) YYFILL(1);
	yych = YYPEEK();
	switch (yych) {
		case 'c': goto yy9;
		default: goto yy10;
	}
yy10:
	YYRESTORETAG(yyt1);
	{ 0 }
}


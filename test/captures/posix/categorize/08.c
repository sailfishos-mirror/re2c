/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --flex-syntax

{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	YYMARKER = YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt1 = YYCURSOR;
			yyt3 = YYCURSOR;
			goto yy2;
		case 'b':
			yyt1 = YYCURSOR;
			yyt3 = YYCURSOR;
			goto yy4;
		default:
			yyt1 = YYCURSOR;
			yyt2 = NULL;
			yyt3 = NULL;
			goto yy1;
	}
yy1:
	yynmatch = 2;
	yypmatch[0] = yyt1;
	yypmatch[2] = yyt2;
	yypmatch[3] = yyt3;
	yypmatch[1] = YYCURSOR;
	{}
yy2:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy5;
		case 'b': goto yy6;
		default: goto yy3;
	}
yy3:
	YYCURSOR = YYMARKER;
	if (yyaccept == 0) {
		yyt1 = YYCURSOR;
		yyt2 = NULL;
		yyt3 = NULL;
		goto yy1;
	} else {
		yyt3 = YYCURSOR;
		goto yy1;
	}
yy4:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy2;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy4;
		default:
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy1;
	}
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy5;
		case 'b': goto yy4;
		default: goto yy3;
	}
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt2 = YYCURSOR;
			goto yy7;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy4;
		default:
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy1;
	}
yy7:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy2;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy8;
		default:
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy1;
	}
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt3 = YYCURSOR;
			goto yy9;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy4;
		default:
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy1;
	}
yy9:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt4 = YYCURSOR;
			goto yy10;
		case 'b': goto yy6;
		default:
			yyt3 = YYCURSOR;
			goto yy1;
	}
yy10:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy5;
		case 'b':
			yyt2 = yyt4;
			goto yy8;
		default: goto yy3;
	}
}

captures/posix/categorize/08.re:6:4: warning: rule matches empty string [-Wmatch-empty-string]
captures/posix/categorize/08.re:7:7: warning: rule matches empty string [-Wmatch-empty-string]
captures/posix/categorize/08.re:7:7: warning: unreachable rule (shadowed by rule at line 6) [-Wunreachable-rules]

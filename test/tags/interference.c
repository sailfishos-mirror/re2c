/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --tags
// shows the neccesity of tracking interference induced by copy commands


{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	YYMARKER = YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy2;
		case 'b':
			yyt3 = YYCURSOR;
			yyt4 = YYCURSOR;
			goto yy4;
		default:
			yyt1 = NULL;
			yyt2 = NULL;
			goto yy1;
	}
yy1:
	p = yyt1;
	q = yyt2;
	{}
yy2:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'b':
			yyt3 = NULL;
			yyt4 = YYCURSOR;
			goto yy4;
		default: goto yy3;
	}
yy3:
	YYCURSOR = YYMARKER;
	if (yyaccept == 0) {
		yyt1 = NULL;
		yyt2 = NULL;
		goto yy1;
	} else {
		goto yy1;
	}
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a': goto yy5;
		default: goto yy3;
	}
yy5:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 'a':
			yyt1 = yyt3;
			yyt2 = yyt4;
			goto yy2;
		case 'b':
			yyt1 = yyt3;
			yyt2 = yyt4;
			yyt3 = YYCURSOR;
			yyt4 = YYCURSOR;
			goto yy4;
		default:
			yyt1 = yyt3;
			yyt2 = yyt4;
			goto yy1;
	}
}

tags/interference.re:6:22: warning: rule matches empty string [-Wmatch-empty-string]

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
			goto yy2;
		case 'b':
			yyt1 = YYCURSOR;
			goto yy4;
		default: goto yy1;
	}
yy1:
	yynmatch = 1;
	yypmatch[0] = YYCURSOR;
	yypmatch[1] = YYCURSOR;
	{}
yy2:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'z': goto yy5;
		default: goto yy2;
	}
yy3:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
		case 0: goto yy1;
		case 1: goto yy12;
		case 2:
			yyt2 = yyt4;
			goto yy12;
		default:
			yyt2 = yyt3;
			goto yy12;
	}
yy4:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy6;
		default: goto yy4;
	}
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'a':
			yyt3 = YYCURSOR;
			goto yy7;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy8;
		case 'z': goto yy5;
		default: goto yy2;
	}
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'a':
			yyt3 = YYCURSOR;
			goto yy9;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy10;
		case 'y': goto yy6;
		default: goto yy4;
	}
yy7:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'z': goto yy11;
		default: goto yy7;
	}
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy13;
		case 'z': goto yy14;
		default: goto yy8;
	}
yy9:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy15;
		case 'z': goto yy16;
		default: goto yy9;
	}
yy10:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy17;
		default: goto yy10;
	}
yy11:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'a':
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy7;
		case 'b':
			yyt2 = yyt3;
			yyt4 = YYCURSOR;
			goto yy18;
		case 'z': goto yy11;
		default:
			yyt2 = yyt3;
			goto yy7;
	}
yy12:
	yynmatch = 3;
	yypmatch[2] = yyt1;
	yypmatch[4] = yyt2;
	yypmatch[0] = yyt1;
	yypmatch[1] = YYCURSOR;
	yypmatch[3] = yyt2;
	yypmatch[5] = YYCURSOR;
	{}
yy13:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'y': goto yy13;
		case 'z':
			yyt2 = yyt3;
			goto yy14;
		default:
			yyt2 = yyt3;
			goto yy8;
	}
yy14:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'a':
			yyt4 = YYCURSOR;
			goto yy19;
		case 'b':
			yyt3 = YYCURSOR;
			goto yy8;
		case 'y': goto yy13;
		case 'z': goto yy14;
		default: goto yy8;
	}
yy15:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'a':
			yyt3 = YYCURSOR;
			goto yy9;
		case 'b':
			yyt4 = YYCURSOR;
			goto yy20;
		case 'y': goto yy15;
		case 'z': goto yy16;
		default: goto yy9;
	}
yy16:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'y':
			yyt2 = yyt3;
			goto yy15;
		case 'z': goto yy16;
		default:
			yyt2 = yyt3;
			goto yy9;
	}
yy17:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'a':
			yyt2 = yyt3;
			yyt4 = YYCURSOR;
			goto yy21;
		case 'b':
			yyt2 = yyt3;
			yyt3 = YYCURSOR;
			goto yy10;
		case 'y': goto yy17;
		default:
			yyt2 = yyt3;
			goto yy10;
	}
yy18:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy22;
		case 'z': goto yy23;
		default: goto yy18;
	}
yy19:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy24;
		case 'z': goto yy25;
		default: goto yy19;
	}
yy20:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy26;
		case 'z': goto yy27;
		default: goto yy20;
	}
yy21:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00: goto yy3;
		case 'y': goto yy28;
		case 'z': goto yy29;
		default: goto yy21;
	}
yy22:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt4;
			goto yy12;
		case 'y': goto yy22;
		case 'z': goto yy23;
		default: goto yy18;
	}
yy23:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'a':
			yyt2 = yyt3;
			yyt3 = yyt4;
			yyt4 = YYCURSOR;
			goto yy19;
		case 'b':
			yyt2 = yyt3;
			yyt4 = YYCURSOR;
			goto yy18;
		case 'y': goto yy22;
		case 'z': goto yy23;
		default:
			yyt2 = yyt3;
			goto yy18;
	}
yy24:
	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'y': goto yy24;
		case 'z': goto yy25;
		default: goto yy19;
	}
yy25:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt4;
			goto yy12;
		case 'a':
			yyt2 = yyt4;
			yyt4 = YYCURSOR;
			goto yy19;
		case 'b':
			yyt2 = yyt4;
			yyt3 = yyt4;
			yyt4 = YYCURSOR;
			goto yy18;
		case 'y': goto yy24;
		case 'z': goto yy25;
		default:
			yyt2 = yyt4;
			goto yy19;
	}
yy26:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt4;
			goto yy12;
		case 'a':
			yyt2 = yyt4;
			yyt3 = yyt4;
			yyt4 = YYCURSOR;
			goto yy21;
		case 'b':
			yyt2 = yyt4;
			yyt4 = YYCURSOR;
			goto yy20;
		case 'y': goto yy26;
		case 'z': goto yy27;
		default:
			yyt2 = yyt4;
			goto yy20;
	}
yy27:
	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'y': goto yy26;
		case 'z': goto yy27;
		default: goto yy20;
	}
yy28:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt3;
			goto yy12;
		case 'a':
			yyt2 = yyt3;
			yyt4 = YYCURSOR;
			goto yy21;
		case 'b':
			yyt2 = yyt3;
			yyt3 = yyt4;
			yyt4 = YYCURSOR;
			goto yy20;
		case 'y': goto yy28;
		case 'z': goto yy29;
		default:
			yyt2 = yyt3;
			goto yy21;
	}
yy29:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
		case 0x00:
			yyt2 = yyt4;
			goto yy12;
		case 'y': goto yy28;
		case 'z': goto yy29;
		default: goto yy21;
	}
}

captures/posix/glennfowler/40.re:7:7: warning: rule matches empty string [-Wmatch-empty-string]

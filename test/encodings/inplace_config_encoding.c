/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -is
EBCDIC:

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == 0x81) goto yy1;
	++YYCURSOR;
	{return DEFAULT;}
yy1:
	++YYCURSOR;
	{return 0;}
}


UCS2:

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych >= 0xFFFF) goto yy3;
	++YYCURSOR;
	{return DEFAULT;}
yy3:
	++YYCURSOR;
	{return 0;}
}


UTF16:

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych == 0xDBFF) goto yy6;
	++YYCURSOR;
yy5:
	{return DEFAULT;}
yy6:
	yych = *++YYCURSOR;
	if (yych != 0xDFFF) goto yy5;
	++YYCURSOR;
	{return 0;}
}


UTF32:

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych >= 0x0010FFFF) goto yy8;
	++YYCURSOR;
	{return DEFAULT;}
yy8:
	++YYCURSOR;
	{return 0;}
}


UTF8:

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 4) YYFILL(4);
	yych = *YYCURSOR;
	if (yych == 0xF4) goto yy11;
	++YYCURSOR;
yy10:
	{return DEFAULT;}
yy11:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych != 0x8F) goto yy10;
	yych = *++YYCURSOR;
	if (yych == 0xBF) goto yy13;
yy12:
	YYCURSOR = YYMARKER;
	goto yy10;
yy13:
	yych = *++YYCURSOR;
	if (yych != 0xBF) goto yy12;
	++YYCURSOR;
	{return 0;}
}


ASCII:

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == 'a') goto yy15;
	++YYCURSOR;
	{return DEFAULT;}
yy15:
	++YYCURSOR;
	{return 0;}
}


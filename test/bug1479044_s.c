/* Generated by re2c */
#line 1 "bug1479044_s.re"
// re2c $INPUT -o $OUTPUT -s
#define NULL ((char*) 0)
#define YYCTYPE char
#define YYCURSOR p
#define YYLIMIT p
#define YYMARKER q
#define YYFILL(n)

#include <stdio.h>

char *scan281(char *p)
{
	char *q;
start:

#line 19 "bug1479044_s.c"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if ((YYLIMIT - YYCURSOR) < 11) YYFILL(11);
	yych = *YYCURSOR;
	if (yych <= 'k') {
		if (yych <= '`') {
			if (yych <= 0x00) goto yy1;
			if (yych <= '/') goto yy2;
			if (yych <= '9') goto yy4;
			goto yy2;
		} else {
			if (yych <= 'c') {
				if (yych <= 'a') goto yy5;
				goto yy6;
			} else {
				if (yych <= 'd') goto yy7;
				if (yych <= 'f') goto yy6;
				goto yy2;
			}
		}
	} else {
		if (yych <= 'r') {
			if (yych <= 'o') {
				if (yych <= 'l') goto yy6;
				goto yy2;
			} else {
				if (yych <= 'p') goto yy8;
				if (yych <= 'q') goto yy2;
				goto yy9;
			}
		} else {
			if (yych <= 'v') {
				if (yych <= 'u') goto yy2;
				goto yy6;
			} else {
				if (yych == 'x') goto yy10;
				goto yy2;
			}
		}
	}
yy1:
	++YYCURSOR;
#line 38 "bug1479044_s.re"
	{
		return NULL;
	}
#line 67 "bug1479044_s.c"
yy2:
	++YYCURSOR;
yy3:
#line 33 "bug1479044_s.re"
	{
		goto start;
	}
#line 75 "bug1479044_s.c"
yy4:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '-') goto yy11;
	if (yych <= '/') goto yy3;
	if (yych <= '9') goto yy13;
	goto yy3;
yy5:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'd') goto yy14;
	goto yy3;
yy6:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'd') goto yy15;
	goto yy3;
yy7:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 'n') {
		if (yych == 'h') goto yy16;
		goto yy3;
	} else {
		if (yych <= 'o') goto yy17;
		if (yych == 's') goto yy18;
		goto yy3;
	}
yy8:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 'p') {
		if (yych <= 'n') goto yy3;
		if (yych <= 'o') goto yy19;
		goto yy20;
	} else {
		if (yych == 'r') goto yy21;
		goto yy3;
	}
yy9:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'h') goto yy22;
	goto yy3;
yy10:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 's') goto yy23;
	goto yy3;
yy11:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy24;
yy12:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 1) {
		if (yyaccept == 0) goto yy3;
		else goto yy104;
	} else {
		if (yyaccept == 2) goto yy118;
		else goto yy120;
	}
yy13:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych == '-') goto yy11;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy13;
	goto yy12;
yy14:
	yych = *++YYCURSOR;
	if (yych == 's') goto yy25;
	goto yy12;
yy15:
	yych = *++YYCURSOR;
	if (yych == 's') goto yy26;
	goto yy12;
yy16:
	yych = *++YYCURSOR;
	if (yych == 'c') goto yy27;
	goto yy12;
yy17:
	yych = *++YYCURSOR;
	if (yych == 'r') goto yy28;
	goto yy12;
yy18:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy29;
	goto yy12;
yy19:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy26;
	goto yy12;
yy20:
	yych = *++YYCURSOR;
	if (yych == 'p') goto yy30;
	goto yy12;
yy21:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy31;
	goto yy12;
yy22:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '-') goto yy32;
	goto yy22;
yy23:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy33;
	goto yy12;
yy24:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych == '-') goto yy34;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy24;
	goto yy12;
yy25:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy35;
	goto yy12;
yy26:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy36;
	goto yy12;
yy27:
	yych = *++YYCURSOR;
	if (yych == 'p') goto yy22;
	goto yy12;
yy28:
	yych = *++YYCURSOR;
	if (yych == 'm') goto yy37;
	goto yy12;
yy29:
	yych = *++YYCURSOR;
	if (yych == 'g') goto yy38;
	if (yych == 'p') goto yy39;
	goto yy12;
yy30:
	yych = *++YYCURSOR;
	if (yych == 'd') goto yy15;
	goto yy12;
yy31:
	yych = *++YYCURSOR;
	if (yych == 'm') goto yy40;
	goto yy12;
yy32:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= ',') {
		if (yych == '\n') goto yy12;
		goto yy22;
	} else {
		if (yych <= '-') goto yy32;
		if (yych <= '/') goto yy22;
		if (yych <= '9') goto yy41;
		goto yy22;
	}
yy33:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy42;
	goto yy12;
yy34:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy43;
	goto yy12;
yy35:
	yych = *++YYCURSOR;
	if (yych == '.') goto yy12;
	if (yych == 'p') goto yy39;
	goto yy45;
yy36:
	yych = *++YYCURSOR;
	if (yych == '.') goto yy12;
	goto yy45;
yy37:
	yych = *++YYCURSOR;
	if (yych == 's') goto yy22;
	goto yy12;
yy38:
	yych = *++YYCURSOR;
	if (yych == 'w') goto yy46;
	goto yy12;
yy39:
	yych = *++YYCURSOR;
	if (yych == 'p') goto yy47;
	goto yy12;
yy40:
	yych = *++YYCURSOR;
	if (yych == 'i') goto yy48;
	goto yy12;
yy41:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= ',') {
		if (yych == '\n') goto yy12;
		goto yy22;
	} else {
		if (yych <= '-') goto yy49;
		if (yych <= '/') goto yy22;
		if (yych <= '9') goto yy41;
		goto yy22;
	}
yy42:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy30;
	goto yy12;
yy43:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych == '-') goto yy50;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy43;
	goto yy12;
yy44:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
yy45:
	if (yych <= '/') {
		if (yych <= ',') goto yy12;
		if (yych <= '-') goto yy44;
		if (yych <= '.') goto yy51;
		goto yy12;
	} else {
		if (yych <= '9') goto yy44;
		if (yych <= '`') goto yy12;
		if (yych <= 'k') goto yy44;
		goto yy12;
	}
yy46:
	yych = *++YYCURSOR;
	if (yych == '4') goto yy52;
	goto yy12;
yy47:
	yych = *++YYCURSOR;
	if (yych == 'p') goto yy36;
	goto yy12;
yy48:
	yych = *++YYCURSOR;
	if (yych == 'u') goto yy53;
	goto yy12;
yy49:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= ',') {
		if (yych == '\n') goto yy12;
		goto yy22;
	} else {
		if (yych <= '-') goto yy32;
		if (yych <= '/') goto yy22;
		if (yych <= '9') goto yy54;
		goto yy22;
	}
yy50:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy55;
	goto yy12;
yy51:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy12;
	goto yy56;
yy52:
	yych = *++YYCURSOR;
	if (yych == 'p') goto yy57;
	goto yy12;
yy53:
	yych = *++YYCURSOR;
	if (yych == 'm') goto yy58;
	goto yy12;
yy54:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		if (yych <= ',') goto yy22;
		goto yy49;
	} else {
		if (yych <= '.') goto yy59;
		if (yych <= '/') goto yy22;
		if (yych <= '9') goto yy54;
		goto yy22;
	}
yy55:
	++YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 8) YYFILL(8);
	yych = *YYCURSOR;
	if (yych == '.') goto yy60;
	if (yych <= '/') goto yy12;
	if (yych <= '9') goto yy55;
	goto yy12;
yy56:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy61;
	goto yy56;
yy57:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy19;
	goto yy12;
yy58:
	yych = *++YYCURSOR;
	if (yych == 'C') goto yy36;
	goto yy12;
yy59:
	yych = *++YYCURSOR;
	if (yych == '\n') goto yy12;
	goto yy62;
yy60:
	yych = *++YYCURSOR;
	if (yych == 'b') goto yy65;
	if (yych == 'd') goto yy66;
	goto yy64;
yy61:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 'u') goto yy68;
		goto yy56;
	}
yy62:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy69;
	goto yy62;
yy63:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy64:
	if (yych == '\n') goto yy12;
	if (yych == 'm') goto yy67;
	goto yy63;
yy65:
	yych = *++YYCURSOR;
	if (yych == 'o') goto yy70;
	goto yy64;
yy66:
	yych = *++YYCURSOR;
	if (yych == 'h') goto yy71;
	goto yy64;
yy67:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'l') {
		if (yych == '\n') goto yy12;
		goto yy63;
	} else {
		if (yych <= 'm') goto yy67;
		if (yych == 'o') goto yy72;
		goto yy63;
	}
yy68:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 's') goto yy73;
		goto yy56;
	}
yy69:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'r') goto yy74;
		goto yy62;
	}
yy70:
	yych = *++YYCURSOR;
	if (yych == 't') goto yy75;
	goto yy64;
yy71:
	yych = *++YYCURSOR;
	if (yych == 'c') goto yy76;
	goto yy64;
yy72:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'c') {
		if (yych == '\n') goto yy12;
		goto yy63;
	} else {
		if (yych <= 'd') goto yy77;
		if (yych == 'm') goto yy67;
		goto yy63;
	}
yy73:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 'w') goto yy78;
		goto yy56;
	}
yy74:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'e') goto yy79;
		goto yy62;
	}
yy75:
	yych = *++YYCURSOR;
	if (yych == 'h') goto yy80;
	goto yy64;
yy76:
	yych = *++YYCURSOR;
	if (yych == 'p') goto yy81;
	goto yy64;
yy77:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= 'd') {
		if (yych == '\n') goto yy12;
		goto yy63;
	} else {
		if (yych <= 'e') goto yy82;
		if (yych == 'm') goto yy67;
		goto yy63;
	}
yy78:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 'e') goto yy83;
		goto yy56;
	}
yy79:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 's') goto yy84;
		goto yy62;
	}
yy80:
	yych = *++YYCURSOR;
	if (yych == 'e') goto yy85;
	goto yy64;
yy81:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy86;
	goto yy81;
yy82:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == 'm') goto yy81;
	goto yy63;
yy83:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 's') goto yy87;
		goto yy56;
	}
yy84:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'n') goto yy88;
		goto yy62;
	}
yy85:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy89;
	goto yy64;
yy86:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'w') goto yy90;
		goto yy81;
	}
yy87:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 't') goto yy91;
		goto yy56;
	}
yy88:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'e') goto yy92;
		goto yy62;
	}
yy89:
	yych = *++YYCURSOR;
	if (yych == 'l') goto yy81;
	goto yy64;
yy90:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'a') goto yy93;
		goto yy81;
	}
yy91:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy94;
	goto yy56;
yy92:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 't') goto yy95;
		goto yy62;
	}
yy93:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 's') goto yy96;
		goto yy81;
	}
yy94:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '.') {
		if (yych == '\n') goto yy12;
		if (yych <= '-') goto yy56;
		goto yy61;
	} else {
		if (yych <= 'n') {
			if (yych <= 'm') goto yy56;
			goto yy97;
		} else {
			if (yych == 'u') goto yy68;
			goto yy56;
		}
	}
yy95:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy98;
	goto yy62;
yy96:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'h') goto yy99;
		goto yy81;
	}
yy97:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 'e') goto yy100;
		goto yy56;
	}
yy98:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '.') {
		if (yych == '\n') goto yy12;
		if (yych <= '-') goto yy62;
		goto yy69;
	} else {
		if (yych <= 'p') {
			if (yych <= 'o') goto yy62;
			goto yy101;
		} else {
			if (yych == 'r') goto yy74;
			goto yy62;
		}
	}
yy99:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'i') goto yy102;
		goto yy81;
	}
yy100:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy56;
	} else {
		if (yych <= '.') goto yy61;
		if (yych == 't') goto yy103;
		goto yy56;
	}
yy101:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'i') goto yy105;
		goto yy62;
	}
yy102:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'n') goto yy106;
		goto yy81;
	}
yy103:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy104;
	if (yych == '.') goto yy61;
	goto yy56;
yy104:
#line 18 "bug1479044_s.re"
	{
		return "dsl";
	}
#line 816 "bug1479044_s.c"
yy105:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 't') goto yy107;
		goto yy62;
	}
yy106:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'g') goto yy108;
		goto yy81;
	}
yy107:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 't') goto yy109;
		goto yy62;
	}
yy108:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 't') goto yy110;
		goto yy81;
	}
yy109:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy111;
	goto yy62;
yy110:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'o') goto yy112;
		goto yy81;
	}
yy111:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '.') {
		if (yych == '\n') goto yy12;
		if (yych <= '-') goto yy62;
		goto yy69;
	} else {
		if (yych <= 'e') {
			if (yych <= 'd') goto yy62;
			goto yy113;
		} else {
			if (yych == 'r') goto yy74;
			goto yy62;
		}
	}
yy112:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych == 'n') goto yy114;
		goto yy81;
	}
yy113:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'd') goto yy115;
		goto yy62;
	}
yy114:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy12;
	if (yych == '.') goto yy116;
	goto yy81;
yy115:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy62;
	} else {
		if (yych <= '.') goto yy69;
		if (yych == 'u') goto yy117;
		goto yy62;
	}
yy116:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '.') {
		if (yych == '\n') goto yy12;
		if (yych <= '-') goto yy81;
		goto yy86;
	} else {
		if (yych <= 'e') {
			if (yych <= 'd') goto yy81;
			goto yy119;
		} else {
			if (yych == 'w') goto yy90;
			goto yy81;
		}
	}
yy117:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy118;
	if (yych == '.') goto yy69;
	goto yy62;
yy118:
#line 23 "bug1479044_s.re"
	{
		return "resnet";
	}
#line 974 "bug1479044_s.c"
yy119:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych != 'd') goto yy81;
	}
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '-') {
		if (yych == '\n') goto yy12;
		goto yy81;
	} else {
		if (yych <= '.') goto yy86;
		if (yych != 'u') goto yy81;
	}
	yyaccept = 3;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych == '\n') goto yy120;
	if (yych == '.') goto yy86;
	goto yy81;
yy120:
#line 28 "bug1479044_s.re"
	{
		return "edu";
	}
#line 1008 "bug1479044_s.c"
}
#line 41 "bug1479044_s.re"

}

int main(int argc, char **argv)
{
	int n = 0;
	char *largv[2];

	if (argc < 2)
	{
		argc = 2;
		argv = largv;
		argv[1] = "D-128-208-46-51.dhcp4.washington.edu";
	}
	while(++n < argc)
	{
		char *res = scan281(argv[n]);
		printf("%s\n", res ? res : "<NULL>");
	}
	return 0;
}
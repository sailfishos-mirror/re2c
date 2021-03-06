/* Generated by re2c */
#line 1 "encodings/unicode_group_Sm_x_encoding_policy_substitute.re"
// re2c $INPUT -o $OUTPUT -x --encoding-policy substitute
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Sm:
	
#line 14 "encodings/unicode_group_Sm_x_encoding_policy_substitute.c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x231F) {
		if (yych <= 0x2089) {
			if (yych <= 0x00D6) {
				if (yych <= '|') {
					if (yych <= ';') {
						if (yych == '+') goto yy3;
					} else {
						if (yych <= '>') goto yy3;
						if (yych >= '|') goto yy3;
					}
				} else {
					if (yych <= 0x00AB) {
						if (yych == '~') goto yy3;
					} else {
						if (yych <= 0x00AC) goto yy3;
						if (yych == 0x00B1) goto yy3;
					}
				}
			} else {
				if (yych <= 0x0608) {
					if (yych <= 0x00F7) {
						if (yych <= 0x00D7) goto yy3;
						if (yych >= 0x00F7) goto yy3;
					} else {
						if (yych == 0x03F6) goto yy3;
						if (yych >= 0x0606) goto yy3;
					}
				} else {
					if (yych <= 0x2051) {
						if (yych == 0x2044) goto yy3;
					} else {
						if (yych <= 0x2052) goto yy3;
						if (yych <= 0x2079) goto yy1;
						if (yych <= 0x207C) goto yy3;
					}
				}
			}
		} else {
			if (yych <= 0x21A2) {
				if (yych <= 0x214B) {
					if (yych <= 0x2118) {
						if (yych <= 0x208C) goto yy3;
						if (yych >= 0x2118) goto yy3;
					} else {
						if (yych <= 0x213F) goto yy1;
						if (yych <= 0x2144) goto yy3;
						if (yych >= 0x214B) goto yy3;
					}
				} else {
					if (yych <= 0x2199) {
						if (yych <= 0x218F) goto yy1;
						if (yych <= 0x2194) goto yy3;
					} else {
						if (yych <= 0x219B) goto yy3;
						if (yych == 0x21A0) goto yy3;
					}
				}
			} else {
				if (yych <= 0x21CF) {
					if (yych <= 0x21A6) {
						if (yych <= 0x21A3) goto yy3;
						if (yych >= 0x21A6) goto yy3;
					} else {
						if (yych == 0x21AE) goto yy3;
						if (yych >= 0x21CE) goto yy3;
					}
				} else {
					if (yych <= 0x21D3) {
						if (yych == 0x21D2) goto yy3;
					} else {
						if (yych <= 0x21D4) goto yy3;
						if (yych <= 0x21F3) goto yy1;
						if (yych <= 0x22FF) goto yy3;
					}
				}
			}
		}
	} else {
		if (yych <= 0x29FD) {
			if (yych <= 0x266E) {
				if (yych <= 0x23E1) {
					if (yych <= 0x237C) {
						if (yych <= 0x2321) goto yy3;
						if (yych >= 0x237C) goto yy3;
					} else {
						if (yych <= 0x239A) goto yy1;
						if (yych <= 0x23B3) goto yy3;
						if (yych >= 0x23DC) goto yy3;
					}
				} else {
					if (yych <= 0x25C0) {
						if (yych == 0x25B7) goto yy3;
					} else {
						if (yych <= 0x25C1) goto yy3;
						if (yych <= 0x25F7) goto yy1;
						if (yych <= 0x25FF) goto yy3;
					}
				}
			} else {
				if (yych <= 0x27FF) {
					if (yych <= 0x27C4) {
						if (yych <= 0x266F) goto yy3;
						if (yych >= 0x27C0) goto yy3;
					} else {
						if (yych <= 0x27C6) goto yy1;
						if (yych <= 0x27E5) goto yy3;
						if (yych >= 0x27F0) goto yy3;
					}
				} else {
					if (yych <= 0x2998) {
						if (yych <= 0x28FF) goto yy1;
						if (yych <= 0x2982) goto yy3;
					} else {
						if (yych <= 0x29D7) goto yy3;
						if (yych <= 0x29DB) goto yy1;
						if (yych <= 0x29FB) goto yy3;
					}
				}
			}
		} else {
			if (yych <= 0xFE63) {
				if (yych <= 0xD835) {
					if (yych <= 0x2B44) {
						if (yych <= 0x2AFF) goto yy3;
						if (yych >= 0x2B30) goto yy3;
					} else {
						if (yych <= 0x2B46) goto yy1;
						if (yych <= 0x2B4C) goto yy3;
						if (yych >= 0xD835) goto yy4;
					}
				} else {
					if (yych <= 0xFB28) {
						if (yych == 0xD83B) goto yy5;
					} else {
						if (yych <= 0xFB29) goto yy3;
						if (yych == 0xFE62) goto yy3;
					}
				}
			} else {
				if (yych <= 0xFF5C) {
					if (yych <= 0xFF0B) {
						if (yych <= 0xFE66) goto yy3;
						if (yych >= 0xFF0B) goto yy3;
					} else {
						if (yych <= 0xFF1B) goto yy1;
						if (yych <= 0xFF1E) goto yy3;
						if (yych >= 0xFF5C) goto yy3;
					}
				} else {
					if (yych <= 0xFFE1) {
						if (yych == 0xFF5E) goto yy3;
					} else {
						if (yych <= 0xFFE2) goto yy3;
						if (yych <= 0xFFE8) goto yy1;
						if (yych <= 0xFFEC) goto yy3;
					}
				}
			}
		}
	}
yy1:
	++YYCURSOR;
yy2:
#line 14 "encodings/unicode_group_Sm_x_encoding_policy_substitute.re"
	{ return YYCURSOR == limit; }
#line 183 "encodings/unicode_group_Sm_x_encoding_policy_substitute.c"
yy3:
	++YYCURSOR;
#line 13 "encodings/unicode_group_Sm_x_encoding_policy_substitute.re"
	{ goto Sm; }
#line 188 "encodings/unicode_group_Sm_x_encoding_policy_substitute.c"
yy4:
	yych = *++YYCURSOR;
	if (yych <= 0xDF35) {
		if (yych <= 0xDEFA) {
			if (yych <= 0xDEC1) {
				if (yych <= 0xDEC0) goto yy2;
				goto yy3;
			} else {
				if (yych == 0xDEDB) goto yy3;
				goto yy2;
			}
		} else {
			if (yych <= 0xDF14) {
				if (yych <= 0xDEFB) goto yy3;
				goto yy2;
			} else {
				if (yych <= 0xDF15) goto yy3;
				if (yych <= 0xDF34) goto yy2;
				goto yy3;
			}
		}
	} else {
		if (yych <= 0xDF88) {
			if (yych <= 0xDF4F) {
				if (yych <= 0xDF4E) goto yy2;
				goto yy3;
			} else {
				if (yych == 0xDF6F) goto yy3;
				goto yy2;
			}
		} else {
			if (yych <= 0xDFA9) {
				if (yych <= 0xDF89) goto yy3;
				if (yych <= 0xDFA8) goto yy2;
				goto yy3;
			} else {
				if (yych == 0xDFC3) goto yy3;
				goto yy2;
			}
		}
	}
yy5:
	yych = *++YYCURSOR;
	if (yych <= 0xDEEF) goto yy2;
	if (yych <= 0xDEF1) goto yy3;
	goto yy2;
}
#line 15 "encodings/unicode_group_Sm_x_encoding_policy_substitute.re"

}
static const unsigned int chars_Sm [] = {0x2b,0x2b,  0x3c,0x3e,  0x7c,0x7c,  0x7e,0x7e,  0xac,0xac,  0xb1,0xb1,  0xd7,0xd7,  0xf7,0xf7,  0x3f6,0x3f6,  0x606,0x608,  0x2044,0x2044,  0x2052,0x2052,  0x207a,0x207c,  0x208a,0x208c,  0x2118,0x2118,  0x2140,0x2144,  0x214b,0x214b,  0x2190,0x2194,  0x219a,0x219b,  0x21a0,0x21a0,  0x21a3,0x21a3,  0x21a6,0x21a6,  0x21ae,0x21ae,  0x21ce,0x21cf,  0x21d2,0x21d2,  0x21d4,0x21d4,  0x21f4,0x22ff,  0x2320,0x2321,  0x237c,0x237c,  0x239b,0x23b3,  0x23dc,0x23e1,  0x25b7,0x25b7,  0x25c1,0x25c1,  0x25f8,0x25ff,  0x266f,0x266f,  0x27c0,0x27c4,  0x27c7,0x27e5,  0x27f0,0x27ff,  0x2900,0x2982,  0x2999,0x29d7,  0x29dc,0x29fb,  0x29fe,0x2aff,  0x2b30,0x2b44,  0x2b47,0x2b4c,  0xfb29,0xfb29,  0xfe62,0xfe62,  0xfe64,0xfe66,  0xff0b,0xff0b,  0xff1c,0xff1e,  0xff5c,0xff5c,  0xff5e,0xff5e,  0xffe2,0xffe2,  0xffe9,0xffec,  0x1d6c1,0x1d6c1,  0x1d6db,0x1d6db,  0x1d6fb,0x1d6fb,  0x1d715,0x1d715,  0x1d735,0x1d735,  0x1d74f,0x1d74f,  0x1d76f,0x1d76f,  0x1d789,0x1d789,  0x1d7a9,0x1d7a9,  0x1d7c3,0x1d7c3,  0x1eef0,0x1eef1,  0x0,0x0};
static unsigned int encode_utf16 (const unsigned int * ranges, unsigned int ranges_count, unsigned int * s)
{
	unsigned int * const s_start = s;
	for (unsigned int i = 0; i < ranges_count; i += 2)
		for (unsigned int j = ranges[i]; j <= ranges[i + 1]; ++j)
		{
			if (j <= re2c::utf16::MAX_1WORD_RUNE)
				*s++ = j;
			else
			{
				*s++ = re2c::utf16::lead_surr(j);
				*s++ = re2c::utf16::trail_surr(j);
			}
		}
	return s - s_start;
}

int main ()
{
	unsigned int * buffer_Sm = new unsigned int [1898];
	YYCTYPE * s = (YYCTYPE *) buffer_Sm;
	unsigned int buffer_len = encode_utf16 (chars_Sm, sizeof (chars_Sm) / sizeof (unsigned int), buffer_Sm);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_Sm[i];
	if (!scan (s, s + buffer_len))
		printf("test 'Sm' failed\n");
	delete [] buffer_Sm;
	return 0;
}

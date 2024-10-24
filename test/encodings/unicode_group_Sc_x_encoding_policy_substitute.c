/* Generated by re2c */
#line 1 "encodings/unicode_group_Sc_x_encoding_policy_substitute.re"
// re2c $INPUT -o $OUTPUT -x --encoding-policy substitute
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Sc:
	
#line 14 "encodings/unicode_group_Sc_x_encoding_policy_substitute.c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x17DA) {
		if (yych <= 0x07FF) {
			if (yych <= 0x058E) {
				if (yych <= '$') {
					if (yych >= '$') goto yy3;
				} else {
					if (yych <= 0x00A1) goto yy1;
					if (yych <= 0x00A5) goto yy3;
				}
			} else {
				if (yych <= 0x060A) {
					if (yych <= 0x058F) goto yy3;
				} else {
					if (yych <= 0x060B) goto yy3;
					if (yych >= 0x07FE) goto yy3;
				}
			}
		} else {
			if (yych <= 0x0AF0) {
				if (yych <= 0x09F3) {
					if (yych >= 0x09F2) goto yy3;
				} else {
					if (yych == 0x09FB) goto yy3;
				}
			} else {
				if (yych <= 0x0BF9) {
					if (yych <= 0x0AF1) goto yy3;
					if (yych >= 0x0BF9) goto yy3;
				} else {
					if (yych == 0x0E3F) goto yy3;
				}
			}
		}
	} else {
		if (yych <= 0xD83B) {
			if (yych <= 0xA838) {
				if (yych <= 0x209F) {
					if (yych <= 0x17DB) goto yy3;
				} else {
					if (yych <= 0x20BF) goto yy3;
					if (yych >= 0xA838) goto yy3;
				}
			} else {
				if (yych <= 0xD837) {
					if (yych == 0xD807) goto yy4;
				} else {
					if (yych <= 0xD838) goto yy5;
					if (yych >= 0xD83B) goto yy6;
				}
			}
		} else {
			if (yych <= 0xFF03) {
				if (yych <= 0xFDFC) {
					if (yych >= 0xFDFC) goto yy3;
				} else {
					if (yych == 0xFE69) goto yy3;
				}
			} else {
				if (yych <= 0xFFE1) {
					if (yych <= 0xFF04) goto yy3;
					if (yych >= 0xFFE0) goto yy3;
				} else {
					if (yych <= 0xFFE4) goto yy1;
					if (yych <= 0xFFE6) goto yy3;
				}
			}
		}
	}
yy1:
	++YYCURSOR;
yy2:
#line 14 "encodings/unicode_group_Sc_x_encoding_policy_substitute.re"
	{ return YYCURSOR == limit; }
#line 91 "encodings/unicode_group_Sc_x_encoding_policy_substitute.c"
yy3:
	++YYCURSOR;
#line 13 "encodings/unicode_group_Sc_x_encoding_policy_substitute.re"
	{ goto Sc; }
#line 96 "encodings/unicode_group_Sc_x_encoding_policy_substitute.c"
yy4:
	yych = *++YYCURSOR;
	if (yych <= 0xDFDC) goto yy2;
	if (yych <= 0xDFE0) goto yy3;
	goto yy2;
yy5:
	yych = *++YYCURSOR;
	if (yych == 0xDEFF) goto yy3;
	goto yy2;
yy6:
	yych = *++YYCURSOR;
	if (yych == 0xDCB0) goto yy3;
	goto yy2;
}
#line 15 "encodings/unicode_group_Sc_x_encoding_policy_substitute.re"

}
static const unsigned int chars_Sc [] = {0x24,0x24,  0xa2,0xa5,  0x58f,0x58f,  0x60b,0x60b,  0x7fe,0x7ff,  0x9f2,0x9f3,  0x9fb,0x9fb,  0xaf1,0xaf1,  0xbf9,0xbf9,  0xe3f,0xe3f,  0x17db,0x17db,  0x20a0,0x20bf,  0xa838,0xa838,  0xfdfc,0xfdfc,  0xfe69,0xfe69,  0xff04,0xff04,  0xffe0,0xffe1,  0xffe5,0xffe6,  0x11fdd,0x11fe0,  0x1e2ff,0x1e2ff,  0x1ecb0,0x1ecb0,  0x0,0x0};
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
	unsigned int * buffer_Sc = new unsigned int [126];
	YYCTYPE * s = (YYCTYPE *) buffer_Sc;
	unsigned int buffer_len = encode_utf16 (chars_Sc, sizeof (chars_Sc) / sizeof (unsigned int), buffer_Sc);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_Sc[i];
	if (!scan (s, s + buffer_len))
		printf("test 'Sc' failed\n");
	delete [] buffer_Sc;
	return 0;
}
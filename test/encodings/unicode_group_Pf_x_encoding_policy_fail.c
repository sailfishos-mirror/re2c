/* Generated by re2c */
#line 1 "encodings/unicode_group_Pf_x_encoding_policy_fail.re"
// re2c $INPUT -o $OUTPUT -x --encoding-policy fail
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Pf:
	
#line 14 "encodings/unicode_group_Pf_x_encoding_policy_fail.c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x2E03) {
		if (yych <= 0x201C) {
			if (yych <= 0x00BB) {
				if (yych >= 0x00BB) goto yy1;
			} else {
				if (yych == 0x2019) goto yy1;
			}
		} else {
			if (yych <= 0x2039) {
				if (yych <= 0x201D) goto yy1;
			} else {
				if (yych <= 0x203A) goto yy1;
				if (yych >= 0x2E03) goto yy1;
			}
		}
	} else {
		if (yych <= 0x2E0C) {
			if (yych <= 0x2E05) {
				if (yych >= 0x2E05) goto yy1;
			} else {
				if (yych == 0x2E0A) goto yy1;
			}
		} else {
			if (yych <= 0x2E1D) {
				if (yych <= 0x2E0D) goto yy1;
				if (yych >= 0x2E1D) goto yy1;
			} else {
				if (yych == 0x2E21) goto yy1;
			}
		}
	}
	++YYCURSOR;
#line 14 "encodings/unicode_group_Pf_x_encoding_policy_fail.re"
	{ return YYCURSOR == limit; }
#line 52 "encodings/unicode_group_Pf_x_encoding_policy_fail.c"
yy1:
	++YYCURSOR;
#line 13 "encodings/unicode_group_Pf_x_encoding_policy_fail.re"
	{ goto Pf; }
#line 57 "encodings/unicode_group_Pf_x_encoding_policy_fail.c"
}
#line 15 "encodings/unicode_group_Pf_x_encoding_policy_fail.re"

}
static const unsigned int chars_Pf [] = {0xbb,0xbb,  0x2019,0x2019,  0x201d,0x201d,  0x203a,0x203a,  0x2e03,0x2e03,  0x2e05,0x2e05,  0x2e0a,0x2e0a,  0x2e0d,0x2e0d,  0x2e1d,0x2e1d,  0x2e21,0x2e21,  0x0,0x0};
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
	unsigned int * buffer_Pf = new unsigned int [22];
	YYCTYPE * s = (YYCTYPE *) buffer_Pf;
	unsigned int buffer_len = encode_utf16 (chars_Pf, sizeof (chars_Pf) / sizeof (unsigned int), buffer_Pf);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_Pf[i];
	if (!scan (s, s + buffer_len))
		printf("test 'Pf' failed\n");
	delete [] buffer_Pf;
	return 0;
}

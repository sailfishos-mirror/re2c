/* Generated by re2c */
#line 1 "encodings/unicode_group_Zp_x_encoding_policy_substitute.re"
// re2c $INPUT -o $OUTPUT -x --encoding-policy substitute
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
Zp:
	
#line 14 "encodings/unicode_group_Zp_x_encoding_policy_substitute.c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych == 0x2029) goto yy1;
	++YYCURSOR;
#line 14 "encodings/unicode_group_Zp_x_encoding_policy_substitute.re"
	{ return YYCURSOR == limit; }
#line 22 "encodings/unicode_group_Zp_x_encoding_policy_substitute.c"
yy1:
	++YYCURSOR;
#line 13 "encodings/unicode_group_Zp_x_encoding_policy_substitute.re"
	{ goto Zp; }
#line 27 "encodings/unicode_group_Zp_x_encoding_policy_substitute.c"
}
#line 15 "encodings/unicode_group_Zp_x_encoding_policy_substitute.re"

}
static const unsigned int chars_Zp [] = {0x2029,0x2029,  0x0,0x0};
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
	unsigned int * buffer_Zp = new unsigned int [4];
	YYCTYPE * s = (YYCTYPE *) buffer_Zp;
	unsigned int buffer_len = encode_utf16 (chars_Zp, sizeof (chars_Zp) / sizeof (unsigned int), buffer_Zp);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_Zp[i];
	if (!scan (s, s + buffer_len))
		printf("test 'Zp' failed\n");
	delete [] buffer_Zp;
	return 0;
}

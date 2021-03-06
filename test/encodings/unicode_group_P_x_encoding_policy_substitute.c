/* Generated by re2c */
#line 1 "encodings/unicode_group_P_x_encoding_policy_substitute.re"
// re2c $INPUT -o $OUTPUT -x --encoding-policy substitute
#include <stdio.h>
#include "utf16.h"
#define YYCTYPE unsigned short
bool scan(const YYCTYPE * start, const YYCTYPE * const limit)
{
	__attribute__((unused)) const YYCTYPE * YYMARKER; // silence compiler warnings when YYMARKER is not used
#	define YYCURSOR start
P:
	
#line 14 "encodings/unicode_group_P_x_encoding_policy_substitute.c"
{
	YYCTYPE yych;
	yych = *YYCURSOR;
	if (yych <= 0x1CD2) {
		if (yych <= 0x083E) {
			if (yych <= 0x0386) {
				if (yych <= '{') {
					if (yych <= ';') {
						if (yych <= '*') {
							if (yych <= ' ') goto yy1;
							if (yych != '$') goto yy3;
						} else {
							if (yych <= '+') goto yy1;
							if (yych <= '/') goto yy3;
							if (yych >= ':') goto yy3;
						}
					} else {
						if (yych <= ']') {
							if (yych <= '>') goto yy1;
							if (yych <= '@') goto yy3;
							if (yych >= '[') goto yy3;
						} else {
							if (yych == '_') goto yy3;
							if (yych >= '{') goto yy3;
						}
					}
				} else {
					if (yych <= 0x00AB) {
						if (yych <= 0x00A1) {
							if (yych == '}') goto yy3;
							if (yych >= 0x00A1) goto yy3;
						} else {
							if (yych == 0x00A7) goto yy3;
							if (yych >= 0x00AB) goto yy3;
						}
					} else {
						if (yych <= 0x00BB) {
							if (yych <= 0x00B5) goto yy1;
							if (yych <= 0x00B7) goto yy3;
							if (yych >= 0x00BB) goto yy3;
						} else {
							if (yych <= 0x00BF) {
								if (yych >= 0x00BF) goto yy3;
							} else {
								if (yych == 0x037E) goto yy3;
							}
						}
					}
				}
			} else {
				if (yych <= 0x0608) {
					if (yych <= 0x05BF) {
						if (yych <= 0x0588) {
							if (yych <= 0x0387) goto yy3;
							if (yych <= 0x0559) goto yy1;
							if (yych <= 0x055F) goto yy3;
						} else {
							if (yych <= 0x058A) goto yy3;
							if (yych == 0x05BE) goto yy3;
						}
					} else {
						if (yych <= 0x05C5) {
							if (yych <= 0x05C0) goto yy3;
							if (yych == 0x05C3) goto yy3;
						} else {
							if (yych <= 0x05C6) goto yy3;
							if (yych <= 0x05F2) goto yy1;
							if (yych <= 0x05F4) goto yy3;
						}
					}
				} else {
					if (yych <= 0x0669) {
						if (yych <= 0x061A) {
							if (yych == 0x060B) goto yy1;
							if (yych <= 0x060D) goto yy3;
						} else {
							if (yych <= 0x061B) goto yy3;
							if (yych <= 0x061D) goto yy1;
							if (yych <= 0x061F) goto yy3;
						}
					} else {
						if (yych <= 0x06FF) {
							if (yych <= 0x066D) goto yy3;
							if (yych == 0x06D4) goto yy3;
						} else {
							if (yych <= 0x07F6) {
								if (yych <= 0x070D) goto yy3;
							} else {
								if (yych <= 0x07F9) goto yy3;
								if (yych >= 0x0830) goto yy3;
							}
						}
					}
				}
			}
		} else {
			if (yych <= 0x13FF) {
				if (yych <= 0x0F12) {
					if (yych <= 0x0AF0) {
						if (yych <= 0x0965) {
							if (yych == 0x085E) goto yy3;
							if (yych >= 0x0964) goto yy3;
						} else {
							if (yych == 0x0970) goto yy3;
							if (yych >= 0x0AF0) goto yy3;
						}
					} else {
						if (yych <= 0x0E4F) {
							if (yych == 0x0DF4) goto yy3;
							if (yych >= 0x0E4F) goto yy3;
						} else {
							if (yych <= 0x0E59) goto yy1;
							if (yych <= 0x0E5B) goto yy3;
							if (yych >= 0x0F04) goto yy3;
						}
					}
				} else {
					if (yych <= 0x0FD4) {
						if (yych <= 0x0F3D) {
							if (yych == 0x0F14) goto yy3;
							if (yych >= 0x0F3A) goto yy3;
						} else {
							if (yych == 0x0F85) goto yy3;
							if (yych >= 0x0FD0) goto yy3;
						}
					} else {
						if (yych <= 0x104F) {
							if (yych <= 0x0FD8) goto yy1;
							if (yych <= 0x0FDA) goto yy3;
							if (yych >= 0x104A) goto yy3;
						} else {
							if (yych <= 0x10FB) {
								if (yych >= 0x10FB) goto yy3;
							} else {
								if (yych <= 0x135F) goto yy1;
								if (yych <= 0x1368) goto yy3;
							}
						}
					}
				}
			} else {
				if (yych <= 0x1945) {
					if (yych <= 0x1734) {
						if (yych <= 0x169A) {
							if (yych <= 0x1400) goto yy3;
							if (yych <= 0x166C) goto yy1;
							if (yych <= 0x166E) goto yy3;
						} else {
							if (yych <= 0x169C) goto yy3;
							if (yych <= 0x16EA) goto yy1;
							if (yych <= 0x16ED) goto yy3;
						}
					} else {
						if (yych <= 0x17D7) {
							if (yych <= 0x1736) goto yy3;
							if (yych <= 0x17D3) goto yy1;
							if (yych <= 0x17D6) goto yy3;
						} else {
							if (yych <= 0x17FF) {
								if (yych <= 0x17DA) goto yy3;
							} else {
								if (yych <= 0x180A) goto yy3;
								if (yych >= 0x1944) goto yy3;
							}
						}
					}
				} else {
					if (yych <= 0x1B60) {
						if (yych <= 0x1AA6) {
							if (yych <= 0x1A1D) goto yy1;
							if (yych <= 0x1A1F) goto yy3;
							if (yych >= 0x1AA0) goto yy3;
						} else {
							if (yych <= 0x1AA7) goto yy1;
							if (yych <= 0x1AAD) goto yy3;
							if (yych >= 0x1B5A) goto yy3;
						}
					} else {
						if (yych <= 0x1C3F) {
							if (yych <= 0x1BFB) goto yy1;
							if (yych <= 0x1BFF) goto yy3;
							if (yych >= 0x1C3B) goto yy3;
						} else {
							if (yych <= 0x1C7F) {
								if (yych >= 0x1C7E) goto yy3;
							} else {
								if (yych <= 0x1CBF) goto yy1;
								if (yych <= 0x1CC7) goto yy3;
							}
						}
					}
				}
			}
		}
	} else {
		if (yych <= 0xA8CD) {
			if (yych <= 0x2CFF) {
				if (yych <= 0x2328) {
					if (yych <= 0x2052) {
						if (yych <= 0x202F) {
							if (yych <= 0x1CD3) goto yy3;
							if (yych <= 0x200F) goto yy1;
							if (yych <= 0x2027) goto yy3;
						} else {
							if (yych == 0x2044) goto yy1;
							if (yych <= 0x2051) goto yy3;
						}
					} else {
						if (yych <= 0x208C) {
							if (yych <= 0x205E) goto yy3;
							if (yych <= 0x207C) goto yy1;
							if (yych <= 0x207E) goto yy3;
						} else {
							if (yych <= 0x208E) goto yy3;
							if (yych <= 0x2307) goto yy1;
							if (yych <= 0x230B) goto yy3;
						}
					}
				} else {
					if (yych <= 0x2982) {
						if (yych <= 0x27C4) {
							if (yych <= 0x232A) goto yy3;
							if (yych <= 0x2767) goto yy1;
							if (yych <= 0x2775) goto yy3;
						} else {
							if (yych <= 0x27C6) goto yy3;
							if (yych <= 0x27E5) goto yy1;
							if (yych <= 0x27EF) goto yy3;
						}
					} else {
						if (yych <= 0x29FB) {
							if (yych <= 0x2998) goto yy3;
							if (yych <= 0x29D7) goto yy1;
							if (yych <= 0x29DB) goto yy3;
						} else {
							if (yych <= 0x2CF8) {
								if (yych <= 0x29FD) goto yy3;
							} else {
								if (yych != 0x2CFD) goto yy3;
							}
						}
					}
				}
			} else {
				if (yych <= 0x303D) {
					if (yych <= 0x3003) {
						if (yych <= 0x2E2E) {
							if (yych == 0x2D70) goto yy3;
							if (yych >= 0x2E00) goto yy3;
						} else {
							if (yych <= 0x2E2F) goto yy1;
							if (yych <= 0x2E42) goto yy3;
							if (yych >= 0x3001) goto yy3;
						}
					} else {
						if (yych <= 0x301F) {
							if (yych <= 0x3007) goto yy1;
							if (yych <= 0x3011) goto yy3;
							if (yych >= 0x3014) goto yy3;
						} else {
							if (yych == 0x3030) goto yy3;
							if (yych >= 0x303D) goto yy3;
						}
					}
				} else {
					if (yych <= 0xA60F) {
						if (yych <= 0x30FB) {
							if (yych == 0x30A0) goto yy3;
							if (yych >= 0x30FB) goto yy3;
						} else {
							if (yych <= 0xA4FD) goto yy1;
							if (yych <= 0xA4FF) goto yy3;
							if (yych >= 0xA60D) goto yy3;
						}
					} else {
						if (yych <= 0xA67E) {
							if (yych == 0xA673) goto yy3;
							if (yych >= 0xA67E) goto yy3;
						} else {
							if (yych <= 0xA6F7) {
								if (yych >= 0xA6F2) goto yy3;
							} else {
								if (yych <= 0xA873) goto yy1;
								if (yych <= 0xA877) goto yy3;
							}
						}
					}
				}
			}
		} else {
			if (yych <= 0xFD3D) {
				if (yych <= 0xAAEF) {
					if (yych <= 0xA9C0) {
						if (yych <= 0xA92D) {
							if (yych <= 0xA8CF) goto yy3;
							if (yych <= 0xA8F7) goto yy1;
							if (yych <= 0xA8FA) goto yy3;
						} else {
							if (yych <= 0xA92F) goto yy3;
							if (yych == 0xA95F) goto yy3;
						}
					} else {
						if (yych <= 0xAA5B) {
							if (yych <= 0xA9CD) goto yy3;
							if (yych <= 0xA9DD) goto yy1;
							if (yych <= 0xA9DF) goto yy3;
						} else {
							if (yych <= 0xAA5F) goto yy3;
							if (yych <= 0xAADD) goto yy1;
							if (yych <= 0xAADF) goto yy3;
						}
					}
				} else {
					if (yych <= 0xD803) {
						if (yych <= 0xD7FF) {
							if (yych <= 0xAAF1) goto yy3;
							if (yych == 0xABEB) goto yy3;
						} else {
							if (yych <= 0xD800) goto yy4;
							if (yych <= 0xD801) goto yy5;
							if (yych <= 0xD802) goto yy6;
						}
					} else {
						if (yych <= 0xD809) {
							if (yych <= 0xD804) goto yy7;
							if (yych <= 0xD805) goto yy8;
							if (yych >= 0xD809) goto yy9;
						} else {
							if (yych <= 0xD81A) {
								if (yych >= 0xD81A) goto yy10;
							} else {
								if (yych == 0xD82F) goto yy11;
							}
						}
					}
				}
			} else {
				if (yych <= 0xFF0A) {
					if (yych <= 0xFE62) {
						if (yych <= 0xFE2F) {
							if (yych <= 0xFD3F) goto yy3;
							if (yych <= 0xFE0F) goto yy1;
							if (yych <= 0xFE19) goto yy3;
						} else {
							if (yych == 0xFE53) goto yy1;
							if (yych <= 0xFE61) goto yy3;
						}
					} else {
						if (yych <= 0xFE69) {
							if (yych <= 0xFE63) goto yy3;
							if (yych == 0xFE68) goto yy3;
						} else {
							if (yych <= 0xFF00) {
								if (yych <= 0xFE6B) goto yy3;
							} else {
								if (yych != 0xFF04) goto yy3;
							}
						}
					}
				} else {
					if (yych <= 0xFF3D) {
						if (yych <= 0xFF1B) {
							if (yych <= 0xFF0B) goto yy1;
							if (yych <= 0xFF0F) goto yy3;
							if (yych >= 0xFF1A) goto yy3;
						} else {
							if (yych <= 0xFF1E) goto yy1;
							if (yych <= 0xFF20) goto yy3;
							if (yych >= 0xFF3B) goto yy3;
						}
					} else {
						if (yych <= 0xFF5B) {
							if (yych == 0xFF3F) goto yy3;
							if (yych >= 0xFF5B) goto yy3;
						} else {
							if (yych <= 0xFF5D) {
								if (yych >= 0xFF5D) goto yy3;
							} else {
								if (yych <= 0xFF5E) goto yy1;
								if (yych <= 0xFF65) goto yy3;
							}
						}
					}
				}
			}
		}
	}
yy1:
	++YYCURSOR;
yy2:
#line 14 "encodings/unicode_group_P_x_encoding_policy_substitute.re"
	{ return YYCURSOR == limit; }
#line 407 "encodings/unicode_group_P_x_encoding_policy_substitute.c"
yy3:
	++YYCURSOR;
#line 13 "encodings/unicode_group_P_x_encoding_policy_substitute.re"
	{ goto P; }
#line 412 "encodings/unicode_group_P_x_encoding_policy_substitute.c"
yy4:
	yych = *++YYCURSOR;
	if (yych <= 0xDF9E) {
		if (yych <= 0xDCFF) goto yy2;
		if (yych <= 0xDD02) goto yy3;
		goto yy2;
	} else {
		if (yych <= 0xDF9F) goto yy3;
		if (yych == 0xDFD0) goto yy3;
		goto yy2;
	}
yy5:
	yych = *++YYCURSOR;
	if (yych == 0xDD6F) goto yy3;
	goto yy2;
yy6:
	yych = *++YYCURSOR;
	if (yych <= 0xDE58) {
		if (yych <= 0xDD1F) {
			if (yych == 0xDC57) goto yy3;
			if (yych <= 0xDD1E) goto yy2;
			goto yy3;
		} else {
			if (yych == 0xDD3F) goto yy3;
			if (yych <= 0xDE4F) goto yy2;
			goto yy3;
		}
	} else {
		if (yych <= 0xDEF6) {
			if (yych == 0xDE7F) goto yy3;
			if (yych <= 0xDEEF) goto yy2;
			goto yy3;
		} else {
			if (yych <= 0xDF3F) {
				if (yych <= 0xDF38) goto yy2;
				goto yy3;
			} else {
				if (yych <= 0xDF98) goto yy2;
				if (yych <= 0xDF9C) goto yy3;
				goto yy2;
			}
		}
	}
yy7:
	yych = *++YYCURSOR;
	if (yych <= 0xDD43) {
		if (yych <= 0xDCBC) {
			if (yych <= 0xDC46) goto yy2;
			if (yych <= 0xDC4D) goto yy3;
			if (yych <= 0xDCBA) goto yy2;
			goto yy3;
		} else {
			if (yych <= 0xDCBD) goto yy2;
			if (yych <= 0xDCC1) goto yy3;
			if (yych <= 0xDD3F) goto yy2;
			goto yy3;
		}
	} else {
		if (yych <= 0xDDC8) {
			if (yych <= 0xDD73) goto yy2;
			if (yych <= 0xDD75) goto yy3;
			if (yych <= 0xDDC4) goto yy2;
			goto yy3;
		} else {
			if (yych <= 0xDDCD) {
				if (yych <= 0xDDCC) goto yy2;
				goto yy3;
			} else {
				if (yych <= 0xDE37) goto yy2;
				if (yych <= 0xDE3D) goto yy3;
				goto yy2;
			}
		}
	}
yy8:
	yych = *++YYCURSOR;
	if (yych <= 0xDDC0) {
		if (yych == 0xDCC6) goto yy3;
		goto yy2;
	} else {
		if (yych <= 0xDDC9) goto yy3;
		if (yych <= 0xDE40) goto yy2;
		if (yych <= 0xDE43) goto yy3;
		goto yy2;
	}
yy9:
	yych = *++YYCURSOR;
	if (yych <= 0xDC6F) goto yy2;
	if (yych <= 0xDC74) goto yy3;
	goto yy2;
yy10:
	yych = *++YYCURSOR;
	if (yych <= 0xDEF5) {
		if (yych <= 0xDE6D) goto yy2;
		if (yych <= 0xDE6F) goto yy3;
		if (yych <= 0xDEF4) goto yy2;
		goto yy3;
	} else {
		if (yych <= 0xDF3B) {
			if (yych <= 0xDF36) goto yy2;
			goto yy3;
		} else {
			if (yych == 0xDF44) goto yy3;
			goto yy2;
		}
	}
yy11:
	yych = *++YYCURSOR;
	if (yych == 0xDC9F) goto yy3;
	goto yy2;
}
#line 15 "encodings/unicode_group_P_x_encoding_policy_substitute.re"

}
static const unsigned int chars_P [] = {0x21,0x23,  0x25,0x2a,  0x2c,0x2f,  0x3a,0x3b,  0x3f,0x40,  0x5b,0x5d,  0x5f,0x5f,  0x7b,0x7b,  0x7d,0x7d,  0xa1,0xa1,  0xa7,0xa7,  0xab,0xab,  0xb6,0xb7,  0xbb,0xbb,  0xbf,0xbf,  0x37e,0x37e,  0x387,0x387,  0x55a,0x55f,  0x589,0x58a,  0x5be,0x5be,  0x5c0,0x5c0,  0x5c3,0x5c3,  0x5c6,0x5c6,  0x5f3,0x5f4,  0x609,0x60a,  0x60c,0x60d,  0x61b,0x61b,  0x61e,0x61f,  0x66a,0x66d,  0x6d4,0x6d4,  0x700,0x70d,  0x7f7,0x7f9,  0x830,0x83e,  0x85e,0x85e,  0x964,0x965,  0x970,0x970,  0xaf0,0xaf0,  0xdf4,0xdf4,  0xe4f,0xe4f,  0xe5a,0xe5b,  0xf04,0xf12,  0xf14,0xf14,  0xf3a,0xf3d,  0xf85,0xf85,  0xfd0,0xfd4,  0xfd9,0xfda,  0x104a,0x104f,  0x10fb,0x10fb,  0x1360,0x1368,  0x1400,0x1400,  0x166d,0x166e,  0x169b,0x169c,  0x16eb,0x16ed,  0x1735,0x1736,  0x17d4,0x17d6,  0x17d8,0x17da,  0x1800,0x180a,  0x1944,0x1945,  0x1a1e,0x1a1f,  0x1aa0,0x1aa6,  0x1aa8,0x1aad,  0x1b5a,0x1b60,  0x1bfc,0x1bff,  0x1c3b,0x1c3f,  0x1c7e,0x1c7f,  0x1cc0,0x1cc7,  0x1cd3,0x1cd3,  0x2010,0x2027,  0x2030,0x2043,  0x2045,0x2051,  0x2053,0x205e,  0x207d,0x207e,  0x208d,0x208e,  0x2308,0x230b,  0x2329,0x232a,  0x2768,0x2775,  0x27c5,0x27c6,  0x27e6,0x27ef,  0x2983,0x2998,  0x29d8,0x29db,  0x29fc,0x29fd,  0x2cf9,0x2cfc,  0x2cfe,0x2cff,  0x2d70,0x2d70,  0x2e00,0x2e2e,  0x2e30,0x2e42,  0x3001,0x3003,  0x3008,0x3011,  0x3014,0x301f,  0x3030,0x3030,  0x303d,0x303d,  0x30a0,0x30a0,  0x30fb,0x30fb,  0xa4fe,0xa4ff,  0xa60d,0xa60f,  0xa673,0xa673,  0xa67e,0xa67e,  0xa6f2,0xa6f7,  0xa874,0xa877,  0xa8ce,0xa8cf,  0xa8f8,0xa8fa,  0xa92e,0xa92f,  0xa95f,0xa95f,  0xa9c1,0xa9cd,  0xa9de,0xa9df,  0xaa5c,0xaa5f,  0xaade,0xaadf,  0xaaf0,0xaaf1,  0xabeb,0xabeb,  0xfd3e,0xfd3f,  0xfe10,0xfe19,  0xfe30,0xfe52,  0xfe54,0xfe61,  0xfe63,0xfe63,  0xfe68,0xfe68,  0xfe6a,0xfe6b,  0xff01,0xff03,  0xff05,0xff0a,  0xff0c,0xff0f,  0xff1a,0xff1b,  0xff1f,0xff20,  0xff3b,0xff3d,  0xff3f,0xff3f,  0xff5b,0xff5b,  0xff5d,0xff5d,  0xff5f,0xff65,  0x10100,0x10102,  0x1039f,0x1039f,  0x103d0,0x103d0,  0x1056f,0x1056f,  0x10857,0x10857,  0x1091f,0x1091f,  0x1093f,0x1093f,  0x10a50,0x10a58,  0x10a7f,0x10a7f,  0x10af0,0x10af6,  0x10b39,0x10b3f,  0x10b99,0x10b9c,  0x11047,0x1104d,  0x110bb,0x110bc,  0x110be,0x110c1,  0x11140,0x11143,  0x11174,0x11175,  0x111c5,0x111c8,  0x111cd,0x111cd,  0x11238,0x1123d,  0x114c6,0x114c6,  0x115c1,0x115c9,  0x11641,0x11643,  0x12470,0x12474,  0x16a6e,0x16a6f,  0x16af5,0x16af5,  0x16b37,0x16b3b,  0x16b44,0x16b44,  0x1bc9f,0x1bc9f,  0x0,0x0};
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
	unsigned int * buffer_P = new unsigned int [1378];
	YYCTYPE * s = (YYCTYPE *) buffer_P;
	unsigned int buffer_len = encode_utf16 (chars_P, sizeof (chars_P) / sizeof (unsigned int), buffer_P);
	/* convert 32-bit code units to YYCTYPE; reuse the same buffer */
	for (unsigned int i = 0; i < buffer_len; ++i) s[i] = buffer_P[i];
	if (!scan (s, s + buffer_len))
		printf("test 'P' failed\n");
	delete [] buffer_P;
	return 0;
}

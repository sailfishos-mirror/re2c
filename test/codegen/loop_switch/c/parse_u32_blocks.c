/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -i --loop-switch
#include <stdint.h>
#include <limits.h>
#include <assert.h>

static const uint64_t ERROR = ~0lu;
enum YYCONDTYPE {
};


template<int BASE> static void adddgt(uint64_t &u, unsigned int d)
{
    u = u * BASE + d;
    if (u > UINT32_MAX) u = ERROR;
}

static uint64_t parse_u32(const char *s)
{
    const char *YYMARKER;
    uint64_t u = 0;

    
{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
		case 0:
			yych = *s;
			++s;
			switch (yych) {
			case '0':
				yystate = 3;
				continue;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				yystate = 5;
				continue;
			default:
				yystate = 1;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			{ return ERROR; }
		case 3:
			YYMARKER = s;
			yych = *s;
			switch (yych) {
			case 'B':
			case 'b':
				++s;
				yystate = 7;
				continue;
			case 'X':
			case 'x':
				++s;
				yystate = 9;
				continue;
			default:
				yystate = 4;
				continue;
			}
		case 4:
			{ goto oct; }
		case 5:
			yystate = 6;
			continue;
		case 6:
			s -= 1;
			{ goto dec; }
		case 7:
			yych = *s;
			switch (yych) {
			case '0':
			case '1':
				++s;
				yystate = 10;
				continue;
			default:
				yystate = 8;
				continue;
			}
		case 8:
			s = YYMARKER;
			yystate = 4;
			continue;
		case 9:
			yych = *s;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				++s;
				yystate = 12;
				continue;
			default:
				yystate = 8;
				continue;
			}
		case 10:
			yystate = 11;
			continue;
		case 11:
			s -= 1;
			{ goto bin; }
		case 12:
			yystate = 13;
			continue;
		case 13:
			s -= 1;
			{ goto hex; }
		}
	}
}

bin:
    
{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
		case 0:
			yych = *s;
			++s;
			switch (yych) {
			case 0x00:
				yystate = 1;
				continue;
			case '0':
			case '1':
				yystate = 5;
				continue;
			default:
				yystate = 3;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			{ return u; }
		case 3:
			yystate = 4;
			continue;
		case 4:
			{ return ERROR; }
		case 5:
			yystate = 6;
			continue;
		case 6:
			{ adddgt<2>(u, s[-1] - '0'); goto bin; }
		}
	}
}

oct:
    
{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
		case 0:
			yych = *s;
			++s;
			switch (yych) {
			case 0x00:
				yystate = 1;
				continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
				yystate = 5;
				continue;
			default:
				yystate = 3;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			{ return u; }
		case 3:
			yystate = 4;
			continue;
		case 4:
			{ return ERROR; }
		case 5:
			yystate = 6;
			continue;
		case 6:
			{ adddgt<8>(u, s[-1] - '0'); goto oct; }
		}
	}
}

dec:
    
{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
		case 0:
			yych = *s;
			++s;
			switch (yych) {
			case 0x00:
				yystate = 1;
				continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				yystate = 5;
				continue;
			default:
				yystate = 3;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			{ return u; }
		case 3:
			yystate = 4;
			continue;
		case 4:
			{ return ERROR; }
		case 5:
			yystate = 6;
			continue;
		case 6:
			{ adddgt<10>(u, s[-1] - '0'); goto dec; }
		}
	}
}

hex:
    
{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
		case 0:
			yych = *s;
			++s;
			switch (yych) {
			case 0x00:
				yystate = 1;
				continue;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				yystate = 5;
				continue;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
				yystate = 7;
				continue;
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				yystate = 9;
				continue;
			default:
				yystate = 3;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			{ return u; }
		case 3:
			yystate = 4;
			continue;
		case 4:
			{ return ERROR; }
		case 5:
			yystate = 6;
			continue;
		case 6:
			{ adddgt<16>(u, s[-1] - '0');      goto hex; }
		case 7:
			yystate = 8;
			continue;
		case 8:
			{ adddgt<16>(u, s[-1] - 'A' + 10); goto hex; }
		case 9:
			yystate = 10;
			continue;
		case 10:
			{ adddgt<16>(u, s[-1] - 'a' + 10); goto hex; }
		}
	}
}

}

int main()
{
    assert(parse_u32("1234567890") == 1234567890);
    assert(parse_u32("0b1101") == 13);
    assert(parse_u32("0x7Fe") == 2046);
    assert(parse_u32("0644") == 420);
    assert(parse_u32("9999999999") == ERROR);
    assert(parse_u32("") == ERROR);
    return 0;
}

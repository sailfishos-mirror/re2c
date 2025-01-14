#line 1 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
#include "ragel/common.c"

const char *delim = "\n";


#line 21 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"



#line 9 "gen/ragel/submatch_34__rep_alt_13_11_7.c"
static const int aaa_start = 14;
static const int aaa_first_final = 14;
static const int aaa_error = 0;

static const int aaa_en_main = 14;


#line 23 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"


static void lex(Input *in, Output *out)
{
	char *p = in->p;
	char *pe = in->pe;
	const char *s;
	int cs;
	

#line 25 "gen/ragel/submatch_34__rep_alt_13_11_7.c"
	{
		cs = (int)aaa_start;
	}
	
#line 32 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"


#line 30 "gen/ragel/submatch_34__rep_alt_13_11_7.c"
{
		switch ( cs ) {
			case 14:
			goto st_case_14;
			case 0:
			goto st_case_0;
			case 1:
			goto st_case_1;
			case 2:
			goto st_case_2;
			case 3:
			goto st_case_3;
			case 4:
			goto st_case_4;
			case 5:
			goto st_case_5;
			case 6:
			goto st_case_6;
			case 7:
			goto st_case_7;
			case 8:
			goto st_case_8;
			case 9:
			goto st_case_9;
			case 10:
			goto st_case_10;
			case 11:
			goto st_case_11;
			case 12:
			goto st_case_12;
			case 13:
			goto st_case_13;
		}
		_ctr8:
			{
#line 13 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
			
			outs(out, s, p);
			outc(out, '.');
			s = p;
		}
		
#line 72 "gen/ragel/submatch_34__rep_alt_13_11_7.c"

			{
#line 18 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
			outc(out, '\n'); }
		
#line 77 "gen/ragel/submatch_34__rep_alt_13_11_7.c"

		goto _st14;
		_ctr17:
			{
#line 17 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
			s = p; }
		
#line 84 "gen/ragel/submatch_34__rep_alt_13_11_7.c"

			{
#line 18 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
			outc(out, '\n'); }
		
#line 89 "gen/ragel/submatch_34__rep_alt_13_11_7.c"

		goto _st14;
		_st14:
		p+= 1;
		st_case_14:
		if ( p == pe )
			goto _out14;
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr17;
			}
			case 97: {
				goto _ctr18;
			}
		}
		goto _st0;
		_st0:
		st_case_0:
		goto _out0;
		_ctr15:
			{
#line 13 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
			
			outs(out, s, p);
			outc(out, '.');
			s = p;
		}
		
#line 117 "gen/ragel/submatch_34__rep_alt_13_11_7.c"

		goto _st1;
		_ctr18:
			{
#line 17 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"
			s = p; }
		
#line 124 "gen/ragel/submatch_34__rep_alt_13_11_7.c"

		goto _st1;
		_st1:
		p+= 1;
		st_case_1:
		if ( p == pe )
			goto _out1;
		if ( ( (*( p))) == 97 ) {
			goto _st2;
		}
		goto _st0;
		_st2:
		p+= 1;
		st_case_2:
		if ( p == pe )
			goto _out2;
		if ( ( (*( p))) == 97 ) {
			goto _st3;
		}
		goto _st0;
		_st3:
		p+= 1;
		st_case_3:
		if ( p == pe )
			goto _out3;
		if ( ( (*( p))) == 97 ) {
			goto _st4;
		}
		goto _st0;
		_st4:
		p+= 1;
		st_case_4:
		if ( p == pe )
			goto _out4;
		if ( ( (*( p))) == 97 ) {
			goto _st5;
		}
		goto _st0;
		_st5:
		p+= 1;
		st_case_5:
		if ( p == pe )
			goto _out5;
		if ( ( (*( p))) == 97 ) {
			goto _st6;
		}
		goto _st0;
		_st6:
		p+= 1;
		st_case_6:
		if ( p == pe )
			goto _out6;
		if ( ( (*( p))) == 97 ) {
			goto _st7;
		}
		goto _st0;
		_st7:
		p+= 1;
		st_case_7:
		if ( p == pe )
			goto _out7;
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr8;
			}
			case 97: {
				goto _st8;
			}
		}
		goto _st0;
		_st8:
		p+= 1;
		st_case_8:
		if ( p == pe )
			goto _out8;
		if ( ( (*( p))) == 97 ) {
			goto _st9;
		}
		goto _st0;
		_st9:
		p+= 1;
		st_case_9:
		if ( p == pe )
			goto _out9;
		if ( ( (*( p))) == 97 ) {
			goto _st10;
		}
		goto _st0;
		_st10:
		p+= 1;
		st_case_10:
		if ( p == pe )
			goto _out10;
		if ( ( (*( p))) == 97 ) {
			goto _st11;
		}
		goto _st0;
		_st11:
		p+= 1;
		st_case_11:
		if ( p == pe )
			goto _out11;
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr8;
			}
			case 97: {
				goto _st12;
			}
		}
		goto _st0;
		_st12:
		p+= 1;
		st_case_12:
		if ( p == pe )
			goto _out12;
		if ( ( (*( p))) == 97 ) {
			goto _st13;
		}
		goto _st0;
		_st13:
		p+= 1;
		st_case_13:
		if ( p == pe )
			goto _out13;
		switch( ( (*( p))) ) {
			case 10: {
				goto _ctr8;
			}
			case 97: {
				goto _ctr15;
			}
		}
		goto _st0;
		_out14: cs = 14; goto _out; 
		_out0: cs = 0; goto _out; 
		_out1: cs = 1; goto _out; 
		_out2: cs = 2; goto _out; 
		_out3: cs = 3; goto _out; 
		_out4: cs = 4; goto _out; 
		_out5: cs = 5; goto _out; 
		_out6: cs = 6; goto _out; 
		_out7: cs = 7; goto _out; 
		_out8: cs = 8; goto _out; 
		_out9: cs = 9; goto _out; 
		_out10: cs = 10; goto _out; 
		_out11: cs = 11; goto _out; 
		_out12: cs = 12; goto _out; 
		_out13: cs = 13; goto _out; 
		_out: {}
	}
	
#line 33 "../../../benchmarks/c/src/ragel/submatch_34__rep_alt_13_11_7.rl"

	
	in->p = p;
	in->pe = pe;
}

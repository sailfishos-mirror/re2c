#line 1 "../../../benchmarks/c/src/ragel/lex_00__numbers1.rl"
#include "ragel/base.h"

namespace ragel_lex_00__numbers1 {
	
	const char *delim = "\n";
	
	
#line 16 "../../../benchmarks/c/src/ragel/lex_00__numbers1.rl"

	

#line 11 "gen/ragel/lex_00__numbers1.cc"
static const int lex_numbers_start = 2;
	static const int lex_numbers_first_final = 2;
	static const int lex_numbers_error = 0;
	
	static const int lex_numbers_en_main = 2;
	
	
#line 18 "../../../benchmarks/c/src/ragel/lex_00__numbers1.rl"

	
	static int lex(Input *in, int count) {
		char *p = in->p;
		char *pe = in->pe;
		const char *p1 = p;
		int cs;
		

#line 26 "gen/ragel/lex_00__numbers1.cc"
	{
			cs = (int)lex_numbers_start;
		}
		
#line 26 "../../../benchmarks/c/src/ragel/lex_00__numbers1.rl"


#line 31 "gen/ragel/lex_00__numbers1.cc"
{
			switch ( cs ) {
				case 2:
				goto st_case_2;
				case 0:
				goto st_case_0;
				case 1:
				goto st_case_1;
			}
			_ctr2:
				{
#line 10 "../../../benchmarks/c/src/ragel/lex_00__numbers1.rl"
				
				OUTS(p1, p);
				p1 = p;
			}
			
#line 48 "gen/ragel/lex_00__numbers1.cc"

			goto _st2;
			_st2:
			p+= 1;
			st_case_2:
			if ( p == pe )
				goto _out2;
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _st1;
			}
			goto _st0;
			_st0:
			st_case_0:
			goto _out0;
			_st1:
			p+= 1;
			st_case_1:
			if ( p == pe )
				goto _out1;
			if ( ( (*( p))) == 10 ) {
				goto _ctr2;
			}
			if ( 48 <= ( (*( p))) && ( (*( p))) <= 57 ) {
				goto _st1;
			}
			goto _st0;
			_out2: cs = 2; goto _out; 
			_out0: cs = 0; goto _out; 
			_out1: cs = 1; goto _out; 
			_out: {}
		}
		
#line 27 "../../../benchmarks/c/src/ragel/lex_00__numbers1.rl"

		
		in->p = p;
		in->pe = pe;
		
		// +1 as we don't count the last newline due to using the entering action
		// >{...} (using the leaving action %{...} helps, but it requires `eof` and
		// breaks on long input in buffered mode).
		return count + 1;
	}
	
	RAGEL_BENCH_AND_TEST()
	
} // namespace ragel_lex_00__numbers1

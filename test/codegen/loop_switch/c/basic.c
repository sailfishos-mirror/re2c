/* Generated by re2c */
// re2c $INPUT -o $OUTPUT --case-ranges --loop-switch -i

int lex(const char *YYCURSOR) {       // C/C++ code

{
	char yych;
	unsigned int yystate = 0;
	for (;;) {
		switch (yystate) {
		case 0:
			yych = *YYCURSOR;
			++YYCURSOR;
			switch (yych) {
			case 'A' ... 'Z':
			case 'a' ... 'z':
				yystate = 3;
				continue;
			default:
				yystate = 1;
				continue;
			}
		case 1:
			yystate = 2;
			continue;
		case 2:
			{ return 1; }
		case 3:
			yych = *YYCURSOR;
			yystate = 4;
			continue;
		case 4:
			switch (yych) {
			case '0' ... '9':
			case 'A' ... 'Z':
			case 'a' ... 'z':
				++YYCURSOR;
				yystate = 3;
				continue;
			default:
				yystate = 5;
				continue;
			}
		case 5:
			{ return 0; }
		}
	}
}

}                                     //
                                      //
int main() {                          // C/C++ code
    return lex("qwerty42");           //
}                                     //

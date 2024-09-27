/* Generated by re2rust */
// re2rust $INPUT -o $OUTPUT

fn lex(yyinput: &[u8]) -> isize {
    // The input must be null-terminated, otherwise the function has UB.
    assert_eq!(yyinput.last(), Some(&0));

    let mut yycursor = 0;
    let mut count = 0;

    'lex: loop { 
{
    #[allow(unused_assignments)]
    let mut yych : u8 = 0;
    let mut yystate : usize = 0;
    'yyl: loop {
        match yystate {
            0 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                yycursor += 1;
                match yych {
                    0x00 => {
                        yystate = 1;
                        continue 'yyl;
                    }
                    0x20 => {
                        yystate = 3;
                        continue 'yyl;
                    }
                    0x61 ..= 0x7A => {
                        yystate = 5;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 2;
                        continue 'yyl;
                    }
                }
            }
            1 => { return count; },
            2 => { return -1; },
            3 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x20 => {
                        yycursor += 1;
                        yystate = 3;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 4;
                        continue 'yyl;
                    }
                }
            }
            4 => { continue 'lex; },
            5 => {
                yych = unsafe {*yyinput.get_unchecked(yycursor)};
                match yych {
                    0x61 ..= 0x7A => {
                        yycursor += 1;
                        yystate = 5;
                        continue 'yyl;
                    }
                    _ => {
                        yystate = 6;
                        continue 'yyl;
                    }
                }
            }
            6 => { count += 1; continue 'lex; },
            _ => panic!("internal lexer error"),
        }
    }
}
}
}

fn main() {
    assert_eq!(lex(b"\x00"), 0);
    assert_eq!(lex(b"one two three\x00"), 3);
    assert_eq!(lex(b"f0ur\x00"), -1);
}

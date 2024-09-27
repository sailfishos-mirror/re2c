// re2v $INPUT -o $OUTPUT -i --header lexer/state.v
module main

import lexer // the package is generated by re2c

/*!header:re2c:on*/
module lexer

pub struct State {
pub mut:
    yyinput string
    yycursor int
    /*!stags:re2c format="@@ int\n"; */
}
/*!header:re2c:off*/

fn lex(mut yyrecord &lexer.State) int {
    mut t := 0
    /*!re2c
        re2c:header = "lexer/state.v";
        re2c:api = record;
        re2c:yyfill:enable = 0;
        re2c:tags = 1;

        [a]* @t [b]* { return t }
    */
}

fn main() {
    mut st := &lexer.State{yyinput:"ab\0",}
    if lex(mut st) != 1 {
        panic("error")
    }
}

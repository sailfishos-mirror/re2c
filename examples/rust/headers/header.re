// re2rust $INPUT -o $OUTPUT --header src/lexer/lexer.rs

mod src;
use src::lexer::lexer; // generated by re2c

/*!header:re2c:on*/
pub struct State<'a> {
    pub str: &'a [u8],
    pub cur: usize,
    pub mar: usize,
    /*!stags:re2c format = "pub @@: usize, "; */
}
/*!header:re2c:off*/

fn lex(st: &mut lexer::State) -> bool {
    /*!re2c
        re2c:header = "src/lexer/lexer.rs";
        re2c:yyfill:enable = 0;
        re2c:define:YYCTYPE   = "u8";
        re2c:define:YYPEEK    = "*st.str.get_unchecked(st.cur)";
        re2c:define:YYSKIP    = "st.cur += 1;";
        re2c:define:YYBACKUP  = "st.mar = st.cur;";
        re2c:define:YYRESTORE = "st.cur = st.mar;";
        re2c:define:YYSTAGP   = "@@ = st.cur;";
        re2c:define:YYRESTORETAG = "st.cur = @@;";
        re2c:tags = 1;
        re2c:tags:expression = "st.@@";

        [x]{1,4} / [x]{3,5} { return false; } // ambiguous trailing context
        *                   { return true; }
    */
}

fn main() {
    let mut st = lexer::State {
        str: b"xxxxxxxx\0",
        cur: 0,
        mar: 0,
        /*!stags:re2c format = "@@: 0, "; */
    };
    assert_eq!(lex(&mut st), false);
    assert_eq!(st.cur, 4);
}

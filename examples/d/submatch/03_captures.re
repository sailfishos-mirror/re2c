// re2d $INPUT -o $OUTPUT
module main;

struct SemVer { int major, minor, patch; };

private int s2n(const(char)* s, const(char)* e) { // pre-parsed string to number
    int n = 0;
    for (; s < e; ++s) n = n * 10 + (*s - '0');
    return n;
}

private bool lex(const(char)* str, ref SemVer ver) {
    const(char)* yycursor = str, yymarker;

    // Final tag variables available in semantic action.
    /*!svars:re2c format = 'const(char)* @@;\n'; */

    // Intermediate tag variables used by the lexer (must be autogenerated).
    /*!stags:re2c format = 'const(char)* @@;\n'; */

    /*!re2c
        re2c:yyfill:enable = 0;
        re2c:captvars = 1;
        re2c:define:YYCTYPE = "char";

        num = [0-9]+;

        (num) "." (num) ("." num)? [\x00] {
            ver.major = s2n(yytl1, yytr1);
            ver.minor = s2n(yytl2, yytr2);
            ver.patch = yytl3 ? s2n(yytl3 + 1, yytr3) : 0;
            return true;
        }
        * { return false; }
    */
}

void main() {
    SemVer v;
    assert(lex("23.34", v) && v.major == 23 && v.minor == 34 && v.patch == 0);
    assert(lex("1.2.999", v) && v.major == 1 && v.minor == 2 && v.patch == 999);
    assert(!lex("1.a", v));
}
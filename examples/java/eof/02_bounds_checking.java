// Generated by re2java
// re2java $INPUT -o $OUTPUT

class Main {
    static final int YYMAXFILL = 1;


    // Expects yymaxfill-padded string.
    static int lex(String str) {
        // Pad string with yymaxfill zeroes at the end.
        byte[] yyinput = new byte[str.length() + YYMAXFILL];
        System.arraycopy(str.getBytes(), 0, yyinput, 0, str.length()); 

        int yycursor = 0;
        int yylimit = yyinput.length;
        int count = 0;

        loop: while (true) {
            
{
    byte yych = 0;
    int yystate = 0;
    yyl: while (true) {
        switch (yystate) {
            case 0:
                if (yylimit <= yycursor) {
                    return -1;
                }
                yych = yyinput[yycursor];
                yycursor += 1;
                switch (yych) {
                    case 0x00:
                        yystate = 1;
                        continue yyl;
                    case 0x20:
                        yystate = 3;
                        continue yyl;
                    case 0x27:
                        yystate = 5;
                        continue yyl;
                    default:
                        yystate = 2;
                        continue yyl;
                }
            case 1:
                {
                    // Check that it is the sentinel, not some unexpected null.
                    return (yycursor - 1 == str.length()) ? count : -1;
                }
            case 2:
                { return -1; }
            case 3:
                if (yylimit <= yycursor) {
                    return -1;
                }
                yych = yyinput[yycursor];
                switch (yych) {
                    case 0x20:
                        yycursor += 1;
                        yystate = 3;
                        continue yyl;
                    default:
                        yystate = 4;
                        continue yyl;
                }
            case 4:
                { continue loop; }
            case 5:
                if (yylimit <= yycursor) {
                    return -1;
                }
                yych = yyinput[yycursor];
                yycursor += 1;
                switch (yych) {
                    case 0x27:
                        yystate = 6;
                        continue yyl;
                    case 0x5C:
                        yystate = 7;
                        continue yyl;
                    default:
                        yystate = 5;
                        continue yyl;
                }
            case 6:
                { count += 1; continue loop; }
            case 7:
                if (yylimit <= yycursor) {
                    return -1;
                }
                yycursor += 1;
                yystate = 5;
                continue yyl;
            default:
                throw new IllegalStateException("internal lexer error");
        }
    }
}

        }
    }

    public static void main(String []args) {
        assert lex("") == 0;
        assert lex("'qu\0tes' 'are' 'fine: \\'' ") == 3;
        assert lex("'unterminated\\'") == -1;
        assert lex("'unexpected \00 null\\'") == -1;
    }
};

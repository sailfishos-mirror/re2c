// Generated by re2java
// re2java $INPUT -o $OUTPUT -b

class Main {
    static boolean lex(String str) {
        int cur = 0;

        
{
    char yych = 0;
    int yystate = 0;
    final int[] yybm = new int[]{
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
        128, 128, 128, 128, 128, 128, 128, 128,
        128, 128,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
          0,   0,   0,   0,   0,   0,   0,   0,
    };
    yyl: while (true) {
        switch (yystate) {
            case 0:
                yych = str.charAt(cur);
                cur += 1;
                if (yych <= 0x30) {
                    yystate = 1;
                    continue yyl;
                }
                if (yych <= 0x39) {
                    yystate = 2;
                    continue yyl;
                }
                yystate = 1;
                continue yyl;
            case 1:
                { return false; }
            case 2:
                yych = str.charAt(cur);
                if ((yybm[0+yych] & 128) != 0) {
                    cur += 1;
                    yystate = 2;
                    continue yyl;
                }
                { return true; }
            default:
                throw new IllegalStateException("internal lexer error");
        }
    }
}

    }

    public static void main(String []args) {
        assert lex("1234\0");
    }
};

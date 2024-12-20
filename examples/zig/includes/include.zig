// Generated by re2zig
// re2zig $INPUT -o $OUTPUT

const std = @import("std");

const Num = enum { integer, floating, nan };




fn lex(yyinput: [:0]const u8) Num {
    var yycursor: u32 = 0;
    var yymarker: u32 = 0;
    
    var yych: u8 = 0;
    var yyaccept: u32 = 0;
    var yystate: u32 = 0;
    yyl: while (true) {
        switch (yystate) {
            0 => {
                yych = yyinput[yycursor];
                yycursor += 1;
                switch (yych) {
                    0x2E => {
                        yystate = 3;
                        continue :yyl;
                    },
                    0x30 => {
                        yystate = 4;
                        continue :yyl;
                    },
                    0x31...0x39 => {
                        yystate = 5;
                        continue :yyl;
                    },
                    else => {
                        yystate = 1;
                        continue :yyl;
                    },
                }
            },
            1 => {
                yystate = 2;
                continue :yyl;
            },
            2 => { return Num.nan; },
            3 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 7;
                        continue :yyl;
                    },
                    else => {
                        yystate = 2;
                        continue :yyl;
                    },
                }
            },
            4 => {
                yyaccept = 0;
                yymarker = yycursor;
                yych = yyinput[yycursor];
                switch (yych) {
                    0x2E => {
                        yycursor += 1;
                        yystate = 7;
                        continue :yyl;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 9;
                        continue :yyl;
                    },
                    0x45,
                    0x65 => {
                        yycursor += 1;
                        yystate = 11;
                        continue :yyl;
                    },
                    else => {
                        yystate = 2;
                        continue :yyl;
                    },
                }
            },
            5 => {
                yyaccept = 1;
                yymarker = yycursor;
                yych = yyinput[yycursor];
                switch (yych) {
                    0x2E => {
                        yycursor += 1;
                        yystate = 7;
                        continue :yyl;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 5;
                        continue :yyl;
                    },
                    0x45,
                    0x65 => {
                        yycursor += 1;
                        yystate = 11;
                        continue :yyl;
                    },
                    else => {
                        yystate = 6;
                        continue :yyl;
                    },
                }
            },
            6 => { return Num.integer; },
            7 => {
                yyaccept = 2;
                yymarker = yycursor;
                yych = yyinput[yycursor];
                switch (yych) {
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 7;
                        continue :yyl;
                    },
                    0x45,
                    0x65 => {
                        yycursor += 1;
                        yystate = 11;
                        continue :yyl;
                    },
                    else => {
                        yystate = 8;
                        continue :yyl;
                    },
                }
            },
            8 => { return Num.floating; },
            9 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x2E => {
                        yycursor += 1;
                        yystate = 7;
                        continue :yyl;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 9;
                        continue :yyl;
                    },
                    0x45,
                    0x65 => {
                        yycursor += 1;
                        yystate = 11;
                        continue :yyl;
                    },
                    else => {
                        yystate = 10;
                        continue :yyl;
                    },
                }
            },
            10 => {
                yycursor = yymarker;
                switch (yyaccept) {
                    0 => {
                        yystate = 2;
                        continue :yyl;
                    },
                    1 => {
                        yystate = 6;
                        continue :yyl;
                    },
                    else => {
                        yystate = 8;
                        continue :yyl;
                    },
                }
            },
            11 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x2B,
                    0x2D => {
                        yycursor += 1;
                        yystate = 12;
                        continue :yyl;
                    },
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 13;
                        continue :yyl;
                    },
                    else => {
                        yystate = 10;
                        continue :yyl;
                    },
                }
            },
            12 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 13;
                        continue :yyl;
                    },
                    else => {
                        yystate = 10;
                        continue :yyl;
                    },
                }
            },
            13 => {
                yych = yyinput[yycursor];
                switch (yych) {
                    0x30...0x39 => {
                        yycursor += 1;
                        yystate = 13;
                        continue :yyl;
                    },
                    else => {
                        yystate = 8;
                        continue :yyl;
                    },
                }
            },
            else => { @panic("internal lexer error"); },
        }
    }

}

test {
    try std.testing.expectEqual(lex("123"), Num.integer);
    try std.testing.expectEqual(lex("123.4567"), Num.floating);
}

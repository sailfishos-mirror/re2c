// Generated by re2zig
// re2zig $INPUT -o $OUTPUT

const std = @import("std");

// Expects a string without terminating null.
fn lex(str: []const u8) i32 {
    var cur: usize = 0;
    var count: i32 = 0;

    loop: while (true) {
        
    var yych: u8 = 0;
    var yystate: u32 = 0;
    while (true) {
        switch (yystate) {
            0 => {
                yych = if (cur >= str.len) 0 else str[cur];
                cur += 1;
                switch (yych) {
                    0x00 => {
                        yystate = 1;
                        continue;
                    },
                    0x20 => {
                        yystate = 3;
                        continue;
                    },
                    0x61...0x7A => {
                        yystate = 5;
                        continue;
                    },
                    else => {
                        yystate = 2;
                        continue;
                    },
                }
            },
            1 => { return count; },
            2 => { return -1; },
            3 => {
                yych = if (cur >= str.len) 0 else str[cur];
                switch (yych) {
                    0x20 => {
                        cur += 1;
                        yystate = 3;
                        continue;
                    },
                    else => {
                        yystate = 4;
                        continue;
                    },
                }
            },
            4 => { continue :loop; },
            5 => {
                yych = if (cur >= str.len) 0 else str[cur];
                switch (yych) {
                    0x61...0x7A => {
                        cur += 1;
                        yystate = 5;
                        continue;
                    },
                    else => {
                        yystate = 6;
                        continue;
                    },
                }
            },
            6 => { count += 1; continue :loop; },
            else => { @panic("internal lexer error"); },
        }
    }

    }
}

test {
    try std.testing.expectEqual(lex(""), 0);
    try std.testing.expectEqual(lex("one two three"), 3);
    try std.testing.expectEqual(lex("f0ur"), -1);
}

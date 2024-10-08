# Generated by re2py
# re2py $INPUT -o $OUTPUT

# expect a string without terminating null
def lex(str):
    cur = 0
    lim = len(str)
    count = 0

    while True: 
        yystate = 0
        while True:
            match yystate:
                case 0:
                    yych = str[cur] if cur < lim else 0
                    cur += 1
                    if yych <= 0x20:
                        if yych <= 0x00:
                            yystate = 1
                            continue
                        if yych <= 0x1F:
                            yystate = 2
                            continue
                        yystate = 3
                        continue
                    else:
                        if yych <= 0x60:
                            yystate = 2
                            continue
                        if yych <= 0x7A:
                            yystate = 4
                            continue
                        yystate = 2
                        continue
                case 1:
                    return count
                case 2:
                    return -1
                case 3:
                    yych = str[cur] if cur < lim else 0
                    if yych == 0x20:
                        cur += 1
                        yystate = 3
                        continue
                    break
                case 4:
                    yych = str[cur] if cur < lim else 0
                    if yych <= 0x60:
                        yystate = 5
                        continue
                    if yych <= 0x7A:
                        cur += 1
                        yystate = 4
                        continue
                    yystate = 5
                    continue
                case 5:
                    count += 1
                    break
                case _:
                    raise "internal lexer error"


assert lex(b"") == 0
assert lex(b"one two three") == 3
assert lex(b"f0ur") == -1

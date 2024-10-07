# Generated by re2py
# re2py $INPUT -o $OUTPUT

from enum import Enum
import os

BUFSIZE = 4096

class State:
    def __init__(self, fname):
        self.file = open(fname, "rb")
        self.yyinput = bytearray(BUFSIZE)
        self.yylimit = BUFSIZE - 1 # exclude terminating null
        self.yycursor = self.yylimit
        self.yymarker = self.yylimit
        self.token = self.yylimit
        self.eof = False

    def __del__(self):
        self.file.close()

class Status(Enum):
    OK = 0
    EOF = 1
    LONG_LEXEME = 2

def fill(st):
    if st.eof:
        return Status.EOF

    # Error: lexeme too long. In real life could reallocate a larger buffer.
    if st.token < 1:
        return Status.LONG_LEXEME

    # Shift buffer contents (discard everything up to the current token).
    st.yyinput = st.yyinput[st.token:st.yylimit]
    st.yycursor -= st.token;
    st.yymarker -= st.token;
    st.yylimit -= st.token;
    st.token = 0;

    # Fill free space at the end of buffer with new data from file.
    bytes = st.file.read(BUFSIZE - st.yylimit - 1) # -1 for sentinel
    if not bytes:
        st.eof = True # end of file
    else:
        st.yylimit += len(bytes);
        st.yyinput += bytes

    st.yyinput += b'\0' # append sentinel

    return Status.OK

def lex(yyrecord, count):
    while True:
        yyrecord.token = yyrecord.yycursor
    
        yystate = 0
        while True:
            match yystate:
                case 0:
                    yych = yyrecord.yyinput[yyrecord.yycursor]
                    if yych <= 0x20:
                        if yych <= 0x00:
                            if yyrecord.yylimit <= yyrecord.yycursor:
                                if fill(yyrecord) == Status.OK:
                                    yystate = 0
                                    continue
                                yystate = 9
                                continue
                            yyrecord.yycursor += 1
                            yystate = 1
                            continue
                        if yych >= 0x20:
                            yyrecord.yycursor += 1
                            yystate = 3
                            continue
                        yyrecord.yycursor += 1
                        yystate = 1
                        continue
                    else:
                        if yych == 0x27:
                            yyrecord.yycursor += 1
                            yystate = 5
                            continue
                        yyrecord.yycursor += 1
                        yystate = 1
                        continue
                case 1:
                    yystate = 2
                    continue
                case 2:
                    return -1
                case 3:
                    yych = yyrecord.yyinput[yyrecord.yycursor]
                    if yych <= 0x00:
                        if yyrecord.yylimit <= yyrecord.yycursor:
                            if fill(yyrecord) == Status.OK:
                                yystate = 3
                                continue
                        yystate = 4
                        continue
                    if yych == 0x20:
                        yyrecord.yycursor += 1
                        yystate = 3
                        continue
                    yystate = 4
                    continue
                case 4:
                    break
                case 5:
                    yyrecord.yymarker = yyrecord.yycursor
                    yych = yyrecord.yyinput[yyrecord.yycursor]
                    if yych >= 0x01:
                        yystate = 7
                        continue
                    if yyrecord.yylimit <= yyrecord.yycursor:
                        if fill(yyrecord) == Status.OK:
                            yystate = 5
                            continue
                        yystate = 2
                        continue
                    yyrecord.yycursor += 1
                    yystate = 6
                    continue
                case 6:
                    yych = yyrecord.yyinput[yyrecord.yycursor]
                    yystate = 7
                    continue
                case 7:
                    if yych <= 0x27:
                        if yych <= 0x00:
                            if yyrecord.yylimit <= yyrecord.yycursor:
                                if fill(yyrecord) == Status.OK:
                                    yystate = 6
                                    continue
                                yystate = 10
                                continue
                            yyrecord.yycursor += 1
                            yystate = 6
                            continue
                        if yych <= 0x26:
                            yyrecord.yycursor += 1
                            yystate = 6
                            continue
                        yyrecord.yycursor += 1
                    else:
                        if yych == 0x5C:
                            yyrecord.yycursor += 1
                            yystate = 8
                            continue
                        yyrecord.yycursor += 1
                        yystate = 6
                        continue
                    count += 1
                    break
                case 8:
                    yych = yyrecord.yyinput[yyrecord.yycursor]
                    if yych <= 0x00:
                        if yyrecord.yylimit <= yyrecord.yycursor:
                            if fill(yyrecord) == Status.OK:
                                yystate = 8
                                continue
                            yystate = 10
                            continue
                        yyrecord.yycursor += 1
                        yystate = 6
                        continue
                    yyrecord.yycursor += 1
                    yystate = 6
                    continue
                case 9:
                    return count
                case 10:
                    yyrecord.yycursor = yyrecord.yymarker
                    yystate = 2
                    continue
                case _:
                    raise "internal lexer error"


def main():
    fname = "input"

    # Prepare input file.
    f = open(fname, "w")
    for i in range(BUFSIZE):
        f.write("'qu\0tes' 'are' 'fine: \\'' ")
    f.close()

    # Run lexer on the prepared file.
    st = State(fname)
    assert lex(st, 0) == 3 * BUFSIZE

    # Cleanup.
    os.remove(fname)

if __name__ == '__main__':
    main()
/* Generated by re2c */
#line 1 "d/state/push.re"
// re2d $INPUT -o $OUTPUT -f
module main;

import core.stdc.stdio;
import core.stdc.string;

// Use a small buffer to cover the case when a lexeme doesn't fit.
// In real world use a larger buffer.
enum BUFSIZE = 10;

struct State {
    FILE* file;
    char[BUFSIZE + 1] buf;
    char* lim, cur, mar, tok;
    int state;
};

enum Status {END, READY, WAITING, BAD_PACKET, BIG_PACKET};

private Status fill(ref State st) {
    const size_t shift = st.tok - cast(char*)st.buf;
    const size_t used = st.lim - st.tok;
    const size_t free = BUFSIZE - used;

    // Error: no space. In real life can reallocate a larger buffer.
    if (free < 1) return Status.BIG_PACKET;

    // Shift buffer contents (discard already processed data).
    memmove(cast(void*)st.buf, st.tok, used);
    st.lim -= shift;
    st.cur -= shift;
    st.mar -= shift;
    st.tok -= shift;

    // Fill free space at the end of buffer with new data.
    const size_t read = fread(st.lim, 1, free, st.file);
    st.lim += read;
    st.lim[0] = 0; // append sentinel symbol

    return Status.READY;
}

private Status lex(ref State st, uint* recv) {
    char yych;
    
#line 49 "d/state/push.d"
switch (st.state) {
	case -1: goto yy0;
	case 0:
		if (st.lim <= st.cur) goto yy8;
		goto yyFillLabel0;
	case 1:
		if (st.lim <= st.cur) goto yy3;
		goto yyFillLabel1;
	case 2:
		if (st.lim <= st.cur) goto yy7;
		goto yyFillLabel2;
	default: assert(false);
}
#line 45 "d/state/push.re"


    for (;;) {
        st.tok = st.cur;
    
#line 69 "d/state/push.d"
yy0:
yyFillLabel0:
	yych = *st.cur;
	switch (yych) {
		case 'a': .. case 'z': goto yy4;
		default:
			if (st.lim <= st.cur) {
				st.state = 0;
				return Status.WAITING;
			}
			goto yy2;
	}
yy2:
	++st.cur;
yy3:
	st.state = -1;
#line 63 "d/state/push.re"
	{ return Status.BAD_PACKET; }
#line 88 "d/state/push.d"
yy4:
	++st.cur;
	st.mar = st.cur;
yyFillLabel1:
	yych = *st.cur;
	switch (yych) {
		case ';': goto yy5;
		case 'a': .. case 'z': goto yy6;
		default:
			if (st.lim <= st.cur) {
				st.state = 1;
				return Status.WAITING;
			}
			goto yy3;
	}
yy5:
	++st.cur;
	st.state = -1;
#line 65 "d/state/push.re"
	{ *recv = *recv + 1; continue; }
#line 109 "d/state/push.d"
yy6:
	++st.cur;
yyFillLabel2:
	yych = *st.cur;
	switch (yych) {
		case ';': goto yy5;
		case 'a': .. case 'z': goto yy6;
		default:
			if (st.lim <= st.cur) {
				st.state = 2;
				return Status.WAITING;
			}
			goto yy7;
	}
yy7:
	st.cur = st.mar;
	goto yy3;
yy8:
	st.state = -1;
#line 64 "d/state/push.re"
	{ return Status.END; }
#line 131 "d/state/push.d"
#line 66 "d/state/push.re"

    }
    assert(0); // unreachable
}

private void test(string[] packets, Status expect) {
    // Create a "socket" (open the same file for reading and writing).
    const(char*) fname = "pipe";
    FILE* fw = fopen(fname, "w");
    FILE* fr = fopen(fname, "r");
    setvbuf(fw, null, _IONBF, 0);
    setvbuf(fr, null, _IONBF, 0);

    // Initialize lexer state: `state` value is -1, all pointers are at the end
    // of buffer.
    State st;
    st.file = fr;
    st.cur = st.mar = st.tok = st.lim = cast(char*)st.buf + BUFSIZE;
    // Sentinel (at YYLIMIT pointer) is set to zero, which triggers YYFILL.
    st.lim[0] = 0;
    st.state = -1;

    // Main loop. The buffer contains incomplete data which appears packet by
    // packet. When the lexer needs more input it saves its internal state and
    // returns to the caller which should provide more input and resume lexing.
    Status status;
    uint send = 0, recv = 0;
    for (;;) {
        status = lex(st, &recv);
        if (status == Status.END) {
            debug{printf("done: got %u packets\n", recv);}
            break;
        } else if (status == Status.WAITING) {
            debug{printf("waiting...\n");}
            if (send < packets.length) {
                debug{printf("sent packet %u\n", send);}
                fprintf(fw, "%s", cast(char*)packets[send]);
                ++send;
            }
            status = fill(st);
            debug{printf("queue: '%s'\n", cast(char*)st.buf);}
            if (status == Status.BIG_PACKET) {
                debug{printf("error: packet too big\n");}
                break;
            }
            assert(status == Status.READY);
        } else {
            assert(status == Status.BAD_PACKET);
            debug{printf("error: ill-formed packet\n");}
            break;
        }
    }

    // Check results.
    assert(status == expect);
    if (status == Status.END) assert(recv == send);

    // Cleanup: remove input file.
    fclose(fw);
    fclose(fr);
    remove(fname);
}

void main() {
    string[] packets1 = [];
    string[] packets2 = ["zero;", "one;", "two;", "three;", "four;"];
    string[] packets3 = ["zer0;"];
    string[] packets4 = ["looooooooooong;"];

    test(packets1, Status.END);
    test(packets2, Status.END);
    test(packets3, Status.BAD_PACKET);
    test(packets4, Status.BIG_PACKET);
}

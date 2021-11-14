// Code generated by re2c, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT --loop-switch -i
package main

import "testing"

// Returns "fake" terminating null if cursor has reached limit.
func peek(str string, cursor int, limit int) byte {
	if cursor >= limit {
		return 0 // fake null
	} else {
		return str[cursor]
	}
}

// Expects a string without terminating null.
func lex(str string) int {
	var cursor, marker int
	limit := len(str)
	count := 0
loop:
	
{
	var yych byte
	yystate := 0
	for {
		switch (yystate) {
		case 0:
			yych = peek(str, cursor, limit)
			switch (yych) {
			case ' ':
				cursor += 1
				yystate = 3
				continue
			case '\'':
				cursor += 1
				yystate = 6
				continue
			default:
				if (cursor >= limit) {
					yystate = 12
					continue
				}
				cursor += 1
				yystate = 1
				continue
			}
		case 1:
			yystate = 2
			continue
		case 2:
			{ return -1 }
		case 3:
			yych = peek(str, cursor, limit)
			yystate = 4
			continue
		case 4:
			switch (yych) {
			case ' ':
				cursor += 1
				yystate = 3
				continue
			default:
				yystate = 5
				continue
			}
		case 5:
			{ goto loop }
		case 6:
			marker = cursor
			yych = peek(str, cursor, limit)
			if (yych >= 0x01) {
				yystate = 8
				continue
			}
			if (cursor >= limit) {
				yystate = 2
				continue
			}
			cursor += 1
			yystate = 7
			continue
		case 7:
			yych = peek(str, cursor, limit)
			yystate = 8
			continue
		case 8:
			switch (yych) {
			case '\'':
				cursor += 1
				yystate = 9
				continue
			case '\\':
				cursor += 1
				yystate = 11
				continue
			default:
				if (cursor >= limit) {
					yystate = 13
					continue
				}
				cursor += 1
				yystate = 7
				continue
			}
		case 9:
			yystate = 10
			continue
		case 10:
			{ count += 1; goto loop }
		case 11:
			yych = peek(str, cursor, limit)
			if (yych <= 0x00) {
				if (cursor >= limit) {
					yystate = 13
					continue
				}
				cursor += 1
				yystate = 7
				continue
			}
			cursor += 1
			yystate = 7
			continue
		case 12:
			{ return count }
		case 13:
			cursor = marker
			yystate = 2
			continue
		}
	}
}

}

func TestLex(t *testing.T) {
	var tests = []struct {
		res int
		str string
	}{
		{0, ""},
		{3, "'qu\000tes' 'are' 'fine: \\'' "},
		{-1, "'unterminated\\'"},
	}

	for _, x := range tests {
		t.Run(x.str, func(t *testing.T) {
			res := lex(x.str)
			if res != x.res {
				t.Errorf("got %d, want %d", res, x.res)
			}
		})
	}
}

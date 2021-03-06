// Code generated by re2c, DO NOT EDIT.
//line "go/eof/03_eof_rule.re":1
//go:generate re2go $INPUT -o $OUTPUT
package main

// Expects a null-terminated string.
func lex(str string) int {
	var cur, mar int
	lim := len(str) - 1 // lim points at the terminating null
	count := 0

	for { 
//line "go/eof/03_eof_rule.go":14
{
	var yych byte
	yych = str[cur]
	switch (yych) {
	case ' ':
		goto yy3
	case '\'':
		goto yy5
	default:
		if (lim <= cur) {
			goto yy10
		}
		goto yy1
	}
yy1:
	cur += 1
yy2:
//line "go/eof/03_eof_rule.re":22
	{ return -1 }
//line "go/eof/03_eof_rule.go":34
yy3:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case ' ':
		goto yy3
	default:
		goto yy4
	}
yy4:
//line "go/eof/03_eof_rule.re":25
	{ continue }
//line "go/eof/03_eof_rule.go":47
yy5:
	cur += 1
	mar = cur
	yych = str[cur]
	if (yych >= 0x01) {
		goto yy7
	}
	if (lim <= cur) {
		goto yy2
	}
yy6:
	cur += 1
	yych = str[cur]
yy7:
	switch (yych) {
	case '\'':
		goto yy8
	case '\\':
		goto yy9
	default:
		if (lim <= cur) {
			goto yy11
		}
		goto yy6
	}
yy8:
	cur += 1
//line "go/eof/03_eof_rule.re":24
	{ count += 1; continue }
//line "go/eof/03_eof_rule.go":77
yy9:
	cur += 1
	yych = str[cur]
	if (yych <= 0x00) {
		if (lim <= cur) {
			goto yy11
		}
		goto yy6
	}
	goto yy6
yy10:
//line "go/eof/03_eof_rule.re":23
	{ return count }
//line "go/eof/03_eof_rule.go":91
yy11:
	cur = mar
	goto yy2
}
//line "go/eof/03_eof_rule.re":26

	}
}

func main() {
	assert_eq := func(x, y int) { if x != y { panic("error") } }
	assert_eq(lex("\000"), 0)
	assert_eq(lex("'qu\000tes' 'are' 'fine: \\'' \000"), 3)
	assert_eq(lex("'unterminated\\'\000"), -1)
}

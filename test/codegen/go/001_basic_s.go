// Code generated by re2go, DO NOT EDIT.
//line "codegen/go/001_basic_s.re":1
//go:generate re2go $INPUT -o $OUTPUT -s
package main

func Lex(str string) int {
	var cursor, marker int

	
//line "codegen/go/001_basic_s.go":11
{
	var yych byte
	yych = str[cursor]
	if (yych <= '/') {
		goto yy1
	}
	if (yych <= '9') {
		goto yy3
	}
yy1:
	cursor += 1
yy2:
//line "codegen/go/001_basic_s.re":17
	{
		return -1
	}
//line "codegen/go/001_basic_s.go":28
yy3:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	if (yych <= 0x00) {
		goto yy4
	}
	if (yych <= '/') {
		goto yy2
	}
	if (yych <= '9') {
		goto yy5
	}
	goto yy2
yy4:
	cursor += 1
//line "codegen/go/001_basic_s.re":21
	{
		return 1
	}
//line "codegen/go/001_basic_s.go":49
yy5:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x00) {
		goto yy4
	}
	if (yych <= '/') {
		goto yy6
	}
	if (yych <= '9') {
		goto yy5
	}
yy6:
	cursor = marker
	goto yy2
}
//line "codegen/go/001_basic_s.re":24

}

func main() {
	if Lex("123\000") != 1 {
		panic("expected 123")
	}
}

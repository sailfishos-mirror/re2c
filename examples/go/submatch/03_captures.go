// Code generated by re2go, DO NOT EDIT.
//line "go/submatch/03_captures.re":1
//go:generate re2go $INPUT -o $OUTPUT --api simple
package main

import "reflect"

type SemVer struct { major, minor, patch int }

func s2n(s string) int { // convert pre-parsed string to a number
	n := 0
	for _, c := range s { n = n*10 + int(c-'0') }
	return n
}

func parse(yyinput string) *SemVer {
	var yycursor, yymarker int

	// Final tag variables used in semantic action.
	
//line "go/submatch/03_captures.go":22
var yytl0 int;var yytl1 int;var yytl2 int;var yytl3 int;var yytr0 int;var yytr1 int;var yytr2 int;var yytr3 int;
//line "go/submatch/03_captures.re":18


	// Intermediate tag variables used by the lexer (must be autogenerated).
	
//line "go/submatch/03_captures.go":29
var yyt1 int;var yyt2 int;var yyt3 int;var yyt4 int;var yyt5 int;
//line "go/submatch/03_captures.re":21


	
//line "go/submatch/03_captures.go":35
{
	var yych byte
	yych = yyinput[yycursor]
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		yyt1 = yycursor
		goto yy3
	default:
		goto yy1
	}
yy1:
	yycursor += 1
yy2:
//line "go/submatch/03_captures.re":39
	{ return nil }
//line "go/submatch/03_captures.go":51
yy3:
	yycursor += 1
	yymarker = yycursor
	yych = yyinput[yycursor]
	switch (yych) {
	case '.':
		goto yy4
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy6
	default:
		goto yy2
	}
yy4:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		yyt2 = yycursor
		goto yy7
	default:
		goto yy5
	}
yy5:
	yycursor = yymarker
	goto yy2
yy6:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case '.':
		goto yy4
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy6
	default:
		goto yy5
	}
yy7:
	yycursor += 1
	yych = yyinput[yycursor]
	switch (yych) {
	case 0x00:
		yyt3 = yycursor
		yyt4 = -1
		yyt5 = -1
		goto yy8
	case '.':
		yyt3 = yycursor
		yyt5 = yycursor
		goto yy9
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy7
	default:
		goto yy5
	}
yy8:
	yycursor += 1
	yytl1 = yyt1
	yytl2 = yyt2
	yytr2 = yyt3
	yytl3 = yyt5
	yytr3 = yyt4
	yytl0 = yyt1
	yytr0 = yycursor
	yytr1 = yyt2
	yytr1 -= 1
//line "go/submatch/03_captures.re":30
	{
			_ = yytl0; _ = yytr0; // some variables are unused
			major := s2n(yyinput[yytl1:yytr1])
			minor := s2n(yyinput[yytl2:yytr2])
			patch := 0
			if yytl3 != -1 { patch = s2n(yyinput[yytl3+1:yytr3]) }

			return &SemVer{major, minor, patch}
		}
//line "go/submatch/03_captures.go":127
yy9:
	yycursor += 1
	yych = yyinput[yycursor]
	if (yych <= 0x00) {
		goto yy5
	}
	goto yy11
yy10:
	yycursor += 1
	yych = yyinput[yycursor]
yy11:
	switch (yych) {
	case 0x00:
		yyt4 = yycursor
		goto yy8
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy10
	default:
		goto yy5
	}
}
//line "go/submatch/03_captures.re":40

}

func main() {
	assert_eq := func(x, y *SemVer) {
		if !reflect.DeepEqual(x, y) { panic("error") }
	}
	assert_eq(parse("23.34\000"), &SemVer{23, 34, 0})
	assert_eq(parse("1.2.9999\000"), &SemVer{1, 2, 9999})
	assert_eq(parse("1.a\000"), nil)
}

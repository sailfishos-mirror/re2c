// Code generated by re2c, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT -i
package main

func lex(str string) {
	var cursor int
	
{
	var yych byte
	yych = str[cursor]
	switch (yych) {
	case '1','2','3','4','5','6','7','8','9':
		goto yy2
	default:
		goto yy1
	}
yy1:
	cursor += 1
	{ panic("error!") }
yy2:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case '0','1','2','3','4','5','6','7','8','9':
		goto yy2
	default:
		goto yy3
	}
yy3:
	{ return }
}

}

func main() {
	lex("1234\x00")
}

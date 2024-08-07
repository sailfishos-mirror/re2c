//go:generate re2go $INPUT -o $OUTPUT -f
package main

import "fmt"
import "os"

/*!max:re2c*/
var SIZE uint = 11

type YYCTYPE byte
type Input struct {
	file   *os.File
	data   []byte
	cursor uint
	marker uint
	token  uint
	limit  uint
	eof    bool
	state  int
}

const (
	lexError = iota
	lexNeedMoreSpace
	lexNeedMoreInput
	lexResume
	lexEnd
	lexNumber1
	lexNumber2
	lexSpace
)

func fill(in *Input, need uint) int {
	// End of input has already been reached, nothing to do.
	if in.eof {
		fmt.Println("fill error: unexpected EOF")
		return lexError
	}

	// Check if after moving the current lexeme to the beginning
	// of buffer there will be enough free space.
	if SIZE-(in.cursor-in.token) < need {
		fmt.Println("fill error: lexeme too long")
		return lexNeedMoreSpace
	}

	// Discard everything up to the start of the current lexeme,
	// shift buffer contents and adjust offsets.
	copy(in.data[0:], in.data[in.token:in.limit])
	in.cursor -= in.token
	in.marker -= in.token
	in.limit -= in.token
	in.token = 0

	// Read new data (as much as possible to fill the buffer).
	n, _ := in.file.Read(in.data[in.limit:SIZE])
	in.limit += uint(n)
	fmt.Printf("fill(%u): %v '%s'\n", need, in.data[:in.limit+1],
		string(in.data[:in.limit]))

	// If read less than expected, this is the end of input.
	in.eof = in.limit < SIZE

	// If end of input, add padding so that the lexer can read
	// the remaining characters at the end of buffer.
	if in.eof {
		for i := uint(0); i < YYMAXFILL; i += 1 {
			in.data[in.limit+i] = 0
		}
		in.limit += YYMAXFILL
	}

	return lexResume
}

func Lex(in *Input) (int, uint) {
	var yych YYCTYPE

	/*!re2c
	re2c:define:YYPEEK = "YYCTYPE(in.data[in.cursor])";
	re2c:define:YYSKIP = "in.cursor += 1";
	re2c:define:YYBACKUP  = "in.marker = in.cursor";
	re2c:define:YYRESTORE = "in.cursor = in.marker";
	re2c:define:YYLESSTHAN = "in.limit-in.cursor < @@";
	re2c:define:YYFILL = "return lexNeedMoreInput, @@";
	re2c:define:YYGETSTATE = "in.state";
	re2c:define:YYSETSTATE = "in.state = @@";

	* {
		fmt.Println("error")
		return lexError, 0
	}

	"\x00" {
		fmt.Println("end")
		return lexEnd, 0
	}

	[0-9]+ {
		fmt.Printf("number-1: %v\n", string(in.data[in.token:in.cursor]))
		return lexNumber1, 0
	}

	[0-9]+ [-] [0-9]+ {
		fmt.Printf("number-2: %v\n", string(in.data[in.token:in.cursor]))
		return lexNumber2, 0
	}

	[ ]+ {
		return lexSpace, 0
	}
	*/
}

func test(data string) int {
	tmpfile := "input.txt"

	f, _ := os.Create(tmpfile)
	f.WriteString(data)
	f.WriteString("\000") // lexer expects NULL-terminator
	f.Seek(0, 0)

	defer func() {
		f.Close()
		os.Remove(tmpfile)
	}()

	in := &Input{
		file:   f,
		data:   make([]byte, SIZE+YYMAXFILL),
		cursor: SIZE,
		marker: SIZE,
		token:  SIZE,
		limit:  SIZE,
		eof:    false,
	}

	need := uint(1)
	result := lexNeedMoreInput
loop:
	for {
		switch result {
		case lexError:
			break loop
		case lexEnd:
			break loop
		case lexNeedMoreInput:
			result = fill(in, need)
			if result != lexResume {
				break loop
			}
		default:
			in.token = in.cursor
			in.state = 0
		}
		result, need = Lex(in)
	}

	return result
}

func main() {
	var s string

	// Succeeds, the lexer has enough characters ahead.
	s = "     123456789      "
	if test(s) != lexEnd {
		panic("expected 'number: 123456789'")
	}

	// Fails, there is no space for the needed characters.
	s = "     1234567890     "
	if test(s) != lexNeedMoreSpace {
		panic("expected 'fill error: lexeme too long'")
	}

	// Succeeds, the lexer has enough characters ahead
	// (although the same lexeme length as the previous case,
	// YYFILL argument is smaller in this state).
	s = "     12345-6789     "
	if test(s) != lexEnd {
		panic("expected 'number: 12345-6789'")
	}

	// Fails, there is no space for any characters.
	s = "     12345-67890     "
	if test(s) != lexNeedMoreSpace {
		panic("expected 'fill error: lexeme too long'")
	}

	// Fails, invalid input.
	s = "?#!*"
	if test(s) != lexError {
		panic("expected 'error'")
	}

	fmt.Println("OK")
}

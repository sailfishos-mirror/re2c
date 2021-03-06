// Code generated by re2c, DO NOT EDIT.
//line "go/reuse/reuse.re":1
//go:generate re2go $INPUT -o $OUTPUT --input-encoding utf8
package main

// This example supports multiple input encodings: UTF-8 and UTF-32.
// Both lexers are generated from the same rules block, and the use
// blocks add only encoding-specific configurations.
//line "go/reuse/reuse.re":16


func lexUTF8(str []uint8) int {
	var cur, mar int
	
//line "go/reuse/reuse.go":16
{
	var yych uint8
	yych = str[cur]
	switch (yych) {
	case 0xE2:
		goto yy3
	default:
		goto yy1
	}
yy1:
	cur += 1
yy2:
//line "go/reuse/reuse.re":15
	{ return 1; }
//line "go/reuse/reuse.go":31
yy3:
	cur += 1
	mar = cur
	yych = str[cur]
	switch (yych) {
	case 0x88:
		goto yy4
	default:
		goto yy2
	}
yy4:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case 0x80:
		goto yy6
	default:
		goto yy5
	}
yy5:
	cur = mar
	goto yy2
yy6:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case 'x':
		goto yy7
	default:
		goto yy5
	}
yy7:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case ' ':
		goto yy8
	default:
		goto yy5
	}
yy8:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case 0xE2:
		goto yy9
	default:
		goto yy5
	}
yy9:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case 0x88:
		goto yy10
	default:
		goto yy5
	}
yy10:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case 0x83:
		goto yy11
	default:
		goto yy5
	}
yy11:
	cur += 1
	yych = str[cur]
	switch (yych) {
	case 'y':
		goto yy12
	default:
		goto yy5
	}
yy12:
	cur += 1
//line "go/reuse/reuse.re":14
	{ return 0; }
//line "go/reuse/reuse.go":112
}
//line "go/reuse/reuse.re":23

}

func lexUTF32(str []uint32) int {
	var cur, mar int
	
//line "go/reuse/reuse.go":121
{
	var yych uint32
	yych = str[cur]
	if (yych == 0x00002200) {
		goto yy15
	}
	cur += 1
yy14:
//line "go/reuse/reuse.re":15
	{ return 1; }
//line "go/reuse/reuse.go":132
yy15:
	cur += 1
	mar = cur
	yych = str[cur]
	if (yych != 'x') {
		goto yy14
	}
	cur += 1
	yych = str[cur]
	if (yych == ' ') {
		goto yy17
	}
yy16:
	cur = mar
	goto yy14
yy17:
	cur += 1
	yych = str[cur]
	if (yych != 0x00002203) {
		goto yy16
	}
	cur += 1
	yych = str[cur]
	if (yych != 'y') {
		goto yy16
	}
	cur += 1
//line "go/reuse/reuse.re":14
	{ return 0; }
//line "go/reuse/reuse.go":162
}
//line "go/reuse/reuse.re":31

}

func main() {
	assert_eq := func(x, y int) { if x != y { panic("error") } }
	assert_eq(lexUTF8([]uint8{0xe2, 0x88, 0x80, 0x78, 0x20, 0xe2, 0x88, 0x83, 0x79}), 0)
	assert_eq(lexUTF32([]uint32{0x2200, 0x78, 0x20, 0x2203, 0x79}), 0)
}

// Code generated by re2go, DO NOT EDIT.
//go:generate re2go $INPUT -o $OUTPUT -ir --input-encoding utf8
package main



func LexUtf8(str string) int {
	var cursor, marker int
	
{
	var yych byte
	yych = str[cursor]
	switch (yych) {
	case 'a':
		goto yy3
	case 0xD0:
		goto yy4
	case 0xD1:
		goto yy5
	case 0xF0:
		goto yy6
	default:
		goto yy1
	}
yy1:
	cursor += 1
yy2:
	{ return 1 }
yy3:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	switch (yych) {
	case 0xD0:
		goto yy7
	default:
		goto yy2
	}
yy4:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	switch (yych) {
	case 0xBE:
		goto yy9
	default:
		goto yy2
	}
yy5:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	switch (yych) {
	case 0x83:
		fallthrough
	case 0x8B:
		fallthrough
	case 0x8D:
		goto yy9
	default:
		goto yy2
	}
yy6:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	switch (yych) {
	case 0x92:
		goto yy10
	default:
		goto yy2
	}
yy7:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0xB3:
		goto yy11
	default:
		goto yy8
	}
yy8:
	cursor = marker
	goto yy2
yy9:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0xD0:
		goto yy7
	default:
		goto yy8
	}
yy10:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0x80:
		goto yy12
	default:
		goto yy8
	}
yy11:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 'a':
		goto yy13
	case 0xD0:
		goto yy14
	case 0xD1:
		goto yy15
	default:
		goto yy8
	}
yy12:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0x94:
		goto yy16
	default:
		goto yy8
	}
yy13:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x00) {
		goto yy17
	}
	goto yy8
yy14:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0xBE:
		goto yy13
	default:
		goto yy8
	}
yy15:
	cursor += 1
	yych = str[cursor]
	switch (yych) {
	case 0x83:
		fallthrough
	case 0x8B:
		fallthrough
	case 0x8D:
		goto yy13
	default:
		goto yy8
	}
yy16:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x00) {
		goto yy18
	}
	goto yy8
yy17:
	cursor += 1
	{ return 0 }
yy18:
	cursor += 1
	{ return 2 }
}

}

func LexUtf16(str []uint16) int {
	var cursor, marker int
	
{
	var yych uint16
	yych = str[cursor]
	if (yych <= 0x0443) {
		if (yych <= 0x043D) {
			if (yych == 'a') {
				goto yy21
			}
		} else {
			if (yych <= 0x043E) {
				goto yy21
			}
			if (yych >= 0x0443) {
				goto yy21
			}
		}
	} else {
		if (yych <= 0x044C) {
			if (yych == 0x044B) {
				goto yy21
			}
		} else {
			if (yych <= 0x044D) {
				goto yy21
			}
			if (yych == 0xD808) {
				goto yy22
			}
		}
	}
	cursor += 1
yy20:
	{ return 1 }
yy21:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	if (yych == 0x0433) {
		goto yy23
	}
	goto yy20
yy22:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	if (yych == 0xDC14) {
		goto yy25
	}
	goto yy20
yy23:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x0442) {
		if (yych <= 'a') {
			if (yych >= 'a') {
				goto yy26
			}
		} else {
			if (yych == 0x043E) {
				goto yy26
			}
		}
	} else {
		if (yych <= 0x044B) {
			if (yych <= 0x0443) {
				goto yy26
			}
			if (yych >= 0x044B) {
				goto yy26
			}
		} else {
			if (yych == 0x044D) {
				goto yy26
			}
		}
	}
yy24:
	cursor = marker
	goto yy20
yy25:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x0000) {
		goto yy27
	}
	goto yy24
yy26:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x0000) {
		goto yy28
	}
	goto yy24
yy27:
	cursor += 1
	{ return 2 }
yy28:
	cursor += 1
	{ return 0 }
}

}

func LexUcs2(str []uint16) int {
	var cursor, marker int
	
{
	var yych uint16
	yych = str[cursor]
	if (yych <= 0x0442) {
		if (yych <= 'a') {
			if (yych >= 'a') {
				goto yy31
			}
		} else {
			if (yych == 0x043E) {
				goto yy31
			}
		}
	} else {
		if (yych <= 0x044B) {
			if (yych <= 0x0443) {
				goto yy31
			}
			if (yych >= 0x044B) {
				goto yy31
			}
		} else {
			if (yych == 0x044D) {
				goto yy31
			}
		}
	}
	cursor += 1
yy30:
	{ return 1 }
yy31:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	if (yych != 0x0433) {
		goto yy30
	}
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x0442) {
		if (yych <= 'a') {
			if (yych >= 'a') {
				goto yy33
			}
		} else {
			if (yych == 0x043E) {
				goto yy33
			}
		}
	} else {
		if (yych <= 0x044B) {
			if (yych <= 0x0443) {
				goto yy33
			}
			if (yych >= 0x044B) {
				goto yy33
			}
		} else {
			if (yych == 0x044D) {
				goto yy33
			}
		}
	}
yy32:
	cursor = marker
	goto yy30
yy33:
	cursor += 1
	yych = str[cursor]
	if (yych >= 0x0001) {
		goto yy32
	}
	cursor += 1
	{ return 0 }
}

}

func LexUtf32(str []uint32) int {
	var cursor, marker int
	
{
	var yych uint32
	yych = str[cursor]
	if (yych <= 0x00000443) {
		if (yych <= 0x0000043D) {
			if (yych == 'a') {
				goto yy36
			}
		} else {
			if (yych <= 0x0000043E) {
				goto yy36
			}
			if (yych >= 0x00000443) {
				goto yy36
			}
		}
	} else {
		if (yych <= 0x0000044C) {
			if (yych == 0x0000044B) {
				goto yy36
			}
		} else {
			if (yych <= 0x0000044D) {
				goto yy36
			}
			if (yych == 0x00012014) {
				goto yy37
			}
		}
	}
	cursor += 1
yy35:
	{ return 1 }
yy36:
	cursor += 1
	marker = cursor
	yych = str[cursor]
	if (yych == 0x00000433) {
		goto yy38
	}
	goto yy35
yy37:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x00000000) {
		goto yy40
	}
	goto yy35
yy38:
	cursor += 1
	yych = str[cursor]
	if (yych <= 0x00000442) {
		if (yych <= 'a') {
			if (yych >= 'a') {
				goto yy41
			}
		} else {
			if (yych == 0x0000043E) {
				goto yy41
			}
		}
	} else {
		if (yych <= 0x0000044B) {
			if (yych <= 0x00000443) {
				goto yy41
			}
			if (yych >= 0x0000044B) {
				goto yy41
			}
		} else {
			if (yych == 0x0000044D) {
				goto yy41
			}
		}
	}
yy39:
	cursor = marker
	goto yy35
yy40:
	cursor += 1
	{ return 2 }
yy41:
	cursor += 1
	yych = str[cursor]
	if (yych >= 0x00000001) {
		goto yy39
	}
	cursor += 1
	{ return 0 }
}

}

func main() {
	if LexUtf8("ыгы\000") != 0 ||
		LexUtf8(string([]byte{0xf0, 0x92, 0x80, 0x94, 0})) != 2 {
		panic("UTF8 failed")
	}
	if LexUtf16([]uint16{0x44b, 0x433, 0x44b, 0}) != 0 ||
		LexUtf16([]uint16{0xd808, 0xdc14, 0}) != 2 {
		panic("UTF16 failed")
	}
	if LexUcs2([]uint16{0x44b, 0x433, 0x44b, 0}) != 0 {
		panic("UCS2 failed")
	}
	if LexUtf32([]uint32{0x44b, 0x433, 0x44b, 0}) != 0 ||
		LexUtf32([]uint32{0x12014, 0}) != 2 {
		panic("UTF32 failed")
	}
}
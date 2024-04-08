/* Generated by re2c */
// re2c $INPUT -o $OUTPUT --recursive-functions -cfi

// getstate (no list), uses global options
void lex(T q) {
	switch (YYGETSTATE()) {
		case -1: return yy0(x);
		case 0: return yy0(x);
		case 1: return yy3(y);
		case 2: return yy7(z);
		case 3: return yy10(z);
		case 4: return yy13(w);
		default: abort();
	}
}


// getstate:z:y, uses z options
// initial case -1 goes to condition dispatch of block z, other cases go directly to YYFILL states
void lex_z(T z) {
	switch (YYGETSTATE()) {
		case -1: return yy6(z);
		case 2: return yy7(z);
		case 3: return yy10(z);
		case 0: return yy0(x);
		default: abort();
	}
}


// block x

void yy0(T x);
void yy1(T x);
void yy2(T x);

void yy0(T x) {
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(0);
		YYFILL(1);
	}
	YYCTYPE yych = *YYCURSOR++;
	switch (yych) {
		case 'x': return yy2(x);
		default: return yy1(x);
	}
}

void yy1(T x) {
	YYSETSTATE(-1);
	*
}

void yy2(T x) {
	YYSETSTATE(-1);
	x
}



// block (no name)

void yy3(T y);
void yy4(T y);
void yy5(T y);

void yy3(T y) {
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(1);
		YYFILL(1);
	}
	YYCTYPE yych = *YYCURSOR++;
	switch (yych) {
		case 'y': return yy5(y);
		default: return yy4(y);
	}
}

void yy4(T y) {
	YYSETSTATE(-1);
	y
}

void yy5(T y) {
	YYSETSTATE(-1);
	y
}



// block z

void yy7(T z);
void yy8(T z);
void yy9(T z);
void yyfnc1(T z);
void yy10(T z);
void yy11(T z);
void yy12(T z);
void yyfnc2(T z);
void yy6(T z);

void yy7(T z) {
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(2);
		YYFILL(1);
	}
	YYCTYPE yych = *YYCURSOR++;
	switch (yych) {
		case 'z': return yy9(z);
		default: return yy8(z);
	}
}

void yy8(T z) {
	YYSETSTATE(-1);
	*
}

void yy9(T z) {
	YYSETSTATE(-1);
	z
}

void yyfnc1(T z) {
	return yy7(z);
}

void yy10(T z) {
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(3);
		YYFILL(1);
	}
	YYCTYPE yych = *YYCURSOR++;
	switch (yych) {
		case 'z': return yy12(z);
		default: return yy11(z);
	}
}

void yy11(T z) {
	YYSETSTATE(-1);
	*
}

void yy12(T z) {
	YYSETSTATE(-1);
	z
}

void yyfnc2(T z) {
	return yy10(z);
}

void yy6(T z) {
	switch (YYGETCONDITION()) {
		case yycc1: return yyfnc1(z);
		case yycc2: return yyfnc2(z);
		default: abort();
	}
}



// block w

void yy13(T w);
void yy14(T w);
void yy15(T w);

void yy13(T w) {
	if (YYLIMIT <= YYCURSOR) {
		YYSETSTATE(4);
		YYFILL(1);
	}
	YYCTYPE yych = *YYCURSOR++;
	switch (yych) {
		case 'w': return yy15(w);
		default: return yy14(w);
	}
}

void yy14(T w) {
	YYSETSTATE(-1);
	*
}

void yy15(T w) {
	YYSETSTATE(-1);
	w
}



// getstate (no list), uses global options
void lex(T q) {
	switch (YYGETSTATE()) {
		case -1: return yy0(x);
		case 0: return yy0(x);
		case 1: return yy3(y);
		case 2: return yy7(z);
		case 3: return yy10(z);
		case 4: return yy13(w);
		default: abort();
	}
}


// getstate:w:z, uses w options
void lex_w(T w) {
	switch (YYGETSTATE()) {
		case -1: return yy13(w);
		case 4: return yy13(w);
		case 2: return yy7(z);
		case 3: return yy10(z);
		default: abort();
	}
}




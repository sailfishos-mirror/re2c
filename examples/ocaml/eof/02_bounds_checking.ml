(* Generated by re2c *)
#1 "ocaml/eof/02_bounds_checking.re"
(* re2ocaml $INPUT -o $OUTPUT *)

exception Fill

type state = {
    buf: string;
    mutable cur: int;
    lim: int;
}

#14 "ocaml/eof/02_bounds_checking.ml"
let yymaxfill = 1
#11 "ocaml/eof/02_bounds_checking.re"


#19 "ocaml/eof/02_bounds_checking.ml"
let rec yy0 (st : state) (count : int) : int =
	if (st.cur + 1 > st.lim) then raise Fill;
	let yych = st.buf.[st.cur] in
	st.cur <- st.cur + 1;
	match yych with
		| '\x00' -> (yy1 [@tailcall]) st count
		| ' ' -> (yy3 [@tailcall]) st count
		| '\'' -> (yy5 [@tailcall]) st count
		| _ -> (yy2 [@tailcall]) st count

and yy1 (st : state) (count : int) : int =
#22 "ocaml/eof/02_bounds_checking.re"
	
        (* check that it is the sentinel, not some unexpected null *)
        if st.cur = String.length st.buf - yymaxfill + 1 then count else -1

#36 "ocaml/eof/02_bounds_checking.ml"

and yy2 (st : state) (count : int) : int =
#28 "ocaml/eof/02_bounds_checking.re"
	-1
#41 "ocaml/eof/02_bounds_checking.ml"

and yy3 (st : state) (count : int) : int =
	if (st.cur + 1 > st.lim) then raise Fill;
	let yych = st.buf.[st.cur] in
	match yych with
		| ' ' ->
			st.cur <- st.cur + 1;
			(yy3 [@tailcall]) st count
		| _ -> (yy4 [@tailcall]) st count

and yy4 (st : state) (count : int) : int =
#27 "ocaml/eof/02_bounds_checking.re"
	lex st count
#55 "ocaml/eof/02_bounds_checking.ml"

and yy5 (st : state) (count : int) : int =
	if (st.cur + 1 > st.lim) then raise Fill;
	let yych = st.buf.[st.cur] in
	st.cur <- st.cur + 1;
	match yych with
		| '\'' -> (yy6 [@tailcall]) st count
		| '\\' -> (yy7 [@tailcall]) st count
		| _ -> (yy5 [@tailcall]) st count

and yy6 (st : state) (count : int) : int =
#26 "ocaml/eof/02_bounds_checking.re"
	lex st (count + 1)
#69 "ocaml/eof/02_bounds_checking.ml"

and yy7 (st : state) (count : int) : int =
	if (st.cur + 1 > st.lim) then raise Fill;
	st.cur <- st.cur + 1;
	(yy5 [@tailcall]) st count

and lex (st : state) (count : int) : int =
	(yy0 [@tailcall]) st count

#29 "ocaml/eof/02_bounds_checking.re"


let test(str, count) =
    let buf = String.cat str (String.make yymaxfill '\x00') in
    let st = {buf = buf; cur = 0; lim = String.length buf} in
    let result = try lex st 0 with Fill -> -1 in
    if not (result = count) then raise (Failure "error")

let main () =
    test("", 0);
    test("'unterminated\\'", -1);
    test("'qu\x00tes' 'are' 'fine: \\'' ", 3);
    test("'unexpected \x00 null", -1)

let _ = main ()
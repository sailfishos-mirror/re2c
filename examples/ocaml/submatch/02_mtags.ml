(* Generated by re2ocaml *)
#1 "ocaml/submatch/02_mtags.re"
(* re2ocaml $INPUT -o $OUTPUT *)

open String

type state = {
    yyinput: string;
    mutable yycursor: int;
    mutable yymarker: int;
    (* Final tag variables available in semantic action. *)
    
#14 "ocaml/submatch/02_mtags.ml"

	mutable t1: int;
	mutable t2: int;
#10 "ocaml/submatch/02_mtags.re"

    
#21 "ocaml/submatch/02_mtags.ml"

	mutable t3: int list;
	mutable t4: int list;
#11 "ocaml/submatch/02_mtags.re"

    (* Intermediate tag variables used by the lexer (must be autogenerated). *)
    
#29 "ocaml/submatch/02_mtags.ml"

	mutable yyt1: int;
	mutable yyt2: int;
#13 "ocaml/submatch/02_mtags.re"

    
#36 "ocaml/submatch/02_mtags.ml"

	mutable yytm3: int list;
	mutable yytm4: int list;
#14 "ocaml/submatch/02_mtags.re"

}

let s2n (str: string) (i1: int) (i2: int) : int =
    let rec f s i j n =
        if i >= j then n else f s (i + 1) j (n * 10 + Char.code s.[i] - 48)
    in f str i1 i2 0


#50 "ocaml/submatch/02_mtags.ml"
let rec yy0 (st : state) : (int list) option =
    let yych = unsafe_get st.yyinput st.yycursor in
    match yych with
        | '0'..'9' ->
            st.yyt1 <- st.yycursor;
            st.yycursor <- st.yycursor + 1;
            (yy3 [@tailcall]) st
        | _ ->
            st.yycursor <- st.yycursor + 1;
            (yy1 [@tailcall]) st

and yy1 (st : state) : (int list) option =
    (yy2 [@tailcall]) st

and yy2 (st : state) : (int list) option =
#37 "ocaml/submatch/02_mtags.re"
    None
#68 "ocaml/submatch/02_mtags.ml"

and yy3 (st : state) : (int list) option =
    st.yymarker <- st.yycursor;
    let yych = unsafe_get st.yyinput st.yycursor in
    match yych with
        | '\x00' ->
            
            
            st.yyt2 <- st.yycursor;
            st.yycursor <- st.yycursor + 1;
            (yy4 [@tailcall]) st
        | '.' ->
            st.yyt2 <- st.yycursor;
            st.yycursor <- st.yycursor + 1;
            (yy5 [@tailcall]) st
        | '0'..'9' ->
            st.yycursor <- st.yycursor + 1;
            (yy7 [@tailcall]) st
        | _ -> (yy2 [@tailcall]) st

and yy4 (st : state) : (int list) option =
    st.t1 <- st.yyt1;
    st.t2 <- st.yyt2;
    st.t3 <- st.yytm3;
    st.t4 <- st.yytm4;
#32 "ocaml/submatch/02_mtags.re"
    
        let x = s2n st.yyinput st.t1 st.t2 in
        let xs = List.rev (List.map2 (fun x y -> s2n st.yyinput x y) st.t3 st.t4) in
        Some (x :: xs)

#100 "ocaml/submatch/02_mtags.ml"

and yy5 (st : state) : (int list) option =
    let yych = unsafe_get st.yyinput st.yycursor in
    match yych with
        | '0'..'9' ->
            st.yytm3 <- st.yycursor :: st.yytm3;
            st.yycursor <- st.yycursor + 1;
            (yy8 [@tailcall]) st
        | _ -> (yy6 [@tailcall]) st

and yy6 (st : state) : (int list) option =
    st.yycursor <- st.yymarker;
    (yy2 [@tailcall]) st

and yy7 (st : state) : (int list) option =
    let yych = unsafe_get st.yyinput st.yycursor in
    match yych with
        | '\x00' ->
            
            
            st.yyt2 <- st.yycursor;
            st.yycursor <- st.yycursor + 1;
            (yy4 [@tailcall]) st
        | '.' ->
            st.yyt2 <- st.yycursor;
            st.yycursor <- st.yycursor + 1;
            (yy5 [@tailcall]) st
        | '0'..'9' ->
            st.yycursor <- st.yycursor + 1;
            (yy7 [@tailcall]) st
        | _ -> (yy6 [@tailcall]) st

and yy8 (st : state) : (int list) option =
    let yych = unsafe_get st.yyinput st.yycursor in
    match yych with
        | '\x00' ->
            st.yytm4 <- st.yycursor :: st.yytm4;
            st.yycursor <- st.yycursor + 1;
            (yy4 [@tailcall]) st
        | '.' ->
            st.yytm4 <- st.yycursor :: st.yytm4;
            st.yycursor <- st.yycursor + 1;
            (yy5 [@tailcall]) st
        | '0'..'9' ->
            st.yycursor <- st.yycursor + 1;
            (yy8 [@tailcall]) st
        | _ -> (yy6 [@tailcall]) st

and parse (st : state) : (int list) option =
    (yy0 [@tailcall]) st

#38 "ocaml/submatch/02_mtags.re"


let test (str: string) (result: (int list) option) =
    let st = {
        yyinput = str;
        yycursor = 0;
        yymarker = 0;
        
#161 "ocaml/submatch/02_mtags.ml"

		t1 = -1;
		t2 = -1;
#45 "ocaml/submatch/02_mtags.re"

        
#168 "ocaml/submatch/02_mtags.ml"

		t3 = [];
		t4 = [];
#46 "ocaml/submatch/02_mtags.re"

        
#175 "ocaml/submatch/02_mtags.ml"

		yyt1 = -1;
		yyt2 = -1;
#47 "ocaml/submatch/02_mtags.re"

        
#182 "ocaml/submatch/02_mtags.ml"

		yytm3 = [];
		yytm4 = [];
#48 "ocaml/submatch/02_mtags.re"

    }
    in if not (parse st = result) then raise (Failure "error")

let main () =
    test "1" (Some [1]);
    test "1.2.3.4.5.6.7" (Some [1; 2; 3; 4; 5; 6; 7;]);
    test "1.2." None

let _ = main ()

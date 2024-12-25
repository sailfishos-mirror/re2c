(* Generated by re2ocaml *)
#1 "ocaml/fill/02_fill.re"
(* re2ocaml $INPUT -o $OUTPUT *)

open Bytes

#8 "ocaml/fill/02_fill.ml"
let yymaxfill = 1
#5 "ocaml/fill/02_fill.re"

let bufsize = 4096

exception Fill

type state = {
    file: in_channel;
    yyinput: bytes;
    mutable yycursor: int;
    mutable yymarker: int;
    mutable yylimit: int;
    mutable token: int;
    mutable eof: bool;
}

type status = Ok | Eof | LongLexeme

let fill (st: state) (need: int) : status =
    if st.eof then Eof else

    (* Error: lexeme too long. In real life could reallocate a larger buffer. *)
    if st.token < need then LongLexeme else (

    (* Shift buffer contents (discard everything up to the current token). *)
    blit st.yyinput st.token st.yyinput 0 (st.yylimit - st.token);
    st.yycursor <- st.yycursor - st.token;
    st.yymarker <- st.yymarker - st.token;
    st.yylimit <- st.yylimit - st.token;
    st.token <- 0;

    (* Fill free space at the end of buffer with new data from file. *)
    let n = input st.file st.yyinput st.yylimit (bufsize - st.yylimit - 1) in (* -1 for sentinel *)
    st.yylimit <- st.yylimit + n;

    (* If read zero characters, this is end of input => add zero padding
       so that the lexer can access characters at the end of buffer. *)
    if n = 0 then
        st.eof <- true; (* end of file *)
        for i = 0 to (yymaxfill - 1) do
            set st.yyinput (st.yylimit + i) '\x00';
            st.yylimit <- st.yylimit + yymaxfill
        done;

    Ok)


#57 "ocaml/fill/02_fill.ml"
let rec yy0 (yyrecord : state) (count : int) : int =
    if (yyrecord.yylimit <= yyrecord.yycursor) then if not (fill yyrecord 1 = Ok) then raise Fill;
    let yych = unsafe_get yyrecord.yyinput yyrecord.yycursor in
    yyrecord.yycursor <- yyrecord.yycursor + 1;
    match yych with
        | '\x00' -> (yy1 [@tailcall]) yyrecord count
        | ' ' -> (yy3 [@tailcall]) yyrecord count
        | '\'' -> (yy5 [@tailcall]) yyrecord count
        | _ -> (yy2 [@tailcall]) yyrecord count

and yy1 (yyrecord : state) (count : int) : int =
#56 "ocaml/fill/02_fill.re"
    
        (* check that it is the sentinel, not some unexpected null *)
        if yyrecord.token = yyrecord.yylimit - yymaxfill then count else -1

#74 "ocaml/fill/02_fill.ml"

and yy2 (yyrecord : state) (count : int) : int =
#62 "ocaml/fill/02_fill.re"
    -1
#79 "ocaml/fill/02_fill.ml"

and yy3 (yyrecord : state) (count : int) : int =
    if (yyrecord.yylimit <= yyrecord.yycursor) then if not (fill yyrecord 1 = Ok) then raise Fill;
    let yych = unsafe_get yyrecord.yyinput yyrecord.yycursor in
    match yych with
        | ' ' ->
            yyrecord.yycursor <- yyrecord.yycursor + 1;
            (yy3 [@tailcall]) yyrecord count
        | _ -> (yy4 [@tailcall]) yyrecord count

and yy4 (yyrecord : state) (count : int) : int =
#61 "ocaml/fill/02_fill.re"
    lex_loop yyrecord count
#93 "ocaml/fill/02_fill.ml"

and yy5 (yyrecord : state) (count : int) : int =
    if (yyrecord.yylimit <= yyrecord.yycursor) then if not (fill yyrecord 1 = Ok) then raise Fill;
    let yych = unsafe_get yyrecord.yyinput yyrecord.yycursor in
    yyrecord.yycursor <- yyrecord.yycursor + 1;
    match yych with
        | '\'' -> (yy6 [@tailcall]) yyrecord count
        | '\\' -> (yy7 [@tailcall]) yyrecord count
        | _ -> (yy5 [@tailcall]) yyrecord count

and yy6 (yyrecord : state) (count : int) : int =
#60 "ocaml/fill/02_fill.re"
    lex_loop yyrecord (count + 1)
#107 "ocaml/fill/02_fill.ml"

and yy7 (yyrecord : state) (count : int) : int =
    if (yyrecord.yylimit <= yyrecord.yycursor) then if not (fill yyrecord 1 = Ok) then raise Fill;
    yyrecord.yycursor <- yyrecord.yycursor + 1;
    (yy5 [@tailcall]) yyrecord count

and lex (yyrecord : state) (count : int) : int =
    (yy0 [@tailcall]) yyrecord count

#63 "ocaml/fill/02_fill.re"


and lex_loop st count =
    st.token <- st.yycursor;
    try lex st count with Fill -> -1

let main () =
    let fname = "input" in

    (* Prepare input file. *)
    Out_channel.with_open_bin fname
        (fun oc -> for i = 1 to bufsize do
            output_string oc "'qu\x00tes' 'are' 'fine: \\'' "
        done);

    (* Run lexer on the prepared file. *)
    In_channel.with_open_bin fname
        (fun ic ->
            let yylimit = bufsize - yymaxfill in
            let st = {
                file = ic;
                yyinput = create bufsize;
                yycursor = yylimit;
                yymarker = yylimit;
                yylimit = yylimit;
                token = yylimit;
                eof = false;
            } in if not (lex_loop st 0 = 3 * bufsize) then
                raise (Failure "error"));

    (* Cleanup. *)
    Sys.remove fname

let _ = main ()

static constexpr const char* DEFAULT_SYNTAX_V =
    "// supported feature lists -----------------------------------------------------\n"
    "\n"
    "supported_apis = [\"simple\", \"generic\", \"record\"];\n"
    "supported_api_styles = [\"free-form\"];\n"
    "supported_code_models = [\"goto-label\", \"loop-switch\", \"recursive-functions\"];\n"
    "supported_targets = [\"code\", \"dot\"];\n"
    "supported_features = [\"nested-ifs\", \"bitmaps\", \"case-ranges\", \"unsafe\",\n"
    "    \"tags\", \"captures\", \"captvars\"];\n"
    "\n"
    "\n"
    "// language-specific options ---------------------------------------------------\n"
    "\n"
    "semicolons = 0;\n"
    "backtick_quoted_strings = 0;\n"
    "single_quoted_strings = 0;\n"
    "indentation_sensitive = 0;\n"
    "wrap_blocks_in_braces = 0;\n"
    "special_escapes = \"\\a\\b\\f\\n\\r\\t\\v\\\\'\\\"\";\n"
    "\n"
    "\n"
    "// immutable configurations (command-line only options) ------------------------\n"
    "\n"
    "re2c:target = code;\n"
    "re2c:code-model = goto-label;\n"
    "re2c:input-encoding = ascii;\n"
    "re2c:date = 1;\n"
    "re2c:version = 1;\n"
    "re2c:conditions = 0;\n"
    "re2c:storable-state = 0;\n"
    "re2c:flex-syntax = 0;\n"
    "re2c:verbose = 0;\n"
    "re2c:line-dirs = 1;\n"
    "\n"
    "\n"
    "// mutable configurations ------------------------------------------------------\n"
    "\n"
    "re2c:api = simple;\n"
    "re2c:api:style = free-form;\n"
    "re2c:api:sigil = \"@@\";\n"
    "re2c:YYGETCOND:naked = 0;\n"
    "re2c:YYSETCOND:naked = 0;\n"
    "re2c:YYSETCOND@cond = \"@@\";\n"
    "re2c:YYGETSTATE:naked = 0;\n"
    "re2c:YYSETSTATE:naked = 0;\n"
    "re2c:YYSETSTATE@state = \"@@\";\n"
    "re2c:YYFILL@len = \"@@\";\n"
    "re2c:YYFILL:naked = 0;\n"
    "re2c:YYFN = [\"<undefined-function-name>;<undefined-function-type>\"];\n"
    "re2c:yyfn:sep = \";\";\n"
    "re2c:yycond = \"yycond\";\n"
    "re2c:yyctable = \"yyctable\";\n"
    "re2c:yyaccept = \"yyaccept\";\n"
    "re2c:yytarget = \"yytarget\";\n"
    "re2c:yystate = \"yystate\";\n"
    "re2c:yynmatch = \"yynmatch\";\n"
    "re2c:yypmatch = \"yypmatch\";\n"
    "re2c:yyrecord = \"yyrecord\";\n"
    "re2c:yych = \"yych\";\n"
    "re2c:yych:conversion = 0;\n"
    "re2c:yych:literals = hex;\n"
    "re2c:yych:emit = (.code_model.recursive_functions ? 0 : 1);\n"
    "re2c:yybm = \"yybm\";\n"
    "re2c:yybm:hex = 0;\n"
    "re2c:yyfill = \"\";\n"
    "re2c:yystable = \"\"; // deprecated\n"
    "re2c:header = \"\";\n"
    "re2c:eof = -1;\n"
    "re2c:sentinel = -1;\n"
    "re2c:yyfill:enable = 1;\n"
    "re2c:yyfill:parameter = 1;\n"
    "re2c:yyfill:check = 1;\n"
    "re2c:tags = 0;\n"
    "re2c:tags:prefix = \"yyt\";\n"
    "re2c:captures = 0;\n"
    "re2c:captvars = 0;\n"
    "re2c:posix-captures = 0;\n"
    "re2c:posix-captvars = 0;\n"
    "re2c:invert-captures = 0;\n"
    "re2c:cond:abort = 0;\n"
    "re2c:cond:prefix = \"yyc_\";\n"
    "re2c:cond:enumprefix = \"yyc\";\n"
    "re2c:cond:divider@cond = \"@@\";\n"
    "re2c:cond:goto@cond = \"@@\";\n"
    "re2c:state:abort = (.code_model.goto_label ? 0 : 1); // historically disabled for goto/label\n"
    "re2c:state:nextlabel = 0;\n"
    "re2c:bit-vectors = 0;\n"
    "re2c:debug-output = 0;\n"
    "re2c:computed-gotos = 0;\n"
    "re2c:computed-gotos:threshold = 9;\n"
    "re2c:nested-ifs = 0;\n"
    "re2c:case-insensitive = 0;\n"
    "re2c:case-inverted = 0;\n"
    "re2c:case-ranges = 1;\n"
    "re2c:unsafe = 0;\n"
    "re2c:monadic = 0;\n"
    "re2c:encoding:ebcdic = 0;\n"
    "re2c:encoding:utf32 = 0;\n"
    "re2c:encoding:ucs2 = 0;\n"
    "re2c:encoding:utf16 = 0;\n"
    "re2c:encoding:utf8 = 0;\n"
    "re2c:encoding-policy = ignore;\n"
    "re2c:empty-class = match-empty;\n"
    "re2c:indent:string = \"    \";\n"
    "re2c:indent:top = 0;\n"
    "re2c:label:prefix = \"yy\";\n"
    "re2c:label:yyfill = \"yyFillLabel\";\n"
    "re2c:label:yyloop = \"yyl\";\n"
    "re2c:label:yyNext = \"yyNext\";\n"
    "re2c:label:start = 0;\n"
    "\n"
    "\n"
    "// mutable code configuration --------------------------------------------------\n"
    "\n"
    "re2c:YYBACKUP = \"yybackup\";\n"
    "re2c:YYBACKUPCTX = \"yybackupctx\";\n"
    "re2c:YYCONDTYPE = \"YYCONDTYPE\";\n"
    "re2c:YYCOPYMTAG = sigil \"{lhs} = \" sigil \"{rhs}\";\n"
    "re2c:YYCOPYSTAG = sigil \"{lhs} = \" sigil \"{rhs}\";\n"
    "re2c:YYCTYPE = \"u8\";\n"
    "re2c:YYCTXMARKER = (.api.record ? yyrecord \".\") \"yyctxmarker\";\n"
    "re2c:YYCURSOR = (.api.record ? yyrecord \".\") \"yycursor\";\n"
    "re2c:YYDEBUG = \"yydebug\";\n"
    "re2c:YYFILL = \"yyfill\";\n"
    "re2c:YYGETACCEPT = sigil \"{var}\";\n"
    "re2c:YYGETCOND = \"yygetcond\";\n"
    "re2c:YYGETSTATE = \"yygetstate\";\n"
    "re2c:YYINPUT = (.api.record ? yyrecord \".\") \"yyinput\";\n"
    "re2c:YYLESSTHAN = \"yylessthan\";\n"
    "re2c:YYLIMIT = (.api.record ? yyrecord \".\") \"yylimit\";\n"
    "re2c:YYMARKER = (.api.record ? yyrecord \".\") \"yymarker\";\n"
    "re2c:YYMAXFILL = \"yymaxfill\";\n"
    "re2c:YYMAXNMATCH = \"yymaxnmatch\";\n"
    "re2c:YYMTAGN = \"yymtagn\";\n"
    "re2c:YYMTAGP = \"yymtagp\";\n"
    "re2c:YYPEEK = \"yypeek\";\n"
    "re2c:YYRESTORE = \"yyrestore\";\n"
    "re2c:YYRESTORECTX = \"yyrestorectx\";\n"
    "re2c:YYRESTORETAG = \"yyrestoretag\";\n"
    "re2c:YYSETACCEPT = sigil \"{var} = \" sigil \"{val}\";\n"
    "re2c:YYSETCOND = \"yysetcond\";\n"
    "re2c:YYSETSTATE = \"yysetstate\";\n"
    "re2c:YYSHIFT = \"yyshift\";\n"
    "re2c:YYSHIFTSTAG = \"yyshiftstag\";\n"
    "re2c:YYSHIFTMTAG = \"yyshiftmtag\";\n"
    "re2c:YYSKIP = \"yyskip\";\n"
    "re2c:YYSTAGN = \"yystagn\";\n"
    "re2c:YYSTAGP = \"yystagp\";\n"
    "re2c:tags:expression = (.api.record ? yyrecord \".\") sigil;\n"
    "re2c:tags:negative = (.api.generic ? \"@@\" : \"-1\");\n"
    "re2c:cond:divider = \"/* *********************************** */\";\n"
    "re2c:cond:goto = \"unsafe { goto \" sigil \" }\";\n"
    "\n"
    "\n"
    "// code templates --------------------------------------------------------------\n"
    "\n"
    "code:var_local = topindent \"mut \" name \" := \" init nl;\n"
    "code:var_global = <undefined>;\n"
    "\n"
    "code:const_local = topindent \"const \" name \" = \" init nl;\n"
    "code:const_global = code:const_local;\n"
    "\n"
    "code:array_local =\n"
    "    topindent name \" := [\" nl indent\n"
    "        [row: topindent [elem{0:-2}: elem \", \"] [elem{-1}: elem \",\"] nl]\n"
    "    dedent topindent \"]\" nl;\n"
    "\n"
    "code:array_global = <undefined>;\n"
    "\n"
    "code:array_elem = array \"[\" index \"]\";\n"
    "\n"
    "// Don't use enum in loop/switch mode, as conditions are assigned to `yystate`.\n"
    "code:enum = (.code_model.loop_switch\n"
    "    ? [elem: \"const \" elem \" = \" init nl]\n"
    "    : \"enum \" type \" {\" nl\n"
    "        indent [elem: topindent elem (.init ? \" = \" init) nl] dedent\n"
    "    \"}\" nl);\n"
    "\n"
    "code:enum_elem = (!.code_model.loop_switch ? \".\") name;\n"
    "\n"
    "code:assign = topindent lhs \" = \" rhs nl;\n"
    "\n"
    "code:type_int = \"int\";\n"
    "code:type_uint = \"u32\";\n"
    "code:type_yybm = \"u8\";\n"
    "code:type_yytarget = <undefined>;\n"
    "\n"
    "code:cmp_eq = \"==\";\n"
    "code:cmp_ne = \"!=\";\n"
    "code:cmp_lt = \"<\";\n"
    "code:cmp_gt = \">\";\n"
    "code:cmp_le = \"<=\";\n"
    "code:cmp_ge = \">=\";\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent \"if \" cond \" {\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent \"} else \" (.cond ? \"if \" cond \" \") \"{\" nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:if_then_else_oneline = <undefined>;\n"
    "\n"
    "code:switch =\n"
    "    topindent \"match \" expr \" {\" nl\n"
    "        indent [case: case] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases = topindent\n"
    "    [case{0:-2}: case \", \"]\n"
    "    [case{-1}:   case \" {\"] nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:switch_cases_oneline = topindent\n"
    "    [case{0:-2}: case \", \"]\n"
    "    [case{-1}:   case \" { \"] [stmt: stmt] \" }\" nl;\n"
    "\n"
    "code:switch_case_range = [val{0}: val] (.many ? \"...\" [val{-1}: val]);\n"
    "\n"
    "code:switch_case_default = \"else\";\n"
    "\n"
    "code:loop =\n"
    "    (.loop_label ? label \":\" nl)\n"
    "    topindent \"for {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    topindent \"}\" nl;\n"
    "\n"
    "code:continue = topindent \"continue\" (.loop_label ? \" \" label) nl;\n"
    "\n"
    "code:goto = topindent \"unsafe { goto \" label \" }\" nl;\n"
    "\n"
    "code:fndecl = <undefined>;\n"
    "\n"
    "code:fndef =\n"
    "    topindent \"fn \" name \"(\"\n"
    "        [arg{0:-2}: argname \" \" argtype \", \"]\n"
    "        [arg{-1}:   argname \" \" argtype]\n"
    "    \")\" (.type ? \" \" type) \" {\" nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    \"}\" nl;\n"
    "\n"
    "code:fncall =\n"
    "    topindent (.retval ? retval \" = \") name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:tailcall =\n"
    "    topindent (.retval ? \"return \") name \"(\" [arg{0:-2}: arg \", \"] [arg{-1}: arg] \")\" nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint =\n"
    "    \"// Code generated by re2v\" (.version ? \" \" version) (.date ? \" on \" date) \", DO NOT EDIT.\" nl;\n"
    "\n"
    "code:line_info = \"//line \\\"\" file \"\\\":\" line nl;\n"
    "\n"
    "code:abort = topindent \"panic(\\\"internal lexer error\\\")\" nl;\n"
    "\n"
    "code:yydebug =\n"
    "    topindent (.api.generic\n"
    "        ? YYDEBUG (.api_style.functions ? \"()\")\n"
    "    : (.api.record\n"
    "        ? YYDEBUG \"(\" yyrecord \")\"\n"
    "        : YYDEBUG \"(\" state \", \" yych \")\"\n"
    "    )) nl;\n"
    "\n"
    "code:yypeek =\n"
    "    topindent yych (.code_model.recursive_functions ? \" := \" : \" = \") (.api.generic\n"
    "        ? YYPEEK\n"
    "        : YYINPUT \"[\" YYCURSOR \"]\"\n"
    "    ) nl;\n"
    "\n"
    "code:yyskip =\n"
    "    topindent (.api.generic\n"
    "        ? YYSKIP\n"
    "        : YYCURSOR \" += 1\"\n"
    "    ) nl;\n"
    "\n"
    "code:yybackup =\n"
    "    topindent (.api.generic\n"
    "        ? YYBACKUP\n"
    "        : YYMARKER \" = \" YYCURSOR\n"
    "    ) nl;\n"
    "\n"
    "code:yybackupctx =\n"
    "    topindent (.api.generic\n"
    "        ? YYBACKUPCTX\n"
    "        : YYCTXMARKER \" = \" YYCURSOR\n"
    "    ) nl;\n"
    "\n"
    "code:yyskip_yypeek = <undefined>;\n"
    "code:yypeek_yyskip = <undefined>;\n"
    "code:yyskip_yybackup = <undefined>;\n"
    "code:yybackup_yyskip = <undefined>;\n"
    "code:yybackup_yypeek = <undefined>;\n"
    "code:yyskip_yybackup_yypeek = <undefined>;\n"
    "code:yybackup_yypeek_yyskip = <undefined>;\n"
    "\n"
    "code:yyrestore =\n"
    "    topindent (.api.generic\n"
    "        ? YYRESTORE\n"
    "        : YYCURSOR \" = \" YYMARKER\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestorectx =\n"
    "    topindent (.api.generic\n"
    "        ? YYRESTORECTX\n"
    "        : YYCURSOR \" = \" YYCTXMARKER\n"
    "    ) nl;\n"
    "\n"
    "code:yyrestoretag =\n"
    "    topindent (.api.generic\n"
    "        ? YYRESTORETAG\n"
    "        : YYCURSOR \" = \" tag\n"
    "    ) nl;\n"
    "\n"
    "code:yyshift =\n"
    "    topindent (.api.generic\n"
    "        ? YYSHIFT\n"
    "        : YYCURSOR \" -= \" offset\n"
    "    ) nl;\n"
    "\n"
    "code:yyshiftstag =\n"
    "    (.nested ? topindent \"if \" tag \" != \" neg \" {\" nl indent)\n"
    "        topindent (.api.generic\n"
    "            ? YYSHIFTSTAG\n"
    "            : tag \"-= \" offset\n"
    "        ) nl\n"
    "    (.nested ? dedent topindent \"}\" nl);\n"
    "\n"
    "code:yyshiftmtag =\n"
    "    topindent YYSHIFTMTAG nl;\n"
    "\n"
    "code:yystagp =\n"
    "    topindent (.api.generic\n"
    "        ? YYSTAGP\n"
    "        : tag \" = \" YYCURSOR\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagp =\n"
    "    topindent YYMTAGP nl;\n"
    "\n"
    "code:yystagn =\n"
    "    topindent (.api.generic\n"
    "        ? YYSTAGN\n"
    "        : tag \" = \" neg\n"
    "    ) nl;\n"
    "\n"
    "code:yymtagn =\n"
    "    topindent YYMTAGN nl;\n"
    "\n"
    "code:yycopystag =\n"
    "    topindent (.api.generic\n"
    "        ? YYCOPYSTAG\n"
    "        : lhs \" = \" rhs\n"
    "    ) nl;\n"
    "\n"
    "code:yycopymtag =\n"
    "    topindent (.api.generic\n"
    "        ? YYCOPYMTAG\n"
    "        : lhs \" = \" rhs\n"
    "    ) nl;\n"
    "\n"
    "code:yygetaccept =\n"
    "    (.api.generic\n"
    "        ? YYGETACCEPT\n"
    "        : (.api.record & (.storable_state | .code_model.recursive_functions) ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetaccept =\n"
    "    topindent (.api.generic\n"
    "        ? YYSETACCEPT\n"
    "        : (.api.record & (.storable_state | .code_model.recursive_functions) ? yyrecord \".\")\n"
    "             var \" = \" val\n"
    "    ) nl;\n"
    "\n"
    "code:yygetcond =\n"
    "    (.api.generic\n"
    "        ? YYGETCOND\n"
    "        : (.api.record ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetcond =\n"
    "    topindent (.api.generic\n"
    "        ? YYSETCOND\n"
    "        : (.api.record ? yyrecord \".\") var \" = \" val\n"
    "    ) nl;\n"
    "\n"
    "code:yygetstate =\n"
    "    (.api.generic\n"
    "        ? YYGETSTATE\n"
    "        : (.api.record ? yyrecord \".\") var);\n"
    "\n"
    "code:yysetstate =\n"
    "    topindent (.api.generic\n"
    "        ? YYSETSTATE\n"
    "        : (.api.record ? yyrecord \".\") var \" = \" val\n"
    "    ) nl;\n"
    "\n"
    "code:yylessthan =\n"
    "    (.api.generic\n"
    "        ? YYLESSTHAN\n"
    "        : (.many\n"
    "            ? \"(\" YYLIMIT \" - \" YYCURSOR \") < \" need\n"
    "            : YYLIMIT \" <= \" YYCURSOR));\n"
    "\n"
    "code:yybm_filter = yych \" & ~0xFF\";\n"
    "\n"
    "code:yybm_match = \"(\" yybm \"[\" offset \"+\" yych \"] & \" mask \") != 0\";\n"
    ;

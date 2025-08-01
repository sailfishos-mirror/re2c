extern const char* help;
const char* help =
"USAGE\n"
"\n"
"    re2hs [ OPTIONS ] [ WARNINGS ] INPUT\n"
"\n"
"    Input can be either a file or - for stdin.\n"
"\n"
"OPTIONS\n"
"\n"
"    -? --help -h\n"
"\n"
"        Show help message.\n"
"\n"
"    --api <simple | record | generic>\n"
"\n"
"        Specify the API used by the generated code to interface with used-\n"
"        defined code. Option simple shold be used in simple cases when there's\n"
"        no need for buffer refilling and storing lexer state. Option record\n"
"        should be used when lexer state needs to be stored in a record (struct,\n"
"        class, etc.). Option generic should be used in complex cases when the\n"
"        other two APIs are not flexible enough.\n"
"\n"
"    --bit-vectors -b\n"
"\n"
"        Optimize conditional jumps using bit masks. This option implies\n"
"        --nested-ifs.\n"
"\n"
"    --captures, --leftmost-captures\n"
"\n"
"        Enable submatch extraction with leftmost greedy capturing groups. The\n"
"        result is collected into an array yybmatch of capacity 2 * YYMAXNMATCH,\n"
"        and yynmatch is set to the number of groups for the matching rule.\n"
"\n"
"    --captvars, --leftmost-captvars\n"
"\n"
"        Enable submatch extraction with leftmost greedy capturing groups. The\n"
"        result is collected into variables yytl<k>, yytr<k> for k-th capturing\n"
"        group.\n"
"\n"
"    --case-insensitive\n"
"\n"
"        Treat single-quoted and double-quoted strings as case-insensitive.\n"
"\n"
"    --case-inverted\n"
"\n"
"        Invert the meaning of single-quoted and double-quoted strings: treat\n"
"        single-quoted strings as case-sensitive and double-quoted strings as\n"
"        case-insensitive.\n"
"\n"
"    --case-ranges\n"
"\n"
"        Collapse consecutive cases in a switch statements into a range of the\n"
"        form low ... high. This syntax is a C/C++ language extension that is\n"
"        supported by compilers like GCC, Clang and Tcc. The main advantage over\n"
"        using single cases is smaller generated code and faster generation\n"
"        time, although for some compilers like Tcc it also results in smaller\n"
"        binary size.\n"
"\n"
"    --computed-gotos -g\n"
"\n"
"        Optimize conditional jumps using non-standard \"computed goto\" extension\n"
"        (which must be supported by the compiler). re2hs generates jump tables\n"
"        only in complex cases with a lot of conditional branches. Complexity\n"
"        threshold can be configured with cgoto:threshold configuration.\n"
"        Relative offsets can be enabled with cgoto:relative configuration. This\n"
"        option implies --bit-vectors.\n"
"\n"
"    --computed-gotos-relative\n"
"\n"
"        Similar to --computed-gotos but generate relative offsets for jump\n"
"        tables instead (which must be supported by the compiler). This option\n"
"        implies --computed-gotos.\n"
"\n"
"    --conditions --start-conditions -c\n"
"\n"
"        Enable support of Flex-like \"conditions\": multiple interrelated lexers\n"
"        within one block. This is an alternative to manually specifying\n"
"        different re2hs blocks connected with goto or function calls.\n"
"\n"
"    --depfile FILE\n"
"\n"
"        Write dependency information to FILE in the form of a Makefile rule\n"
"        <output-file> : <input-file> [include-file ...]. This allows one to\n"
"        track build dependencies in the presence of include blocks/directives,\n"
"        so that updating include files triggers regeneration of the output\n"
"        file. This option depends on the --output option.\n"
"\n"
"    --ebcdic --ecb -e\n"
"\n"
"        Generate a lexer that reads input in EBCDIC encoding. re2hs assumes\n"
"        that the character range is 0 -- 0xFF and character size is 1 byte.\n"
"\n"
"    --empty-class <match-empty | match-none | error>\n"
"\n"
"        Define the way re2hs treats empty character classes. With match-empty\n"
"        (the default) empty class matches empty input (which is illogical, but\n"
"        backwards-compatible). With match-none empty class always fails to\n"
"        match. With error empty class raises a compilation error.\n"
"\n"
"    --encoding-policy <fail | substitute | ignore>\n"
"\n"
"        Define the way re2hs treats Unicode surrogates. With fail re2hs aborts\n"
"        with an error when a surrogate is encountered. With substitute re2hs\n"
"        silently replaces surrogates with the error code point 0xFFFD. With\n"
"        ignore (the default) re2hs treats surrogates as normal code points. The\n"
"        Unicode standard says that standalone surrogates are invalid, but real-\n"
"        world libraries and programs behave in different ways.\n"
"\n"
"    --flex-syntax -F\n"
"\n"
"        Partial support for Flex syntax: in this mode named definitions don't\n"
"        need the equal sign and the terminating semicolon, and when used they\n"
"        must be surrounded with curly braces. Names without curly braces are\n"
"        treated as double-quoted strings.\n"
"\n"
"    --goto-label\n"
"\n"
"        Use \"goto/label\" code model: encode DFA in form of labeled code blocks\n"
"        connected with goto transitions across blocks. This is only supported\n"
"        for languages that have a goto statement.\n"
"\n"
"    --header --type-header -t HEADER\n"
"\n"
"        Generate a HEADER file. The contents of the file can be specified using\n"
"        special blocks header:on and header:off. If conditions are used, the\n"
"        generated header will have a condition enum automatically appended to\n"
"        it (unless there is an explicit conditions block).\n"
"\n"
"    -I PATH\n"
"\n"
"        Add PATH to the list of locations which are used when searching for\n"
"        include files. This option is useful in combination with include block\n"
"        or directive. re2hs looks for FILE in the directory of the parent file\n"
"        and in the include locations specified with -I option.\n"
"\n"
"    --input <default | custom>\n"
"\n"
"        Deprecated alias for --api. Option default corresponds to simple (it is\n"
"        indeed the default for most backends, but not for all). Option custom\n"
"        corresponds to generic.\n"
"\n"
"    --input-encoding <ascii | utf8>\n"
"\n"
"        Specify the way re2hs parses regular expressions. With ascii (the\n"
"        default) re2hs handles input as ASCII-encoded: any sequence of code\n"
"        units is a sequence of standalone 1-byte characters. With utf8 re2hs\n"
"        handles input as UTF8-encoded and recognizes multibyte characters.\n"
"\n"
"    --invert-captures\n"
"\n"
"        Invert the meaning of capturing and non-capturing groups. By default\n"
"        (...) is capturing and (! ...) is non-capturing. With this option (!\n"
"        ...) is capturing and (...) is non-capturing.\n"
"\n"
"    --lang <none | c | d | go | haskell | java | js | ocaml | python | rust |\n"
"    swift | v | zig>\n"
"\n"
"        Specify the target language. Supported languages are C, D, Go, Haskell,\n"
"        Java, JS, OCaml, Python, Rust, Swift, V, Zig (more languages can be\n"
"        added via user-defined syntax files, see the --syntax option). Option\n"
"        none disables default suntax configs, so that the target language is\n"
"        undefined.\n"
"\n"
"    --location-format <gnu | msvc>\n"
"\n"
"        Specify location format in messages. With gnu locations are printed as\n"
"        'filename:line:column: ...'. With msvc locations are printed as\n"
"        'filename(line,column) ...'. The default is gnu.\n"
"\n"
"    --loop-switch\n"
"\n"
"        Use \"loop/switch\" code model: encode DFA in form of a loop over a\n"
"        switch statement, where individual states are switch cases. State is\n"
"        stored in a variable yystate. Transitions between states update yystate\n"
"        to the case label of the destination state and continue execution to\n"
"        the head of the loop.\n"
"\n"
"    --nested-ifs -s\n"
"\n"
"        Use nested if statements instead of switch statements in conditional\n"
"        jumps. This usually results in more efficient code with non-optimizing\n"
"        compilers.\n"
"\n"
"    --no-debug-info -i\n"
"\n"
"        Do not output line directives. This may be useful when the generated\n"
"        code is stored in a version control system (to avoid huge autogenerated\n"
"        diffs on small changes).\n"
"\n"
"    --no-generation-date\n"
"\n"
"        Suppress date output in the generated file.\n"
"\n"
"    --no-version\n"
"\n"
"        Suppress version output in the generated file.\n"
"\n"
"    --no-unsafe\n"
"\n"
"        Do not generate unsafe wrapper over YYPEEK (this option is specific to\n"
"        Rust). For performance reasons YYPEEK should avoid bounds-checking, as\n"
"        the lexer already performs end-of-input checks in a more efficient way.\n"
"        The user may choose to provide a safe YYPEEK definition, or a\n"
"        definition that is unsafe only in release builds, in which case the\n"
"        --no-unsafe option helps to avoid warnings about redundant unsafe\n"
"        blocks.\n"
"\n"
"    --output -o OUTPUT\n"
"\n"
"        Specify the OUTPUT file.\n"
"\n"
"    --posix-captures, -P\n"
"\n"
"        Enable submatch extraction with POSIX-style capturing groups. The\n"
"        result is collected into an array yybmatch of capacity 2 * YYMAXNMATCH,\n"
"        and yynmatch is set to the number of groups for the matching rule.\n"
"\n"
"    --posix-captvars\n"
"\n"
"        Enable submatch extraction with POSIX-style capturing groups. The\n"
"        result is collected into variables yytl<k>, yytr<k> for k-th capturing\n"
"        group.\n"
"\n"
"    --recursive-functions\n"
"\n"
"        Use code model based on co-recursive functions, where each DFA state is\n"
"        a separate function that may call other state-functions or itself.\n"
"\n"
"    --reusable -r\n"
"\n"
"        Deprecated since version 2.2 (reusable blocks are allowed by default\n"
"        now).\n"
"\n"
"    --skeleton -S\n"
"\n"
"        Ignore user-defined interface code and generate a self-contained\n"
"        \"skeleton\" program. Additionally, generate input files with strings\n"
"        derived from the regular grammar and compressed match results that are\n"
"        used to verify \"skeleton\" behavior on all inputs. This option is useful\n"
"        for finding bugs in optimizations and code generation. This option is\n"
"        supported only for C.\n"
"\n"
"    --storable-state -f\n"
"\n"
"        Generate a lexer which can store its inner state. This is useful in\n"
"        push-model lexers which are stopped by an outer program when there is\n"
"        not enough input, and then resumed when more input becomes available.\n"
"        In this mode users should additionally define YYGETSTATE and YYSETSTATE\n"
"        primitives, and variables yych, yyaccept and state should be part of\n"
"        the stored lexer state.\n"
"\n"
"    --syntax FILE\n"
"\n"
"        Load configurations from the specified FILE and apply them on top of\n"
"        the default syntax file. Note that FILE can define only a few\n"
"        configurations (if it's used to amend the default syntax file), or it\n"
"        can define a whole new language backend (in the latter case it is\n"
"        recommended to use --lang none option).\n"
"\n"
"    --tags -T\n"
"\n"
"        Enable submatch extraction with tags.\n"
"\n"
"    --ucs2 --wide-chars -w\n"
"\n"
"        Generate a lexer that reads UCS2-encoded input. re2hs assumes that the\n"
"        character range is 0 -- 0xFFFF and character size is 2 bytes. This\n"
"        option implies --nested-ifs.\n"
"\n"
"    --utf8 --utf-8 -8\n"
"\n"
"        Generate a lexer that reads input in UTF-8 encoding. re2hs assumes that\n"
"        the character range is 0 -- 0x10FFFF and character size is 1 byte.\n"
"\n"
"    --utf16 --utf-16 -x\n"
"\n"
"        Generate a lexer that reads UTF16-encoded input. re2hs assumes that the\n"
"        character range is 0 -- 0x10FFFF and character size is 2 bytes. This\n"
"        option implies --nested-ifs.\n"
"\n"
"    --utf32 --unicode -u\n"
"\n"
"        Generate a lexer that reads UTF32-encoded input. re2hs assumes that the\n"
"        character range is 0 -- 0x10FFFF and character size is 4 bytes. This\n"
"        option implies --nested-ifs.\n"
"\n"
"    --verbose\n"
"\n"
"        Output a short message in case of success.\n"
"\n"
"    --vernum -V\n"
"\n"
"        Show version information in MMmmpp format (major, minor, patch).\n"
"\n"
"    --version -v\n"
"\n"
"        Show version information.\n"
"\n"
"    --single-pass -1\n"
"\n"
"        Deprecated. Does nothing (single pass is the default now).\n"
"\n"
"    --debug-output -d\n"
"\n"
"        Emit YYDEBUG invocations in the generated code. This is useful to trace\n"
"        lexer execution.\n"
"\n"
"    --dump-adfa\n"
"\n"
"        Debug option: output DFA after tunneling (in .dot format).\n"
"\n"
"    --dump-cfg\n"
"\n"
"        Debug option: output control flow graph of tag variables (in .dot\n"
"        format).\n"
"\n"
"    --dump-closure-stats\n"
"\n"
"        Debug option: output statistics on the number of states in closure.\n"
"\n"
"    --dump-dfa-det\n"
"\n"
"        Debug option: output DFA immediately after determinization (in .dot\n"
"        format).\n"
"\n"
"    --dump-dfa-min\n"
"\n"
"        Debug option: output DFA after minimization (in .dot format).\n"
"\n"
"    --dump-dfa-tagopt\n"
"\n"
"        Debug option: output DFA after tag optimizations (in .dot format).\n"
"\n"
"    --dump-dfa-tree\n"
"\n"
"        Debug option: output DFA under construction with states represented as\n"
"        tag history trees (in .dot format).\n"
"\n"
"    --dump-dfa-raw\n"
"\n"
"        Debug option: output DFA under construction with expanded state-sets\n"
"        (in .dot format).\n"
"\n"
"    --dump-interf\n"
"\n"
"        Debug option: output interference table produced by liveness analysis\n"
"        of tag variables.\n"
"\n"
"    --dump-nfa\n"
"\n"
"        Debug option: output NFA (in .dot format).\n"
"\n"
"    --emit-dot -D\n"
"\n"
"        Instead of normal output generate lexer graph in .dot format. The\n"
"        output can be converted to an image with the help of Graphviz (e.g.\n"
"        something like dot -Tpng -odfa.png dfa.dot).\n"
"\n"
"    --dfa-minimization <moore | table>\n"
"\n"
"        Internal option: DFA minimization algorithm used by re2hs. The moore\n"
"        option is the Moore algorithm (it is the default). The table option is\n"
"        the \"table filling\" algorithm. Both algorithms should produce the same\n"
"        DFA up to states relabeling; table filling is simpler and much slower\n"
"        and serves as a reference implementation.\n"
"\n"
"    --eager-skip\n"
"\n"
"        Internal option: make the generated lexer advance the input position\n"
"        eagerly -- immediately after reading the input symbol. This changes the\n"
"        default behavior when the input position is advanced lazily -- after\n"
"        transition to the next state.\n"
"\n"
"    --no-lookahead\n"
"\n"
"        Internal option, deprecated. It used to enable TDFA(0) algorithm.\n"
"        Unlike TDFA(1), TDFA(0) algorithm does not use one-symbol lookahead. It\n"
"        applies register operations to the incoming transitions rather than the\n"
"        outgoing ones. Benchmarks showed that TDFA(0) algorithm is less\n"
"        efficient than TDFA(1).\n"
"\n"
"    --no-optimize-tags\n"
"\n"
"        Internal option: suppress optimization of tag variables (useful for\n"
"        debugging).\n"
"\n"
"    --posix-closure <gor1 | gtop>\n"
"\n"
"        Internal option: specify shortest-path algorithm used for the\n"
"        construction of epsilon-closure with POSIX disambiguation semantics:\n"
"        gor1 (the default) stands for Goldberg-Radzik algorithm, and gtop\n"
"        stands for \"global topological order\" algorithm.\n"
"\n"
"    --posix-prectable <complex | naive>\n"
"\n"
"        Internal option: specify the algorithm used to compute POSIX precedence\n"
"        table. The complex algorithm computes precedence table in one traversal\n"
"        of tag history tree and has quadratic complexity in the number of TNFA\n"
"        states; it is the default. The naive algorithm has worst-case cubic\n"
"        complexity in the number of TNFA states, but it is much simpler than\n"
"        complex and may be slightly faster in non-pathological cases.\n"
"\n"
"    --stadfa\n"
"\n"
"        Internal option, deprecated. It used to enable staDFA algorithm, which\n"
"        differs from TDFA in that register operations are placed in states\n"
"        rather than on transitions. Benchmarks showed that staDFA algorithm is\n"
"        less efficient than TDFA.\n"
"\n"
"    --fixed-tags <none | toplevel | all>\n"
"\n"
"        Internal option: specify whether the fixed-tag optimization should be\n"
"        applied to all tags (all), none of them (none), or only those in\n"
"        toplevel concatenation (toplevel). The default is all. \"Fixed\" tags are\n"
"        those that are located within a fixed distance to some other tag\n"
"        (called \"base\"). In such cases only the base tag needs to be tracked,\n"
"        and the value of the fixed tag can be computed as the value of the base\n"
"        tag plus a static offset. For tags that are under alternative or\n"
"        repetition it is also necessary to check if the base tag has a no-match\n"
"        value (in that case fixed tag should also be set to no-match,\n"
"        disregarding the offset). For tags in top-level concatenation the check\n"
"        is not needed, because they always match.\n"
"\n"
"WARNINGS\n"
"\n"
"    -W\n"
"\n"
"        Turn on all warnings.\n"
"\n"
"    -Werror\n"
"\n"
"        Turn warnings into errors. Note that this option alone doesn't turn on\n"
"        any warnings; it only affects those warnings that have been turned on\n"
"        so far or will be turned on later.\n"
"\n"
"    -W<warning>\n"
"\n"
"        Turn on warning.\n"
"\n"
"    -Wno-<warning>\n"
"\n"
"        Turn off warning.\n"
"\n"
"    -Werror-<warning>\n"
"\n"
"        Turn on warning and treat it as an error (this implies -W<warning>).\n"
"\n"
"    -Wno-error-<warning>\n"
"\n"
"        Don't treat this particular warning as an error. This doesn't turn off\n"
"        the warning itself.\n"
"\n"
"    -Wcondition-order\n"
"\n"
"        Warn if the generated program makes implicit assumptions about\n"
"        condition numbering. One should use either --header option or\n"
"        conditions block to generate a mapping of condition names to numbers\n"
"        and then use the autogenerated condition names.\n"
"\n"
"    -Wempty-character-class\n"
"\n"
"        Warn if a regular expression contains an empty character class. Trying\n"
"        to match an empty character class makes no sense: it should always\n"
"        fail. However, for backwards compatibility reasons re2hs permits empty\n"
"        character classes and treats them as empty strings. Use the --empty-\n"
"        class option to change the default behavior.\n"
"\n"
"    -Wmatch-empty-string\n"
"\n"
"        Warn if a rule is nullable (matches an empty string). If the lexer runs\n"
"        in a loop and the empty match is unintentional, the lexer may\n"
"        unexpectedly hang in an infinite loop.\n"
"\n"
"    -Wswapped-range\n"
"\n"
"        Warn if the lower bound of a range is greater than its upper bound. The\n"
"        default behavior is to silently swap the range bounds.\n"
"\n"
"    -Wundefined-control-flow\n"
"\n"
"        Warn if some input strings cause undefined control flow in the lexer\n"
"        (the faulty patterns are reported). This is a dangerous and common\n"
"        mistake. It can be easily fixed by adding the default rule * which has\n"
"        the lowest priority, matches any code unit, and always consumes a\n"
"        single code unit.\n"
"\n"
"    -Wunreachable-rules\n"
"\n"
"        Warn about rules that are shadowed by other rules and will never match.\n"
"\n"
"    -Wdeprecated-eof_rule\n"
"\n"
"        Warn about standalone end of input rules $ that will be broken by the\n"
"        future changes and require fixing. At the moment these rules take\n"
"        precedence when conflicting with other rules, but after the\n"
"        introduction of generalized end of input symbol $ precedence order will\n"
"        change and these rules will become shadowed by other rules.\n"
"\n"
"    -Wuseless-escape\n"
"\n"
"        Warn if a symbol is escaped when it shouldn't be. By default, re2hs\n"
"        silently ignores such escapes, but this may as well indicate a typo or\n"
"        an error in the escape sequence.\n"
"\n"
"    -Wnondeterministic-tags\n"
"\n"
"        Warn if a tag has n-th degree of nondeterminism, where n is greater\n"
"        than 1.\n"
"\n"
"    -Wsentinel-in-midrule\n"
"\n"
"        Warn if the sentinel symbol occurs in the middle of a rule --- this may\n"
"        cause reads past the end of buffer, crashes or memory corruption in the\n"
"        generated lexer. This warning is only applicable if the sentinel method\n"
"        of checking for the end of input is used. It is set to an error if\n"
"        re2c:sentinel configuration is used.\n"
"\n"
"    -Wundefined-syntax-config\n"
"\n"
"        Warn if the syntax file specified with --syntax option is missing\n"
"        definitions of some configurations. This helps to maintain user-defined\n"
"        syntax files: if a new release adds configurations, old syntax file\n"
"        will raise a warning, and the user will be notified. If some\n"
"        configurations are unused and do not need a definition, they should be\n"
"        explicitly set to <undefined>.\n"
;

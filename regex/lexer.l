%option noyywrap
%{
    #include <iostream>
    #include <cstdlib>

    #include "regex.hpp"
    #include "parser.tab.hpp"
    
%}


%%

"BASIC"         { return basic_token; }

"DEFINITION"    { return definition_token; }

[a-z] {
    yylval.c = *yytext;
    return char_token;
}

[A-Z] {
    yylval.c = *yytext;
    return regex_token;
}

[\n+*?|\[\](){}=] { return *yytext; }

[0-9] {
    yylval.d = atoi(yytext);
    return num_token;
}

[ \t\.] { }

. {
    std::cerr << "Leksicka greska, neocekivano na ulazu: " << *yytext;
    exit(EXIT_FAILURE);
}



%%

// a*.b+.c.d.e{3}|a+.b?.c.d|[abcde]|(a.b)*.[cde]?

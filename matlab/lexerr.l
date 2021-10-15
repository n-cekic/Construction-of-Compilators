%option noyywrap
%option nounput
%{

// #include <string>
// #include <cstdlib>
#include <iostream>
// #include <vector>
#include "matrix.hpp"
#include "parser.tab.hpp"


%}

%%
[a-zA-Z_][a-zA-Z_0-9]* {
    yylval.s = new std::string(yytext);
    return id_token;
}

[0-9]+(\.[0-9]*)? { 
    yylval.d = std::atof(yytext);
    return num_token;
}

[+\-*/\[\]\.=;'\n] { return *yytext; }

[ \t] { }
. {
    std::cerr << "Leksicka greska: neocekivan karakter: " << *yytext << std::endl;
    exit(EXIT_FAILURE);
}


%%
%option noyywrap
%{
#include <iostream>
#include <cstdlib>

#include "polinomi.hpp"
#include "parser.tab.hpp"

%}

%%

-?[0-9]+(\.[0-9]+)? { 
    yylval.d = atof(yytext);
    return num_token; 
}

[-+=*<>!\[\]:()',\n] { return *yytext; }

[a-z]+[0-9]+ { 
    yylval.s = new std::string(yytext);
    return id_token; 
}

[ \t] {}

. { std::cerr << "neocekivano na ulazu " << *yytext << std::endl;}

%%
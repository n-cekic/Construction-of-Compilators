%option noyywrap
%option nounput
%{
#include <cstdio>
#include <cstdlib>
#include <string>
#include "function.hpp"

using namespace std;

/* Ukljucujemo zaglavlje u kome su definisani tokeni */
#include "function.tab.hpp"

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
value                        { return value_token; }
sin                          { return sin_token; }
cos                          { return cos_token; }
function                     { return function_token; }
[a-wy-zA-Z]                  { yylval.c = *yytext; return id_token; }
{DIGIT}+(\.{DIGIT}*)?        {
                                 /* Postavljamo atribut tokena na procitanu vrednost
                                  * ali sada je yylval unija, pa moramo reci koje polje unije postavljamo
                                  */
                                 yylval.d = atof(yytext);
                                 return num_token;
                              }
[+\-*/();\n"=x\[\]']          {  return *yytext; }
[ \t]                         { }
.                             {
                                 fprintf(stderr, "Leksicka greska: Nepoznat karakter %c\n", *yytext);
                                 exit(EXIT_FAILURE);
                               }

%%
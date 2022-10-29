
%{
#include "bex3.tab.h"
#include <stdio.h>
#include <ctype.h> // tolower
%}

%option nounput
%option noyywrap

NUM1 ([12]?[0-9])
NUM2 ([3][0-2])

%%

[[:alpha:]] {
    yylval = tolower(yytext[0]); // mono-lettre non "case-sensitive", est-ce que ça fonctionne avec l'union??
    return ID;}

\{ {return '{';}

\} {return '}';}

":=" {return AFF;}

\, {return ',';}

\n {return '\n';}

({NUM1}|{NUM2}) {
    yylval = atoi(yytext);
    return ELEMENT;
    }

("UNION"|"union") {return UNION;}

("INTER"|"inter") {return INTER;}

("COMP"|"comp") {return COMP;}

("DIFF"|"diff") {return DIFF;}

[[:space:]] ;

. {fprintf(stderr, "Erreur lexicale (%c)\n", yytext[0]);}

%%


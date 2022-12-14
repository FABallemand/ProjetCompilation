%{
    #include <stdio.h>
    #include <string.h>
    
    #include "quad.h"
    #include "bsos.tab.h"
    #include "error_handling.h"

    #include "error_handling.h"

    char *removeQuote(char *src);
%}

%option nounput
%option noyywrap
%option yylineno

%%

"-n" return T_NOT_EMPTY;
"-z" return T_EMPTY;
"-eq" return T_EQUAL;
"-ne" return T_NOT_EQUAL;
"-gt" return T_GT;
"-ge" return T_GE;
"-lt" return T_LT;
"-le" return T_LE;
"-a" return C_AND;
"-o" return C_OR;


\+ return PLUS;
\- return MINUS;
\* return STAR;
\/ return DIVISION;
% return MOD;
= return EQUAL;
!= return NOT_EQUAL;

! return NOT;
"|" return CASE_OR;
"$" return DOLLAR;
\? return STATUS;
";" return SEMI_CO;

\( return OPAR;
\) return CPAR;
\{ return OBRA;
\} return CBRA;
\[ return OABRA;
\] return CABRA;


test return TEST;
expr return EXPR;

local return LOCAL;
declare return DECLARE;

if return IF;
then return THEN;
elif return ELIF;
else return ELSE;
fi return FI;

for return FOR;
while return WHILE;
until return UNTIL;
case return CASE;
esac return ESAC;

in return IN;
do return DO;
done return DONE;

read return READ;
echo return ECHO_;

return return RETURN;

exit return EXIT;
    
[\"\']([^\"\'\\]|\\.)*[\"\'] {yylval.val = strdup(removeQuote(yytext)); return STRING;}

(([1-9][0-9]*)|0) {yylval.val = strdup(yytext); return INTEGER;}

[a-zA-Z_][0-9a-zA-Z_]* {yylval.val = strdup(yytext); return ID;}

#[^\n]*\n ;

[[:space:]] ;

. {printError("Unité lexicale incorrecte"); exit(1);}

%%

char *removeQuote(char *src){
    size_t s = 0;
    char tmp = src[s];
    while(tmp != '\0')
    {
        s++;
        tmp = src[s];
    }
    s -= 2;
    char *res = malloc(s);
    CHK_NULL(res);
    size_t i = 0;
    for(; i < s; i++)
    {
        res[i] = src[i+1];
    }
    res[i] = '\0';
    return res;
}
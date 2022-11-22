%{
    #include "quad.h"
    #include "bsos.tab.h"
    #include <stdio.h>
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
";" {printf("semi_co\n");return SEMI_CO;} // SEMICO ?

\( {printf("OPAR\n");return OPAR;}
\) {printf("CPAR\n");return CPAR;}
\{ return OBRA;
\} return CBRA;
\[ return OABRA; // Why ABRA ? -> SBRA for Square Bracket ? BRA for Bracket and CBRA for Curly Bracket above?
\] return CABRA;


test return TEST;
expr return EXPR;

local return LOCAL;
declare {printf("DECLARE\n");return DECLARE;}

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

return {printf("return !\n");return RETURN;}

exit return EXIT;

[\"\']([^\"\'\\]|\\.)*[\"\'] return STRING;

[[:space:]] ;

#[^\n]*\n {printf("COMMENT\n");}

\n ;

[^[:space:]\n\\\(\)\{\}\[\]\=\!\,\;\:\$\|\*\%]+ return WORD;

. printf("ah bon ?\n"); // xD

%%
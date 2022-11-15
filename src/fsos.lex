%{
    #include "bsos.tab.h"
    #include "token.h"
    #include <stdio.h>
%}

%option nounput
%option noyywrap

%%

\+ return PLUS;
\- return yytext[0];
\* return yytext[0];
\/ return yytext[0];
% return yytext[0];
= return EQUAL;
!= return NOT_EQUAL;

! return NOT;
"|" return yytext[0];

\( return yytext[0];
\) return yytext[0];
\{ return yytext[0];
\} return yytext[0];
\[ return yytext[0];
\] return yytext[0];
\" return yytext[0];


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

[[:digit:]][[:digit:]]* return ENTIER;

[\"\']([^\"\'\\]|\\.)*[\"\'] return CHAINE;

[[:alpha:]_][[:alnum:]_-]* return ID;

[[:space:]] ;

#[[:alnum:][:blank:]]*\n return COMMENT;

. ;

%%


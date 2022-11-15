%{
#include "bsos.tab.h"
#include <stdio.h>
%}

%option nounput
%option noyywrap

%%

\- return yytext[0];
\* return yytext[0];
\/ return yytext[0];
% return yytext[0];
= return yytext[0];
!= return yytext;

! return yytext[0];
& return yytext[0];
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
echo return ECHO;

return return RETURN;

exit return EXIT;

[[:digit:]][[:digit:]]* return ENTIER;

'(.|"\\n"|"\\t")' return CHAR_VALUE;

[\"\']([^\"\'\\]|\\.)*[\"\'] return CHAINE;

[[:alpha:]_][[:alnum:]_-]* return ID;

[[:space:]] ;

# .* '\n' return COMMENT;

. ;

%%


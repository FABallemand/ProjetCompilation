
%{
#include "projet.tab.h"
#include <stdio.h>
%}

%option nounput
%option noyywrap

%%

#[[:alnum:][:blank:]]*\n {
	return COM;
}

\n {
	return EOL;
}

[[:space:]] ;

. {
	return ERROR;
}

%%


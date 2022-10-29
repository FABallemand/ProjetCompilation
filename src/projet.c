#include <stdio.h>
#include <stdlib.h>

extern int yydebug;
extern int yyparse(void);

extern FILE *yyin;
extern char *yytext;
extern int yylex();

int main()
{
    // yydebug = 1;
    int r = yyparse();
    printf("-> %d\n", r);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*Objets permettant la gestion des symboles et de leur valeur*/
#define NB_MAX_ENSEMBLES 64
char identificateurs[NB_MAX_ENSEMBLES];
long int valeurs[NB_MAX_ENSEMBLES];
int nb_ensembles = 0;

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
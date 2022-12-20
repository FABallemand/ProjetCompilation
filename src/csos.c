#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "code.h"

extern int yydebug;
extern int yyparse(void);

extern FILE *yyin;
extern FILE *yyout;
extern char *yytext;
extern int yylex();
extern int yylineno;

int main(int argc, char **argv)
{
    int symbol_table = 0; //< Marqueur pour l'affichage de la table des symboles
    int input_file = 0;   //< Marqueur d'utilisation d'un fichier d'entrée
    int output_file = 0;  //< Marqueur d'utilisation d'un fichier de sortie

    for (int i = 1; i < argc; i++)
    {
        if (strcmp("-h", argv[i]) == 0)
        {
            // execlp("cat", "cat", "help.md", NULL);
            execlp("echo", "echo", "-e", "$(< help)", NULL);
            exit(1);
        }
        if (strcmp("-version", argv[i]) == 0)
        {
            printf("-ALLEMAND Fabien\n-LEBOT Samuel\n");
        }
        if (strcmp("-tos", argv[i]) == 0)
        {
            symbol_table = 1;
        }
        if (strcmp("-i", argv[i]) == 0)
        {
            input_file = 1;
            printf("Compiling programm located at %s\n", argv[i + 1]);
            yyin = fopen(argv[i + 1], "r");
        }
        if (strcmp("-o", argv[i]) == 0)
        {
            output_file = 1;
            printf("Output will be saved in %s\n", argv[i + 1]);
            yyout = fopen(argv[i + 1], "w");
        }
    }

    // yydebug = 1;

    initGlobalCode(1048);

    // char *t1 = newtemp();
    // char *t2 = newtemp();
    // char *t3 = newtemp();
    // char *t4 = newtemp();
    // printf("%s %s %s %s\n",t1,t2,t3,t4);

    yylineno = 1;
    int r = yyparse();
    printf("yytext :%s\n", yytext);
    printf("yylineno : %d\n", yylineno);
    printf("-> %d\n", r);

    printAllQuad();

    freeGlobalCode();

    if (input_file)
    {
        fclose(yyin);
    }
    if (output_file)
    {
        fclose(yyout);
    }
    if (symbol_table)
    {
        // Afficher la table des symboles ici
    }

    return r;
}
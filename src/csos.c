#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "error_handling.h"
#include "code.h"
#include "translator.h"

extern int yydebug;
extern int yyparse(void);

extern FILE *yyin;
extern FILE *yyout;
extern char *yytext;
extern int yylex();
extern int yylineno;

extern char *MIPS_library;
extern FILE *output_file;

int main(int argc, char **argv)
{
    int symbol_table = 0;   //< Marqueur pour l'affichage de la table des symboles
    int input_file_ind = 0; //< Marqueur d'utilisation d'un fichier d'entrée

    for (int i = 1; i < argc; i++)
    {
        if (strcmp("-h", argv[i]) == 0)
        {
            execlp("cat", "cat", "help", NULL);
            exit(1);
        }
        else if (strcmp("-version", argv[i]) == 0)
        {
            printf("-ALLEMAND Fabien\n-LEBOT Samuel\n");
        }
        else if (strcmp("-tos", argv[i]) == 0)
        {
            symbol_table = 1;
        }
        else if (strcmp("-i", argv[i]) == 0)
        {
            input_file_ind = 1;
            printInfo("Compiling programm located at %s\n", argv[i + 1]);
            yyin = fopen(argv[++i], "r");
            CHK_NULL(yyin);
        }
        else if (strcmp("-o", argv[i]) == 0)
        {
            printInfo("Output will be saved in %s\n", argv[i + 1]);
            CHK_NULL(output_file = fopen(argv[++i], "w"));
        }
        else if (strcmp("-l", argv[i]) == 0)
        {
            printInfo("Linking with MIPS library %s\n", argv[i + 1]);
            MIPS_library = strdup(argv[++i]);
        }
        else
        {
            printError("Argument invalide");
            exit(1);
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
    if (r == 1)
    {
        printError("Echec de la compilation !\nErreur ligne %d : symbole \"%s\" non reconnu", yylineno, yytext);
        exit(1);
    }

    if (DEBUG)
        printAllQuad(); // Afficher le tableau de quadruplets

    if (symbol_table)
    {
        printAllStackFrame();
    }

    translator(); // Traduction du code intermédiaire en code MIPS

    freeGlobalCode(); // Libérer l'espace occupé par le code intermédiaire

    if (input_file_ind)
    {
        fclose(yyin);
    }
    fclose(output_file);

    return r;
}
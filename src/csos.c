#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    // int c;
    // while ((c = getopt(argc, argv, "i:o:s:cp:l:a:n:h")) != -1) // getopt returns -1 when there is no more option character (ie: -*)
    // {
    //     switch (c)
    //     {
    //     case 'v':
    //         printf("ALLEMAND Fabien - LEBOT Samuel\n");
    //         break;
    //     }
    // }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp("-version", argv[i]))
        {
            printf("ALLEMAND Fabien - LEBOT Samuel\n");
        }
        if (strcmp("-tos", argv[i]))
        {
            // DO something here
        }
        if (strcmp("-o", argv[i]))
        {
            printf("Output will be saved in %s\n", argv[i + 1]);
            yyout = fopen(argv[i + 1], "w"); // Do not forget to close file
        }
    }

    // yydebug = 1;

    initGlobalCode(1048);
    
    yylineno = 1;
    int r = yyparse();
    printf("yytext :%s\n", yytext);
    printf("yylineno : %d\n", yylineno);
    printf("-> %d\n", r);

    //char t1[64];
    //char t2[64];
    //char t3[64];
    //char t4[64];
    //newtemp(t1);
    //newtemp(t2);
    //newtemp(t3);
    //newtemp(t4);
    //printf("%s %s %s %s\n",t1,t2,t3,t4);

    printAllQuad();

    freeGlobalCode();

    return r;
}

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         fprintf(stderr, "usage: %s input_file\n", argv[0]);
//         exit(1);
//     }
//     yyin = fopen(argv[1], "r");
//     // yyout = fopen(argv[2], "w");

//     fclose(yyin);
//     // fclose(yyout);

//     return 0;
// }
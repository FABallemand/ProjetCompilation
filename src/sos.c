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
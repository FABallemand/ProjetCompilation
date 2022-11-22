#include "code.h"


struct quad *global_code = NULL;       //< Tableau de quadruplets correspondants au programme
size_t global_code_size = 0;           //< Taille du tableau de quadruplets
size_t global_code_scaling_factor = 1; //< Facteur d'agrandissement du tableau de quadruplets
size_t next_quad = 0;                  //< Indice du prochain quadruplet dans le tableau de quadruplets


void initGlobalCode(size_t t)
{
    global_code_size = t;
    CHK_NULL(global_code = malloc(global_code_size * sizeof(struct quad)));
}

void increaseGlobalCodeSize()
{
    struct quad *tmp = realloc(global_code, global_code_size * (++global_code_scaling_factor));
    CHK_NULL(tmp);
    free(global_code);
    global_code = tmp;
}

void freeGlobalCode()
{
    free(global_code);
    global_code = NULL;
    global_code_size = 0;
}

void gencode(struct quad q)
{
    if (next_quad >= global_code_size)
    {
        increaseGlobalCodeSize();
    }
    global_code[next_quad++] = q;
}
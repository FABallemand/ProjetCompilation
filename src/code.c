#include "code.h"

void initGlobalCode(size_t t)
{
    global_code_size = t;
    CHK_NULL(global_code = malloc(global_code_size * sizeof(quad_t)));
}

void increaseGlobalCodeSize()
{
    quad_t *tmp = realloc(global_code, global_code_size * (++global_code_scaling_factor));
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

void gencode(quad_t q)
{
    // vérifier qu'il y a de la place dans le tableau, sinon l'agrandir...
    global_code[next_quad++] = q;
}
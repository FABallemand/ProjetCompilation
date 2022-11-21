#include "code.h"

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
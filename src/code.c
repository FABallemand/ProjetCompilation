#include "code.h"

struct quad *global_code; //< Tableau de quadruplets correspondants au programme
size_t next_quad = 0;     //< Indice du prochain quadruplet dans le tableau de quadruplets

void initGlobalCode()
{
    CHK_NULL(global_code = malloc(INITIAL_GLOBAL_CODE_SIZE * sizeof(struct quad)));
}

void increaseGlobalCodeSize()
{
    struct quad *tmp = realloc(global_code, (next_quad + INITIAL_GLOBAL_CODE_SIZE) * sizeof(struct quad));

    CHK_NULL(tmp);
    free(global_code);
    global_code = tmp;
}

void freeGlobalCode()
{
    free(global_code);
    global_code = NULL;
}

void genCode(struct quad q)
{
    if (next_quad != 0 && ((next_quad % INITIAL_GLOBAL_CODE_SIZE) == 0))
    {
        increaseGlobalCodeSize();
    }
    global_code[next_quad++] = q;
}

char *newtemp()
{
    static size_t next_tmp = 0;
    char dest[20]; // avoid an useless malloc
    if (sprintf(dest, "%s%ld", "%%TMP_", next_tmp) < 0)
    {
        exit(1);
    }
    next_tmp++;
    return strdup(dest);
}

void complete(struct list *l, size_t addr)
{
    if (!l) // pas de liste
    {
        return;
    }
    struct list *new_l = l; // clone pour itérer
    while (new_l)
    {
        global_code[new_l->addr].op1 = quadop_addr(addr);
        new_l = new_l->next;
    }
    freeList(l);
    return;
}

void printAllQuad()
{
    for (int i = 0; i < next_quad; i++)
    {
        printf("%d : ", i);
        printQuad(global_code[i]);
    }
}
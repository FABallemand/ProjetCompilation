#include "code.h"

struct quad *global_code; //< Tableau de quadruplets correspondants au programme
size_t next_quad = 0;     //< Indice du prochain quadruplet dans le tableau de quadruplets

void initGlobalCode()
{
    if(DEBUG)
        printCall("initGlobalCode");
    CHK_NULL(global_code = malloc(INITIAL_GLOBAL_CODE_SIZE * sizeof(struct quad)));
}

void increaseGlobalCodeSize()
{
    if(DEBUG)
        printCall("increaseGlobalCodeSize");
    struct quad *tmp = realloc(global_code, (next_quad + INITIAL_GLOBAL_CODE_SIZE) * sizeof(struct quad));

    CHK_NULL(tmp);
    free(global_code);
    global_code = tmp;
}

void freeGlobalCode()
{
    if(DEBUG)
        printCall("freeGlobalCode");
    free(global_code);
    global_code = NULL;
}

void genCode(struct quad q)
{
    if(DEBUG)
        printCall("genCode");
    if (next_quad != 0 && ((next_quad % INITIAL_GLOBAL_CODE_SIZE) == 0))
    {
        increaseGlobalCodeSize();
    }
    global_code[next_quad++] = q;
}

char *newtemp()
{
    if(DEBUG)
        printCall("newTemp");
    static size_t next_tmp = 0;
    char dest[20]; // avoid an useless malloc
    if (sprintf(dest, "%s%ld", "%%TMP_", next_tmp) < 0)
    {
        exit(1);
    }
    next_tmp++;
    char * dest_bis = strdup(dest);
    newName(S_GLOBAL, dest_bis, VAR, 0);
    return dest_bis;
}

void complete(struct list *l, size_t addr)
{
    if(DEBUG)
        printCall("complete");
    if (l) // si liste non vide
    {
        struct list *new_l = l; // clone pour itérer
        while (new_l)
        {
            printf("test\n");
            global_code[new_l->addr].res = quadop_addr(addr);
            printf("test\n");
            new_l = new_l->next;
            printf("test\n");
        }
        freeList(l);
    }
}

void printAllQuad()
{
    if(DEBUG)
        printCall("printAllQuad");
    for (int i = 0; i < next_quad; i++)
    {
        printf("%d : ", i);
        printQuad(global_code[i]);
    }
}
#include "code.h"

struct quad *global_code;          //< Tableau de quadruplets correspondants au programme
size_t global_code_size;           //< Taille du tableau de quadruplets
size_t next_quad;                  //< Indice du prochain quadruplet dans le tableau de quadruplets

void initGlobalCode(size_t t)
{
    global_code_size = t;
    CHK_NULL(global_code = malloc(global_code_size * sizeof(struct quad)));
}

void increaseGlobalCodeSize()
{
    global_code_size *= 2; //plus simple ? quand penses tu ?
    struct quad *tmp = realloc(global_code, global_code_size * sizeof(struct quad));
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

void genCode(struct quad q)
{
    if (next_quad >= global_code_size)
    {
        increaseGlobalCodeSize();
    }
    global_code[next_quad++] = q;
    //pas complet
}

void complete(struct list* l,size_t addr)
{
    if(!l) //pas de liste
    {
        return;
    }
    struct list *new_l = l; //clone pour itérer
    while(new_l)
    {
        global_code[new_l->addr].op1 = quadop_cst(addr);
        new_l = new_l->next;
    }
    freeList(l);
    return;
}
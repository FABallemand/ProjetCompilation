#include "list.h"

struct list *createList(size_t a)
{
    struct list *l;
    CHK_NULL(l = malloc(sizeof(struct list)));
    l->addr = a;
    l->next = NULL;
    return l;
}

void freeList(struct list *l)
{
    if (l->next != NULL)
    {
        free(l->next);
    }
    free(l);
}

struct list *concat(struct list *l1, struct list *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    else
    {
        l1->next = concat(l1->next, l2);
        return l1;
    }
}
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
    //je pense que tu voulais faire une fonction recursive mais tu as oublié l'appel recursif
    if(!l)
    {
        return;
    }
    struct list *temp = l->next;
    while(temp){
        struct list *tmp = temp->next;
        free(temp);
        temp=tmp;
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
        //j'ai viré la récursion pour limiter les appels inutiles 
        struct list *temp = l1;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = l2;
        return l1;
    }
}
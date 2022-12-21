#include "list.h"

struct call_list *not_finished_call = NULL;

struct list *createList(size_t a)
{
    if(DEBUG)
        printCall("createList");
    struct list *l;
    CHK_NULL(l = malloc(sizeof(struct list)));
    l->addr = a;
    l->next = NULL;
    return l;
}

void freeList(struct list *l)
{
     if(DEBUG)
        printCall("freeList");
    if (!l)
    {
        return;
    }
    struct list *temp = l->next;
    while (temp)
    {
        struct list *tmp = temp->next;
        free(temp);
        temp = tmp;
    }
    free(l);
}

struct list *concat(struct list *l1, struct list *l2)
{
    if(DEBUG)
        printCall("concat");
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
        struct list *temp = l1;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = l2;
        return l1;
    }
}

void addCallList(size_t nb_arg, struct symbol *fun)
{
    if(DEBUG)
        printCall("addCallList");
    struct call_list *l;
    CHK_NULL(l = malloc(sizeof(struct call_list)));
    l->nb_arg = nb_arg;
    l->fun = fun;
    l->next = not_finished_call;
    not_finished_call = l;
}

void removeCallList(struct symbol *fun)
{
    if(DEBUG)
        printCall("removeCallList");
    struct call_list *copy = not_finished_call;
    struct call_list *prev = NULL;
    while (copy) // Tant qu'il y a des appels de fonctions non résolus à analyser
    {
        if (copy->fun == fun && copy->nb_arg == fun->size) // Appel valide (il faut supprimer l'élément)
        {
            if (prev) // Pas début de liste
            {
                prev->next = copy->next;
                free(copy);
            }
            else // En début de liste
            {
                not_finished_call = copy->next;
                free(copy);
                copy = not_finished_call;
                continue; // Si on supprime le premier élément, "on recommence du début"
            }
        }
        else if (copy->fun == fun && copy->nb_arg != fun->size) // Appel invalide !!
        {
            // Faire fonction erreur
            exit(1);
        }
        prev = copy;
        copy = copy->next;
    }
}

void freeCallList(struct call_list *l)
{
    if(DEBUG)
        printCall("freeCallList");
    if (!l)
    {
        return;
    }
    struct call_list *temp = l->next;
    while (temp)
    {
        struct call_list *tmp = temp->next;
        free(temp);
        temp = tmp;
    }
    free(l);
}
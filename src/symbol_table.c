#include "symbol_table.h"

struct stack *S_GLOBAL_stack = NULL;

void increaseContextSize(struct stack *s)
{
    s->size *= 2;
    s->context = realloc(s->context, s->size * sizeof(struct symbol));
    CHK_NULL(s->context);
}

void pushContext()
{
    struct stack *new = malloc(sizeof(struct stack));

    CHK_NULL(new);
    new->size = INITIAL_CONTEXT_SIZE;
    new->current_symb = 0;
    new->context = malloc(new->size * sizeof(struct symbol));
    CHK_NULL(new->context);
    if (S_GLOBAL_stack)
    {
        new->prev = S_GLOBAL_stack;
    }
    else
    {
        new->prev = NULL;
    }
    S_GLOBAL_stack = new;
}

struct stack *popContext()
{
    struct stack *tmp = S_GLOBAL_stack;
    S_GLOBAL_stack = S_GLOBAL_stack->prev;
    return tmp; // Question concernant free?
}

struct symbol *newName(enum scope s, char *name, enum sym_type type, size_t size)
{
    // Se placer dans le bon contexte
    struct stack *ctx = S_GLOBAL_stack;
    if (s != S_LOCAL)
    {
        while (ctx->prev)
        {
            ctx = ctx->prev;
        }
    }

    // Vérifier qu'il reste de la place dans le contexte
    if (ctx->current_symb + 1 == ctx->size)
    {
        increaseContextSize(ctx);
    }

    // Ajouter un symbole dans le contexte
    ctx->context[ctx->current_symb].name = name;
    ctx->context[ctx->current_symb].type = type;
    ctx->context[ctx->current_symb].size = size;
    ctx->current_symb++;
}

struct symbol *lookUp(enum scope s, char *name)
{
    // Appel récursif pour chercher dans le contexte S_LOCAL ou S_GLOBAL (on nen cherhce pas dans les contextes intermédiares car les fonctions sont S_GLOBALes)
    struct symbol *res = NULL;
    if (s == S_AUTO)
    {
        if (res = lookUp(S_LOCAL, name))
        {
            return res;
        }
        return lookUp(S_GLOBAL, name);
    }

    // Se placer dans le contexte S_LOCAL
    struct stack *ctx = S_GLOBAL_stack;
    // Se placer dans le contexte S_GLOBAL
    if (s == S_GLOBAL)
    {
        while (ctx->prev)
        {
            ctx = ctx->prev;
        }
    }

    // Parcourir les entrées du contexte
    for (int i = 0; i < ctx->current_symb; i++)
    {
        if (strcmp(name, ctx->context[i].name) == 0)
        {
            return &(ctx->context[i]);
        }
    }
    return NULL;
}

// struct symbol *lookUp(enum scope s, char *name)
// {
//     // Parcourir les contextes en partant du haut
//     struct stack *ctx = S_GLOBAL_stack;
//     while (ctx)
//     {
//         // Parcourir les entrées du contexte
//         for (int i = 0; i < ctx->current_symb; i++)
//         {
//             if (strcmp(name, ctx->context[i].name) == 0)
//             {
//                 return &(ctx->context[i]);
//             }
//         }
//     }
//     return NULL;
// }
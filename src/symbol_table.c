#include "symbol_table.h"

struct stack *S_GLOBAL_stack = NULL;                     //< Pile des contextes (nom à changer)
struct stack_frame stack_frame_list[NB_MAX_STACK_FRAME]; //< Liste de stack frame déjà calculés
size_t nb_stack_frame = 0;                               //< Nombre de stack frame déjà calculés

void increaseContextSize(struct stack *s)
{
    if(DEBUG)
        printCall("increaseContextSize");

    s->size *= 2;
    s->context = realloc(s->context, s->size * sizeof(struct symbol));
    CHK_NULL(s->context);
}

void pushContext()
{
    if(DEBUG)
        printCall("pushContext");

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
    if(DEBUG)
        printCall("popContext");

    struct stack *tmp = S_GLOBAL_stack;
    S_GLOBAL_stack = S_GLOBAL_stack->prev;
    return tmp;
}

void newName(enum scope s, char *name, enum sym_type type, ssize_t size)
{
    if(DEBUG)
        printCall("newName");

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
    if(DEBUG)
        printCall("lookUp");

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

size_t countArg()
{
    if(DEBUG)
        printCall("countArg");

    size_t count = 0;
    // Se placer dans le contexte S_LOCAL
    struct stack *ctx = S_GLOBAL_stack;

    // Compter les arguments
    for (int i = 0; i < ctx->current_symb; i++)
    {
        printf("%d\n", i);
        if (ctx->context[i].type == ARG)
        {
            count++;
        }
    }
    return count;
}

int checkInsideFunction()
{
    if(DEBUG)
        printCall("checkInsideFunction");
    // Si on a pas de contexte ou que le context est global alors faux sinon vrai.
    if (S_GLOBAL_stack == NULL || S_GLOBAL_stack->prev == NULL)
    {
        return 0;
    }
    return 1;
}

void createNewStackFrame(char *name, struct stack *stack)
{
    if(DEBUG)
        printCall("createNewStackFrame");

    // Gestion d'erreur
    if (nb_stack_frame == (NB_MAX_STACK_FRAME - 1))
    {
        printError("Nombre maximal de stack atteint");
        exit(1);
    }
    // Sauvegarde du stack frame
    stack_frame_list[nb_stack_frame].context_name = name;
    stack_frame_list[nb_stack_frame].context = stack->context;
    stack_frame_list[nb_stack_frame].nb_symb = stack->current_symb;
    size_t temp_size = 0;
    for (size_t i = 0; i < stack->current_symb; i++)
    {
        printf("%ld\n", i);
        if (stack->context[i].type == TAB)
        {
            temp_size += stack->context[i].size * SIZE_MIPS_WORD;
        }
        else
        {
            temp_size += SIZE_MIPS_WORD;
        }
    }
    stack_frame_list[nb_stack_frame].stack_frame_size = temp_size;
    free(stack); // Free la stack mais pas le context
    nb_stack_frame++;
}
#ifndef __DEF_SYMBOL_TABLE_H__
#define __DEF_SYMBOL_TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CONTEXT_SIZE 64

#define CHK_NULL(x)           \
    do                        \
    {                         \
        if ((x) == NULL)      \
        {                     \
            printf("NULL\n"); \
            exit(1);          \
        }                     \
    } while (0)

/**
 * \brief
 *
 */
enum scope
{
    S_LOCAL,
    S_GLOBAL,
    S_AUTO // = LOCAL + GLOBAL -> réfléchir, fonctions imbriquées globales
};

/**
 * \brief
 *
 */
enum sym_type
{
    VAR,
    TAB,
    FUN
};

struct symbol
{
    char *name;         //< Nom du symbole (identifiant)
    enum sym_type type; //< Type de variables
    size_t size;        //< Taille du tableau SoS (0 si le symbole est une variable SoS et >0 si le symbole est un tableau SoS)
};

/**
 * \struct stack
 *
 * \brief stack de table des symboles
 */
struct stack
{
    size_t size;            //< Taille actuelle de la table de symboles (nombre maximal de symbole enregistrables)
    size_t current_symb;    //< Indice dernier symbole ajouté
    struct symbol *context; //< Table des symboles
    struct stack *prev;     //< Element suivant
};

void increaseContextSize(struct stack *s);

void pushContext();

struct stack *popContext();

struct symbol *newName(enum scope s, char *name, enum sym_type type, size_t size);

struct symbol *lookUp(enum scope s, char *name);

#endif
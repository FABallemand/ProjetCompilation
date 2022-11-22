#ifndef __DEF_CODE_H__
#define __DEF_CODE_H__


/**
 * \file
 *
 * \brief
 */

#include <stdio.h>
#include <stdlib.h>

#include "quad.h"
// #include "bsos.tab.c"

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
 * \brief Initialise le tableau de quadruplets correspondant au programme
 *
 * \param t taille initiale du tableau
 */
void initGlobalCode(size_t t);

/**
 * \brief Augmente la taille du tableau de quadruplets correspondant au programme
 * 
 */
void increaseGlobalCodeSize();

/**
 * \brief Libére la mémoire occupée par le tableau correspondant au programme
 * 
 */
void freeGlobalCode();

/**
 * \brief Crée une nouvelle variable temporaire
 *
 * \return un symbole "frais"
 */
char *newtemp();

/**
 * \brief Génère le code d'un quadruplet
 *
 * \param q un quadruplet
 * \return le code en assembleur MIPS correspondant au quadruplet donné en argument
 */
void gencode(struct quad q);

#endif
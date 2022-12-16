#ifndef __DEF_CODE_H__
#define __DEF_CODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quad.h"
#include "list.h"
#include "symbol_table.h"

#define INITIAL_GLOBAL_CODE_SIZE 64 //< Taille initiale du tableau de quadruplets constituant le code intermédiaire du programme

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
 * \file code.h
 *
 * \brief Gestion de la génération de code
 */

extern struct quad *global_code; //< Tableau de quadruplets correspondant au programme
extern size_t next_quad;         //< Indice du prochain quadruplet dans le tableau de quadruplets

/**
 * \brief Initialise le tableau de quadruplets correspondant au programme
 */
void initGlobalCode();

/**
 * \brief Augmente la taille du tableau de quadruplets correspondant au programme
 */
void increaseGlobalCodeSize();

/**
 * \brief Libère la mémoire occupée par le tableau correspondant au programme
 */
void freeGlobalCode();

/**
 * \brief Crée une nouvelle variable temporaire
 *
 * \param dest Adresse de la chaine finale
 * \return Symbole "frais"
 */
char *newtemp();

/**
 * \brief Génère le code d'un quadruplet
 *
 * \param q Un quadruplet
 * \return Code en assembleur MIPS correspondant au quadruplet donné en argument
 */
void genCode(struct quad q);

/**
 * \brief Complète une liste de quad de type Q_GOTO
 *
 * \param l Liste de quad Q_GOTO incomplets
 * \param addr Adresse d'un quad
 */
void complete(struct list *l, size_t addr);

/**
 * \brief Affiche tous les quads jusqu'à next_quad
 */
void printAllQuad();

#endif
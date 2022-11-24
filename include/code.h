#ifndef __DEF_CODE_H__
#define __DEF_CODE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quad.h"
#include "list.h"

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

// struct quad *global_code = NULL;       //< Tableau de quadruplets correspondants au programme
// size_t global_code_size = 0;           //< Taille du tableau de quadruplets
// size_t global_code_scaling_factor = 1; //< Facteur d'agrandissement du tableau de quadruplets
// size_t next_quad = 0;                  //< Indice du prochain quadruplet dans le tableau de quadruplets

extern struct quad *global_code;          //< Tableau de quadruplets correspondants au programme
extern size_t global_code_size;           //< Taille du tableau de quadruplets
extern size_t next_quad;                  //< Indice du prochain quadruplet dans le tableau de quadruplets

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
void newtemp( char * dest);

/**
 * \brief Génère le code d'un quadruplet
 *
 * \param q un quadruplet
 * \return le code en assembleur MIPS correspondant au quadruplet donné en argument
 */
void genCode(struct quad q);

/**
 * \brief Complete une liste de quad goto
 * 
 * \param l list de quad goto incomplet
 * \param addr adresse d'un quad
 */
void complete(struct list* l,size_t addr);

/**
 * \brief Affiche tous les quads jusqu'à next quad
 * 
 */
void printAllQuad();

#endif
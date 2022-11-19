#include <stdio.h>
#include <stdlib.h>
#include "quad.h"

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
 * \file
 *
 * \brief
 */

quad_t *global_code = NULL;            //< Tableau de quadruplets correspondants au programme
size_t global_code_size = 0;           //< Taille du tableau de quadruplets
size_t global_code_scaling_factor = 1; //< Facteur d'agrandissement du tableau de quadruplets

size_t next_quad = 0; //< Indice du prochain quadruplet dans le tableau de quadruplets

void initGlobalCode(size_t t);

void increaseGlobalCodeSize();

void freeGlobalCode();

/**
 * \brief
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
void gencode(quad_t q);
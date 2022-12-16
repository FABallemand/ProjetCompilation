#ifndef __DEF_LIST_H__
#define __DEF_LIST_H__

#include <stdio.h>
#include <stdlib.h>

#include "symbol_table.h"

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
 * \file list.h
 *
 * \brief Listes chainées
 */

/**
 * \struct list
 *
 * \brief Liste chainée
 */
struct list
{
    size_t addr;       //< Numéro de quadruplet dans le tableau de quadruplets
    struct list *next; //< Element suivant
};

/**
 * \brief Crée une liste chainée
 *
 * \param a valeur du premier élément (ie: adresse du premier quaruplet)
 * \return un pointeur sur la liste
 */
struct list *createList(size_t a);

/**
 * \brief Libère la mémoire occupée par une liste chainée
 *
 * \param l un pointeur sur la nouvelle liste chainée
 */
void freeList(struct list *l);

/**
 * \brief Concatène deux listes chainées
 *
 * \param l1 pointeur sur la première liste chainée
 * \param l2 pointeur sur la seconde liste chainée
 * \return pointeur sur la liste chainée résulta de la concaténation
 */
struct list *concat(struct list *l1, struct list *l2);

/**
 * \struct call_list
 *
 * \brief Liste chainée
 */
struct call_list
{
    size_t nb_arg;      //< Nombre d'arguments donnés à la fonction appelée
    struct symbol *fun; //< Fonction appelée
    struct call_list *next;  //< Element suivant
};

/**
 * \brief Crée une liste chainée
 *
 * \param nb_arg valeur du premier élément (ie: adresse du premier quaruplet)
 */
void addCallList(size_t nb_arg, struct symbol *fun);

void removeCallList(struct symbol *fun);

/**
 * \brief Libère la mémoire occupée par une liste chainée
 *
 * \param l un pointeur sur la nouvelle liste chainée
 */
void freeCallList(struct call_list *l);

#endif
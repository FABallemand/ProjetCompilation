#ifndef __DEF_LIST_H__
#define __DEF_LIST_H__

#include <stdio.h>
#include <stdlib.h>

#include "error_handling.h"

#include "symbol_table.h"

/**
 * \file list.h
 *
 * \brief Listes chainées
 */

/**
 * \struct list
 *
 * \brief Liste chainée d'adresses de quadruplets (expliquer utilité)
 */
struct list
{
    size_t addr;       //< Numéro de quadruplet dans le tableau de quadruplets
    struct list *next; //< Element suivant
};

/**
 * \brief Crée une liste chainée
 *
 * \param a Valeur du premier élément (ie: adresse du premier quaruplet)
 * \return Pointeur sur la liste
 */
struct list *createList(size_t a);

/**
 * \brief Libère la mémoire occupée par une liste chainée
 *
 * \param l Pointeur sur la nouvelle liste chainée
 */
void freeList(struct list *l);

/**
 * \brief Concatène deux listes chainées
 *
 * \param l1 Pointeur sur la première liste chainée
 * \param l2 Pointeur sur la seconde liste chainée
 * \return Pointeur sur la liste chainée résultat de la concaténation
 */
struct list *concat(struct list *l1, struct list *l2);

/*===========================================================================*/

/**
 * \struct call_list
 *
 * \brief Liste chainée d'appels à aux fonctions. Permet de vérifier si les fonctions sont appelées avec le bon nombre d'arguments.
 */
struct call_list
{
    size_t nb_arg;          //< Nombre d'arguments donnés à la fonction appelée
    struct symbol *fun;     //< Fonction appelée
    struct call_list *next; //< Element suivant
};

/**
 * \brief Crée une liste chainée
 *
 * \param nb_arg Valeur du premier élément (ie: adresse du premier quaruplet)
 */
void addCallList(size_t nb_arg, struct symbol *fun);

/**
 * \brief Retire de la liste tous les éléments relatifs à une fonctions dont le nombre d'arguments a été déterminé et déclenche une erreur si une fonction est appelée avec un nombre d'arguments invalide
 * 
 * \param fun Fonction dont le nombre d'arguments est connu
 */
void removeCallList(struct symbol *fun);

/**
 * \brief Libère la mémoire occupée par une liste chainée
 *
 * \param l Pointeur sur la nouvelle liste chainée
 */
void freeCallList(struct call_list *l);

#endif
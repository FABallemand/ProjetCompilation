#ifndef __DEF_LIST_H__
#define __DEF_LIST_H__

#include <stdio.h>
#include <stdlib.h>

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

// typedef struct elem_quad_s elem_inc_quad_t;
// struct elem_inc_quad_s
// {
//     unsigned int quad_pos;
//     elem_inc_quad_t *next;
// };

// /**
//  * \struct
//  *
//  * \brief
//  */
// typedef struct liste_quad_s liste_quad_t; // Utiliser des listes chainées
// struct liste_quad_s
// {
//     elem_inc_quad_t *first;
// };

// /**
//  * \brief crée une liste avec un seul élément.
//  *
//  * \param quad_pos positon du quad dans le tableau de quad.
//  * \return liste_quad_t* pointeur sur la liste nouvellement créé.
//  */
// liste_quad_t *creelist(int quad_pos);

// /**
//  * \brief concatène deux listes de quad en une nouvelle liste puis détruit la liste originale.
//  *
//  * \param liste1 première liste.
//  * \param liste2 deuxième liste.
//  * \return liste_quad_t* pointeur sur une nouvelle liste concaténée.
//  */
// liste_quad_t *concat(liste_quad_t *liste1, liste_quad_t *liste2);

// /**
//  * \brief
//  *
//  * \param liste liste dont les quads doivent être complétés.
//  * \param quad_pos la position ou les quads doivent être finis.
//  */
// void complete(liste_quad_t *liste, int quad_pos);

/* Linked List */

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

#endif
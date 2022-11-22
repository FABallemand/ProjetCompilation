#ifndef __DEF_LIST_H__
#define __DEF_LIST_H__



/**
 * \file
 *
 * \brief
 */

#include <stdlib.h>

/**
 * \struct
 *
 * \brief
 */
typedef struct elem_quad_s elem_inc_quad_t;
struct elem_inc_quad_s
{
    unsigned int quad_pos;
    elem_inc_quad_t *next;
};

/**
 * \struct
 *
 * \brief
 */
typedef struct liste_quad_s liste_quad_t; // Utiliser des listes chainées
struct liste_quad_s
{
    elem_inc_quad_t *first;
};

/**
 * \brief crée une liste avec un seul élément.
 *
 * \param quad_pos positon du quad dans le tableau de quad.
 * \return liste_quad_t* pointeur sur la liste nouvellement créé.
 */
liste_quad_t *creelist(int quad_pos);

/**
 * \brief concatène deux listes de quad en une nouvelle liste puis détruit la liste originale.
 *
 * \param liste1 première liste.
 * \param liste2 deuxième liste.
 * \return liste_quad_t* pointeur sur une nouvelle liste concaténée.
 */
liste_quad_t *concat(liste_quad_t *liste1, liste_quad_t *liste2);

/**
 * \brief
 *
 * \param liste liste dont les quads doivent être complétés.
 * \param quad_pos la position ou les quads doivent être finis.
 */
void complete(liste_quad_t *liste, int quad_pos);

#endif
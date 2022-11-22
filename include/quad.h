#ifndef __DEF_QUAD_H__
#define __DEF_QUAD_H__



/**
 * \file
 *
 * \brief
 */

/**
 * \brief Constructeur de quadop_t pour les constantes
 */
#define quadop_cst(v)                         \
    (struct quadop)                           \
    {                                         \
        .kind = QO_CST, .valeur = {.cst = v } \
    }
// struct quadop quadop_cst(int v);

#endif
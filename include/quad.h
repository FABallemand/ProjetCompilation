#ifndef __DEF_QUAD_H__
#define __DEF_QUAD_H__

#include <stdio.h>

/**
 * \file quad.h
 *
 * \brief Gestion des quadruplets
 */

/**
 * \struct quadop
 *
 * \brief Opérande d'un quadruplet
 */
struct quadop
{
    enum
    {
        QO_CST,
        QO_STRING,
        QO_EMPTY,
        QO_UNKNOWN
    } kind; //< Type de l'opérateur

    union
    {
        int cst;
        char *string;
    } valeur; //< Valeur de l'opérateur


};

/**
 * \brief Constructeur de quadop_t pour les constantes
 */
#define quadop_cst(v)                         \
    (struct quadop)                           \
    {                                         \
        .kind = QO_CST, .valeur = {.cst = v } \
    }

// #define quadop_string(v)                            \
//     (struct quadop)                                 \
//     {                                               \
//         .kind = QO_STRING, .valeur = {.string = v } \
//     }

#define quadop_bool(v)                          \
    (struct quadop)                             \
    {                                           \
        .kind = QO_BOOL, .valeur = {.bool = v } \
    }

#define quadop_empty(v)  \
    (struct quadop)      \
    {                    \
        .kind = QO_EMPTY \
    }

/**
 * \struct quad
 *
 * \brief Quadruplet
 */
struct quad
{
    enum
    {
        Q_ADD, // addition
        Q_SUB, // substraction
        Q_MUL, // multiplication
        Q_DIV, // division
        Q_MOD, // modulo
        Q_EQUAL, // egale entre entier
        Q_NOT_EQUAL, // non egal entre entier
        Q_GT, // plus grand strict entier
        Q_GE, // plus grand entier
        Q_LT, // plus petit strict entier
        Q_LE, // plus petit entier
        Q_EMP, // chaine vide
        Q_N_EMP, // chaine non vide
        Q_EQUAL_STRING, // egale entre chaine
        Q_NOT_EQUAL_STRING, // non egal entre chaine
        Q_GOTO //goto
    } kind; //< Type de quadruplet

    struct quadop op1, op2, res; //< Opérandes
};

#define quad_add(op1, op2, res)                           \
    (struct quadop)                                       \
    {                                                     \
        .kind = Q_ADD, .op1 = op1, .op2 = op2, .res = res \
    }

#define quad_and(op1, op2, res)                           \
    (struct quadop)                                       \
    {                                                     \
        .kind = Q_AND, .op1 = op1, .op2 = op2, .res = res \
    }

void printQuadop(struct quadop q);

void printQuad(struct quad q);

#endif
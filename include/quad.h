#ifndef __DEF_QUAD_H__
#define __DEF_QUAD_H__

#include <stdio.h>
#define MAX_SIZE_VAR_NAME 64
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
        QO_VAR,
        QO_STRING,
        QO_EMPTY,
        QO_UNKNOWN
    } kind; //< Type de l'opérateur

    union
    {
        int cst;
        char *name;
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

#define quadop_var(v)                            \
    (struct quadop)                                 \
    {                                               \
        .kind = QO_VAR, .valeur = {.name = strdup(v) } \
    }                         

#define quadop_string(v)                            \
    (struct quadop)                                 \
    {                                               \
        .kind = QO_STRING, .valeur = {.string = strdup(v) } \
    }

#define quadop_unknown()                          \
    (struct quadop)                             \
    {                                           \
        .kind = QO_UNKNOWN                      \
    }

#define quadop_empty()  \
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
        Q_AFFECT, //AFFECTATION
        Q_GOTO //goto
    } kind; //< Type de quadruplet

    struct quadop op1, op2, res; //< Opérandes
};

#define quad_new(q ,qop1, qop2, qres)                           \
    (struct quad)                                       \
    {                                                     \
        .kind = q, .op1 = (qop1), .op2 = (qop2), .res = (qres) \
    }

void printQuadop(struct quadop q);

void printQuad(struct quad q);

#endif
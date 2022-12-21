#ifndef __DEF_QUAD_H__
#define __DEF_QUAD_H__

#include <stdio.h>

#define MAX_SIZE_VAR_NAME 64 //< Taille maximale en nombre de caractère du nom d'une variable

/**
 * \file quad.h
 *
 * \brief Gestion des quadruplets constituants le code intermédiaire
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
        QO_ADDR,
        QO_EMPTY,
        QO_UNKNOWN
    } kind; //< Type de l'opérande

    union
    {
        size_t addr;                     //< Valeur d'adresse (pour goto)
        char *value;                     //< Valeur de l'opérande (chaîne de caractères correspondant à sa valeur ou a son nom)
    } qval;                              //< Valeur de l'opérande
};

/**
 * \brief Construit un quadop pour une constante
 */
#define quadop_cst(v)                         \
    (struct quadop)                           \
    {                                         \
        .kind = QO_CST, .qval = {.value = v } \
    }

/**
 * \brief Construit un quadop pour une variable
 */
#define quadop_var(v)                         \
    (struct quadop)                           \
    {                                         \
        .kind = QO_VAR, .qval = {.value = v } \
    }

/**
 * \brief Construit un quadop pour une chaîne de caractère
 */
#define quadop_string(v)                         \
    (struct quadop)                              \
    {                                            \
        .kind = QO_STRING, .qval = {.value = v } \
    }

/**
 * \brief Construit un quadop pour une adresse
 */
#define quadop_addr(v)                        \
    (struct quadop)                           \
    {                                         \
        .kind = QO_ADDR, .qval = {.addr = v } \
    }

/**
 * \brief Construit un quadop pour une opérande inconnue
 */
#define quadop_unknown()                         \
    (struct quadop)                              \
    {                                            \
        .kind = QO_UNKNOWN, .qval = {.addr = 0 } \
    }

/**
 * \brief Construit un quadop vide
 */
#define quadop_empty()   \
    (struct quadop)      \
    {                    \
        .kind = QO_EMPTY \
    }

/**
 * \struct quad
 *
 * \brief Quadruplet constituant le code intermédiaire
 */
struct quad
{
    enum // vérifier l'utilité de chacun
    {
        Q_CONCAT,
        Q_ADD,
        Q_SUB,
        Q_MUL,
        Q_DIV,
        Q_MOD,
        Q_EQUAL,
        Q_NOT_EQUAL,
        Q_GT,
        Q_GE,
        Q_LT,
        Q_LE,
        Q_EMP,
        Q_N_EMP,
        Q_EQUAL_STRING,
        Q_NOT_EQUAL_STRING,
        Q_AFFECT,
        Q_GOTO,
        Q_DECLARE,
        Q_LOCAL,
        Q_ECHO,
        Q_RETURN,
        Q_EXIT,
        Q_EXIT_VAL,
        Q_ARRAY_GET
    } kind; //< Type de quadruplet

    struct quadop op1, op2, res; //< Opérandes
};

/**
 * \brief Construit un quad
 */
#define quad_new(q, qop1, qop2, qres)                          \
    (struct quad)                                              \
    {                                                          \
        .kind = q, .op1 = (qop1), .op2 = (qop2), .res = (qres) \
    }

/**
 * \brief Affiche un opérateur de quadruplet
 *
 * \param q Opérateur de quadruplet
 */
void printQuadop(struct quadop q);

/**
 * \brief Affiche un quadruplet
 *
 * \param q Quadruplet
 */
void printQuad(struct quad q);

#endif
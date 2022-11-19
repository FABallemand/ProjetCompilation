
/**
 * \file
 *
 * \brief
 */

/**
 * \struct Opérande d'un quadruplet
 *
 * \brief
 */
typedef struct quadop_t
{
    enum
    {
        QO_CST,
        QO_CHAINE
    } type; //< Type de l'opérateur

    union
    {
        int cst;
        char *chaine;
    } valeur; //< Valeur de l'opérateur
};

/**
 * \struct Quadruplet
 *
 * \brief
 */
typedef struct quad_t
{
    enum
    {
        Q_ADDITION,
        Q_SOUSTRACTION
    } type; //< Type de quadruplet

    struct quadop_t op1, op2, res; //< Opérandes
};

/**
 * \brief Constructeur de quadop_t pour les constantes
 */
#define quadop_cst(v)                    \
    \ (struct quadop_t)                  \
    {                                    \
        .kind = QO_CST, .u = {.cst = v } \
    }
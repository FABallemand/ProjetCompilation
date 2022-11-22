/**
 * \file
 *
 * \brief
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
        QO_STRING
    } kind; //< Type de l'opérateur

    union
    {
        int cst;
        char *STRING;
    } valeur; //< Valeur de l'opérateur
};

/**
 * \struct quad
 *
 * \brief Quadruplet
 */
struct quad
{
    enum
    {
        Q_ADD,
        Q_SUB,
        Q_MUL,
        Q_DIV,
        Q_MOD
    } kind; //< Type de quadruplet

    struct quadop op1, op2, res; //< Opérandes
};

/**
 * \brief Constructeur de quadop_t pour les constantes
 */
#define quadop_cst(v)                         \
    (struct quadop)                           \
    {                                         \
        .kind = QO_CST, .valeur = {.cst = v } \
    }
// struct quadop quadop_cst(int v);

/**
 * \brief Affiche un quadruplet
 *
 */
void printQuad(struct quad q);
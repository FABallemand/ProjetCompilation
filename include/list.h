#include <stdlib.h>

typedef struct elem_quad_s elem_inc_quad_t;
struct elem_inc_quad_s
{
    unsigned int quad_pos;
    elem_inc_quad_t *next;
};

typedef struct liste_quad_s liste_quad_t;
struct liste_quad_s
{
    elem_inc_quad_t *first;
};

/**
 * @brief cree une liste avec un seul élément.
 * 
 * @param quad_pos positon du quad dans le tabelau de quad.
 * @return liste_quad_t* pointeur sur la liste nouvellement créé.
 */
liste_quad_t* creelist(int quad_pos);

/**
 * @brief concatène deux listes de quad en une nouvelle liste puis détruit la liste original.
 * 
 * @param liste1 première liste.
 * @param liste2 deuxième liste.
 * @return liste_quad_t* pointeur sur une nouvelle liste concaténé.
 */
liste_quad_t* concat(liste_quad_t* liste1,liste_quad_t* liste2);


/**
 * @brief 
 * 
 * @param liste liste dont les quads doivent être complété.
 * @param quad_pos la position ou les quads doivent être fini.
 */
void complete(liste_quad_t* liste, int quad_pos);
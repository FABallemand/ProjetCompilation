#ifndef __DEF_SYMBOL_TABLE_H__
#define __DEF_SYMBOL_TABLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_handling.h"

#define INITIAL_CONTEXT_SIZE 64 //< Taille initiale d'un contexte
#define NB_MAX_STACK_FRAME 32   //< Nombre maximal de stack frame
#define SIZE_MIPS_WORD 4        //< Taille d'un mot MIPS

/**
 * \enum scope
 *
 * \brief Décrit un niveau de contexte ou la portée d'une variable
 */
enum scope
{
    S_LOCAL,
    S_GLOBAL,
    S_AUTO // = LOCAL + GLOBAL -> réfléchir, fonctions imbriquées globales
};

/**
 * \enum sym_type
 *
 * \brief Décrit le type d'un symbole
 */
enum sym_type
{
    VAR,
    TAB,
    FUN,
    ARG
};

/**
 * \struct symbol
 *
 * \brief Décrit un symbole dans la table des symboles
 */
struct symbol
{
    char *name;         //< Nom du symbole (identifiant)
    enum sym_type type; //< Type de variable
    ssize_t size;       //< Taille du tableau ou nombre d'arguments (variable: 0, tableau: >0, fonction: -1 si nombre d'arguments est indéterminé et >= 0 sinon)
};

/**
 * \struct stack
 *
 * \brief Pile de tables des symboles
 */
struct stack
{
    size_t size;            //< Taille actuelle de la table de symboles (nombre maximal de symbole enregistrables)
    size_t current_symb;    //< Indice du dernier symbole ajouté
    struct symbol *context; //< Table des symboles
    struct stack *prev;     //< Element suivant
};

/**
 * \struct stack_frame
 *
 * \brief
 */
struct stack_frame
{
    char *context_name;      //< Nom du contexte (ie: nom de la fonction)
    struct symbol *context;  //< Contexte
    size_t nb_symb;          //< Nombre de symboles dans le contexte
    size_t stack_frame_size; //< Taille du contexte (en octet)
};

/**
 * \brief Augmente la taille du contexte passé en argument
 *
 * \param s Contexte
 */
void increaseContextSize(struct stack *s);

/**
 * \brief Empile un nouveau contexte sur la pile des contextes
 */
void pushContext();

/**
 * \brief Retire un contexte de la pile des contextes
 *
 * \return struct stack* Pointeur vers le contexte dépilée
 */
struct stack *popContext();

/**
 * \brief Crée un nouveau symbole dans la table des symboles
 *
 * \param s Portée du symbole
 * \param name Nom du symbole
 * \param type Type du symbole
 * \param size Taille du symbole
 */
void newName(enum scope s, char *name, enum sym_type type, ssize_t size);

/**
 * \brief Recherche un symbole dans la table des symbole (à préciser)
 *
 * \param s Niveau de contexte
 * \param name Nom du symbole
 * \return struct symbol* Symbole correspondant à la recherche ou NULL si le symbole recherché n'existe pas dans le contexte
 */
struct symbol *lookUp(enum scope s, char *name);

/**
 * \brief Compte le nombre d'arguments d'une fonctions (ie: compte les symboles non locaux rencontrés dans le contexte de la fonction, à savoir le contexte au sommet de la pile)
 *
 * \return size_t Nombre d'arguments
 */
size_t countArg();

/**
 * \brief Vérifie si on est dans le contexte global ou le contexte d'une fonction (utile pour l'utilisation des return)
 *
 * \return int 0 uniquement si on est dans le contxte global
 */
int checkInsideFunction();

/**
 * \brief Crée un nouveau stack frame dans stack_frame_list
 *
 * \param name
 * \param stack
 */
void createNewStackFrame(char *name, struct stack *stack);

void printStackFrame(struct stack_frame sf);

void printAllStackFrame();

void printSymbol(struct symbol s);

void setNbArgProgramme(size_t nb);

/**
 * \brief Retrouve le contexte ayant le même nom que var
 * 
 * \param var Variable
 * \return struct stack_frame Contexte contenant la variable
 */
struct stack_frame findContext(char *var);

/**
 * \brief Indique si une variable est dans un contexte
 * 
 * \return -1 si la variable n'est pas dans le contexte, l'offset (en octet) de la variable dans le contexte sinon
 */
int isInContext(char *var, struct stack_frame context);

#endif
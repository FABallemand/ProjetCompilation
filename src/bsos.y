%{
#include <stdio.h>
#include <stdlib.h>
#include "quad.h"

extern int yylex();
extern void yyerror(const char *msg);
%}

%union {
    int int_val;
    char *str_val;

    /**
    * \struct Opérande d'un quadruplet
    *
    * \brief
    */
    struct quadop
    {
        enum
        {
            QO_CST,
            QO_CHAINE
        } kind; //< Type de l'opérateur

        union
        {
            int cst;
            char *chaine;
        } valeur; //< Valeur de l'opérateur
    } quadop;

    /**
    * \struct Quadruplet
    *
    * \brief
    */
    struct quad
    {
        enum
        {
            Q_ADDITION,
            Q_SOUSTRACTION
        } kind; //< Type de quadruplet

        struct quadop op1, op2, res; //< Opérandes
    } quad;
    
    struct {
        struct quadop result;
    } expr_val;
}

%token <str_val> CHAINE
%token MOT TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT PLUS MINUS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR
%left PLUS MINUS
%left STAR DIVISION

%start programme

%%

programme
: liste_instructions {}
;

liste_instructions
: liste_instructions SEMI_CO instruction {}
| instruction {}
;

instruction
: MOT EQUAL concatenation {} // check si mot est un ID
| MOT OABRA operande_entier CABRA EQUAL concatenation {} // check si mot est un ID
| DECLARE MOT OABRA MOT CABRA {} // check si mot est un ID et check si le deuxième mot est un ENTIER
| IF test_bloc THEN liste_instructions else_part FI {}
| FOR MOT DO liste_instructions DONE {} // check si mot est un ID
| FOR MOT IN liste_operandes DO liste_instructions DONE {} // check si mot est un ID
| WHILE test_bloc DO liste_instructions DONE {}
| UNTIL test_bloc DO liste_instructions DONE {}
| CASE operande IN liste_cas ESAC {}
| ECHO_ liste_operandes {}
| READ MOT {} // check si mot est un ID
| READ MOT OABRA operande_entier CABRA {} // check si mot est un ID
| declaration_de_fonction {}
| appel_de_fonction {}
| RETURN {}
| RETURN operande_entier {}
| EXIT {}
| EXIT operande_entier {}
;

else_part
: ELIF test_bloc THEN liste_instructions else_part {}
| ELSE liste_instructions {}
| %empty {}
;

liste_cas
: liste_cas filtre CPAR liste_instructions SEMI_CO SEMI_CO {}
| filtre CPAR liste_instructions SEMI_CO SEMI_CO {}
;

filtre
: MOT {}
| CHAINE {}
| filtre CASE_OR MOT {}
| filtre CASE_OR CHAINE {}
| STAR 
;

liste_operandes
: liste_operandes operande {}
| operande {}
| DOLLAR OBRA MOT OABRA STAR CABRA CBRA {} // check si mot est un ID
;

concatenation
: concatenation operande {}
| operande {}
;

test_bloc
: TEST test_expr {}
;

test_expr
: test_expr C_OR test_expr2 {}
| test_expr2 {}
;

test_expr2
: test_expr2 C_AND test_expr3 {}
| test_expr3 {}
;

test_expr3
: OPAR test_expr CPAR {}
| NOT OPAR test_expr CPAR {}
| test_instruction {}
| NOT test_instruction {}
;

test_instruction
: concatenation EQUAL concatenation {}
| concatenation NOT_EQUAL concatenation {}
| operateur1 concatenation {}
| operande operateur2 operande {}
;

operande
: DOLLAR OBRA MOT CBRA {} // check si mot est un ID
| DOLLAR OBRA MOT OABRA operande_entier CABRA CBRA {} // check si mot est un ID
| MOT {}
| DOLLAR MOT {} // check si mot est un ENTIER
| DOLLAR STAR  {}
| DOLLAR STATUS {}
| CHAINE {}
| DOLLAR OPAR EXPR somme_entiere CPAR {}
| DOLLAR OPAR appel_de_fonction CPAR {}
;

operateur1
: T_NOT_EMPTY {}
| T_EMPTY {}
;

operateur2
: T_EQUAL {}
| T_NOT_EQUAL {}
| T_GT {}
| T_GE {}
| T_LT {}
| T_LE {}
;

somme_entiere
: somme_entiere plus_ou_moins produit_entier {}
| produit_entier {}
;

produit_entier
: produit_entier fois_div_mod operande_entier {}
| operande_entier {}
;

operande_entier
: DOLLAR OBRA MOT CBRA {} // check si mot est un ID
| DOLLAR OBRA MOT OABRA operande_entier CABRA CBRA {} // check si mot est un ID
| DOLLAR MOT {} //check si mot est un ENTIER
| plus_ou_moins DOLLAR OBRA MOT CBRA {} // check si mot est un ID
| plus_ou_moins DOLLAR OBRA MOT OABRA operande_entier CABRA CBRA {} // check si mot est un ID
| plus_ou_moins DOLLAR MOT {} //check si mot est un ENTIER
| MOT {} //check si mot est un ENTIER
| plus_ou_moins MOT {} //check si mot est un ENTIER
| OPAR somme_entiere CPAR {}
;

plus_ou_moins
: PLUS {printf("plus\n");}
| MINUS {}
;

fois_div_mod
: STAR  {}
| DIVISION {}
| MOD {}
;

declaration_de_fonction
: MOT OPAR CPAR OBRA decl_loc liste_instructions CBRA {} // check si mot est un ID
;


decl_loc
: decl_loc LOCAL MOT EQUAL concatenation SEMI_CO {} // check si mot est un ID
| %empty {}
;

appel_de_fonction
: MOT liste_operandes {} // check si mot est un ID
| MOT {} // check si mot est un ID
;

%%

void yyerror(const char *msg)
{
    fprintf(stderr, "Erreur syntaxique : %s\n", msg);
}
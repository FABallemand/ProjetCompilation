%{
#include <stdio.h>
#include <stdlib.h>
#include "quad.h"

extern int yylex();
extern void yyerror(const char *msg);

/*
Rq: -Espace avant les ";" de fin de ligne ?

Actions: -Expr. arithmétiques
         -Expr. bool
         -Instructions (affectations en premier)
*/
%}

%union {
    int int_val;

    char *str_val;

    struct {
        struct quadop result;
    } expr_val;
}

%token <str_val> STRING
%token WORD TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT PLUS MINUS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR
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
: WORD EQUAL concatenation {} // check si WORD est un ID
| WORD OABRA operande_entier CABRA EQUAL concatenation {} // check si WORD est un ID
| DECLARE WORD OABRA WORD CABRA {} // check si WORD est un ID et check si le deuxième WORD est un ENTIER
| IF test_bloc THEN liste_instructions else_part FI {}
| FOR WORD DO liste_instructions DONE {} // check si WORD est un ID
| FOR WORD IN liste_operandes DO liste_instructions DONE {} // check si WORD est un ID
| WHILE test_bloc DO liste_instructions DONE {}
| UNTIL test_bloc DO liste_instructions DONE {}
| CASE operande IN liste_cas ESAC {}
| ECHO_ liste_operandes {}
| READ WORD {} // check si WORD est un ID
| READ WORD OABRA operande_entier CABRA {} // check si WORD est un ID
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
: WORD {}
| STRING {}
| filtre CASE_OR WORD {}
| filtre CASE_OR STRING {}
| STAR 
;

liste_operandes
: liste_operandes operande {}
| operande {}
| DOLLAR OBRA WORD OABRA STAR CABRA CBRA {} // check si WORD est un ID
;

concatenation
: concatenation operande {}
| operande {}
;

test_bloc
: TEST test_expr {}
;

test_expr
: test_expr C_OR test_expr2 {/*complete($1.true, 1er quad de calcul après la condition);
                             $$.true = concat($1.true, $3.true);
                             $$.false = concat($1.false, $3.false);*/} // true = ltrue
| test_expr2 {}
;

test_expr2
: test_expr2 C_AND test_expr3 {/*complete($1.true, 1er quad de calcul de $3);
                               $$.true = $3.true;
                               $$.false = concat($1.false, $3.false);*/}
| test_expr3 {}
;

test_expr3
: OPAR test_expr CPAR {/*$$.true = $2.true;
                       $$.false = $2.false;*/}
| NOT OPAR test_expr CPAR {/*$$.true = $3.false;
                           $$.false = $3.true;*/}
| test_instruction {}
| NOT test_instruction {/*$$.true = $2.false;
                        $$.false = $2.true;*/}
;

test_instruction
: concatenation EQUAL concatenation {/*$$.true = creeListe(nextquad);
                                     genCode(...);
                                     $$.false = creeListe(nextquad);
                                     genCode(...);*/}
| concatenation NOT_EQUAL concatenation {/*$$.true = creeListe(nextquad);
                                         genCode(...);
                                         $$.false = creeListe(nextquad);
                                         genCode(...);*/}
| operateur1 concatenation {}
| operande operateur2 operande {} // Faire une règle par opérateur -> supprimer operateur2??
;

operande
: DOLLAR OBRA WORD CBRA {} // check si WORD est un ID
| DOLLAR OBRA WORD OABRA operande_entier CABRA CBRA {} // check si WORD est un ID
| WORD {}
| DOLLAR WORD {} // check si WORD est un ENTIER
| DOLLAR STAR  {}
| DOLLAR STATUS {}
| STRING {}
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
: DOLLAR OBRA WORD CBRA {} // check si WORD est un ID
| DOLLAR OBRA WORD OABRA operande_entier CABRA CBRA {} // check si WORD est un ID
| DOLLAR WORD {} //check si WORD est un ENTIER
| plus_ou_moins DOLLAR OBRA WORD CBRA {} // check si WORD est un ID
| plus_ou_moins DOLLAR OBRA WORD OABRA operande_entier CABRA CBRA {} // check si WORD est un ID
| plus_ou_moins DOLLAR WORD {} //check si WORD est un ENTIER
| WORD {} //check si WORD est un ENTIER
| plus_ou_moins WORD {} //check si WORD est un ENTIER
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
: WORD OPAR CPAR OBRA decl_loc liste_instructions CBRA {} // check si WORD est un ID
;


decl_loc
: decl_loc LOCAL WORD EQUAL concatenation SEMI_CO {} // check si WORD est un ID
| %empty {}
;

appel_de_fonction
: WORD liste_operandes {} // check si WORD est un ID
| WORD {} // check si WORD est un ID
;

%%

void yyerror(const char *msg)
{
    fprintf(stderr, "Erreur syntaxique : %s\n", msg);
}
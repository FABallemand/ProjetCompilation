%{
#include <stdio.h>
#include <stdlib.h>
#include "code.h"
#include "quad.h"
#include "list.h"

extern int yylex();
extern void yyerror(const char *msg);

%}

%union {
    int int_val;

    char *str_val; //string + id

    struct {
        struct quadop result;
    } expr_val;

    struct {
        struct list* true_l;
        struct list* false_l;
    } bool_val;

    struct {
        struct list* next;
    } inst_val;
}

%token TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT PLUS MINUS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR

%token <int_val> INTEGER

%token <str_val> STRING ID

%type <inst_val> instruction liste_instructions

%type <bool_val> test_bloc test_expr test_expr2 test_expr3 test_instruction

%type <expr_val> concatenation operande

%left PLUS MINUS
%left STAR DIVISION MOD

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
: ID EQUAL concatenation 
{
    genCode(quad_new(Q_AFFECT,$3.result,quadop_empty(),quadop_var($1)));
}
| ID OABRA operande_entier CABRA EQUAL concatenation {}
| DECLARE ID OABRA INTEGER CABRA {}
| IF test_bloc THEN liste_instructions else_part FI {}
| FOR ID DO liste_instructions DONE {}
| FOR ID IN liste_operandes DO liste_instructions DONE {}
| WHILE test_bloc DO liste_instructions DONE {}
| UNTIL test_bloc DO liste_instructions DONE {}
| CASE operande IN liste_cas ESAC {}
| ECHO_ liste_operandes {}
| READ ID {}
| READ ID OABRA operande_entier CABRA {}
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
: STRING {}
| filtre CASE_OR STRING {}
| STAR 
;

liste_operandes
: liste_operandes operande {}
| operande {}
| DOLLAR OBRA ID OABRA STAR CABRA CBRA {}
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
| T_NOT_EMPTY concatenation {}
| T_EMPTY concatenation {}
| operande T_EQUAL operande {} 
| operande T_NOT_EQUAL operande {} 
| operande T_GT operande {} 
| operande T_GE operande {} 
| operande T_LT operande {} 
| operande T_LE operande {} 
;

operande
: DOLLAR OBRA ID CBRA {}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| DOLLAR INTEGER {}
| DOLLAR STAR  {}
| DOLLAR STATUS {}
| INTEGER {$$.result = quadop_cst($1);}
| STRING {}
| DOLLAR OPAR EXPR somme_entiere CPAR {}
| DOLLAR OPAR appel_de_fonction CPAR {}
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
: DOLLAR OBRA ID CBRA {}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| DOLLAR INTEGER {}
| plus_ou_moins DOLLAR OBRA ID CBRA {}
| plus_ou_moins DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| plus_ou_moins DOLLAR INTEGER {}
| INTEGER {}
| plus_ou_moins INTEGER {}
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
: ID OPAR CPAR OBRA decl_loc liste_instructions CBRA {}
;


decl_loc
: decl_loc LOCAL ID EQUAL concatenation SEMI_CO {}
| %empty {}
;

appel_de_fonction
: ID liste_operandes {}
| ID {}
;

%%

void yyerror(const char *msg)
{
    fprintf(stderr, "Erreur syntaxique : %s\n", msg);
}
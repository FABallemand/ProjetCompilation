%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern void yyerror(const char *msg);
%}

%token TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT COMMENT ID MOT CHAINE ENTIER PLUS MOINS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR
%left PLUS MOINS
%left STAR DIVISION
%left UMOINS

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
: ID EQUAL concatenation {}
| ID OABRA operande_entier CABRA EQUAL concatenation {}
| DECLARE ID OABRA ENTIER CABRA {}
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
: MOT {}
| CHAINE {}
| filtre CASE_OR MOT {}
| filtre CASE_OR CHAINE {}
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
: DOLLAR OBRA ID CBRA {}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| MOT {}
| DOLLAR ENTIER {}
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
: DOLLAR OBRA ID CBRA {}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| DOLLAR ENTIER {}
| plus_ou_moins DOLLAR OBRA ID CBRA {}
| plus_ou_moins DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| plus_ou_moins DOLLAR ENTIER {}
| ENTIER {}
| plus_ou_moins ENTIER {}
| OPAR somme_entiere CPAR {}
;

plus_ou_moins
: PLUS {}
| MOINS {}
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
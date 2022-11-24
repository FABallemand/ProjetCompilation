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
        size_t firstquad;
        struct quadop result;
    } expr_val;

    struct {
        size_t firstquad;
        struct list* ltrue;
        struct list* lfalse;
    } bool_val;

    struct {
        size_t firstquad;
        struct list* next;
    } inst_val;
}

%token TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT PLUS MINUS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR

%token <int_val> INTEGER

%token <str_val> STRING ID

%type <inst_val> instruction liste_instructions else_part g

%type <bool_val> test_bloc test_expr test_expr2 test_expr3 test_instruction

%type <expr_val> concatenation operande somme_entiere produit_entier operande_entier

%left PLUS MINUS
%left STAR DIVISION MOD
%left UMINUS

%start programme

%%

programme
: liste_instructions {}
;

liste_instructions
: liste_instructions SEMI_CO instruction
{
    $$.firstquad = $1.firstquad;
    complete($1.next, $3.firstquad);
    $$.next = $3.next;
}
| instruction
{
    $$.firstquad = $1.firstquad;
    $$.next = $1.next;
}
;

instruction
: ID EQUAL concatenation 
{
    $$.firstquad = next_quad;
    genCode(quad_new(Q_AFFECT,$3.result,quadop_empty(),quadop_var($1)));
}
| ID OABRA operande_entier CABRA EQUAL concatenation {}
| DECLARE ID OABRA INTEGER CABRA {}
| IF test_bloc THEN liste_instructions g else_part FI
{
    $$.firstquad = $2.firstquad;
    complete($2.ltrue, $4.firstquad);
    if ($5.next != NULL)
    {
        complete($2.lfalse, $6.firstquad);
        $$.next = concat($4.next, $5.next);
    }
    else
    {
        $$.next = concat($2.lfalse, $4.next);
    }
    $$.next = concat($$.next, $6.next);
    // à vérifier
}
| FOR ID DO liste_instructions DONE
{
    
}
| FOR ID IN liste_operandes DO liste_instructions DONE
{
    
}
| WHILE test_bloc DO liste_instructions g DONE
{
    $$.firstquad = $2.firstquad; // A FAIRE PARTOUT
    complete($2.ltrue, $4.firstquad);
    $$.next = $2.lfalse;
    complete($4.next, $2.firstquad);
    complete($5.next, $2.firstquad);
}
| UNTIL test_bloc DO liste_instructions g DONE
{
    $$.firstquad = $2.firstquad; // A FAIRE PARTOUT
    complete($2.lfalse, $4.firstquad);
    $$.next = $2.ltrue;
    complete($4.next, $2.firstquad);
    complete($5.next, $2.firstquad);
}
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
: ELIF test_bloc THEN liste_instructions g else_part
{
    $$.firstquad = $2.firstquad;
    complete($2.ltrue, $4.firstquad);
    if ($5.next != NULL)
    {
        complete($2.lfalse, $6.firstquad);
        $$.next = concat($4.next, $5.next);
    }
    else
    {
        $$.next = concat($2.lfalse, $4.next);
    }
    $$.next = concat($$.next, $6.next);
    // à vérifier
}
| ELSE liste_instructions
{
    $$.firstquad = $2.firstquad;
    $$.next = $2.next;
}
| %empty 
{
    $$.next = NULL;
}
;

liste_cas
: liste_cas filtre CPAR liste_instructions SEMI_CO SEMI_CO {}
| filtre CPAR liste_instructions SEMI_CO SEMI_CO {}
;

filtre
: STRING
{

}
| filtre CASE_OR STRING {}
| STAR 
;

liste_operandes
: liste_operandes operande {}
| operande {}
| DOLLAR OBRA ID OABRA STAR CABRA CBRA {}
;

concatenation
: concatenation operande
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_ADD, $1.result, $2.result, result));
    $$.result = result;
}
| operande
{
    $$.firstquad = $1.firstquad;
}
;

test_bloc
: TEST test_expr
{
    $$ = $2;
}
;

test_expr
: test_expr C_OR test_expr2
{
    $$.firstquad = $1.firstquad;
    complete($1.lfalse, $3.firstquad);
    $$.ltrue = concat($1.ltrue, $3.ltrue);
    $$.lfalse = $3.lfalse;
}
| test_expr2
{
    $$.firstquad = $1.firstquad;
    $$ = $1;
}
;

test_expr2
: test_expr2 C_AND test_expr3
{
    $$.firstquad = $1.firstquad;
    complete($1.ltrue, $3.firstquad);
    $$.ltrue = $3.ltrue;
    $$.lfalse = concat($1.lfalse, $3.lfalse);
}
| test_expr3
{
    $$.firstquad = $1.firstquad;
    $$ = $1;
}
;

test_expr3
: OPAR test_expr CPAR
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = $2.ltrue;
    $$.lfalse = $2.lfalse;
}
| NOT OPAR test_expr CPAR
{
    $$.firstquad = $3.firstquad;
    $$.ltrue = $3.lfalse;
    $$.lfalse = $3.ltrue;
}
| test_instruction
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = $1.ltrue;
    $$.lfalse = $1.lfalse;
}
| NOT test_instruction
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = $2.lfalse;
    $$.lfalse = $2.ltrue;
}
;

test_instruction
: concatenation EQUAL concatenation
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EQUAL_STRING, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| concatenation NOT_EQUAL concatenation
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_NOT_EQUAL_STRING, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| T_NOT_EMPTY concatenation
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_N_EMP, $2.result, quadop_empty(), quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| T_EMPTY concatenation
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EMP, $2.result, quadop_empty(), quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| operande T_EQUAL operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EQUAL, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| operande T_NOT_EQUAL operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_NOT_EQUAL, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| operande T_GT operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_GT, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| operande T_GE operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_GE, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| operande T_LT operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_LT, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
| operande T_LE operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_LE, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
;

operande
: DOLLAR OBRA ID CBRA {}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| DOLLAR INTEGER {}
| DOLLAR STAR  {}
| DOLLAR STATUS {}
| INTEGER {$$.result = quadop_cst($1);}
| STRING
{
    $$.firstquad = next_quad;
    $$.result = quadop_string($1);
}
| DOLLAR OPAR EXPR somme_entiere CPAR {}
| DOLLAR OPAR appel_de_fonction CPAR {}
;

somme_entiere
: somme_entiere PLUS produit_entier
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_ADD, $1.result, $3.result, result));
    $$.result = result;
}
| somme_entiere MINUS produit_entier
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_SUB, $1.result, $3.result, result));
    $$.result = result;
}
| produit_entier
{
    $$.firstquad = $1.firstquad;
    $$.result = $1.result;
}
;

produit_entier
: produit_entier STAR operande_entier
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_MUL, $1.result, $3.result, result));
    $$.result = result;
}
| produit_entier DIVISION operande_entier
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_DIV, $1.result, $3.result, result));
    $$.result = result;
}
| produit_entier MOD operande_entier
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_MOD, $1.result, $3.result, result));
    $$.result = result;
}
| operande_entier
{
    $$.firstquad = $1.firstquad;
    $$.result = $1.result;
}
;

operande_entier
: DOLLAR OBRA ID CBRA {}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| DOLLAR INTEGER {}
| PLUS DOLLAR OBRA ID CBRA {}
| MINUS DOLLAR OBRA ID CBRA %prec UMINUS{}
| PLUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA {}
| MINUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA %prec UMINUS {}
| PLUS DOLLAR INTEGER {}
| MINUS DOLLAR INTEGER %prec UMINUS{}
| INTEGER
{
    $$.result = quadop_cst($1);
}
| PLUS INTEGER
{
    $$.result = quadop_cst($2);
}
| MINUS INTEGER %prec UMINUS
{
    $$.result = quadop_cst(-$2);
}
| OPAR somme_entiere CPAR
{
    $$ = $2;
}
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

g
: %empty
{
    $$.next = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty()));
}
;

%%

void yyerror(const char *msg)
{
    fprintf(stderr, "Erreur syntaxique : %s\n", msg);
}
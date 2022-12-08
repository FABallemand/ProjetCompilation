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
    char *val; //string + id + int

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

    struct {
        size_t firstquad;
        size_t size;
    } list_op_val;
}

%token TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT PLUS MINUS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR

%token <val> INTEGER STRING ID

%type <inst_val> instruction liste_instructions else_part g decl_loc

%type <bool_val> test_bloc test_expr test_expr2 test_expr3 test_instruction

%type <expr_val> concatenation operande somme_entiere produit_entier operande_entier

%type <list_op_val> liste_operandes

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
    $$.firstquad = $3.firstquad;
    genCode(quad_new(Q_AFFECT,$3.result,quadop_empty(),quadop_var($1)));
    $$.next = NULL;
}
| ID OABRA operande_entier CABRA EQUAL concatenation 
{
    $$.firstquad = $3.firstquad;
    // a fix ! c'est temporaire
    genCode(quad_new(Q_AFFECT,$6.result,quadop_empty(),quadop_var($1)));
    $$.next = NULL;
}
| DECLARE ID OABRA INTEGER CABRA
{
    //au final ça ne produira pas de quad (car pas d'instruction MIPS généré) -> a faire avec la table des symboles
    $$.firstquad = next_quad;
    genCode(quad_new(Q_DECLARE, quadop_cst($4), quadop_empty(), quadop_var($2)));
    $$.next = NULL;
}
| IF test_bloc THEN liste_instructions g else_part FI
{
    $$.firstquad = $2.firstquad;
    complete($2.ltrue, $4.firstquad);
    if ($6.next != NULL) // else_part
    {
        complete($2.lfalse, $6.firstquad);
    }
    else // pas de else_part
    {
        $$.next = concat($$.next, $2.lfalse);
    }
    $$.next = concat($$.next, $4.next);
    $$.next = concat($$.next, $5.next);
    $$.next = concat($$.next, $6.next); // n'a d'effet que quand il y a une else_part
}
| FOR ID DO liste_instructions DONE
{
    
}
| FOR ID IN liste_operandes DO liste_instructions DONE
{
    // $$firstquad = 
}
| WHILE test_bloc DO liste_instructions g DONE
{
    $$.firstquad = $2.firstquad;
    // test_bloc (true/false)
    complete($2.ltrue, $4.firstquad);
    $$.next = $2.lfalse;
    // fin de liste_instructions*
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
| CASE operande IN liste_cas ESAC
{

}
| ECHO_ liste_operandes
{
    $$.firstquad = $2.firstquad;
    genCode(quad_new(Q_ECHO, quadop_empty(), quadop_empty(), quadop_empty()));
}
| READ ID {}
| READ ID OABRA operande_entier CABRA {}
| declaration_de_fonction {}
| appel_de_fonction {}
| RETURN
{
    $$.firstquad = next_quad;
    genCode(quad_new(Q_RETURN, quadop_empty(), quadop_empty(), quadop_empty()));
}
| RETURN operande_entier
{
    $$.firstquad = $2.firstquad;
    genCode(quad_new(Q_RETURN_VAL, $2.result, quadop_empty(), quadop_empty()));
}
| EXIT
{
    $$.firstquad = next_quad;
    genCode(quad_new(Q_EXIT, quadop_empty(), quadop_empty(), quadop_empty()));
}
| EXIT operande_entier
{
    $$.firstquad = $2.firstquad;
    genCode(quad_new(Q_EXIT_VAL, $2.result, quadop_empty(), quadop_empty()));
}
;

else_part
: ELIF test_bloc THEN liste_instructions g else_part
{
    $$.firstquad = $2.firstquad;
    complete($2.ltrue, $4.firstquad);
    if ($6.next != NULL) // else_part
    {
        complete($2.lfalse, $6.firstquad);
    }
    else // pas de else_part
    {
        $$.next = concat($$.next, $2.lfalse);
    }
    $$.next = concat($$.next, $4.next);
    $$.next = concat($$.next, $5.next);
    $$.next = concat($$.next, $6.next); // n'a d'effet que quand il y a une else_part
}
| ELSE liste_instructions g
{
    $$.firstquad = $2.firstquad;
    $$.next = concat($2.next,$3.next);
}
| %empty 
{
    $$.next = NULL;
}
;

liste_cas
: liste_cas filtre CPAR liste_instructions SEMI_CO SEMI_CO
{

}
| filtre CPAR liste_instructions SEMI_CO SEMI_CO
{

}
;

filtre
: STRING
{

}
| filtre CASE_OR STRING
{

}
| STAR
{

}
;

liste_operandes
: liste_operandes operande
{
    $$.firstquad = $1.firstquad;
    $$.size = $1.size + 1;
    char test[3];
    sprintf(test, "%ld", $$.size);
    genCode(quad_new(Q_AFFECT, $2.result, quadop_empty(), quadop_var(strdup(test)))); // conflit dans la table des symboles??
}
| operande
{
    $$.firstquad = $1.firstquad;
    $$.size = 1;
    genCode(quad_new(Q_AFFECT, $1.result, quadop_empty(), quadop_var("1")));
}
| DOLLAR OBRA ID OABRA STAR CABRA CBRA
{}
;

concatenation
: concatenation operande
{
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_CONCAT, $1.result, $2.result, result));
    $$.result = result;
}
| operande
{
    $$.firstquad = $1.firstquad;
    $$.result = $1.result;
}
;

test_bloc
: TEST test_expr
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = $2.ltrue;
    $$.lfalse = $2.lfalse;
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
    $$.ltrue = $1.ltrue;
    $$.lfalse = $1.lfalse;
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
    $$.ltrue = $1.ltrue;
    $$.lfalse = $1.lfalse;
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
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| concatenation NOT_EQUAL concatenation
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_NOT_EQUAL_STRING, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| T_NOT_EMPTY concatenation
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_N_EMP, $2.result, quadop_empty(), quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| T_EMPTY concatenation
{
    $$.firstquad = $2.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EMP, $2.result, quadop_empty(), quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_EQUAL operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EQUAL, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_NOT_EQUAL operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_NOT_EQUAL, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_GT operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_GT, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_GE operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_GE, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_LT operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_LT, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_LE operande
{
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_LE, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
;

operande
: DOLLAR OBRA ID CBRA
{
    $$.firstquad = next_quad;
}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    $$.firstquad = next_quad;
}
| DOLLAR INTEGER
{
    $$.firstquad = next_quad;
}
| DOLLAR STAR
{
    $$.firstquad = next_quad;
}
| DOLLAR STATUS
{
    $$.firstquad = next_quad;
}
| INTEGER // -INTEGER / +INTEGER
{
    $$.firstquad = next_quad;
    $$.result = quadop_cst($1);
}
| STRING
{
    $$.firstquad = next_quad;
    $$.result = quadop_string($1);
}
| DOLLAR OPAR EXPR somme_entiere CPAR
{
    $$.firstquad = $4.firstquad;
    $$.result = $4.result;
}
| DOLLAR OPAR appel_de_fonction CPAR
{
    $$.firstquad = next_quad;
}
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
    $$.firstquad = next_quad;
    $$.result = quadop_cst($1);
}
| PLUS INTEGER
{
    $$.firstquad = next_quad;
    $$.result = quadop_cst($2);
}
| MINUS INTEGER %prec UMINUS
{
    $$.firstquad = next_quad;
    $$.result = quadop_cst(strcat("-", $2));
}
| OPAR somme_entiere CPAR
{
    $$.firstquad = $2.firstquad;
    //
}
;

declaration_de_fonction
: ID OPAR CPAR OBRA decl_loc liste_instructions CBRA {}
;

decl_loc
: decl_loc LOCAL ID EQUAL concatenation SEMI_CO
{
    //au final ça ne produira pas de quad (car pas d'instruction MIPS généré) -> a faire avec la table des symboles
    $$.firstquad = $1.firstquad;
    genCode(quad_new(Q_LOCAL, $5.result, quadop_empty(), quadop_var($3)));
}
| %empty
{
    $$.firstquad = next_quad;
}
;

appel_de_fonction
: ID liste_operandes {}
| ID {}
;

g
: %empty
{
    $$.next = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
;

%%

void yyerror(const char *msg)
{
    fprintf(stderr, "Erreur syntaxique : %s\n", msg);
}
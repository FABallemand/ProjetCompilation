%{
#include <stdio.h>
#include <stdlib.h>

#include "error_handling.h"

#include "code.h"
#include "quad.h"
#include "list.h"
#include "symbol_table.h"

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
        // int return_value; //< Vrai si la liste d'instruction contient un return <operande entier>
    } inst_val;

    struct {
        size_t firstquad;
        size_t size;
    } list_op_val;
}

%token TEST EXPR LOCAL DECLARE IF THEN ELIF ELSE FI FOR WHILE UNTIL CASE ESAC IN DO DONE READ ECHO_ RETURN EXIT PLUS MINUS STAR DIVISION EQUAL NOT_EQUAL NOT MOD CASE_OR SEMI_CO OPAR CPAR OBRA CBRA OABRA CABRA DOLLAR STATUS T_NOT_EMPTY T_EMPTY T_EQUAL T_NOT_EQUAL T_GT T_GE T_LT T_LE C_AND C_OR

%token <val> INTEGER STRING ID

%type <inst_val> instruction liste_instructions else_part g decl_loc declaration_de_fonction

%type <bool_val> test_bloc test_expr test_expr2 test_expr3 test_instruction

%type <expr_val> concatenation operande somme_entiere produit_entier operande_entier appel_de_fonction

%type <list_op_val> liste_operandes

%left PLUS MINUS
%left STAR DIVISION MOD
%left UMINUS

%start programme

%%

programme
: {
    pushContext();
    newName(S_GLOBAL, "?", VAR, 0);
    genCode(quad_new(Q_AFFECT, quadop_cst(0), quadop_empty(), quadop_var("?")));
}
liste_instructions
{
    popContext();
}
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
    struct symbol *id = lookUp(S_AUTO, $1);
    if(id == NULL)
    {
        newName(S_GLOBAL, $1, VAR, 0);
    }
    genCode(quad_new(Q_AFFECT, $3.result, quadop_empty(), quadop_var($1)));
    $$.next = NULL;
}
| ID OABRA operande_entier CABRA EQUAL concatenation 
{
    $$.firstquad = $3.firstquad;
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable %s non définie", $1);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $1);
        exit(1);
    }
    else if($3.result.kind == QO_CST && id->size <= atoi($3.result.qval.value)) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %ld en dehors du tableau %s)", atoi($3.result.qval.value), $1);
        exit(1);
    }
    genCode(quad_new(Q_AFFECT,$6.result,quadop_empty(),quadop_var($1)));
    $$.next = NULL;
}
| DECLARE ID OABRA INTEGER CABRA
{
    $$.firstquad = next_quad;
    if(lookUp(S_GLOBAL, $2)) // Variable déjà utilisée dans le contexte S_GLOBAL
    {
        printError("Variable %s déjà utilisée dans le contexte global", $2);
        exit(1);
    }
    else // Création d'un nouveau tableau dans le contexte S_GLOBAL
    {
        newName(S_GLOBAL, $2, TAB, atoi($4));
    }
    // genCode(quad_new(Q_DECLARE, quadop_cst($4), quadop_empty(), quadop_var($2)));
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
    // $$.firstquad = $.firstquad;
    struct symbol *id = lookUp(S_AUTO, $2);
    if(id == NULL)
    {
        newName(S_GLOBAL, $2, VAR, 0);
    }
}
| FOR ID IN liste_operandes DO liste_instructions DONE
{
    // $$.firstquad = $.firstquad;
    struct symbol *id = lookUp(S_AUTO, $2);
    if(id == NULL)
    {
        newName(S_GLOBAL, $2, VAR, 0);
    }
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
| READ ID
{
    struct symbol *id = lookUp(S_AUTO, $2);
    if(id == NULL)
    {
        newName(S_GLOBAL, $2, VAR, 0);
    }

    // FAIRE READ
}
| READ ID OABRA operande_entier CABRA
{
    struct symbol *id = lookUp(S_GLOBAL, $2);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable %s non-définie", $2);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $2);
        exit(1);
    }
    else if($4.result.kind == QO_CST && id->size <= atoi($4.result.qval.value)) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %ld en dehors du tableau)", atoi($4.result.qval.value));
        exit(1);
    }

    // FAIRE READ
}
| declaration_de_fonction
{

}
| appel_de_fonction
{

}
| RETURN
{
    $$.firstquad = next_quad;
    // $$.return_value = 0; // A faire partout ailleurs
    genCode(quad_new(Q_RETURN, quadop_empty(), quadop_empty(), quadop_empty()));
}
| RETURN operande_entier
{
    $$.firstquad = $2.firstquad;
    // $$.return_value = 1;
    genCode(quad_new(Q_RETURN_VAL, $2.result, quadop_empty(), quadop_empty())); // Mettre "?" à $2.result
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
    struct symbol *id = lookUp(S_AUTO, $3);
    if(id == NULL)
    {
        printError("Variable %s non définie", $3);
        exit(1);
    }

    $$.result = quadop_var($3);
}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $3);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable %s non définie", $3);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $3);
        exit(1);
    }
    else if($5.result.kind == QO_CST && id->size <= atoi($5.result.qval.value)) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %ld en dehors du tableau %s)", atoi($5.result.qval.value), $3);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_ARRAY_GET, quadop_var($3), $5.result, res));
    $$.result = res;
}
| DOLLAR INTEGER
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_LOCAL, $2);
    if(id == NULL)
    {
        newName(S_LOCAL, $2, ARG, 0);
    }
    $$.result = quadop_var($2);
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
: DOLLAR OBRA ID CBRA
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $3);
    if(id == NULL)
    {
        printError("Variable %s non définie", $3);
        exit(1);
    }

    // FAIRE ACTION
}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $3);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable %s non définie", $3);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $3);
        exit(1);
    }
    else if($5.result.kind == QO_CST && id->size <= atoi($5.result.qval.value)) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %ld en dehors du tableau %s)", atoi($5.result.qval.value), $3);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_ARRAY_GET, quadop_var($3), $5.result, res));
    $$.result = res;
}
| DOLLAR INTEGER
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_LOCAL, $2);
    if(id == NULL)
    {
        newName(S_LOCAL, $2, ARG, 0);
    }
    // Faire quadop
}
| PLUS DOLLAR OBRA ID CBRA
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $4);
    if(id == NULL)
    {
        printError("Variable %s non définie", $4);
        exit(1);
    }

    // FAIRE ACTION
}
| MINUS DOLLAR OBRA ID CBRA %prec UMINUS
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $4);
    if(id == NULL)
    {
        printError("Variable %s non définie", $4);
        exit(1);
    }

    // FAIRE ACTION
}
| PLUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $4);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable %s non définie", $4);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $4);
        exit(1);
    }
    else if($6.result.kind == QO_CST && id->size <= atoi($6.result.qval.value)) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %ld en dehors du tableau %s)", atoi($6.result.qval.value), $4);
        exit(1);
    }

    // FAIRE ACTION
}
| MINUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA %prec UMINUS
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $4);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable %s non définie", $4);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $4);
        exit(1);
    }
    else if($6.result.kind == QO_CST && id->size <= atoi($6.result.qval.value)) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %ld en dehors du tableau %s)", atoi($6.result.qval.value), $4);
        exit(1);
    }

    // FAIRE ACTION
}
| PLUS DOLLAR INTEGER
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_LOCAL, $3);
    if(id == NULL)
    {
        newName(S_LOCAL, $3, ARG, 0);
    }
    // Faire quadop
}
| MINUS DOLLAR INTEGER %prec UMINUS
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_LOCAL, $3);
    if(id == NULL)
    {
        newName(S_LOCAL, $3, ARG, 0);
    }
    // Faire quadop, attention au signe (créer variable temporaire et vérifier entier)
}
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
: ID
    {
        struct symbol *id = lookUp(S_GLOBAL, $1);
        if(id != NULL) // Fonction déjà définie
        {
            printError("Fonction %s déjà définie", $1);
            exit(1);
        }
        newName(S_GLOBAL, $1, FUN, -1);
        pushContext();
    }
OPAR CPAR OBRA decl_loc liste_instructions CBRA
{
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // ERREUR TRES GRAVE
    {
        printError("Fonction %s non définie (ERREUR TRES GRAVE)", $1);
        exit(1); 
    }

    // GEstion des arguments de la fonction
    id->size = countArg();
    removeCallList(id); // Pour les fonctions rec :)

    // Gestion du retour de la fonction
    // if($7.return_value)
    // {
    //     id->type = FUN;
    // }
}
;

decl_loc
: decl_loc LOCAL ID EQUAL concatenation SEMI_CO
{
    //au final ça ne produira pas de quad (car pas d'instruction MIPS généré) -> a faire avec la table des symboles
    $$.firstquad = $1.firstquad;
    struct symbol *id = lookUp(S_LOCAL, $3);
    if(id != NULL) // Variable locale déjà définie
    {
        printError("Variable locale %s déjà définie", $3);
        exit(1);
    }
    newName(S_LOCAL, $3, VAR, 0);
    genCode(quad_new(Q_AFFECT, $5.result, quadop_empty(), quadop_var($3)));
}
| %empty
{
    $$.firstquad = next_quad;
}
;

appel_de_fonction
: ID liste_operandes
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // Fonction pas définie
    {
        printError("Fonciton %s non définie", $1);
        exit(1);
    }
    else if(id->type != FUN) // Fonction n'est pas une fonction
    {
        printError("Symbole %s n'est pas une fonction", $1);
        exit(1);
    }
    else if (id->size == -1) // Appel de fonction non résolu (il faut vérifier le nombre d'arguments)
    {
        addCallList($2.size, id);
    }
    else if ($2.size != id->size) // Nombre d'arguments invalide
    {
        printError("Appel de fonction %s invalide (nombre d'arguments incorrect)", $1);
        exit(1);
    }
}
| ID
{
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // Fonction pas définie
    {
        printError("Fonciton %s non définie", $1);
        exit(1);
    }
    else if(id->type != FUN) // Fonction n'est pas une fonction
    {
        printError("Symbole %s n'est pas une fonction", $1);
        exit(1);
    }
    else if (id->size == -1) // Appel de fonction non résolu (il faut vérifier le nombre d'arguments)
    {
        addCallList(0, id);
    }
    else if (0 != id->size) // Nombre d'arguments invalide
    {
        printError("Appel de fonction %s invalide (nombre d'arguments incorrect)", $1);
        exit(1);
    }
}
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
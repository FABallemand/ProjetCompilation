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

char name_global[7] = "global";
char return_value[14] = "_return_value";
char status[2] = "?";
char zero[2] = "0";
char empty[2] = "\0";
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

%type <inst_val> instruction liste_instructions else_part g decl_loc declaration_de_fonction

%type <bool_val> test_bloc test_expr test_expr2 test_expr3 test_instruction

%type <expr_val> concatenation operande somme_entiere produit_entier operande_entier appel_de_fonction

%type <list_op_val> liste_operandes liste_operandes_echo

%left PLUS MINUS
%left STAR DIVISION MOD
%left UMINUS

%start programme

%%

programme
: initialisation liste_instructions
{
    if(DEBUG)
        printRule("initialisation liste_instructions");
    setNbArgProgramme(countArg());
    createNewStackFrame(name_global, popContext());
    if(global_code[next_quad - 1].kind != Q_EXIT)
    {
        printError("Instruction de fin de programme manquante");
        exit(1);
    }
}
;

initialisation 
: %empty
{
    if(DEBUG)
        printRule("empty (initialisation)");
    pushContext();
    newName(S_GLOBAL, status, VAR, 0);
    genCode(quad_new(Q_AFFECT, quadop_cst(zero), quadop_empty(), quadop_var(status)));
    newName(S_GLOBAL, return_value, VAR, 0);
    genCode(quad_new(Q_AFFECT, quadop_cst(empty), quadop_empty(), quadop_var(return_value)));
}

liste_instructions
: liste_instructions SEMI_CO instruction
{
    if(DEBUG)
        printRule("liste_instructions SEMI_CO instruction");
    $$.firstquad = $1.firstquad;
    complete($1.next, $3.firstquad);
    $$.next = $3.next;
}
| instruction
{
    if(DEBUG)
        printRule("instruction");
    $$.firstquad = $1.firstquad;
    $$.next = $1.next;
}
;

instruction
: ID EQUAL concatenation 
{
    if(DEBUG)
        printRule("ID EQUAL concatenation");
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
    if(DEBUG)
        printRule("ID OABRA operande_entier CABRA EQUAL concatenation");
    $$.firstquad = $3.firstquad;
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable \"%s\" non définie", $1);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $1);
        exit(1);
    }
    else if($3.result.kind == QO_CST && (atoi($3.result.qval.value) < 0 || id->size < atoi($3.result.qval.value))) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %d en dehors du tableau %s)", atoi($3.result.qval.value), $1);
        exit(1);
    }
    genCode(quad_new(Q_AFFECT, $6.result, $3.result, quadop_var($1))); // ATTENTION: vérifier indice dans le tableau dans autres règles
    $$.next = NULL;
}
| DECLARE ID OABRA INTEGER CABRA
{
    if(DEBUG)
        printRule("DECLARE ID OABRA INTEGER CABRA");
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
    // Pas de code: action uniquement dans la table des symboles
    $$.next = NULL;
}
| IF test_bloc THEN liste_instructions g else_part FI
{
    if(DEBUG)
        printRule("IF test_bloc THEN liste_instructions g else_part FI");
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
    $$.next = concat($$.next, $6.next); // N'a d'effet que quand il y a une else_part
}
| FOR ID DO liste_instructions DONE
{
    if(DEBUG)
        printRule("FOR ID DO liste_instructions DONE");
    // $$.firstquad = $.firstquad;
    struct symbol *id = lookUp(S_AUTO, $2);
    if(id == NULL)
    {
        newName(S_GLOBAL, $2, VAR, 0);
    }
}
| FOR ID IN liste_operandes DO liste_instructions DONE
{
    if(DEBUG)
        printRule("FOR ID IN liste_operandes DO liste_instructions DONE");
    $$.firstquad = $6.firstquad;
    struct symbol *id = lookUp(S_AUTO, $2);
    if(id == NULL)
    {
        newName(S_GLOBAL, $2, VAR, 0);
    }
}
| WHILE test_bloc DO liste_instructions g DONE
{
    if(DEBUG)
        printRule("WHILE test_bloc DO liste_instructions g DONE");
    $$.firstquad = $2.firstquad;
    // test_bloc (true/false)
    complete($2.ltrue, $4.firstquad);
    $$.next = $2.lfalse;
    // fin de liste_instructions
    complete($4.next, $2.firstquad);
    complete($5.next, $2.firstquad);
}
| UNTIL test_bloc DO liste_instructions g DONE
{
    if(DEBUG)
        printRule("UNTIL test_bloc DO liste_instructions g DONE");
    $$.firstquad = $2.firstquad; // A FAIRE PARTOUT
    complete($2.lfalse, $4.firstquad);
    $$.next = $2.ltrue;
    complete($4.next, $2.firstquad);
    complete($5.next, $2.firstquad);
}
| CASE operande IN liste_cas ESAC
{
    if(DEBUG)
        printRule("CASE operande IN liste_cas ESAC");
}
| ECHO_ liste_operandes_echo
{
    if(DEBUG)
        printRule("ECHO_ liste_operandes");
    $$.firstquad = $2.firstquad;
    char tmp[3];
    sprintf(tmp, "%ld", $2.size);
    if(checkInsideFunction())
    {
        genCode(quad_new(Q_ECHO_FUNCTION, quadop_cst(strdup(tmp)), quadop_empty(), quadop_empty()));
    }
    else
    {
        genCode(quad_new(Q_ECHO, quadop_cst(strdup(tmp)), quadop_empty(), quadop_empty()));
    }
    $$.next = NULL;
}
| READ ID
{
    if(DEBUG)
        printRule("READ ID");
    struct symbol *id = lookUp(S_AUTO, $2);
    if(id == NULL)
    {
        newName(S_GLOBAL, $2, VAR, 0);
    }
    $$.firstquad = next_quad;
    genCode(quad_new(Q_READ, quadop_empty(),  quadop_empty(), quadop_var($2)));
}
| READ ID OABRA operande_entier CABRA
{
    if(DEBUG)
        printRule("READ ID OABRA operande_entier CABRA");
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
    else if($4.result.kind == QO_CST && (atoi($4.result.qval.value) < 0 || id->size < atoi($4.result.qval.value))) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %d en dehors du tableau)", atoi($4.result.qval.value));
        exit(1);
    }
    $$.firstquad = next_quad;
    genCode(quad_new(Q_READ, quadop_empty(), $4.result, quadop_var($2)));
}
| declaration_de_fonction
{
    if(DEBUG)
        printRule("declaration_de_fonction");
    $$.firstquad = next_quad;
    $$.next = $1.next;
}
| appel_de_fonction
{
    if(DEBUG)
        printRule("appel_de_fonction");
    $$.firstquad = $1.firstquad;
    $$.next = NULL;
}
| RETURN
{   
    if(DEBUG)
        printRule("RETURN");
    // Si on n'est pas dans une fonction pas de return
    if(!checkInsideFunction())
    {
        printError("Return en dehors de fonction");
        exit(1);
    }
    $$.firstquad = next_quad;
    $$.next = NULL;
    genCode(quad_new(Q_AFFECT, quadop_cst(zero), quadop_empty(), quadop_var(status)));
    genCode(quad_new(Q_RETURN, quadop_empty(), quadop_empty(), quadop_empty()));
}
| RETURN operande_entier
{
    if(DEBUG)
        printRule("RETURN operande_entier");
    // si on n'est pas dans une fonction pas de return
    if(!checkInsideFunction())
    {
        printError("Return en dehors de fonction");
        exit(1);
    }
    $$.firstquad = $2.firstquad;
    $$.next = NULL;
    genCode(quad_new(Q_AFFECT, $2.result, quadop_empty(), quadop_var(status)));
    genCode(quad_new(Q_RETURN, quadop_empty(), quadop_empty(), quadop_empty()));
}
| EXIT
{
    if(DEBUG)
        printRule("EXIT");
    $$.firstquad = next_quad;
    genCode(quad_new(Q_EXIT, quadop_empty(), quadop_empty(), quadop_empty()));
    $$.next = NULL;
}
| EXIT operande_entier
{
    if(DEBUG)
        printRule("EXIT opreande_entier");
    $$.firstquad = $2.firstquad;
    genCode(quad_new(Q_EXIT, $2.result, quadop_empty(), quadop_empty()));
    $$.next = NULL;
}
;

else_part
: ELIF test_bloc THEN liste_instructions g else_part
{
    if(DEBUG)
        printRule("ELIF test_bloc THEN liste_instructions g else_part");
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
    if(DEBUG)
        printRule("ELSE liste_instructions g");
    $$.firstquad = $2.firstquad;
    $$.next = concat($2.next,$3.next);
}
| %empty 
{
    if(DEBUG)
        printRule("no elsepart");
    $$.next = NULL;
}
;

liste_cas
: liste_cas filtre CPAR liste_instructions SEMI_CO SEMI_CO
{
    if(DEBUG)
        printRule("liste_cas filtre CPAR liste_instructions SEMI_CO SEMI_CO");
}
| filtre CPAR liste_instructions SEMI_CO SEMI_CO
{
    if(DEBUG)
        printRule("filtre CPAR liste_instructions SEMI_CO SEMI_CO");
}
;

filtre
: STRING
{
    if(DEBUG)
        printRule("STRING");
}
| filtre CASE_OR STRING
{
    if(DEBUG)
        printRule("CASE_OR STRING");
}
| STAR
{
    if(DEBUG)
        printRule("STAR");
}
;

liste_operandes_echo
: liste_operandes_echo operande
{
    if(DEBUG)
        printRule("liste_operandes operande");
    $$.firstquad = $1.firstquad;
    $$.size = $1.size + 1;
    char tmp[3];
    sprintf(tmp, "%ld", $$.size);
    genCode(quad_new(Q_AFFECT_STACK, $2.result, quadop_empty(), quadop_var(strdup(tmp))));
}
| operande
{
    if(DEBUG)
        printRule("operande (listop)");
    $$.firstquad = $1.firstquad;
    $$.size = 1;
    genCode(quad_new(Q_AFFECT_STACK, $1.result, quadop_empty(), quadop_var("1")));
}
| DOLLAR OBRA ID OABRA STAR CABRA CBRA
{
    if(DEBUG)
        printRule("DOLLAR OBRA ID OABRA STAR CABRA CBRA");
}
;

liste_operandes
: liste_operandes operande
{
    // Quadop tag ??
    if(DEBUG)
        printRule("liste_operandes operande");
    $$.firstquad = $1.firstquad;
    $$.size = $1.size + 1;
    char tmp[3];
    sprintf(tmp, "%ld", $$.size);
    genCode(quad_new(Q_AFFECT, $2.result, quadop_empty(), quadop_var(strdup(tmp)))); // conflit dans la table des symboles??
}
| operande
{
    if(DEBUG)
        printRule("operande (listop)");
    $$.firstquad = $1.firstquad;
    $$.size = 1;
    genCode(quad_new(Q_AFFECT, $1.result, quadop_empty(), quadop_var("1")));
}
| DOLLAR OBRA ID OABRA STAR CABRA CBRA
{
    if(DEBUG)
        printRule("DOLLAR OBRA ID OABRA STAR CABRA CBRA");
}
;

concatenation
: concatenation operande
{
    if(DEBUG)
        printRule("concatenation operande");
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_CONCAT, $1.result, $2.result, result));
    $$.result = result;
}
| operande
{
    if(DEBUG)
        printRule("operande (concat)");
    $$.firstquad = $1.firstquad;
    $$.result = $1.result;
}
;

test_bloc
: TEST test_expr
{
    if(DEBUG)
        printRule("TEST test_expr");
    $$.firstquad = $2.firstquad;
    $$.ltrue = $2.ltrue;
    $$.lfalse = $2.lfalse;
}
;

test_expr
: test_expr C_OR test_expr2
{
    if(DEBUG)
        printRule("test_expr C_OR test_expr2");
    $$.firstquad = $1.firstquad;
    complete($1.lfalse, $3.firstquad);
    $$.ltrue = concat($1.ltrue, $3.ltrue);
    $$.lfalse = $3.lfalse;
}
| test_expr2
{
    if(DEBUG)
        printRule("test_expr2");
    $$.firstquad = $1.firstquad;
    $$.ltrue = $1.ltrue;
    $$.lfalse = $1.lfalse;
}
;

test_expr2
: test_expr2 C_AND test_expr3
{
    if(DEBUG)
        printRule("test_expr2 C_AND test_expr3");
    $$.firstquad = $1.firstquad;
    complete($1.ltrue, $3.firstquad);
    $$.ltrue = $3.ltrue;
    $$.lfalse = concat($1.lfalse, $3.lfalse);
}
| test_expr3
{
    if(DEBUG)
        printRule("test_expr3");
    $$.firstquad = $1.firstquad;
    $$.ltrue = $1.ltrue;
    $$.lfalse = $1.lfalse;
}
;

test_expr3
: OPAR test_expr CPAR
{
    if(DEBUG)
        printRule("OPAR test_expr CPAR");
    $$.firstquad = $2.firstquad;
    $$.ltrue = $2.ltrue;
    $$.lfalse = $2.lfalse;
}
| NOT OPAR test_expr CPAR
{
    if(DEBUG)
        printRule("NOT OPAR test_expr CPAR");
    $$.firstquad = $3.firstquad;
    $$.ltrue = $3.lfalse;
    $$.lfalse = $3.ltrue;
}
| test_instruction
{
    if(DEBUG)
        printRule("test_instruction");
    $$.firstquad = $1.firstquad;
    $$.ltrue = $1.ltrue;
    $$.lfalse = $1.lfalse;
}
| NOT test_instruction
{
    if(DEBUG)
        printRule("NOT test_instruction");
    $$.firstquad = $2.firstquad;
    $$.ltrue = $2.lfalse;
    $$.lfalse = $2.ltrue;
}
;

test_instruction
: concatenation EQUAL concatenation
{
    if(DEBUG)
        printRule("concatenation EQUAL concatenation");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EQUAL_STRING, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| concatenation NOT_EQUAL concatenation
{
    if(DEBUG)
        printRule("concatenation NOT_EQUAL concatenation");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_NOT_EQUAL_STRING, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| T_NOT_EMPTY concatenation
{
    if(DEBUG)
        printRule("T_NOT_EMPTY concatenation");
    $$.firstquad = $2.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_N_EMP, $2.result, quadop_empty(), quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| T_EMPTY concatenation
{
    if(DEBUG)
        printRule("T_EMPTY concatenation");
    $$.firstquad = $2.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EMP, $2.result, quadop_empty(), quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_EQUAL operande
{
    if(DEBUG)
        printRule("operande T_EQUAL operande");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_EQUAL, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_NOT_EQUAL operande
{
    if(DEBUG)
        printRule("operande T_NOT_EQUAL operande");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_NOT_EQUAL, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_GT operande
{
    if(DEBUG)
        printRule("operande T_GT operande");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_GT, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_GE operande
{
    if(DEBUG)
        printRule("operande T_GE operande");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_GE, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_LT operande
{
    if(DEBUG)
        printRule("operande T_LT operande");
    $$.firstquad = $1.firstquad;
    $$.ltrue = createList(next_quad);
    genCode(quad_new(Q_LT, $1.result, $3.result, quadop_unknown()));
    $$.lfalse = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
| operande T_LE operande
{
    if(DEBUG)
        printRule("operande T_LE operande");
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
    if(DEBUG)
        printRule("DOLLAR OBRA ID CBRA");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $3);
    if(id == NULL)
    {
        printError("Variable \"%s\" non définie", $3);
        exit(1);
    }
    $$.result = quadop_var($3);
}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    if(DEBUG)
        printRule("DOLLAR OBRA ID OABRA operande_entier CABRA CBRA");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $3);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable \"%s\" non définie", $3);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $3);
        exit(1);
    }
    else if($5.result.kind == QO_CST && (atoi($5.result.qval.value) < 0 || id->size < atoi($5.result.qval.value))) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %d en dehors du tableau %s)", atoi($5.result.qval.value), $3);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_ARRAY_GET, quadop_var($3), $5.result, res));
    $$.result = res;
}
| DOLLAR INTEGER
{
    if(DEBUG)
        printRule("DOLLAR INTEGER");
    $$.firstquad = next_quad;
    if(checkInsideFunction() == 1) // si on est dans une fonction alors on regarde uniquement dans le contexte local
    {   
        struct symbol *id = lookUp(S_LOCAL, $2);
        if(id == NULL)
        {
            newName(S_LOCAL, $2, ARG, 0);
        }
    }
    else // si on est dans le  global alors on regarde uniquemeent dans le context global
    {
        struct symbol *id = lookUp(S_GLOBAL, $2);
        if(id == NULL)
        {
            newName(S_GLOBAL, $2, ARG, 0);
        }
    }
    $$.result = quadop_var($2);
}
| DOLLAR STAR
{
    if(DEBUG)
        printRule("DOLLAR STAR");
    $$.firstquad = next_quad;
}
| DOLLAR STATUS
{
    if(DEBUG)
        printRule("DOLLAR STATUS");
    $$.firstquad = next_quad;
    $$.result = quadop_var(status);

}
| INTEGER
{
    if(DEBUG)
        printRule("INTEGER");
    $$.firstquad = next_quad;
    $$.result = quadop_cst($1);
}
| PLUS INTEGER
{
    if(DEBUG)
        printRule("PLUS INTEGER");
    $$.firstquad = next_quad;
    $$.result = quadop_cst($2);
}
| MINUS INTEGER %prec UMINUS
{
    if(DEBUG)
        printRule("MINUS INTEGER prec UMINUS");
    $$.firstquad = next_quad;
    size_t size = strlen($2);
    char *tmp = malloc(size + 2);
    CHK_NULL(tmp);
    tmp[0] = '-';
    tmp[1] = '\0';
    $$.result = quadop_cst(strcat(tmp, $2));
}
| STRING
{
    if(DEBUG)
        printRule("STRING");
    $$.firstquad = next_quad;
    $$.result = quadop_string($1);
}
| DOLLAR OPAR EXPR somme_entiere CPAR
{
    if(DEBUG)
        printRule("DOLLAR OPAR EXPR somme_entiere CPAR");
    $$.firstquad = $4.firstquad;
    $$.result = $4.result;
}
| DOLLAR OPAR appel_de_fonction CPAR
{
    if(DEBUG)
        printRule("DOLLAR OPAR appel_de_fonction CPAR");
    $$.firstquad = $3.firstquad;
    $$.result = $3.result;
}
;

somme_entiere
: somme_entiere PLUS produit_entier
{
    if(DEBUG)
        printRule("somme_entiere PLUS produit_entier");
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_ADD, $1.result, $3.result, result));
    $$.result = result;
}
| somme_entiere MINUS produit_entier
{
    if(DEBUG)
        printRule("somme_entiere MINUS produit_entier");
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_SUB, $1.result, $3.result, result));
    $$.result = result;
}
| produit_entier
{
    if(DEBUG)
        printRule("produit_entier");
    $$.firstquad = $1.firstquad;
    $$.result = $1.result;
}
;

produit_entier
: produit_entier STAR operande_entier
{
    if(DEBUG)
        printRule("produit_entier STAR operande_entier");
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_MUL, $1.result, $3.result, result));
    $$.result = result;
}
| produit_entier DIVISION operande_entier
{
    if(DEBUG)
        printRule("produit_entier DIVISION operande_entier");
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_DIV, $1.result, $3.result, result));
    $$.result = result;
}
| produit_entier MOD operande_entier
{
    if(DEBUG)
        printRule("produit_entier MOD operande_entier");
    $$.firstquad = $1.firstquad;
    struct quadop result = quadop_var(newtemp());
    genCode(quad_new(Q_MOD, $1.result, $3.result, result));
    $$.result = result;
}
| operande_entier
{
    if(DEBUG)
        printRule("operande_entier");
    $$.firstquad = $1.firstquad;
    $$.result = $1.result;
}
;

operande_entier
: DOLLAR OBRA ID CBRA
{
    if(DEBUG)
        printRule("DOLLAR OBRA ID CBRA");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $3);
    if(id == NULL)
    {
        printError("Variable \"%s\" non définie", $3);
        exit(1);
    }
    $$.result = quadop_var($3);
}
| DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    if(DEBUG)
        printRule("DOLLAR OBRA ID OABRA operande_entier CABRA CBRA");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $3);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable \"%s\" non définie", $3);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $3);
        exit(1);
    }
    else if($5.result.kind == QO_CST && (atoi($5.result.qval.value) < 0 || id->size < atoi($5.result.qval.value))) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %d en dehors du tableau %s)", atoi($5.result.qval.value), $3);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_ARRAY_GET, quadop_var($3), $5.result, res));
    $$.result = res;
}
| DOLLAR INTEGER
{
    if(DEBUG)
        printRule("DOLLAR INTEGER");
    $$.firstquad = next_quad;
    if(checkInsideFunction() == 1) // si on est dans une fonction alors on regarde uniquement dans le contexte local
    {   
        struct symbol *id = lookUp(S_LOCAL, $2);
        if(id == NULL)
        {
            newName(S_LOCAL, $2, ARG, 0);
        }
    }
    else // si on est dans le  global alors on regarde uniquemeent dans le context global
    {
        struct symbol *id = lookUp(S_GLOBAL, $2);
        if(id == NULL)
        {
            newName(S_GLOBAL, $2, ARG, 0);
        }
    }
    $$.result = quadop_var($2);
}
| PLUS DOLLAR OBRA ID CBRA
{
    if(DEBUG)
        printRule("PLUS DOLLAR OBRA ID CBRA");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $4);
    if(id == NULL)
    {
        printError("Variable \"%s\" non définie", $4);
        exit(1);
    }
    $$.result = quadop_var($4);
}
| MINUS DOLLAR OBRA ID CBRA %prec UMINUS
{
    if(DEBUG)
        printRule("MINUS DOLLAR OBRA ID CBRA %prec UMINUS");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_AUTO, $4);
    if(id == NULL)
    {
        printError("Variable \"%s\" non définie", $4);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_SUB, quadop_cst(zero), quadop_var($4), res));
    $$.result = res;
}
| PLUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA
{
    if(DEBUG)
        printRule("PLUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $4);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable \"%s\" non définie", $4);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole %s n'est pas un tableau", $4);
        exit(1);
    }
    else if($6.result.kind == QO_CST && (atoi($6.result.qval.value) < 0 || id->size < atoi($6.result.qval.value))) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %d en dehors du tableau %s)", atoi($6.result.qval.value), $4);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_ARRAY_GET, quadop_var($4), $6.result, res));
    $$.result = res;
}
| MINUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA %prec UMINUS
{
    if(DEBUG)
        printRule("MINUS DOLLAR OBRA ID OABRA operande_entier CABRA CBRA %prec UMINUS");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $4);
    if(id == NULL) // Variable pas définie
    {
        printError("Variable \"%s\" non définie", $4);
        exit(1);
    }
    else if(id->type != TAB) // Variable n'est pas un tableau
    {
        printError("Symbole \"%s\" n'est pas un tableau", $4);
        exit(1);
    }
    else if($6.result.kind == QO_CST && (atoi($6.result.qval.value) < 0 || id->size < atoi($6.result.qval.value))) // Accès interdit avec valeur constante (si c'est une variable on ne peut pas vérifier à la compilation)
    {
        printError("Accès interdit (indice %d en dehors du tableau %s)", atoi($6.result.qval.value), $4);
        exit(1);
    }
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_ARRAY_GET, quadop_var($4), $6.result, res));
    genCode(quad_new(Q_SUB, quadop_cst(zero), res, res));
    $$.result = res;
}
| PLUS DOLLAR INTEGER
{
    if(DEBUG)
        printRule("PLUS DOLLAR INTEGER");
    $$.firstquad = next_quad;
    if(checkInsideFunction() == 1) // si on est dans une fonction alors on regarde uniquement dans le contexte local
    {   
        struct symbol *id = lookUp(S_LOCAL, $3);
        if(id == NULL)
        {
            newName(S_LOCAL, $3, ARG, 0);
        }
    }
    else // si on est dans le  global alors on regarde uniquemeent dans le context global
    {
        struct symbol *id = lookUp(S_GLOBAL, $3);
        if(id == NULL)
        {
            newName(S_GLOBAL, $3, ARG, 0);
        }
    }

    // verifier qu'on est bien dans une fonction car pas d'argument au programme...
    $$.result = quadop_var($3);
}
| MINUS DOLLAR INTEGER %prec UMINUS 
{
    if(DEBUG)
        printRule("MINUS DOLLAR INTEGER %prec UMINUS");
    $$.firstquad = next_quad;
    if(checkInsideFunction() == 1) // si on est dans une fonction alors on regarde uniquement dans le contexte local
    {   
        struct symbol *id = lookUp(S_LOCAL, $3);
        if(id == NULL)
        {
            newName(S_LOCAL, $3, ARG, 0);
        }
    }
    else // si on est dans le  global alors on regarde uniquemeent dans le context global
    {
        struct symbol *id = lookUp(S_GLOBAL, $3);
        if(id == NULL)
        {
            newName(S_GLOBAL, $3, ARG, 0);
        }
    }
    // verifier qu'on est bien dans une fonction car pas d'argument au programme...
    struct quadop res = quadop_var(newtemp());
    genCode(quad_new(Q_SUB, quadop_cst(zero), quadop_var($3), res));
    $$.result = res;
}
| INTEGER
{
    if(DEBUG)
        printRule("INTEGER");
    $$.firstquad = next_quad;
    $$.result = quadop_cst($1);
}
| PLUS INTEGER
{
    if(DEBUG)
        printRule("PLUS INTEGER");
    $$.firstquad = next_quad;
    $$.result = quadop_cst($2);
}
| MINUS INTEGER %prec UMINUS
{
    if(DEBUG)
        printRule("MINUS INTEGER prec UMINUS");
    $$.firstquad = next_quad;
    size_t size = strlen($2);
    char *tmp = malloc(size + 2);
    CHK_NULL(tmp);
    tmp[0] = '-';
    tmp[1] = '\0';
    $$.result = quadop_cst(strcat(tmp, $2));
}
| OPAR somme_entiere CPAR
{
    if(DEBUG)
        printRule("OPAR somme_entiere CPAR");
    $$.firstquad = $2.firstquad;
    $$.result = $2.result;
}
;

declaration_de_fonction
: ID
{
    if(DEBUG)
        printRule("ID OPAR CPAR OBRA decl_loc liste_instructions CBRA");
    $<inst_val>$.next = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_unknown(), quadop_empty(), quadop_empty())); // pour passer la fonction à l'exécution
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id != NULL) // Fonction déjà définie
    {
        printError("Fonction %s déjà définie", $1);
        exit(1);
    }
    newName(S_GLOBAL, $1, FUN, -1);
    genCode(quad_new(Q_FUNCTION_BEGIN, quadop_empty(), quadop_empty(), quadop_var($1)));
    pushContext();
}
OPAR CPAR OBRA decl_loc liste_instructions CBRA
{
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // ERREUR TRES GRAVE
    {
        printError("Fonction \"%s\" non définie (ERREUR TRES GRAVE)", $1);
        exit(1); 
    }

    // Gestion des arguments de la fonction
    id->size = countArg();
    removeCallList(id); // Pour les fonctions rec :)
    complete($7.next, next_quad); // Compléter goto pour sortir de la fonction
    createNewStackFrame($1, popContext());
    genCode(quad_new(Q_AFFECT, quadop_cst(zero), quadop_empty(), quadop_var(status)));
    genCode(quad_new(Q_RETURN, quadop_empty(), quadop_empty(), quadop_empty()));
    genCode(quad_new(Q_FUNCTION_END, quadop_empty(), quadop_empty(), quadop_empty()));
    $$.next = $<inst_val>2.next;
}
;

decl_loc
: decl_loc LOCAL ID EQUAL concatenation SEMI_CO
{
    if(DEBUG)
        printRule("decl_loc LOCAL ID EQUAL concatenation SEMI_CO");
    // au final ça ne produira pas de quad (car pas d'instruction MIPS généré) -> a faire avec la table des symboles
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
: ID 
{
    if(DEBUG)
        printRule("ID liste_operandes");
    // Verifier que la fonction existe
    // $<expr_val>$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // Fonction pas définie
    {
        printError("Fonction \"%s\" non définie", $1);
        exit(1);
    }
    else if(id->type != FUN) // Fonction n'est pas une fonction
    {
        printError("Symbole %s n'est pas une fonction", $1);
        exit(1);
    }
    $<inst_val>$.firstquad = next_quad;
    genCode(quad_new(Q_CALL, quadop_var($1), quadop_empty(), quadop_empty()));
}
liste_operandes // ici on crée le code pour affecter les variables
{
    $$.firstquad = $<inst_val>2.firstquad; // quasiment sur que c'est faux ici.
    // Verifier que l'utilisateur a mis le bon nombre d'argument
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if (id->size == -1) // Appel de fonction non résolu (il faut vérifier le nombre d'arguments)
    {
        addCallList($3.size, id);
    }
    else if ($3.size != id->size) // Nombre d'arguments invalide
    {
        printError("Appel de fonction %s invalide (nombre d'arguments incorrect)", $1);
        exit(1);
    }
    genCode(quad_new(Q_GOTO_FUN, quadop_empty(), quadop_empty(), quadop_var($1)));
    $$.result = quadop_var(return_value);
}
| ID
{
    if(DEBUG)
        printRule("ID");
    $$.firstquad = next_quad;
    struct symbol *id = lookUp(S_GLOBAL, $1);
    if(id == NULL) // Fonction pas définie
    {
        printError("Fonction \"%s\" non définie", $1);
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
    // Agrandir la stack
    genCode(quad_new(Q_CALL, quadop_var($1), quadop_empty(), quadop_empty()));
    genCode(quad_new(Q_GOTO_FUN, quadop_empty(), quadop_empty(), quadop_var($1)));
    $$.result = quadop_var(return_value);
}
;

g
: %empty
{
    if(DEBUG)
        printRule("empty");
    $$.next = createList(next_quad);
    genCode(quad_new(Q_GOTO, quadop_empty(), quadop_empty(), quadop_unknown()));
}
;

%%

void yyerror(const char *msg)
{
    printError("Erreur syntaxique : %s", msg);
}
%{
#include stdio.h
#include stdlib.h

extern int yylex();
extern void yyerror(const char *msg);
%}

%token ID MOT CHAINE

%%

programme
: liste_instructions {}
;

liste_instructions
: liste_instructions ';' instruction {}
| instruction {}
;

instruction
: ID '=' concatenation {}
| ID[operande_entier] '=' concatenation {}
| declare ID[entier] {}
| if test_bloc then liste_instructions else_part fi {}
| for ID do liste_instructions done {}
| for ID in liste_operandes do liste_instructions done {}
| while test_bloc do liste_instructions done {}
| until test_bloc do liste_instructions done {}
| case operande in liste_cas esac {}
| echo liste_operandes {}
| read ID {}
| read ID[operande_entier] {}
| declaration_de_fonction {}
| appel_de_fonction {}
| return {}
| return operande_entier {}
| exit {}
| exit operande_entier {}
;

else_part
: elif test_bloc then liste_instructions else_part {}
| else liste_instructions {}
| %empty {}
;

liste_cas
: liste_cas filtre ')' liste_instructions ";;" {}
| filtre ')' liste_instructions ";;" {}
;

filtre
: MOT {}
| \" CHAINE \" {}
| \' CHAINE \' {}
| filtre '|' MOT {}
| filtre '|' \' CHAINE \' {}
| filtre '|' \' CHAINE \' {}
| '*'
;

liste_operandes
: liste_operandes operande {}
| operande {}
| "${" ID "[*]}" {}
;

concatenation
: concatenationoperande {}
| operande {}
;

test_bloc
: test test_expr {}
;

test_expr
: test_expr "-o" test_expr2 {}
| test_expr2 {}
;

test_expr2
: test_expr2 "-a" test_expr3 {}
| test_expr3 {}
;

test_expr3
: '(' test_expr ')' {}
| '!' '(' test_expr ')' {}
| test_instruction {}
| '!' test_instruction {}
;

test_instruction
: concatenation '=' concatenation {}
| concatenation "!=" concatenation {}
| operateur1 concatenation {}
| operande operateur2 operande {}
;

operande
: "${" ID '}' {}
| "${" ID '[' operande_entier "]}" {}
| MOT {}
| '$' entier {}
| "$*" {}
| "$?" {}
| \" CHAINE \" {}
| \' CHAINE \' {}
| "$(" expr somme_entiere ')' {}
| "$(" appel_de_fonction ')' {}
;

operateur1
: "-n" {}
| "-z" {}
;

operateur2
: "-eq" {}
| "-ne" {}
| "-gt" {}
| "-ge" {}
| "-lt" {}
| "-le" {}
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
: "${" ID '}' {}
| "${" ID '[' operande_entier "]}" {}
| '$' entier {}
| plus_ou_moins "${" ID '}' {}
| plus_ou_moins "${" ID '[' operande_entier "]}" {}
| plus_ou_moins '$' entier {}
| entier {}
| plus_ou_moins entier {}
| '(' somme_entiere ')' {}
;

plus_ou_moins
: '+' {}
| '-' {}
;

fois_div_mod
: '*' {}
| '/' {}
| '%' {}
;

declaration_de_fonction
: ID "() {" decl_loc liste_instructions '}' {}
;


decl_loc
: decl_loc local ID '=' concatenation ';' {}
| %empty {}
;

appel_de_fonction
: ID liste_operandes {}
| ID {}
;

%%
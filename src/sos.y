
%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern void yyerror(const char *msg);

%token ID MOT CHAINE

%%

<programme>
: <liste_instructions> {}
;

<liste_instructions>
: <liste_instructions> ';' <instruction> {}
| <instruction> {}
;

<instruction>
: ID '=' <concatenation> {}
| ID[<operande_entier>] '=' <concatenation> {}
| declare ID[entier] {}
| if <test_bloc> then <liste_instructions> <else_part> fi {}
| for ID do <liste_instructions> done {}
| for ID in <liste_operandes> do <liste_instructions> done {}
| while <test_bloc> do <liste_instructions> done {}
| until <test_bloc> do <liste_instructions> done {}
| case <operande> in <liste_cas> esac {}
| echo <liste_operandes> {}
| read ID {}
| read ID[<operande_entier>] {}
| <declaration_de_fonction> {}
| <appel_de_fonction> {}
| return {}
| return <operande_entier> {}
| exit {}
| exit <operande_entier> {}
;

<else_part>
: elif <test_bloc> then <liste_instructions> <else_part> {}
| else <liste_instructions> {}
| %empty {}
;

<liste_cas>
: <liste_cas> <filtre> ')' <liste_instructions> ";;" {}
| <filtre> ')' <liste_instructions> ";;" {}
;

<filtre>
: MOT {}
| \" CHAINE \" {}
| \' CHAINE \' {}
| <filtre> '|' MOT {}
| <filtre> '|' '"' CHAINE '"' {}
| <filtre> '|' \' CHAINE \' {}
| *
;

<liste_opérandes>
: <liste_opérandes> <opérande> {}
| <opérande> {}
| "${" ID "[*]}" {}
;

<concaténation>
: <concaténation><opérande> {}
| <opérande> {}
;

<test_bloc>
: test <test_expr> {}
;

<test_expr>
: <test_expr> -o <test_expr2> {}
| <test_expr2> {}
;

<test_expr2>
: <test_expr2> -a <test_expr3> {}
| <test_expr3> {}
;

<test_expr3>
: '(' <test_expr> ')' {}
| "! (" <test_expr> ')' {}
| <test_instruction> {}
| '!' <test_instruction> {}
;

<test_instruction>
: <concaténation> '=' <concaténation> {}
| <concaténation> "!=" <concaténation> {}
| <opérateur1> <concaténation> {}
| <opérande> <opérateur2> <opérande> {}
;

<opérande>
: "${" ID '}' {}
| "${" ID '[' <opérande_entier> "]}" {}
| MOT {}
| '$' entier {}
| "$*" {}
| "$?" {}
| '"' CHAINE '"' {}
| \' CHAINE \' {}
| "$(" expr <somme_entière> ')' {}
| "$(" <appel_de_fonction> ')' {}
;

<opérateur1>
: "-n" {}
| "-z" {}
;

<opérateur2>
: "-eq" {}
| "-ne" {}
| "-gt" {}
| "-ge" {}
| "-lt" {}
| "-le" {}
;

<somme_entière>
: <somme_entière> <plus_ou_moins> <produit_entier> {}
| <produit_entier> {}
;

<produit_entier>
: <produit_entier> <fois_div_mod> <opérande_entier> {}
| <opérande_entier> {}
;

<opérande_entier>
: "${" ID '}' {}
| "${" ID '[' <opérande_entier> "]}" {}
| '$' entier {}
| <plus_ou_moins> "${" ID '}' {}
| <plus_ou_moins> "${" ID '[' <opérande_entier> "]}" {}
| <plus_ou_moins> '$' entier {}
| entier {}
| <plus_ou_moins> entier {}
| '(' <somme_entière> ')' {}
;

<plus_ou_moins>
: '+' {}
| '-' {}
;

<fois_div_mod>
: '*' {}
| '/' {}
| '%' {}
;

<déclaration_de_fonction>
: ID "() {" <décl_loc> <liste_instructions> '}' {}
;


<décl_loc>
: <décl_loc> local ID '=' <concaténation> ';' {}
| %empty {}
;

<appel_de_fonction>
: ID <liste_opérandes> {}
| ID {}
;

%%
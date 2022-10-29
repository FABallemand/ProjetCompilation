
%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern void yyerror(const char *msg);

/*
La gestion des valeurs des ensembles se fait au moyen d'une table des symboles et d'une table de valeurs.
Pour des raisons de simplicité le nombre d'ensemble est limité à NB_MAX_ENSEMBLES.
Les fonctions qui suivent permettent d'affecter une valeur à un ensemble, d'afficher un ensemble,
de retrouver un ensemble dans la tanble des symboles ainsi que sa valeur et de faire des opérations sur les ensembles.
*/
#define NB_MAX_ENSEMBLES 64
extern char identificateurs[NB_MAX_ENSEMBLES];
extern long int valeurs[NB_MAX_ENSEMBLES];
extern int nb_ensembles;
int trouverEnsemble(char id, int *nb_ensembles);
void affectation(char id, long int val, int *nb_ensembles);
long int valeurEnsemble(char id, int *nb_ensembles);
void afficheEnsemble(long int e, char *msg);
long int operateur2(long int elmt1, char op, long int elmt2);
long int operateur1(char op, long int elmt);
%}

%token ID ELEMENT AFF UNION INTER DIFF COMP

%start liste

%%

liste
: %empty
| liste instruction '\n'
;

instruction
: ID AFF exp {affectation($1,$3,&nb_ensembles);}
| ID {afficheEnsemble(valeurEnsemble($1,&nb_ensembles), NULL);}
;

exp
: operande {$$ = $1;}
| operande operateur2 operande {$$ = operateur2($1, $2, $3);}
| operateur1 operande {$$ = operateur1($1,$2);}
;

operateur2
: UNION {$$ = 'u';}
| INTER {$$ = 'i';}
| DIFF {$$ = 'd';}
;

operateur1
: COMP {$$ = 'c';}
;

operande
: ID {$$ = valeurEnsemble($1,&nb_ensembles);}
| ensemble {$$ = $1;}
;

ensemble
: '{' '}' {$$ = (long int)0;} // "{}" ne fonctionne pas car { et } sont renvoyés indépendamment
| '{' liste_elements '}' {$$ = $2;}
;

liste_elements
: ELEMENT {$$ = 0 | (1 << (($1)-1));}
| ELEMENT ',' liste_elements {$$ = $3 | (1 << (($1)-1));}
;

%%

/**
 * On cherche à représenter les ensembles (pas d'ordre, pas de répétition) pouvant contenir les entiers de 1 à 32.
 * On peut utiliser le type lint qui est codé avec 32 bits: chaque bit représente la présence d'un entier dans l'ensemble.
 * Exemples: Si le premier bit vaut 1 alors l'ensemble contient l'entier 1.
 *           Si le deuxième bit vaut 0 alors l'ensemble ne contient pas l'entier 2.
 */

int trouverEnsemble(char id, int *nb_ensembles)
{
    for(int i=0; i<*nb_ensembles; i++)
    {
        if(identificateurs[i] == id)
        {
            return i;
        }
    }
    return -1;
}

void affectation(char id, long int val, int *nb_ensembles)
{
    int i;
    if(((i = trouverEnsemble(id, nb_ensembles)) == -1) && *nb_ensembles < NB_MAX_ENSEMBLES)
    {
        identificateurs[*nb_ensembles] = id;
        valeurs[*nb_ensembles] = val;
        (*nb_ensembles)++;
    }
    else {
        valeurs[i] = val;
    }
}

long int valeurEnsemble(char id, int *nb_ensembles)
{
    return valeurs[trouverEnsemble(id, nb_ensembles)]; // ATTENTION: si l'ensemble n'existe pas...
}

void afficheEnsemble(long int e, char *msg)
{
    if(msg)
    {
        printf("%s ", msg);
    }
    int non_vide = 0;
    printf("{");
    for(int i=0; i<32; i++)
    {
        if(e & (1 << i))
        {
            non_vide = 1;
            printf("%d, ", i+1);
        }
    }
    if(non_vide)
    {
        printf("\b\b}\n");
    }
    else{
        printf("}\n");
    }
}

long int operateur2(long int elmt1, char op, long int elmt2)
{
    if(op == 'u')
        return elmt1 | elmt2;
    if(op == 'i')
        return elmt1 & elmt2;
    if(op == 'd')
        return elmt1 & ~elmt2;
}

long int operateur1(char op, long int elmt)
{
    if(op == 'c')
        return ~elmt;
    else
        exit(1);
}

void yyerror(const char *msg)
{
    fprintf(stderr, "Erreur syntaxique : %s\n", msg);
}
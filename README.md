# Projet Compilation M1 SDSC

## Membres du groupe

-ALLEMAND Fabien  
-LEBOT Samuel  

## Makefile

1. Compiler le projet
> make
3. Créer le graphe de la grammaire dans le dossier *graph*
> make graph
4. Lancer les tests automatiquement
> make test
5. Nettoyer l'espace de travail
> make clean
6. Nettoyer l'espace de travail relatif au graphe
> make clean_graph
7. Nettoyer l'espace de travail relatif aux tests
> make clean_test

## Utilisation:

SOS

**NAME**  
    sos - compilateur pour la langage SoS

**SYNOPSIS**  
>    sos [OPTION]...  
>    ./bin/sos [OPTION]...  

**DESCRIPTION**  
    Compile un programme écrit en langage SoS en code MIPS. Sos est un langage impératif simple qui utilise une syntaxe et des fonctionnalités issues d'un sous-ensemble de langage shell unix (Sous-Shell).

    -h          Affiche cette aide et arrête le programme  
    -version    Indique les membres de l'équipe de développement  
    -tos        Affiche la table des symboles  
    -i          Permet d'indiquer le fichier à compiler  
    -o          Permet d'indiquer le fichier résultat de la compilation  

## Remarques:
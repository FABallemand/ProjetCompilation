# Projet Compilation M1 SDSC

## Membres du groupe

-ALLEMAND Fabien  
-LEBOT Samuel  

## Makefile

1. Compiler le projet
> make
2. Nettoyer l'espace de travail
> make clean
3. Créer le graphe de la grammaire dans le dossier graph
> make graph
4. Lancer les test automatiquement
> make test
5. Nettoyer l'espace de travail relatif aux tests
> make clean_test

## Utilisation:

> ./bin/sos [...]

Faire manuel d'utilisation

## remarque 

- on a un petit problème la : si j'écris 1+2 le compile reconnais le mot "1+2" et pas l'addiction ENTIER + ENTIER (je sais pas comment fix ça)
- il faut réecrire les regex pour mot et chaine à partir de la def de caractère du sujet)
#!/bin/bash

SUCCESS=0
FAIL=1

# programme
PROG=${PROG:=bin/sos}

# fichier d'entrée
INPUT="test/input"

# fichier de sortie
OUTPUT="test/output"

# préparation de l'espace de travail
rm -R $OUTPUT
mkdir $OUTPUT
echo "Program : $PROG\n"

##############################################################################

i=0

# fichiers corrects
for f in $(ls ${INPUT} | grep "^[^_-]"); do
    echo -n "Test" $i "-" $f ".........."
    $PROG < $INPUT/$f > $OUTPUT/$f 2>&1
    if [ $? -ne $SUCCESS ]
    then
        return 1
    fi
    echo "OK"
    i=$((i+1))
done

# fichiers incorrects
for f in $(ls ${INPUT} | grep "^_"); do
    echo -n "Test" $i "-" $f
    $PROG < $INPUT/$f > $OUTPUT/$f 2>&1
    if [ $? -ne $FAIL ]
    then
        return 1
    fi
    echo "OK"
    i=$((i+1))
done

##############################################################################
# tests

# test_1()
# {
#     echo "Test 1 - valeurs et variables"

#     ##########################################################################
#     echo -n "Test 1.1 - chaines de caractères................................"
#     $PROG < $INPUT/chaines_caracteres > $OUTPUT/chaines_caracteres
#     if [ $? -ne $SUCCESS ]
#     then
#         return 1
#     fi
#     echo "OK"

#     ##########################################################################
#     echo -n "Test 1.2 - nombres.............................................."
#     $PROG < $INPUT/nombres > $OUTPUT/nombres
#     if [ $? -ne $SUCCESS ]
#     then
#         return 1
#     fi
#     echo "OK"

#     ##########################################################################
#     echo -n "Test 1.3 - affectation.........................................."
#     $PROG < $INPUT/affectation > $OUTPUT/affectation
#     if [ $? -ne $SUCCESS ]
#     then
#         return 1
#     fi
#     echo "OK"

#     ##########################################################################
#     echo -n "Test 1.4 - commentaires........................................."
#     $PROG < $INPUT/commentaire > $OUTPUT/commentaire
#     if [ $? -ne $SUCCESS ]
#     then
#        return 1
#     fi
#     echo "OK"

#     ##########################################################################

#     return 0
# }

##############################################################################
# run tests

# run_all()
# {
#     # run serie of tests
#     for T in $(seq 1 10); do
#         if test_$T; then
#             echo "Test $T - ok $T/10\n"
#         else
#             echo "Test $T - failed"
#             return 1
#         fi
#     done
#     rm -R $OUTPUT
#     echo "Program $PROG succeeded all tests !\n"
# }

# rm -R $OUTPUT
# mkdir $OUTPUT
# echo "Program : $PROG\n"

# if [ $# -eq 1 ]; then
#     case $1 in 1) test_1;; #
#                2) test_2;; #
#                3) test_3;; #
#                4) test_4;; #
#                5) test_5;; #
#                6) test_6;; #
#                7) test_7;; #
#                8) test_8;; #
#                9) test_9;; #
#                10) test_10;; #
#                *) echo "test inexistant"; return 1;
#     esac
# else
#     run_all
# fi
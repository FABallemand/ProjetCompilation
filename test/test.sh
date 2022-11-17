#!/bin/bash

SUCCESS=0
FAIL=1

# program
PROG=${PROG:=bin/sos}

# input files
INPUT="test/input"

# output files
OUTPUT="test/output"

##############################################################################
# tests

test_1()
{
    echo "Test 1 - fonctionnalités de base"

    ##########################################################################
    echo -n "Test 1.1 - chaines de caractères................................"
    $PROG < $INPUT/chaines_caracteres > $OUTPUT/chaines_caracteres
    if [ $? -ne $SUCCESS ]
    then
        return 1
    fi
    echo "OK"

    ##########################################################################
    echo -n "Test 1.2 - nombres.............................................."
    $PROG < $INPUT/nombres > $OUTPUT/nombres
    if [ $? -ne $SUCCESS ]
    then
        return 1
    fi
    echo "OK"

    ##########################################################################
    echo -n "Test 1.3 - commentaires........................................."
    $PROG < $INPUT/commentaire > $OUTPUT/commentaire
    if [ $? -ne $SUCCESS ]
    then
        return 1
    fi
    echo "OK"

    ##########################################################################

    return 0
}

test_2()
{
    echo "Test 2 - "

    

    return 0
}

test_3()
{
    echo "Test 3 - "

    

    return 0
}

test_4()
{
    echo "Test 4 - "

    

    return 0
}

test_5()
{
    echo "Test 5 - "

    

    return 0
}

test_6()
{
    echo "Test 6 - "

    

    return 0
}

test_7()
{
    echo "Test 7 - "

    

    return 0
}

test_8()
{
    echo "Test 8 - "

    

    return 0
}

test_9()
{
    echo "Test 9 - "

    

    return 0
}

test_10()
{
    echo "Test 10 - FINAL TEST"

    ##########################################################################
    echo -n "Test 10.1 - sujet_1............................................."
    $PROG < $INPUT/sujet_1 > $OUTPUT/sujet_1
    if [ $? -ne $SUCCESS ]
    then
        return 1
    fi
    echo "OK"

    ##########################################################################
    echo -n "Test 10.2 - sujet_2............................................."
    $PROG < $INPUT/sujet_2 > $OUTPUT/sujet_2
    if [ $? -ne $SUCCESS ]
    then
        return 1
    fi
    echo "OK"

    return 0
}

##############################################################################
# run tests

run_all()
{
    # run serie of tests
    for T in $(seq 1 10); do
        if test_$T; then
            echo "Test $T - ok $T/10\n"
        else
            echo "Test $T - failed"
            return 1
        fi
    done
    rm -R $OUTPUT
    echo "Program $PROG succeeded all tests !\n"
}

rm -R $OUTPUT
mkdir $OUTPUT
echo "Program : $PROG\n"

if [ $# -eq 1 ]; then
    case $1 in 1) test_1;; #
               2) test_2;; #
               3) test_3;; #
               4) test_4;; #
               5) test_5;; #
               6) test_6;; #
               7) test_7;; #
               8) test_8;; #
               9) test_9;; #
               10) test_10;; #
               *) echo "test inexistant"; return 1;
    esac
else
    run_all
fi
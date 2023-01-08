#!/bin/bash

COMPILATION_SUCCESS=0
COMPILATION_FAIL=1
ASSEMBLY_ERROR=2
EXECUTION_ERROR=3
RES=0

# programme
PROG=${PROG:=bin/sos}

# bibliotèque MIPS
MIPS_LIB="../../mips/string.asm"

# fichier d'entrée
INPUT="test/input"

# fichier de sortie
OUTPUT="test/output"

# Simulateur MIPS
MARS="SimulateurMIPS/Mars4_5.jar"

# préparation de l'espace de travail
rm -R $OUTPUT
mkdir $OUTPUT
echo "Program : $PROG\n"

##############################################################################

i=0

# fichiers corrects
for f in $(ls ${INPUT} | grep "^[^_-]"); do
    echo "Test" $i "-" $f
    $PROG -i $INPUT/$f -o $OUTPUT/$f -l $MIPS_LIB
    if [ $? -ne $COMPILATION_SUCCESS ]
    then
        return 1
    fi
    echo "COMPILATION - OK"
    java -jar ${MARS} me ae2 se3 $OUTPUT/$f me
    echo $?
    if [ $? -eq $ASSEMBLY_ERROR ]
    then
        return 2
    fi
    if [ $? -eq $EXECUTION_ERROR ]
    then
        return 3
    fi
    echo "EXECUTION - OK"
    i=$((i+1))
done

# fichiers incorrects
for f in $(ls ${INPUT} | grep "^_"); do
    echo "Test" $i "-" $f
    $PROG -i $INPUT/$f -o $OUTPUT/$f
    if [ $? -ne $COMPILATION_FAIL ]
    then
        return 1
    fi
    echo "COMPILATION - OK"
    i=$((i+1))
done
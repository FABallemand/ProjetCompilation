.data

global_stack: .space 4
const_0: .asciiz "0"
const_1: .asciiz "1"
const_2: .asciiz "0"
const_3: .asciiz "4"
const_4: .asciiz "3"
const_5: .asciiz "bonjour"
const_6: .asciiz "test"
const_7: .asciiz "salut\n"
const_8: .asciiz "3"
const_9: .asciiz "91"
const_10: .asciiz "7"
const_11: .asciiz "0"
const_12: .asciiz "a"
const_13: .asciiz "b"
const_14: .asciiz "c\n"
const_15: .asciiz "3"
const_16: .asciiz "0"
const_17: .asciiz "1"
const_18: .asciiz "0"
const_19: .asciiz "1"
const_20: .asciiz "1"
const_21: .asciiz "1"

.text

addi $sp, $sp, -36 # Empiler contexte global
la $t0, global_stack
sw $sp, 0($t0) # Enregistrer l'adresse du contexte global dans global_stack
Label0:
la $t0, const_0
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label1:
la $t0, const_1
la $a0, const_2
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label2:
la $t0, const_3
la $t2, const_4
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
bgt $t0, $t2, Label4
Label3:
j Label15
Label4:
la $t0, const_5
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label5:
la $t0, const_6
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label6:
la $t0, const_7
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label7:
la $a0, const_8
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label8:
la $t0, const_9
la $t2, const_10
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 20($t1)
Label9:
lw $t0, 20($sp)
la $a0, const_11
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label10:
la $t0, const_12
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label11:
la $t0, const_13
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label12:
la $t0, const_14
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label13:
la $a0, const_15
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label14:
j Label15
Label15:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_16
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 24($t1)
Label16:
lw $t0, 24($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label17:
la $a0, const_17
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label18:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_18
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 28($t1)
Label19:
lw $t0, 28($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label20:
la $a0, const_19
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label21:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_20
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 32($t1)
Label22:
lw $t0, 32($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label23:
la $a0, const_21
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label24:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

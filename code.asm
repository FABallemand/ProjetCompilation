.data

global_stack: .space 4
const_0: .asciiz "0"
const_1: .asciiz "4"
const_2: .asciiz "3"
const_3: .asciiz "if"
const_4: .asciiz "1"
const_5: .asciiz "\n"
const_6: .asciiz "3"
const_7: .asciiz "1"
const_8: .asciiz "2"
const_9: .asciiz "0"
const_10: .asciiz "3"
const_11: .asciiz "2"
const_12: .asciiz "elif"
const_13: .asciiz "2"
const_14: .asciiz "\n"
const_15: .asciiz "3"
const_16: .asciiz "1"
const_17: .asciiz "1"
const_18: .asciiz "1"
const_19: .asciiz "else 3 \n"
const_20: .asciiz "1"
const_21: .asciiz "1"
const_22: .asciiz "2"
const_23: .asciiz "1"
const_24: .asciiz "0"
const_25: .asciiz "\n/^"
const_26: .asciiz "2"
const_27: .asciiz "1"
const_28: .asciiz "\n"
const_29: .asciiz "2"

.text

addi $sp, $sp, -32 # Empiler contexte global
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
la $t2, const_2
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
bgt $t0, $t2, Label3
Label2:
j Label10
Label3:
la $t0, const_3
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label4:
la $t0, const_4
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label5:
la $t0, const_5
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label6:
la $a0, const_6
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label7:
la $t0, const_7
la $t2, const_8
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 12($t1)
Label8:
lw $t0, 12($sp)
la $a0, const_9
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label9:
j Label24
Label10:
la $t0, const_10
la $t2, const_11
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label12
Label11:
j Label19
Label12:
la $t0, const_12
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label13:
la $t0, const_13
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label14:
la $t0, const_14
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label15:
la $a0, const_15
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label16:
la $t0, const_16
la $t2, const_17
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 16($t1)
Label17:
lw $t0, 16($sp)
la $a0, const_18
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label18:
j Label24
Label19:
la $t0, const_19
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label20:
la $a0, const_20
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label21:
la $t0, const_21
la $t2, const_22
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 20($t1)
Label22:
lw $t0, 20($sp)
la $a0, const_23
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label23:
j Label24
Label24:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_24
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 24($t1)
Label25:
lw $t0, 24($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label26:
la $t0, const_25
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label27:
la $a0, const_26
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label28:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_27
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 28($t1)
Label29:
lw $t0, 28($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label30:
la $t0, const_28
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label31:
la $a0, const_29
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label32:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

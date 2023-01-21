.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
err_arg: .asciiz "Mauvais nombre d'argument pour le programme, 0 argument(s) attendu(s)"
const_0: .asciiz "0"
const_1: .asciiz ""
const_2: .asciiz "0"
const_3: .asciiz "0"
const_4: .asciiz "1"
const_5: .asciiz "1"
const_6: .asciiz "0"
const_7: .asciiz "0"
const_8: .asciiz "1"
const_9: .asciiz "42"
const_10: .asciiz "NOK\n"
const_11: .asciiz "1"
const_12: .asciiz "1"
const_13: .asciiz "OK\n"
const_14: .asciiz "1"
const_15: .asciiz "NOK\n"
const_16: .asciiz "1"

.text

addi $sp, $sp, -24 # Empiler contexte global
la $t0, global_stack
sw $sp, 0($t0) # Enregistrer l'adresse du contexte global dans global_stack
beq $a0, 0, fin_check_arg
li $v0, 4
la $a0, err_arg
syscall
li $v0, 10
syscall
fin_check_arg:
Label0:
la $t0, const_0
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label1:
la $t0, const_1
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label2:
la $t0, const_2
la $a0, const_3
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label3:
la $t0, const_4
la $a0, const_5
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label4:
lw $t1, global_stack
addi $t0, $t1, 8
la $a0, const_6
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 16($t1)
Label5:
lw $t0, 16($sp)
la $t2, const_7
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
beq $t0, $t2, Label7
Label6:
j Label22
Label7:
lw $t1, global_stack
addi $t0, $t1, 8
la $a0, const_8
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 20($t1)
Label8:
lw $a0, 20($sp)
la $a1, const_9
jal equal_string
beq $v0, 1, Label10
Label9:
j Label13
Label10:
la $t0, const_10
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label11:
la $a0, const_11
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label12:
j Label22
Label13:
lw $a0, 20($sp)
la $a1, const_12
jal equal_string
beq $v0, 1, Label15
Label14:
j Label18
Label15:
la $t0, const_13
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label16:
la $a0, const_14
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label17:
j Label22
Label18:
la $t0, const_15
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label19:
la $a0, const_16
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label20:
j Label22
Label21:
j Label22
Label22:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

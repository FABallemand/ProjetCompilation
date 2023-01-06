.data

global_stack: .space 4
const_0: .asciiz "0"
const_1: .asciiz "65"
const_2: .asciiz "0"
const_3: .asciiz "66"
const_4: .asciiz "1"
const_5: .asciiz "0"
const_6: .asciiz "1"
const_7: .asciiz "OK"
const_8: .asciiz "1"
const_9: .asciiz "NOK"
const_10: .asciiz "1"
const_11: .asciiz "1"
const_12: .asciiz "7"
const_13: .asciiz "1"

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
la $a0, const_2
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label2:
la $t0, const_3
la $a0, const_4
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label3:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_5
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 12($t1)
Label4:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_6
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 16($t1)
Label5:
lw $t0, 12($sp)
lw $t2, 16($sp)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
beq $t0, $t2, Label7
Label6:
j Label10
Label7:
la $t0, const_7
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label8:
la $a0, const_8
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label9:
j Label13
Label10:
la $t0, const_9
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label11:
la $a0, const_10
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label12:
j Label13
Label13:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_11
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 20($t1)
Label14:
lw $t0, 20($sp)
la $t2, const_12
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 24($t1)
Label15:
lw $t0, 24($sp)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 28($t2)
Label16:
lw $t0, 28($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label17:
la $a0, const_13
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label18:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

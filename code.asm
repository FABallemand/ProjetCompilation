.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
const_0: .asciiz "0"
const_1: .asciiz "0"
const_2: .asciiz "10"
const_3: .asciiz "2"
const_4: .asciiz "0"
const_5: .asciiz "paire : "
const_6: .asciiz "1"
const_7: .asciiz "impaire : "
const_8: .asciiz "1"
const_9: .asciiz "\nXd"
const_10: .asciiz "2"
const_11: .asciiz "1"
const_12: .asciiz "fin\nV"
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
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 20($t2)
Label2:
lw $t0, 20($sp)
la $t2, const_2
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label4
Label3:
j Label19
Label4:
lw $t0, 20($sp)
la $t2, const_3
move $a0, $t0
move $a1, $t2
jal mod_string
lw $t1, global_stack
sw $v0, 24($t1)
Label5:
lw $t0, 24($sp)
la $t2, const_4
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
la $t0, const_5
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label8:
la $a0, const_6
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label9:
j Label13
Label10:
la $t0, const_7
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label11:
la $a0, const_8
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label12:
j Label13
Label13:
lw $t0, 20($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label14:
la $t0, const_9
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label15:
la $a0, const_10
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label16:
lw $t0, 20($sp)
la $t2, const_11
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 28($t1)
Label17:
lw $t0, 28($sp)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 20($t2)
Label18:
j Label2
Label19:
la $t0, const_12
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label20:
la $a0, const_13
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label21:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

.data

global_stack: .space 4
const_0: .asciiz "0"
const_1: .asciiz "abc"
const_2: .asciiz "abc"
const_3: .asciiz "OK"
const_4: .asciiz "1"
const_5: .asciiz "NOK"
const_6: .asciiz "1"

.text

addi $sp, $sp, -4 # Empiler contexte global
la $t0, global_stack
sw $sp, 0($t0) # Enregistrer l'adresse du contexte global dans global_stack
Label0:
la $t0, const_0
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label1:
la $a0, const_1
la $a1, const_2
jal equal_string
beq $v0, 1, Label3
Label2:
j Label7
Label3:
sub $sp, $sp, 4 # Augmenter la taille de la pile
Label4:
la $t0, const_3
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label5:
la $a0, const_4
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label6:
j Label11
Label7:
sub $sp, $sp, 4 # Augmenter la taille de la pile
Label8:
la $t0, const_5
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label9:
la $a0, const_6
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label10:
j Label11
la $a0, const_5
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label9:
la $t0, const_6
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label10:
la $t0, const_7
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label11:
sub $sp, $sp, 16 # Augmenter la taille de la pile
Label12:
la $t0, const_8
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label13:
lw $t0, 4($sp)
sw $t0, 4($sp) # Enregistrer $t0 dans la pile
Label14:
la $t0, const_9
sw $t0, 8($sp) # Enregistrer $t0 dans la pile
Label15:
lw $t0, 8($sp)
sw $t0, 12($sp) # Enregistrer $t0 dans la pile
Label16:
la $a0, const_10
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label17:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

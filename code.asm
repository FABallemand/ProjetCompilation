.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
err_arg: .asciiz "Mauvais nombre d'argument pour le programme, 0 argument(s) attendu(s)"
const_0: .asciiz "0"
const_1: .asciiz "1"
const_2: .asciiz "\n"
const_3: .asciiz "2"
const_4: .asciiz "\n"
const_5: .asciiz "2"
const_6: .asciiz "0"
const_7: .asciiz "1"
const_8: .asciiz "1"
const_9: .asciiz "1"
const_10: .asciiz "\n"
const_11: .asciiz "2"
const_12: .asciiz "\n"
const_13: .asciiz "2"
const_14: .asciiz "5"
const_15: .asciiz "status de fonction :"
const_16: .asciiz "\n"
const_17: .asciiz "3"

.text

addi $sp, $sp, -16 # Empiler contexte global
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
j Label36
Label2:
factoriel:
sw $ra, 8($sp) # Savegarder $ra
Label3:
lw $t0, 0($sp)
la $t2, const_1
move $a0, $t0
move $a1, $t2
jal sub_string
lw $t1, global_stack
sw $v0, 8($t1)
Label4:
lw $t1, global_stack
lw $t0, 8($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label5:
lw $t0, 0($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label6:
la $t0, const_2
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label7:
la $a0, const_3
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label8:
lw $t0, 4($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label9:
la $t0, const_4
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label10:
la $a0, const_5
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label11:
lw $t0, 0($sp)
la $t2, const_6
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
beq $t0, $t2, Label13
Label12:
j Label16
Label13:
la $t0, const_7
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label14:
addi $sp, $sp, 8 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label15:
j Label21
Label16:
lw $t0, 0($sp)
la $t2, const_8
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
beq $t0, $t2, Label18
Label17:
j Label21
Label18:
la $t0, const_9
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label19:
addi $sp, $sp, 8 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label20:
j Label21
Label21:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIE QUE DANS LA FONCTION
addi $sp, $sp, -8 # Agrandir la pile (appel de fonction)
Label22:
lw $t1, prev_stack
lw $t0, 4($t1)
sw $t0, 0($sp)
Label23:
jal factoriel
Label24:
lw $t1, global_stack
lw $t0, 0($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label25:
lw $t0, 4($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label26:
la $t0, const_10
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label27:
la $a0, const_11
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label28:
lw $t0, 4($sp)
lw $t2, 0($sp)
move $a0, $t0
move $a1, $t2
jal mult_string
lw $t1, global_stack
sw $v0, 12($t1)
Label29:
lw $t1, global_stack
lw $t0, 12($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label30:
lw $t0, 4($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label31:
la $t0, const_12
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label32:
la $a0, const_13
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label33:
lw $t0, 4($sp)
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label34:
addi $sp, $sp, 8 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label35:
Label36:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIE QUE DANS LA FONCTION
addi $sp, $sp, -8 # Agrandir la pile (appel de fonction)
Label37:
la $t0, const_14
sw $t0, 0($sp)
Label38:
jal factoriel
Label39:
la $t0, const_15
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label40:
lw $t0, 4($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label41:
la $t0, const_16
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label42:
la $a0, const_17
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label43:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

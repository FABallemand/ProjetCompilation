.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
err_arg: .asciiz "Mauvais nombre d'argument pour le programme, 0 argument(s) attendu(s)"
const_0: .asciiz "0"
const_1: .asciiz ""
const_2: .asciiz "10"
const_3: .asciiz "1"
const_4: .asciiz "1"
const_5: .asciiz "-1"
const_6: .asciiz "FINAL:"
const_7: .asciiz "\n"
const_8: .asciiz "3"
const_9: .asciiz "OK"
const_10: .asciiz "1"

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
la $t0, const_1
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label2:
la $t0, const_2
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label3:
lw $t0, 8($sp)
la $t2, const_3
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label10
Label4:
j Label5
Label5:
lw $t0, 8($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label6:
la $a0, const_4
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label7:
lw $t0, 8($sp)
la $t2, const_5
move $a0, $t0
move $a1, $t2
jal concat_string
lw $t1, global_stack
sw $v0, 12($t1)
Label8:
lw $t0, 12($sp)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label9:
j Label3
Label10:
la $t0, const_6
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label11:
lw $t0, 12($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label12:
la $t0, const_7
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label13:
la $a0, const_8
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
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
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

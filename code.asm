.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
const_0: .asciiz "0"
const_1: .asciiz "3"
const_2: .asciiz "-1"

.text

addi $sp, $sp, -12 # Empiler contexte global
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
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

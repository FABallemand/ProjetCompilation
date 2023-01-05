.data

global_stack: .space 4
const_0: .asciiz "0"
const_1: .asciiz "0"
const_2: .asciiz "boujour"

.text

addi $sp, $sp, -48 # Empiler contexte global
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
sw $t0, 4($t2)
Label2:
la $t0, const_2
lw $a0, 4($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label3:
li $a0, 3
jal echo_string
li $v0, 10
syscall

.include "mips/string.asm"

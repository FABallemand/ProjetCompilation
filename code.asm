.data

global_stack: .space 4
const_0: .asciiz "0"
const_1: .asciiz "1"
const_2: .asciiz "1"
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
la $t0, const_1
la $t2, const_2
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
beq $t0, $t2, Label_3
Label2:
goto Label7
Label3:
Label4:
la $t0, const_3
li $t2, 0
mul $t2, $t2, 4

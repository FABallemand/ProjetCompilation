.data

const_0: .asciiz "0"
const_1: .asciiz "bonjour"
const_2: .asciiz "1"
const_3: .asciiz "je suis un compilateur"
const_4: .asciiz "12"
const_5: .asciiz "qui fonctionne parfaitement"
const_6: .asciiz "123"
const_7: .asciiz "c\'est magnifique !!!"
const_8: .asciiz "1234"
const_9: .asciiz "8"

.text

main:
    addi $sp, $sp, -4
    la $t0, const_1
    sw $t0, 0($sp)
    li $a0, 1
    jal echo_string
    li $v0 10
    syscall
.include "mips/string.asm"
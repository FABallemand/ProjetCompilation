.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
const_0: .asciiz "0"
const_1: .asciiz "9"
const_2: .asciiz "0"
const_3: .asciiz "54"
const_4: .asciiz "1"
const_5: .asciiz "7"
const_6: .asciiz "2"
const_7: .asciiz "37"
const_8: .asciiz "3"
const_9: .asciiz "5"
const_10: .asciiz "4"
const_11: .asciiz "2"
const_12: .asciiz "5"
const_13: .asciiz "9"
const_14: .asciiz "6"
const_15: .asciiz "2"
const_16: .asciiz "7"
const_17: .asciiz "1"
const_18: .asciiz "8"
const_19: .asciiz "12"
const_20: .asciiz "9"
const_21: .asciiz "10"
const_22: .asciiz "0"
const_23: .asciiz "0"
const_24: .asciiz "1"
const_25: .asciiz "0"
const_26: .asciiz "1"
const_27: .asciiz "1"
const_28: .asciiz "1"
const_29: .asciiz "1"
const_30: .asciiz "1"
const_31: .asciiz "1"
const_32: .asciiz "0"
const_33: .asciiz "0"
const_34: .asciiz "1"
const_35: .asciiz "2"
const_36: .asciiz "3"
const_37: .asciiz "4"
const_38: .asciiz "5"
const_39: .asciiz "6"
const_40: .asciiz "7"
const_41: .asciiz "8"
const_42: .asciiz "9"
const_43: .asciiz "\n�O�"
const_44: .asciiz "11"

.text

addi $sp, $sp, -148 # Empiler contexte global
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
la $t0, const_5
la $a0, const_6
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label4:
la $t0, const_7
la $a0, const_8
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label5:
la $t0, const_9
la $a0, const_10
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label6:
la $t0, const_11
la $a0, const_12
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label7:
la $t0, const_13
la $a0, const_14
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label8:
la $t0, const_15
la $a0, const_16
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label9:
la $t0, const_17
la $a0, const_18
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label10:
la $t0, const_19
la $a0, const_20
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label11:
la $t0, const_21
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 44($t2)
Label12:
j Label47
Label13:
tri_bulle:
sw $ra, 12($sp) # Savegarder $ra
Label14:
la $t0, const_22
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label15:
la $t0, const_23
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label16:
lw $t0, 8($sp)
la $t2, const_24
move $a0, $t0
move $a1, $t2
jal sub_string
lw $t1, global_stack
sw $v0, 52($t1)
Label17:
lw $t0, 0($sp)
lw $t1, global_stack
lw $t2, 52($t1)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label19
Label18:
j Label44
Label19:
la $t0, const_25
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label20:
lw $t0, 8($sp)
lw $t2, 0($sp)
move $a0, $t0
move $a1, $t2
jal sub_string
lw $t1, global_stack
sw $v0, 56($t1)
Label21:
lw $t1, global_stack
lw $t0, 56($t1)
la $t2, const_26
move $a0, $t0
move $a1, $t2
jal sub_string
lw $t1, global_stack
sw $v0, 60($t1)
Label22:
lw $t0, 4($sp)
lw $t1, global_stack
lw $t2, 60($t1)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label24
Label23:
j Label41
Label24:
lw $t1, global_stack
addi $t0, $t1, 4
lw $a0, 4($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 64($t1)
Label25:
lw $t0, 4($sp)
la $t2, const_27
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 68($t1)
Label26:
lw $t1, global_stack
addi $t0, $t1, 4
lw $t1, global_stack
lw $a0, 68($t1)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 72($t1)
Label27:
lw $t1, global_stack
lw $t0, 64($t1)
lw $t1, global_stack
lw $t2, 72($t1)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
bgt $t0, $t2, Label29
Label28:
j Label38
Label29:
lw $t1, global_stack
addi $t0, $t1, 4
lw $a0, 4($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 76($t1)
Label30:
lw $t1, global_stack
lw $t0, 76($t1)
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 80($t1)
Label31:
lw $t0, 4($sp)
la $t2, const_28
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 84($t1)
Label32:
lw $t1, global_stack
addi $t0, $t1, 4
lw $t1, global_stack
lw $a0, 84($t1)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 88($t1)
Label33:
lw $t1, global_stack
lw $t0, 88($t1)
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 92($t1)
Label34:
lw $t1, global_stack
lw $t0, 92($t1)
lw $a0, 4($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 4($t1)
Label35:
lw $t0, 4($sp)
la $t2, const_29
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 96($t1)
Label36:
lw $t1, global_stack
lw $t0, 80($t1)
lw $t1, global_stack
lw $a0, 96($t1)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 4($t1)
Label37:
j Label38
Label38:
lw $t0, 4($sp)
la $t2, const_30
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 100($t1)
Label39:
lw $t1, global_stack
lw $t0, 100($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label40:
j Label20
Label41:
lw $t0, 0($sp)
la $t2, const_31
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 104($t1)
Label42:
lw $t1, global_stack
lw $t0, 104($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label43:
j Label16
Label44:
la $t0, const_32
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label45:
addi $sp, $sp, 12 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label46:
Label47:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIT QUE DANS LA FONCTION
addi $sp, $sp, -12 # Agrandir la pile (appel de fonction)
Label48:
lw $t1, prev_stack
lw $t0, 44($t1)
sw $t0, 8($sp)
Label49:
jal tri_bulle
Label50:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_33
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 108($t1)
Label51:
lw $t0, 108($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label52:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_34
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 112($t1)
Label53:
lw $t0, 116($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label54:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_35
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 116($t1)
Label55:
lw $t0, 124($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label56:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_36
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 120($t1)
Label57:
lw $t0, 132($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label58:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_37
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 124($t1)
Label59:
lw $t0, 140($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label60:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_38
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 128($t1)
Label61:
lw $t0, 148($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label62:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_39
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 132($t1)
Label63:
lw $t0, 156($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label64:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_40
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 136($t1)
Label65:
lw $t0, 164($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label66:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_41
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 140($t1)
Label67:
lw $t0, 172($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label68:
lw $t1, global_stack
addi $t0, $t1, 4
la $a0, const_42
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 144($t1)
Label69:
lw $t0, 180($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label70:
la $t0, const_43
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label71:
la $a0, const_44
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label72:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

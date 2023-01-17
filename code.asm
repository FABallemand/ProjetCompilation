.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
err_arg: .asciiz "Mauvais nombre d'argument pour le programme, 0 argument(s) attendu(s)"
const_0: .asciiz "0"
const_1: .asciiz ""
const_2: .asciiz "0"
const_3: .asciiz "Il faut saisir "
const_4: .asciiz "valeurs entieres\n"
const_5: .asciiz "3"
const_6: .asciiz "1"
const_7: .asciiz "Entrez la valeur "
const_8: .asciiz " : \n"
const_9: .asciiz "3"
const_10: .asciiz "0"
const_11: .asciiz "Les valeurs doivent etre strictement positives !\n"
const_12: .asciiz "1"
const_13: .asciiz "1"
const_14: .asciiz "1"
const_15: .asciiz "0"
const_16: .asciiz "0"
const_17: .asciiz "0"
const_18: .asciiz "1"
const_19: .asciiz "1"
const_20: .asciiz "0"
const_21: .asciiz "Nombre de valeurs :"
const_22: .asciiz "1"
const_23: .asciiz "0"
const_24: .asciiz "Moyenne ="
const_25: .asciiz "\n"
const_26: .asciiz "3"
const_27: .asciiz "Erreur\n"
const_28: .asciiz "1"

.text

addi $sp, $sp, -72 # Empiler contexte global
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
j Label51
Label3:
lecture_valeurs:
sw $ra, 12($sp) # Savegarder $ra
Label4:
la $t0, const_2
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label5:
lw $t0, 4($sp)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 8($t2)
Label6:
la $t0, const_3
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label7:
lw $t0, 8($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label8:
la $t0, const_4
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label9:
la $a0, const_5
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string_function # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label10:
lw $t0, 0($sp)
lw $t2, 8($sp)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label12
Label11:
j Label30
Label12:
lw $t0, 0($sp)
la $t2, const_6
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 28($t1)
Label13:
lw $t1, global_stack
lw $t0, 28($t1)
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 32($t1)
Label14:
la $t0, const_7
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label15:
lw $t1, global_stack
lw $t0, 32($t1)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label16:
la $t0, const_8
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label17:
la $a0, const_9
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string_function # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label18:
jal read_string
move $t0, $v0
lw $a0, 0($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 8($t1)
Label19:
lw $t1, global_stack
addi $t0, $t1, 8
lw $a0, 0($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 36($t1)
Label20:
lw $t1, global_stack
lw $t0, 36($t1)
la $t2, const_10
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
bgt $t0, $t2, Label27
Label21:
j Label22
Label22:
la $t0, const_11
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label23:
la $a0, const_12
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string_function # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label24:
la $t0, const_13
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label25:
addi $sp, $sp, 12 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label26:
j Label27
Label27:
lw $t0, 0($sp)
la $t2, const_14
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 40($t1)
Label28:
lw $t1, global_stack
lw $t0, 40($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label29:
j Label10
Label30:
la $t0, const_15
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label31:
addi $sp, $sp, 12 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label32:
Label33:
j Label51
Label34:
moyenne:
sw $ra, 12($sp) # Savegarder $ra
Label35:
la $t0, const_16
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label36:
la $t0, const_17
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label37:
lw $t0, 0($sp)
lw $t2, 8($sp)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label39
Label38:
j Label45
Label39:
lw $t1, global_stack
addi $t0, $t1, 8
lw $a0, 0($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 48($t1)
Label40:
lw $t0, 4($sp)
lw $t1, global_stack
lw $t2, 48($t1)
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 52($t1)
Label41:
lw $t1, global_stack
lw $t0, 52($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label42:
lw $t0, 0($sp)
la $t2, const_18
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 56($t1)
Label43:
lw $t1, global_stack
lw $t0, 56($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label44:
j Label37
Label45:
lw $t0, 4($sp)
lw $t2, 8($sp)
move $a0, $t0
move $a1, $t2
jal div_string
lw $t1, global_stack
sw $v0, 60($t1)
Label46:
lw $t1, global_stack
lw $t0, 60($t1)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label47:
la $a0, const_19
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string_function # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label48:
la $t0, const_20
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label49:
addi $sp, $sp, 12 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label50:
Label51:
la $t0, const_21
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label52:
la $a0, const_22
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label53:
jal read_string
move $t0, $v0
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 64($t2)
Label54:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIE QUE DANS LA FONCTION
addi $sp, $sp, -12 # Agrandir la pile (appel de fonction)
Label55:
lw $t1, prev_stack
lw $t0, 64($t1)
sw $t0, 4($sp)
Label56:
jal lecture_valeurs
Label57:
lw $a0, 0($sp)
la $a1, const_23
jal equal_string
beq $v0, 1, Label59
Label58:
j Label68
Label59:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIE QUE DANS LA FONCTION
addi $sp, $sp, -12 # Agrandir la pile (appel de fonction)
Label60:
lw $t1, prev_stack
lw $t0, 64($t1)
sw $t0, 8($sp)
Label61:
jal moyenne
Label62:
lw $t0, 4($sp)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 68($t2)
Label63:
la $t0, const_24
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label64:
lw $t0, 72($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label65:
la $t0, const_25
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label66:
la $a0, const_26
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label67:
j Label71
Label68:
la $t0, const_27
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label69:
la $a0, const_28
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label70:
j Label71
Label71:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

.data

global_stack: .space 4
prev_stack: .space 4 # Enregistre l'emplacement dans la pile de stack de a fonction appelante (utile pour le passage d'arguments locaux)
err_arg: .asciiz "Mauvais nombre d'argument pour le programme, 0 argument(s) attendu(s)"
const_0: .asciiz "0"
const_1: .asciiz ""
const_2: .asciiz "0"
const_3: .asciiz "1"
const_4: .asciiz "RES"
const_5: .asciiz "\n"
const_6: .asciiz "3"
const_7: .asciiz "\n"
const_8: .asciiz "3"
const_9: .asciiz "Il faut saisir "
const_10: .asciiz "valeurs entieres\n"
const_11: .asciiz "3"
const_12: .asciiz "dans le while"
const_13: .asciiz "\n"
const_14: .asciiz "3"
const_15: .asciiz "1"
const_16: .asciiz "Entrez la valeur "
const_17: .asciiz " : \n"
const_18: .asciiz "3"
const_19: .asciiz "0"
const_20: .asciiz "Les valeurs doivent etre strictement positives !\n"
const_21: .asciiz "1"
const_22: .asciiz "1"
const_23: .asciiz "1"
const_24: .asciiz "0"
const_25: .asciiz "0"
const_26: .asciiz "0"
const_27: .asciiz "1"
const_28: .asciiz "1"
const_29: .asciiz "0"
const_30: .asciiz "Nombre de valeurs :"
const_31: .asciiz "1"
const_32: .asciiz "Avant appel de lecture_valeur"
const_33: .asciiz "\n"
const_34: .asciiz "3"
const_35: .asciiz "0"
const_36: .asciiz "Moyenne ="
const_37: .asciiz "\n"
const_38: .asciiz "3"
const_39: .asciiz "Erreur\n"
const_40: .asciiz "1"

.text

addi $sp, $sp, -80 # Empiler contexte global
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
j Label65
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
lw $t0, 0($sp)
la $t2, const_3
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 28($t1)
Label7:
lw $t1, global_stack
lw $t0, 28($t1)
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 32($t1)
Label8:
la $t0, const_4
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label9:
lw $t1, global_stack
lw $t0, 32($t1)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label10:
la $t0, const_5
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label11:
la $a0, const_6
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label12:
lw $t0, 0($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label13:
lw $t0, 12($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label14:
la $t0, const_7
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label15:
la $a0, const_8
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label16:
la $t0, const_9
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label17:
lw $t0, 8($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label18:
la $t0, const_10
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label19:
la $a0, const_11
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label20:
lw $t0, 0($sp)
lw $t2, 8($sp)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label22
Label21:
j Label44
Label22:
la $t0, const_12
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label23:
lw $t0, 4($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label24:
la $t0, const_13
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label25:
la $a0, const_14
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label26:
lw $t0, 0($sp)
la $t2, const_15
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 36($t1)
Label27:
lw $t1, global_stack
lw $t0, 36($t1)
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 40($t1)
Label28:
la $t0, const_16
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label29:
lw $t1, global_stack
lw $t0, 40($t1)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label30:
la $t0, const_17
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label31:
la $a0, const_18
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label32:
jal read_string
move $t0, $v0
lw $a0, 0($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 8($t1)
Label33:
lw $t1, global_stack
addi $t0, $t1, 8
lw $a0, 0($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 44($t1)
Label34:
lw $t1, global_stack
lw $t0, 44($t1)
la $t2, const_19
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
bgt $t0, $t2, Label41
Label35:
j Label36
Label36:
la $t0, const_20
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label37:
la $a0, const_21
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label38:
la $t0, const_22
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label39:
addi $sp, $sp, 12 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label40:
j Label41
Label41:
lw $t0, 0($sp)
la $t2, const_23
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 48($t1)
Label42:
lw $t1, global_stack
lw $t0, 48($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label43:
j Label20
Label44:
la $t0, const_24
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
j Label65
Label48:
moyenne:
sw $ra, 12($sp) # Savegarder $ra
Label49:
la $t0, const_25
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label50:
la $t0, const_26
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label51:
lw $t0, 0($sp)
lw $t2, 8($sp)
move $a0, $t0
jal string_to_int
move $t0, $v0
move $a0, $t2
jal string_to_int
move $t2, $v0
blt $t0, $t2, Label53
Label52:
j Label59
Label53:
lw $t1, global_stack
addi $t0, $t1, 8
lw $a0, 0($sp)
jal string_to_int
move $t2, $v0
mul $t2, $t2, 4  # Convertir l'offset en octet
add $t0, $t0, $t2 # Adresse de l'élément du tableau
lw $t3, 0($t0)    # Charger la valeur dans $t3
lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global
sw $t3, 56($t1)
Label54:
lw $t0, 4($sp)
lw $t1, global_stack
lw $t2, 56($t1)
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 60($t1)
Label55:
lw $t1, global_stack
lw $t0, 60($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 4($t2)
Label56:
lw $t0, 0($sp)
la $t2, const_27
move $a0, $t0
move $a1, $t2
jal add_string
lw $t1, global_stack
sw $v0, 64($t1)
Label57:
lw $t1, global_stack
lw $t0, 64($t1)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 0($t2)
Label58:
j Label51
Label59:
lw $t0, 4($sp)
lw $t2, 8($sp)
move $a0, $t0
move $a1, $t2
jal div_string
lw $t1, global_stack
sw $v0, 68($t1)
Label60:
lw $t1, global_stack
lw $t0, 68($t1)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label61:
la $a0, const_28
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
lw $t0, global_stack # 
sw $v0, 4($t0) # Sauvegarder le résultat dans la varible globale _return_value
Label62:
la $t0, const_29
li $t2, 0
mul $t2, $t2, 4
lw $t1, global_stack
add $t1, $t1, $t2
sw $t0, 0($t1)
Label63:
addi $sp, $sp, 12 # Rétrécir la pile (appel de fonction)
lw $ra, 0($sp) # Savegarder $ra
addi $sp, $sp, 4 # Rétrécir la pile pour $ra
jr $ra # retour à l'appelant
Label64:
Label65:
la $t0, const_30
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label66:
la $a0, const_31
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label67:
jal read_string
move $t0, $v0
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 72($t2)
Label68:
la $t0, const_32
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label69:
lw $t0, 76($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label70:
la $t0, const_33
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label71:
la $a0, const_34
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label72:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIE QUE DANS LA FONCTION
addi $sp, $sp, -12 # Agrandir la pile (appel de fonction)
Label73:
lw $t1, prev_stack
lw $t0, 72($t1)
sw $t0, 4($sp)
Label74:
jal lecture_valeurs
Label75:
lw $a0, 0($sp)
la $a1, const_35
jal equal_string
beq $v0, 1, Label77
Label76:
j Label86
Label77:
la $t0, prev_stack
sw $sp, 0($t0) # on enregistre l'emplacement de la stack appelante
addi $sp, $sp, -4 # Agrandir la pile pour $ra ATTENTION CETTE CASE MEMOIRE N'EST REMPLIE QUE DANS LA FONCTION
addi $sp, $sp, -12 # Agrandir la pile (appel de fonction)
Label78:
lw $t1, prev_stack
lw $t0, 72($t1)
sw $t0, 8($sp)
Label79:
jal moyenne
Label80:
lw $t0, 4($sp)
li $t2, 0
mul $t2, $t2, 4
add $t2, $t2, $sp
sw $t0, 76($t2)
Label81:
la $t0, const_36
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label82:
lw $t0, 80($sp)
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label83:
la $t0, const_37
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label84:
la $a0, const_38
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label85:
j Label89
Label86:
la $t0, const_39
sub $sp, $sp, 4 # Ajouter de l'espace dans la pile
sw $t0, 0($sp) # Enregistrer $t0 dans la pile
Label87:
la $a0, const_40
jal string_to_int # Convertir le nombre de chaine en entier
move $a0, $v0 # Placer le nombre de chaine en argument de fonction
jal echo_string # Appeler la fonction echo_string
Label88:
j Label89
Label89:
li $a0, 0
li $v0, 17
syscall

.include "mips/string.asm"

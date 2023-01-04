# Bibliothèque de gestion des chaines de caratères en mips

.data

error_string_not_an_int: .asciiz "erreur : la chaine que vous essayez de convertir n'est pas un entier."
error_overflow_msg: .asciiz "erreur : overflow detecté."
int_to_str: .space 512
one_space: .asciiz " "
read_buffer: .space 1024

.text

save_reg:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

restore_reg:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp

error_not_int:
	li $v0, 4                       # 
	la $a0, error_string_not_an_int # Charger adresse du message d'erreur
	syscall                         #
	li $v0, 10                      #
	syscall                         #

error_overflow:
	li $v0, 4			   #
	la $a0, error_overflow_msg # Charger adresse du message d'erreur
	syscall                #
	li $v0, 10             #
	syscall                #

# FUN countchar
# ARGS:
# $a0: Addresse de la chaine de caractères dont on veut connaitre la taille
# RETURN $v0: La taille de la chaine de caractères (sans compter le caractère sentinelle)
count_char:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	li   $v0, 0 # Compteur (initialisé à 0) dans la valeur de retour ($v0) pour compter le nombre de caractères différents de \0
	li   $t2, 0 # Initiliser offset pour la lecture des caractères
count_char_loop:
	add $t3, $t2, $a0 		  # Calcul de l'adresse du prochain caractère (adresse de départ ($a0) + nombre de caractères déjà lus ($t2))
	lb $t1, 0($t3)    		  # Charger le prochain char ascii dans $t1
	beqz $t1, count_char_exit # Si le caratère est le caractère sentinelle (0) alors arreter de compter (fin de boucle)
	addi $v0, $v0, 1 		  # Incrémenter le compteur
	addi $t2, $t2, 1 		  # Incrémenter l'offset pour lire le caractère suivant (probalement redondant avec v0)
	j count_char_loop		  # Boucle
count_char_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
# END FUN count_char

# FUN is_integer
# ARGS:
# $a0: Addresse de la chaine de caractères
# RETURN $v0: 1 si la chaine de caratère est un entier, 0 sinon
is_integer:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	li $v0, 1 							# Initialement la chaine de caractère est considérée comme un entier
	li $t2, 0 							# Initialiser offset pour la lecture des caractères
	lb $t1, 0($a0)                      # Test préliminaire sur le premier caractère
	beqz $t1, is_integer_false          # Chaine vide, ce n'est pas un nombre
	beq  $t1, 45, is_integer_first_symb # Premier caractère est -
	beq $t1, 43, is_integer_first_symb  # Premier caractère est +
	j is_integer_loop
is_integer_first_symb:
	addi $t2, $t2, 1           # Incrémenter offset pour la lecture des caractères (au prochain tour de boucle)
	lb $t1, 1($a0) 			   # Test préliminaire sur le deuxième caractère
	beqz $t1, is_integer_false # Chaine contenant uniquement - ou +, ce n'est pas un nombre
is_integer_loop:
	add $t3, $t2, $a0 		  	  # Calcul de l'adresse du prochain caractère (adresse de départ ($a0) + nombre de caractères déjà lus ($t2))
	lb $t1, 0($t3)    		  	  # Charger le prochain char ascii dans $t1
	beqz $t1, is_integer_exit 	  # Fin de la chaine de caractère
	blt $t1, 48, is_integer_false # Code ascii inferieur à celui du caractère "0", ce n'est pas un chiffre
	bgt $t1, 57, is_integer_false # Code ascii supérieur à celui du caractère "9", ce n'est pas un chiffre
	addi $t2, $t2, 1 			  # Incrémenter l'offset pour lire le caractère suivant (probalement redondant avec v0)
	j is_integer_loop			  # Boucle
is_integer_false:
	li $v0, 0
is_integer_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
# END FUN is_integer	

# FUN string_to_int
# ARGS:
# $a0: Addresse de la chaine de caractères
# RETURN $v0: Entier correspondant à la chaine de caractère
string_to_int:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)
	
	jal is_integer          # Verifier si la chaine contient un entier
	beqz $v0, error_not_int #
	li $t5, 0 			    # Initialiser le résultat
	li $t2, 0 			    # Initialiser offset pour la lecture des caractères
	li $t9, 10			    # Constante pour multiplications par 10
	lb $t1, 0($a0)          # Test préliminaire sur le premier caractère
	beq  $t1, 45, sti_neg   # Premier caractère est -
	beq $t1, 43, sti_pos    # Premier caractère est +
	li $t4, 1 			    # Pas de signe, marquer l'entier comme positif
	j sti_loop              # Boucle
sti_neg:
	addi $t2, $t2, 1 # Incrémenter offset pour la lecture des caractères (ie: ignorer le signe lors de la conversion)
	li $t4, -1 		 # Marquer l'entier comme négatif
	j sti_loop	     # Boucle
sti_pos:
	addi $t2, $t2, 1 # Incrémenter offset pour la lecture des caractères (ie: ignorer le signe lors de la conversion)
	li $t4, 1        # Marquer l'entier comme positif
	j sti_loop       # Boucle
sti_loop:
	add $t3, $t2, $a0 		     # Calcul de l'adresse du prochain caractère (adresse de départ ($a0) + nombre de caractères déjà lus ($t2))
	lb $t1, 0($t3)    		     # Charger le prochain char ascii dans $t1
	beqz $t1, sti_exit           # Fin de la chaine de caractères
	mult $t5, $t9                # Multiplier l'entier par 10
	mfhi $t6 			         # Charger le résultat de la multiplication par 10
	mflo $t5 			         # Charger le résultat de la multiplication par 10
	bnez $t6, error_overflow     # Vérifier overflow multiplication
	move $t6, $t5                # Faire une copie avant l'addtition
	sub $t1, $t1, 48             # Soustraire le code ascii de zéro au caractère lu pour obtenir le chiffre
	add $t5, $t5, $t1            # Additionner le chiffre
	blt $t5, $t6, error_overflow # Vérifier overflow addition (si le chiffre après addition est plus faible qu'avant on a fait un overflow)
	addi $t2, $t2, 1 		     # Incrémenter offset pour la lecture des caractères
	j sti_loop				     # Boucle
sti_exit:
	mult $t4, $t5     # Ajouter le signe
	mflo $v0          # Placer le résultat dans $v0
	mthi $zero	      # Réinitialiser les registres de multiplication
	mtlo $zero        # Réinitialiser les registres de multiplication
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
# END FUN string_to_int

# FUN int_to_string (à étudier en détail...trouvée sur internet-> ajouter le lien vers la page!!!)
# ARGS:
# $a0: Entier à convertir
# $a1: Adresse de l'espace mémoire de la chaine résultante
int_to_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	bltz $a0, neg_num # Si l'entier est négatif
	j next0           # Sinon
neg_num:
	li   $t0, '-'      # 
	sb   $t0, ($a1)    # Placer "-" à l'adresse de la chaine de caractère résultante
	addi $a1, $a1, 1   # Incrémenter l'adresse de la chaine de caractère résultante (pour pointer après le "-")
	li   $t0, -1       #
	mul  $a0, $a0, $t0 # Transformer l'entier à convertir en entier positif
next0:
	li   $t0, -1	  #
	addi $sp, $sp, -4 # Faire de la place dans la pile pour un caractère
	sw   $t0, ($sp)   # Enregistrer -1 dans la pile (marqueur de fin de pile)
push_digits:
	blez $a0, next1   # Si l'entier est négatif ou nul
	li   $t0, 10      # Sinon
	div  $a0, $t0     # Diviser l'entier par 10 (lo = quotient, hi = remainder)
	mfhi $t0          # $t0 = entier % 10
	mflo $a0          # entier = entier // 10  
	addi $sp, $sp, -4 # Faire de la place dans la pile pour un caractère
	sw   $t0, ($sp)   # Enregistrer entier % 10 dans la pile
	j    push_digits  # Boucle
next1:
	lw $t0, ($sp)     # $t0 = dernier entier dans la pile
	addi $sp, $sp, 4    # Faire de la place dans la pile pour un caractère
	bltz $t0, neg_digit # Si le dernier entier dans la pile est négatif ou nul (ie: entier = 0)
	j    pop_digits     # Sinon
neg_digit:
	li   $t0, '0'    #
	sb   $t0, ($a1)  # *str = ASCII of '0'
	addi $a1, $a1, 1 # str++
	j    next2       # jump to next2
pop_digits:
	bltz $t0, next2    # if digit <= 0 goto next2 (end of loop)
	addi $t0, $t0, '0' # else, $t0 = ASCII of digit
	sb   $t0, ($a1)    # *str = ASCII of digit
	addi $a1, $a1, 1   # str++
	lw $t0, ($sp)    # digit = pop off from MIPS stack 
	addi $sp, $sp, 4   # restore stack
	j    pop_digits    # and loop
next2:
	sb  $zero, ($a1) # *str = 0 (end of string marker)
	mthi $zero
	mtlo $zero
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant
# END FUN int_to_string

# FUN add_string
# ARGS:
# $a0: Addresse de la première chaine de caractères
# $a1: Addresse de la deuxième chaine de caractères
# RETURN $v0: Adresse de la chaine de caractère nouvellement allouée contenant le résultat de l'opération
# PAS DE VERIFICATION D'OVERFLOW
add_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t0, $a0  			# Faire une copie de la première chaine
	move $t1, $a1  			# Faire une copie de la deuxième chaine
	jal is_integer 			# Vérifier si la première chaine est un entier
	beqz $v0, error_not_int # Vérifier si la première chaine est un entier
	jal string_to_int       # Convertir la première chaine en nombre
	move $t2, $v0           # Enregistrer le résultat dans $t2
	jal count_char          # Déterminer la taille de la première chaine de caractères
	move $t4, $v0           # Enregistrer le résultat dans $t4

	move $a0, $a1			# Placer la deuxième chaine dans $a0
	jal is_integer          # Vérifier si la deuxième chaine est un entier
	beqz $v0, error_not_int # Vérifier si la deuxième chaine est un entier
	jal string_to_int       # Convertir la deuxième chaine en nombre
	move $t3, $v0           # Enregistrer le résultat dans $t3
	jal count_char          # Déterminer la taille de la deuxième chaine de caractères
	move $t5, $v0           # Enregistrer le résultat dans $t5

	bge $t4, $t5, add_string_4_ge_5 # La taille de la chaine résultante corrspond à la taille de la plus grande chaine + 3 (+1 caractère sentinelle, +1 éventuel signe, +1 passage à la dizaine, centaine... supérieure)
	add $t4, $t5, 3 			    # Enregistrer la taille de la chaine résultante dans $t4
	j add_string_next
add_string_4_ge_5:
	add $t4, $t4, 3   # Enregistrer la taille de la chaine résultante dans $t4
	j add_string_next # (Saut inutile)
add_string_next:
	move $a0, $t4 # Placer la taille de la chaine résultante en argument
	li $v0, 9     # Code de la primitive pour sbrk
	syscall       # Allocation de la memoire necessaire

	move $a1, $v0     # Placer $v0 en argument de fonction
	add $a0, $t2, $t3 # Additionner les deux nombres et placer le résultat en argument de focntion
	jal int_to_string # Convertir le résultat de l'addition en chaine de caractères
	j add_string_exit # (Saut inutile)
add_string_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
#END FUN add_string

# FUN sub_string
# ARGS:
# $a0: Addresse de la première chaine de caractères
# $a1: Addresse de la deuxième chaine de caractères
# RETURN $v0: Adresse de la chaine de caractère nouvellement allouée contenant le résultat de l'opération
# PAS DE VERIFICATION D'OVERFLOW
sub_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t0, $a0  			# Faire une copie de la première chaine
	move $t1, $a1  			# Faire une copie de la deuxième chaine
	jal is_integer 			# Vérifier si la première chaine est un entier
	beqz $v0, error_not_int # Vérifier si la première chaine est un entier
	jal string_to_int       # Convertir la première chaine en nombre
	move $t2, $v0           # Enregistrer le résultat dans $t2
	jal count_char          # Déterminer la taille de la première chaine de caractères
	move $t4, $v0           # Enregistrer le résultat dans $t4

	move $a0, $a1			# Placer la deuxième chaine dans $a0
	jal is_integer          # Vérifier si la deuxième chaine est un entier
	beqz $v0, error_not_int # Vérifier si la deuxième chaine est un entier
	jal string_to_int       # Convertir la deuxième chaine en nombre
	move $t3, $v0           # Enregistrer le résultat dans $t3
	jal count_char          # Déterminer la taille de la deuxième chaine de caractères
	move $t5, $v0           # Enregistrer le résultat dans $t5

	bge $t4, $t5, sub_string_4_ge_5 # La taille de la chaine résultante corrspond à la taille de la plus grande chaine + 3 (+1 caractère sentinelle, +1 éventuel signe, +1 passage à la dizaine, centaine... supérieure)
	add $t4, $t5, 3 			    # Enregistrer la taille de la chaine résultante dans $t4
	j sub_string_next
sub_string_4_ge_5:
	add $t4, $t4, 3   # Enregistrer la taille de la chaine résultante dans $t4
	j sub_string_next # (Saut inutile)
sub_string_next:
	move $a0, $t4 # Placer la taille de la chaine résultante en argument
	li $v0, 9     # Code de la primitive pour sbrk
	syscall       # Allocation de la memoire necessaire

	move $a1, $v0     # Placer $v0 en argument de fonction
	add $a0, $t2, $t3 # Additionner les deux nombres et placer le résultat en argument de focntion
	jal int_to_string # Convertir le résultat de l'addition en chaine de caractères
	j sub_string_exit # (Saut inutile)
sub_string_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
#END FUN sub_string

# FUN mult_string
# ARGS:
# $a0: Addresse de la première chaine de caractères
# $a1: Addresse de la deuxième chaine de caractères
# RETURN $v0: Adresse de la chaine de caractère nouvellement allouée contenant le résultat de l'opération
# PAS DE VERIFICATION D'OVERFLOW
mult_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t0, $a0  			# Faire une copie de la première chaine
	move $t1, $a1  			# Faire une copie de la deuxième chaine
	jal is_integer 			# Vérifier si la première chaine est un entier
	beqz $v0, error_not_int # Vérifier si la première chaine est un entier
	jal string_to_int       # Convertir la première chaine en nombre
	move $t2, $v0           # Enregistrer le résultat dans $t2

	move $a0, $a1			# Placer la deuxième chaine dans $a0
	jal is_integer          # Vérifier si la deuxième chaine est un entier
	beqz $v0, error_not_int # Vérifier si la deuxième chaine est un entier
	jal string_to_int       # Convertir la deuxième chaine en nombre
	move $t3, $v0           # Enregistrer le résultat dans $t3

	li $t4, 16     # Le nombre maximal sur 32 bit signé est 2 147 483 647 (donc 10 caractères + le caractère sentinelle). Allouer 16 pour plus de sécurité (a changer durant l'optimisation).
	move $a0, $t4  #
	li $v0, 9      #
	syscall        # Allocation de la memoire necessaire
	move $a1, $v0  # Placer la mémoire allouée en argument de fonction
	mult $t2 , $t3 # Multiplier les deux nombres
	mflo $a0       # Placer le résultat en argument de focntion
	mfhi $t9       # Vérification overflow
	beqz $t9, suite_mult_l
	beq $t9, -1, suite_mult_l # il y a un probleme ici (certain overflow nous echappe dans les negatifs) mais je suis pas ssez malin pour le fix
	mthi $zero
	j error_overflow
suite_mult_l:
	jal int_to_string # Convertir le résultat de la multiplication en chaine de caractères
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
#END FUN mult_string

# FUN div_string
# ARGS:
# $a0: Addresse de la première chaine de caractères
# $a1: Addresse de la deuxième chaine de caractères
# RETURN $v0: Adresse de la chaine de caractère nouvellement allouée contenant le résultat de l'opération
# PAS DE VERIFICATION D'OVERFLOW
div_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t0, $a0  			# Faire une copie de la première chaine
	move $t1, $a1  			# Faire une copie de la deuxième chaine
	jal is_integer 			# Vérifier si la première chaine est un entier
	beqz $v0, error_not_int # Vérifier si la première chaine est un entier
	jal string_to_int       # Convertir la première chaine en nombre
	move $t2, $v0           # Enregistrer le résultat dans $t2

	move $a0, $a1			# Placer la deuxième chaine dans $a0
	jal is_integer          # Vérifier si la deuxième chaine est un entier
	beqz $v0, error_not_int # Vérifier si la deuxième chaine est un entier
	jal string_to_int       # Convertir la deuxième chaine en nombre
	move $t3, $v0           # Enregistrer le résultat dans $t3

	li $t4, 16        # Le nombre maximal sur 32 bit signé est 2 147 483 647 (donc 10 caractères + le caractère sentinelle). Allouer 16 pour plus de sécurité (a changer durant l'optimisation).
	move $a0, $t4     #
	li $v0, 9         #
	syscall           # Allocation de la memoire necessaire
	move $a1, $v0     # Placer la mémoire allouée en argument de fonction
	div $t2 , $t3     # Effectuer la division entre les deux nombres et récupérer le quotient
	mflo $a0          # Placer le résultat en argument de fonction
	mthi $zero        # ???
	mtlo $zero        # ???
	jal int_to_string # Convertir le résultat de la division en chaine de caractère
	j div_string_exit # (Saut inutile)
div_string_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
#END FUN div_string

# FUN mod_string
# ARGS:
# $a0: Addresse de la première chaine de caractères
# $a1: Addresse de la deuxième chaine de caractères
# RETURN $v0: Adresse de la chaine de caractère nouvellement allouée contenant le résultat de l'opération
# PAS DE VERIFICATION D'OVERFLOW
mod_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t0, $a0  			# Faire une copie de la première chaine
	move $t1, $a1  			# Faire une copie de la deuxième chaine
	jal is_integer 			# Vérifier si la première chaine est un entier
	beqz $v0, error_not_int # Vérifier si la première chaine est un entier
	jal string_to_int       # Convertir la première chaine en nombre
	move $t2, $v0           # Enregistrer le résultat dans $t2

	move $a0, $a1			# Placer la deuxième chaine dans $a0
	jal is_integer          # Vérifier si la deuxième chaine est un entier
	beqz $v0, error_not_int # Vérifier si la deuxième chaine est un entier
	jal string_to_int       # Convertir la deuxième chaine en nombre
	move $t3, $v0           # Enregistrer le résultat dans $t3

	li $t4, 16        # Le nombre maximal sur 32 bit signé est 2 147 483 647 (donc 10 caractères + le caractère sentinelle). Allouer 16 pour plus de sécurité (a changer durant l'optimisation).
	move $a0, $t4     #
	li $v0, 9         #
	syscall           # Allocation de la memoire necessaire
	move $a1, $v0     # Placer la mémoire allouée en argument de fonction
	div $t2, $t3      # Effectuer la division entre les deux nombres et récupérer le reste
	mfhi $a0          # Placer le résultat en argument de fonction
	mthi $zero        # Réinitialiser les registres dans le doute...
	mtlo $zero        # Réinitialiser les registres dans le doute...
	jal int_to_string # Convertir le reste de la division en chaine de caractère
	j mod_string_exit # (Saut inutile)
mod_string_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
#END FUN mod_string

# FUN concat_string
# ARGS:
# $a0: Addresse de la première chaine de caractères
# $a1: Addresse de la deuxième chaine de caractères
# RETURN $v0: Adresse de la chaine de caractère nouvellement allouée contenant le résultat de l'opération
# PAS DE VERIFICATION D'OVERFLOW
concat_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t0, $a0  # Faire une copie de la première chaine
	move $t1, $a1  # Faire une copie de la deuxième chaine
	jal count_char # Déterminer la taille de la première chaine de caractères
	move $t2, $v0  # Enregistrer le résultat dans $t2
	move $a0, $a1  # Placer la deuxième chaine en argument de fonction
	jal count_char # Déterminer la taille de la deuxième chaine de caractères
	move $t3, $v0  # Enregistrer le résultat dans $t3

	add $t4, $t2, $t3 # Calcul de la taille de la chaine de caractère résultante
	add $t4, $t4, 1   # Ajouter 1 pour le caractère sentinelle

	move $a0, $t4 # Placer la taille de la chaine de caractère résultante en argument de focntion
	li $v0, 9     #
	syscall       # Allocation de la memoire necessaire
	move $t5, $v0 # Enregristrer l'adresse de la zone memoire pour la renvoyer à la fin
	move $t6, $v0 # Enregristrer l'adresse de la zone memoire pour la modifier
loop_concat_1:
	lb $t7, 0($t0)          # Enregistrer temporairement le caractère en début de chaine
	beqz $t7, loop_concat_2 # Fin de la première chaine de caractères
	add $t0, $t0, 1         # Déplacer la tête de lecture sur la première chaine d'un caractère
	sb $t7, 0($t6)          # Enregistrer le caractère dans la chaine résultat
	add $t6, $t6, 1         # Déplacer la tête d'écriture dans la chaine résultat
	j loop_concat_1			# Boucle
loop_concat_2:
	lb $t7, 0($t1)               # Enregistrer temporairement le caractère en début de chaine
	beqz $t7, concat_string_exit # Fin de la deuxième chaine de caractères
	add $t1, $t1, 1              # Déplacer la tête de lecture sur la deuxième chaine d'un caractère
	sb $t7, 0($t6)               # Enregistrer le caractère dans la chaine résultat
	add $t6, $t6, 1              # Déplacer la tête d'écriture dans la chaine résultat
	j loop_concat_2              # Boucle
concat_string_exit:
	sb $zero, 0($t6)
	move $v0, $t5
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	jr $ra 			  # Retour à l'appelant avec resultat dans v0
#END FUN concat_string

# FUN echo_string
# ARGS:
# $a0: Nombre de chaines à afficher (on considère que leurs adresses ont été rentrées dans l'ordre dans la pile)
# ATTENTION : On reduit la taille de la pile à l'intérieur du echo!
#             Cela permet de s'épargner un quad.
#             A la fin de cette fonction le pointeur de pile est plus grand de $a0*4.
echo_string:
	addi $sp, $sp, -44 # Enregistre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp)
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)
	
	move $t0, $a0
	beqz $t0, echo_string_exit # Si aucun argument
	move $t7, $a0
	li   $t1, 40               # Offset initial des arguments dans la pile (normalement 44 mais vue que au minimum on a 1 argument ça fait 40+4*1 donc 44)
	                           # Afficher la première chaine (car si elle est seule on ne rajoutera pas d'espace)
	mul $t2, $t0, 4            # Multiplier le nombre d'argmuents restants par la taille d'un mot (4)
	add $t3, $t2, $t1          # j'additionne l'offset aisni obtenu avec l'offset inititial
	add $t3, $t3, $sp          # je calcule l'adresse réel de l'élément grace au stack pointer
	lw  $a0, 0($t3)            # je deplace cette adresse dans a0
	li  $v0, 4				   #
	syscall                    #
	sub $t0, $t0, 1            # Décrémenter le nombre de chaines à afficher
echo_string_loop:
	beqz $t0, echo_string_exit
	la $a0, one_space
	li $v0, 4
	syscall
	mul $t2, $t0, 4 # je multiplie le nombre d'argmuent restant par la taille d'un mot (4)
	add $t3, $t2, $t1 # j'additionne l'offsey aisni obtenu avec l'offset inititial
	add $t3, $t3, $sp # je calcule l'adresse réel de l'élément grace au stack pointer
	lw $a0, 0($t3) # je deplace cette adresse dans a0
	li $v0, 4
	syscall
	sub $t0, $t0, 1 # je decremente le nombre de chaine a afficher
	j echo_string_loop
echo_string_exit:
	lw $ra, 40($sp) # Restaurer $t9
	lw $t9, 36($sp) # Restaurer $t9
	lw $t8, 32($sp) # Restaurer $t8
	lw $t7, 28($sp) # Restaurer $t7
	lw $t6, 24($sp) # Restaurer $t6
	lw $t5, 20($sp) # Restaurer $t5
	lw $t4, 16($sp) # Restaurer $t4
	lw $t3, 12($sp) # Restaurer $t3
	lw $t2, 8($sp)  # Restaurer $t2
	lw $t1, 4($sp)  # Restaurer $t1
	lw $t0, 0($sp)  # Restaurer $t0
	addi $sp, $sp, 44 # Restaurer $sp
	mul  $t0, $t7, 4
	mtlo $zero
	add  $sp, $sp, $t0 # Réduire la taille de la pile a l'intérieur du echo! Cela permet de s'épargner un quad. A la fin de cette fonction le pointeur de pile est plus grand de $a0*4 
	jr $ra
#END FUN echo_string

# FUN read_string
# ARGS:
# $a0: Adresse de l'espace memoire nouvellement lu (et malloc)
read_string:
	addi $sp, $sp, -44 # Enreigstre les registres $t* dans la pile (pour simplifier)
	sw   $t0, 0($sp)
	sw   $t1, 4($sp)
	sw   $t2, 8($sp)
	sw   $t3, 12($sp)
	sw   $t4, 16($sp)
	sw   $t5, 20($sp)
	sw   $t6, 24($sp) 
	sw   $t7, 28($sp)
	sw   $t8, 32($sp)
	sw   $t9, 36($sp)
	sw   $ra, 40($sp)

	move $t9, $a0         # Sauvegarder l'adresse cible
	la   $a0, read_buffer # Charger l'adresse du buffer
	li   $a1, 1024        # Charger la taille du buffer
	li   $v0, 8			  # 
	syscall               # Lire la chaine de caractère
	jal count_char        # Déterminer la taille de la chaine lue
	move $a0, $v0         # Enregistrer le résultat dans $a0
	addi $a0, $a0, 1      # Ajouter 1 pour le caractère sentinelle
	li   $v0, 9			  #
	syscall               # Allouer l'espace mémoire nécessaire pour enregistrer la chaine de caractères lue
	la   $t0, read_buffer #
	move $t6, $v0		  #
loop_copy:
	lb   $t7, 0($t0)           # Enregistrer temporairement le caractère en début de chaine
	beqz $t7, read_string_exit # Fin de la première chaine de caractères
	add  $t0, $t0, 1           # Déplacer la tête de lecture sur la première chaine d'un caractère
	sb   $t7, 0($t6)           # Enregistrer le caractère dans la chaine résultat
	add  $t6, $t6, 1           # Déplacer la tête d'écriture dans la chaine résultat
	j loop_copy			       # Boucle
read_string_exit:
	sb $zero, 0($t6)
	sw   $v0, 0($t9)  # Renvoyer le mot
	move $a0, $t9     # Restaurer l'argument
	lw   $ra, 40($sp) # Restaurer $t9
	lw   $t9, 36($sp) # Restaurer $t9
	lw   $t8, 32($sp) # Restaurer $t8
	lw   $t7, 28($sp) # Restaurer $t7
	lw   $t6, 24($sp) # Restaurer $t6
	lw   $t5, 20($sp) # Restaurer $t5
	lw   $t4, 16($sp) # Restaurer $t4
	lw   $t3, 12($sp) # Restaurer $t3
	lw   $t2, 8($sp)  # Restaurer $t2
	lw   $t1, 4($sp)  # Restaurer $t1
	lw   $t0, 0($sp)  # Restaurer $t0
	jr   $ra

#bibliothèque de gestion des srting en mips

.data

##########TEST####################
string1: .asciiz "Hello"
string2: .asciiz "-17"
string3: .asciiz "World"
string4: .asciiz ""
string5: .asciiz "3"
##########TEST####################


error_string_not_an_int: .asciiz "erreur : la chaine que vous essayez de convertir n'est pas un entier."
error_overflow: .asciiz "erreur : overflow detecté."
int_to_str: .space 512
one_space: .asciiz " "
.text


main:
	addi $sp, $sp, -20
	la $t0, string1
	la $t1, string3
	la $t2, string2
	la $t3, string3
	la $t4, string5
	sw $t0, 0($sp)          
	sw $t1, 4($sp)
	sw $t2, 8($sp)          
	sw $t3, 12($sp)
	sw $t4, 16($sp)
	li $a0, 5
	jal echo_string
	move $a0, $v0
	li $v0, 4
	syscall
	li $v0, 10        # System call code for exit.
        syscall


# entré : $a0 -> la chaine dans on veut connaitre la taille
# sorti:  $v0 -> la taille de la chaine
count_char:
	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

	li $v0, 0 # on crée un compteur dans la valeur de retour (v0) pour compter le nombre de char (!= du char sentinel)
	li $t2, 0 # on lit le char 0 en premier
count_char_loop:
	add $t3, $t2, $a0 #je calcule l'adresse de mon prochain char (adresse de depart a0 + nombre de char deja lu t2)
	lb $t1, 0($t3) # on load le prochain char ascii dans t1 (8 bits donc un seul octet et donc lb et non lw)
	beqz $t1, count_char_exit # si le caratère est le caractère sentinel (0) alors on arrete de compter
	addi $v0, $v0, 1 # on incremente le compteur
	addi $t2, $t2, 1 # on lira le char suivant au prochain tour de boucle (probalement redondant avec v0)
	j count_char_loop
count_char_exit:
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra # retour a l'appelant avec le resultat dans v0 (attention : on a pas compté le char sentinel)



# entré : $a0 -> la chaine a convertir
# sorti:  $v0 -> 0 si faux, 1 sinon
is_integer:
	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

	li $v0, 1 # pour le moment on a pas trouver de chose qui nous font dire que la chaine n'est pas un integer donc vrai
	li $t2, 0 # on lit le char 0 en premier
	lb $t1, 0($a0) #c'est un test préalamble
	beqz $t1, is_integer_false # si la chaine est vide alors c'est pas un nombre
	beq  $t1, 45, is_integer_first_symb # si le premier symbole est quand un - c'est quand même un chiffre
	beq $t1, 43, is_integer_first_symb # si le premier symbole est quand un + c'est quand même un chiffre
	j is_integer_loop
is_integer_first_symb:
	addi $t2, $t2, 1 # on lira le char suivant au prochain tour de boucle
	lb $t1, 1($a0) # on va tester si c'est pas juste un moins (au cas ou)
	beqz $t1, is_integer_false # si on a juste un symbole simple (+ ou -) alors c'est pas un entier
is_integer_loop:
	add $t3, $t2, $a0 #je calcule l'adresse de mon prochain char (adresse de depart a0 + nombre de char deja lu t2)
	lb $t1, 0($t3) # on load le prochain char ascii dans t1 (8 bits donc un seul octet et donc lb et non lw)
	beqz $t1, is_integer_exit # si on est arrivé a la fin de la chaine on se casse
	blt $t1, 48, is_integer_false # si le code ascii est inferieur a celui du char "0" on quitte en mettant false
	bgt $t1, 57, is_integer_false # si le code ascii est superieur a celui du char "9" on quitte en mettant false
	addi $t2, $t2, 1 # on lira le char suivant au prochain tour de boucle
	j is_integer_loop
is_integer_false:
	li $v0, 0
is_integer_exit:
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra # retour a l'appelant avec le resultat dans v0 (0 égale faux et 1 égale vrai)
	
	
	
	
	
# entré : $a0 -> la chaine a convertir
# sorti:  $v0 -> l'entier correspondant
convert_string_to_int:
	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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
	
	jal is_integer # on verifie si la chaine dans a0 contient bien un entier
	beqz $v0 ,csto_erreur_not_an_int
	li $t5, 0 # c'est le nombre a renvoyer a la fin :)
	li $t2, 0 # on lit le char 0 en premier
	li $t9, 10
	lb $t1, 0($a0) # c'est un test préalamble
	beq  $t1, 45, convert_string_to_int_neg # on check si l'entier est negatif
	beq $t1, 43, convert_string_to_int_pos # on check si l'entier est positif
	li $t4, 1 # on enregristre que l'entier est bien positif (pour la fin) -- si il n'y a pas de symbole on considère que c'est positif
	j csto_loop
convert_string_to_int_neg:	
	addi $t2, $t2, 1 # on ignorera le premier char lors de la convertion
	li $t4, -1 # on enregristre que l'entier est bien negatif (pour la fin)
	j csto_loop
convert_string_to_int_pos:
	addi $t2, $t2, 1 # on ignorera le premier char lors de la convertion
	li $t4, 1 # on enregristre que l'entier est bien positif (pour la fin)
	j csto_loop
csto_loop:
	add $t3, $t2, $a0 #je calcule l'adresse de mon prochain char (adresse de depart a0 + nombre de char deja lu t2)
	lb $t1, 0($t3) # on load le prochain char ascii dans t1 (8 bits donc un seul octet et donc lb et non lw)
	beqz $t1, csto_exit # si on est arrivé a la fin de la chaine on se casse
	mult $t5, $t9 # on multiplie ce qu'on avait deja par 10
	mfhi $t6 # check qu'on a pas d'overflow
	mflo $t5
	bnez $t6, csto_erreur_overflow
	move $t6, $t5 # on fait une copie avant l'addtition pour verifier l'overflow
	sub $t1, $t1, 48 # on veut le chiffre donc on soustrait le code ascii de 0
	add $t5, $t5, $t1 # on additionne le nouveau chiffre lu a ce qu'on avait deja lu.
	blt $t5, $t6, csto_erreur_overflow # si le chiffre après l'addition est plus faible qu'avant on a fait un overflow
	addi $t2, $t2, 1 # on lira le char suivant au prochain tour de boucle
	j csto_loop
csto_exit:
	mult $t4, $t5 #on rajoute le signe 
	mflo $v0
	mthi $zero
	mtlo $zero
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44    
	jr $ra
csto_erreur_not_an_int:
	li $v0, 4
	la $a0, error_string_not_an_int
        syscall
        li $v0, 10
        syscall
csto_erreur_overflow:
	li $v0, 4
	la $a0, error_overflow
        syscall
        li $v0, 10
        syscall
       
        
         
######################################       A MODIFIER : JE L'AI PIQUER SUR LE NET      #############################################  
convert_int_to_string:
# entré : $a0 -> l'entier a convertir
#	  $a1 -> l'adresse de l'espace memoire ou ranger la chaine
# sorti:  rien
	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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
  
bltz $a0, neg_num         # is num < 0 ?
j    next0                # else, goto 'next0'

neg_num:                  # body of "if num < 0:"
li   $t0, '-'
sb   $t0, ($a1)           # *str = ASCII of '-' 
addi $a1, $a1, 1          # str++
li   $t0, -1
mul  $a0, $a0, $t0        # num *= -1

next0:
li   $t0, -1
addi $sp, $sp, -4         # make space on stack
sw   $t0, ($sp)           # and save -1 (end of stack marker) on MIPS stack

push_digits:
blez $a0, next1           # num < 0? If yes, end loop (goto 'next1')
li   $t0, 10              # else, body of while loop here
div  $a0, $t0             # do num / 10. LO = Quotient, HI = remainder
mfhi $t0                  # $t0 = num % 10
mflo $a0                  # num = num // 10  
addi $sp, $sp, -4         # make space on stack
sw   $t0, ($sp)           # store num % 10 calculated above on it
j    push_digits          # and loop

next1:
lw   $t0, ($sp)           # $t0 = pop off "digit" from MIPS stack
addi $sp, $sp, 4          # and 'restore' stack

bltz $t0, neg_digit       # if digit <= 0, goto neg_digit (i.e, num = 0)
j    pop_digits           # else goto popping in a loop

neg_digit:
li   $t0, '0'
sb   $t0, ($a1)           # *str = ASCII of '0'
addi $a1, $a1, 1          # str++
j    next2                # jump to next2

pop_digits:
bltz $t0, next2           # if digit <= 0 goto next2 (end of loop)
addi $t0, $t0, '0'        # else, $t0 = ASCII of digit
sb   $t0, ($a1)           # *str = ASCII of digit
addi $a1, $a1, 1          # str++
lw   $t0, ($sp)           # digit = pop off from MIPS stack 
addi $sp, $sp, 4          # restore stack
j    pop_digits           # and loop

next2:
sb  $zero, ($a1)          # *str = 0 (end of string marker)
	
	mthi $zero
	mtlo $zero
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
jr  $ra

################################################################### FIN DE LA FONCTION VOLER #############################################################


# PAS DE VERIFICATION D'OVERFLOW
# entré : $a0 -> chaine 1
#	  $a1 -> chaine 2
# sorti:  $v0 -> chaine nouvellement malloc contenant le reslutat de l'opération
add_string:

	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

move $t0, $a0 # faire une copie d'arg 1
move $t1, $a1 # faire une copie d'arg 2
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, add_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t2, $v0
jal count_char #on compte la taille max de la chaine final
move $t4, $v0
move $a0, $a1
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, add_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t3, $v0
jal count_char #on compte la taille max de la chaine final
move $t5, $v0

bge $t4, $t5, add_string_4_s_5 #je prend la plus grande taille des deux et je rajoute 3 (1 pour le char sentinel, 1 pour le signe eventuel et 1 pour la sécurité même si 2 devraient toujours suffir)
add $t4, $t5, 3 # la taille de la chaine résulatante est toujours contenu dans $t4
j adds_next_1
add_string_4_s_5:
add $t4, $t4, 3 # la taille de la chaine résulatante est toujours contenu dans $t4
j adds_next_1

adds_next_1:
move $a0, $t4
li $v0, 9
syscall # allocation de la memoire necessaire
move $a1, $v0 # on met v0 dans a0 pour pouvoir exec le convertisseru un peu plus tard
add $a0, $t2 , $t3 #on additionne les deux opérandes
jal convert_int_to_string
j add_string_exit

add_string_exit:
	
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra
	
add_string_error_not_int:
	li $v0, 4
	la $a0, error_string_not_an_int
        syscall
        li $v0, 10
        syscall

# PAS DE VERIFICATION D'OVERFLOW
# entré : $a0 -> chaine 1
#	  $a1 -> chaine 2
# sorti:  $v0 -> chaine nouvellement malloc contenant le reslutat de l'opération
sub_string:

	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

move $t0, $a0 # faire une copie d'arg 1
move $t1, $a1 # faire une copie d'arg 2
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, sub_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t2, $v0
jal count_char #on compte la taille max de la chaine final
move $t4, $v0
move $a0, $a1
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, sub_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t3, $v0
jal count_char #on compte la taille max de la chaine final
move $t5, $v0

bge $t4, $t5, sub_string_4_s_5 #je prend la plus grande taille des deux et je rajoute 3 (1 pour le char sentinel, 1 pour le signe eventuel et 1 pour la sécurité même si 2 devraient toujours suffir)
add $t4, $t5, 3 # la taille de la chaine résulatante est toujours contenu dans $t4
j sub_next_1
sub_string_4_s_5:
add $t4, $t4, 3 # la taille de la chaine résulatante est toujours contenu dans $t4
j sub_next_1

sub_next_1:
move $a0, $t4
li $v0, 9
syscall # allocation de la memoire necessaire
move $a1, $v0 # on met v0 dans a0 pour pouvoir exec le convertisseru un peu plus tard
sub $a0, $t2 , $t3 #on additionne les deux opérandes
jal convert_int_to_string
j sub_string_exit

sub_string_exit:
	
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra
	
sub_string_error_not_int:
	li $v0, 4
	la $a0, error_string_not_an_int
        syscall
        li $v0, 10
        syscall


# PAS DE VERIFICATION D'OVERFLOW
# entré : $a0 -> chaine 1
#	  $a1 -> chaine 2
# sorti:  $v0 -> chaine nouvellement malloc contenant le reslutat de l'opération
mult_string:

	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

move $t0, $a0 # faire une copie d'arg 1
move $t1, $a1 # faire une copie d'arg 2
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, mult_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t2, $v0
move $a0, $a1
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, mult_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t3, $v0

li $t4, 16 # le nombre maximal sur 32 bit signé est 2 147 483 647 (donc 10 char + le sentinel). j'alloue 16 pour plus de sécurité (a chnager durant l'optimisation).

mult_next_1:
move $a0, $t4
li $v0, 9
syscall # allocation de la memoire necessaire
move $a1, $v0 # on met v0 dans a0 pour pouvoir exec le convertisseru un peu plus tard
mult $t2 , $t3 # on additionne les deux opérandes
mflo $a0 # on met le resultat de l'opération dans a0 pour le transformer en string
mfhi $t9 # check si il y a un un overflow
beqz $t9, suite_mult_l
beq $t9, -1, suite_mult_l # il y a un probleme ici (certain overflow nous echappe dans les negatifs) mais je suis pas ssez malin pour le fix
mthi $zero
j mult_string_err
suite_mult_l:
jal convert_int_to_string
j mult_string_exit

mult_string_exit:
	
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra
	
mult_string_error_not_int:
	li $v0, 4
	la $a0, error_string_not_an_int
        syscall
        li $v0, 10
        syscall

mult_string_err:
	li $v0, 4
	la $a0, error_overflow
        syscall
        li $v0, 10
        syscall	

        
# PAS DE VERIFICATION D'OVERFLOW
# entré : $a0 -> chaine 1
#	  $a1 -> chaine 2
# sorti:  $v0 -> chaine nouvellement malloc contenant le reslutat de l'opération
div_string:

	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

move $t0, $a0 # faire une copie d'arg 1
move $t1, $a1 # faire une copie d'arg 2
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, div_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t2, $v0
move $a0, $a1
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, div_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t3, $v0

li $t4, 16 # le nombre maximal sur 32 bit signé est 2 147 483 647 (donc 10 char + le sentinel). j'alloue 16 pour plus de sécurité (a chnager durant l'optimisation).

div_next_1:
move $a0, $t4
li $v0, 9
syscall # allocation de la memoire necessaire
move $a1, $v0 # on met v0 dans a0 pour pouvoir exec le convertisseru un peu plus tard
div $t2 , $t3 # on additionne les deux opérandes
mflo $a0 # on met le resultat de l'opération dans a0 pour le transformer en string
mthi $zero
mtlo $zero
jal convert_int_to_string
j div_string_exit

div_string_exit:
	
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra
	
div_string_error_not_int:
	li $v0, 4
	la $a0, error_string_not_an_int
        syscall
        li $v0, 10
        syscall




# PAS DE VERIFICATION D'OVERFLOW
# entré : $a0 -> chaine 1
#	  $a1 -> chaine 2
# sorti:  $v0 -> chaine nouvellement malloc contenant le reslutat de l'opération
mod_string:

	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

move $t0, $a0 # faire une copie d'arg 1
move $t1, $a1 # faire une copie d'arg 2
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, mod_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t2, $v0
move $a0, $a1
jal is_integer # on test si l'arg 1 est bien un entier 
beqz $v0, mod_string_error_not_int
jal convert_string_to_int #on converti l'entier en nombre
move $t3, $v0

li $t4, 16 # le nombre maximal sur 32 bit signé est 2 147 483 647 (donc 10 char + le sentinel). j'alloue 16 pour plus de sécurité (a chnager durant l'optimisation).

mod_next_1:
move $a0, $t4
li $v0, 9
syscall # allocation de la memoire necessaire
move $a1, $v0 # on met v0 dans a0 pour pouvoir exec le convertisseru un peu plus tard
div $t2 , $t3 # on additionne les deux opérandes
mfhi $a0 # on met le resultat de l'opération dans a0 pour le transformer en string
mthi $zero
mtlo $zero
jal convert_int_to_string
j mod_string_exit

mod_string_exit:
	
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra
	
mod_string_error_not_int:
	li $v0, 4
	la $a0, error_string_not_an_int
        syscall
        li $v0, 10
        syscall
       
       

        
# PAS DE VERIFICATION D'OVERFLOW
# entré : $a0 -> chaine 1
#	  $a1 -> chaine 2
# sorti:  $v0 -> chaine nouvellement malloc contenant la concatenation
concat_string:

	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

move $t0, $a0 # faire une copie d'arg 1
move $t1, $a1 # faire une copie d'arg 2
jal count_char # choper la taille de la chaine 1
move $t2, $v0 # on enregistre la taille dans une var temp
move $a0, $a1 # on place la chaine 2 dans l'argument 0 pour comptage
jal count_char # choper la taille de la chaine 1
move $t3, $v0 # on enregistre la taille dans une var temp

add $t4, $t2, $t3 # la taille de la chaine resultante est egale à la somme des tailles des chaines precedentes (+1 pour le char sentinel)
add $t4, $t4, 1 #pour le char sentinel

move $a0, $t4
li $v0, 9
syscall # allocation de la memoire necessaire
move $t5, $v0 # on enregristre l'adresse de la zone memoire quelque part pour la renvoyer a la fin
move $t6, $v0 # on enregristre l'adresse de la zone memoire quelque part pour la modifier

loop_concat_1:
lb $t7, 0($t0) # j'enregistre temporairement le char en debut de ma chaine
beqz $t7, loop_concat_2 # si j'ai fini de copier la liste 1 je passe a la deuxième
add $t0, $t0, 1 # je deplace ma tête de lecture sur le prochain char de la chaine 1
sb $t7, 0($t6) # j'enregistre mon char dans la chaine final
add $t6, $t6, 1 # j'avance de 1 dans la chaine final 
j loop_concat_1

loop_concat_2:
lb $t7, 0($t1) # j'enregistre temporairement le char en debut de ma chaine
beqz $t7, concat_string_exit # si j'ai fini de copier la liste 1 je passe a la deuxième
add $t1, $t1, 1 # je deplace ma tête de lecture sur le prochain char de la chaine 1
sb $t7, 0($t6) # j'enregistre mon char dans la chaine final
add $t6, $t6, 1 # j'avance de 1 dans la chaine final
j loop_concat_2


concat_string_exit:
	sb $zero, 0($t6)
	move $v0, $t5
	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	jr $ra


# entré : $a0 -> nombre de chaine a afficher (on considère que leurs adresses ont été rentré dans l'ordre dans la pile
# sorti:  rien
# ATTENTION : On reduit la taille de la pile a l'intérieur du echo !!!! ça permet de s'épargner un quad !!!! à la fin de cette fonction le pointeur de pile est plus grand de a0*4 
echo_string:
	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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
	li $t1, 40 # offset initial des arguments dans la pile -> normalement 44 mais vue que au minimum on a 1 argument ça fait 40+4*1 donc 44
	beqz $t0, echo_string_exit
	# on commance par print le print la premiere chaine (car si elle est seuk on ne rajoutera pas d'espace)
	mul $t2, $t0, 4 # je multiplie le nombre d'argmuent restant par la taille d'un mot (4)
	add $t3, $t2, $t1 # j'additionne l'offsey aisni obtenu avec l'offset inititial
	add $t3, $t3, $sp # je calcule l'adresse réel de l'élément grace au stack pointer
	lw $a0, 0($t3) # je deplace cette adresse dans a0
	li $v0, 4
	syscall
	sub $t0, $t0, 1 # je decremente le nombre de chaine a afficher
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

	lw   $ra, 40($sp)
	lw   $t9, 36($sp)           # restore $t9 value before function was called
	lw   $t8, 32($sp)           # restore $t8 value before function was called
	lw   $t7, 28($sp)           # restore $t7 value before function was called
	lw   $t6, 24($sp)           # restore $t6 value before function was called
	lw   $t5, 20($sp)           # restore $t5 value before function was called
	lw   $t4, 16($sp)           # restore $t4 value before function was called
	lw   $t3, 12($sp)           # restore $t3 value before function was called
	lw   $t2, 8($sp)           # restore $t2 value before function was called
	lw   $t1, 4($sp)           # restore $t1 value before function was called
	lw   $t0, 0($sp)           # restore $t0 value before function was called
	addi $sp, $sp, 44  
	mul $t0, $a0, 4
	mtlo $zero
	addi $sp, $sp, 20 # On reduit la taille de la pile a l'intérieur du echo !!!! ça permet de s'épargner un quad!!!! a la fin de cette fonction le pointeur de pile est plus grand de a0*4 
	jr $ra
	
# entré : $a0 -> l'adresse de l'espace memoire ou mettre l'adresse de la chaine nouvellement lu (et malloc)
# sorti:  rien
read_string:
	addi $sp, $sp, -44 # to avoid headaches save $t- registers used in this procedure on stack
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

	
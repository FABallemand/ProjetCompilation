#bibliothèque de gestion des srting en mips

.data

##########TEST####################
string1: .asciiz "-"
string2: .asciiz "9123456"
string3: .asciiz "+5764"
string4: .asciiz ""
string5: .asciiz "-05677"
##########TEST####################


error_string_not_an_int: .asciiz "erreur : la chaine que vous essayez de convertir n'est pas un entier."
error_overflow: .asciiz "erreur : overflow detecté."
int_to_str: .space 512

.text


main:
	li $a0, -45
	la $a1, int_to_str
	jal convert_int_to_string
	la $a0, int_to_str
	li $v0, 4
	syscall
	li $v0, 10        # System call code for exit.
        syscall


# entré : $a0 -> la chaine dans on veut connaitre la taille
# sorti:  $v0 -> la taille de la chaine
count_char:
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
	jr $ra # retour a l'appelant avec le resultat dans v0 (attention : on a pas compté le char sentinel)



# entré : $a0 -> la chaine a convertir
# sorti:  $v0 -> 0 si faux, 1 sinon
is_integer:
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
	jr $ra # retour a l'appelant avec le resultat dans v0 (0 égale faux et 1 égale vrai)
	
	
	
	
	
# entré : $a0 -> la chaine a convertir
# sorti:  $v0 -> l'entier correspondant
convert_string_to_int:
	move $t8, $ra
	jal is_integer # on verifie si la chaine dans a0 contient bien un entier
	move $ra, $t8
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
addi $sp, $sp, -4         # to avoid headaches save $t- registers used in this procedure on stack
sw   $t0, ($sp)           # so the values don't change in the caller. We used only $t0 here, so save that.
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

lw   $t0, ($sp)           # restore $t0 value before function was called
addi $sp, $sp, 4          # restore stack
jr  $ra
       

	
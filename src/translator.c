#include "translator.h"

// li $a0, 3
// jal echo_string
// li $v0, 10
// syscall

FILE *output_file = NULL;

void translator()
{
    size_t nb_const = 0;
    size_t nb_used_const = 0;
    struct stack_frame current_frame_list[MAX_NESTED_DECLARATION];
    size_t nb_nested_declaration = 0;
    current_frame_list[0] = findContext("global");
    if (!output_file)
    {
        CHK_NULL(output_file = fopen(OUTPUT_NAME, "w"));
    }

    // Segment data
    fprintf(output_file, ".data\n\n");
    fprintf(output_file, "global_stack: .space 4\n");
    for (size_t i = 0; i < next_quad; i++)
    {
        if (global_code[i].kind == Q_GOTO)
            continue;
        if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
        {
            fprintf(output_file, "const_%ld: .asciiz \"%s\"\n", nb_const++, global_code[i].op1.qval.value);
        }
        if (global_code[i].op2.kind == QO_CST || global_code[i].op2.kind == QO_STRING)
        {
            fprintf(output_file, "const_%ld: .asciiz \"%s\"\n", nb_const++, global_code[i].op2.qval.value);
        }
        if (global_code[i].res.kind == QO_CST || global_code[i].res.kind == QO_STRING)
        {
            fprintf(output_file, "const_%ld: .asciiz \"%s\"\n", nb_const++, global_code[i].res.qval.value);
        }
    }
    // Segment text
    fprintf(output_file, "\n.text\n\n");
    fprintf(output_file, "addi $sp, $sp, -%ld # Empiler contexte global\n", current_frame_list[0].stack_frame_size); // à vérifier
    fprintf(output_file, "la $t0, global_stack\n");
    fprintf(output_file, "sw $sp, 0($t0) # Enregistrer l'adresse du contexte global dans global_stack\n");
    for (size_t i = 0; i < next_quad; i++)
    {
        fprintf(output_file, "Label%ld:\n", i);
        switch (global_code[i].kind)
        {
        case Q_CONCAT:
            nb_used_const = operation(i, nb_used_const, current_frame_list, nb_nested_declaration, "concat");
            break;
        case Q_ADD:
            nb_used_const = operation(i, nb_used_const, current_frame_list, nb_nested_declaration, "add");
            break;
        case Q_SUB:
            nb_used_const = operation(i, nb_used_const, current_frame_list, nb_nested_declaration, "sub");
            break;
        case Q_MUL:
            nb_used_const = operation(i, nb_used_const, current_frame_list, nb_nested_declaration, "mult");
            break;
        case Q_DIV:
            nb_used_const = operation(i, nb_used_const, current_frame_list, nb_nested_declaration, "div");
            break;
        case Q_MOD:
            nb_used_const = operation(i, nb_used_const, current_frame_list, nb_nested_declaration, "mod");
            break;
        case Q_EQUAL:
            nb_used_const = comparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "beq");
            break;
        case Q_NOT_EQUAL:
            nb_used_const = comparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "bne");
            break;
        case Q_GT:
            nb_used_const = comparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "bgt");
            break;
        case Q_GE:
            nb_used_const = comparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "bge");
            break;
        case Q_LT:
            nb_used_const = comparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "blt");
            break;
        case Q_LE:
            nb_used_const = comparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "ble");
            break;
        case Q_EMP:
            nb_used_const = stringTest(i, nb_used_const, current_frame_list, nb_nested_declaration, "empty_string");
            break;
        case Q_N_EMP:
            nb_used_const = stringTest(i, nb_used_const, current_frame_list, nb_nested_declaration, "not_empty_string");
            break;
        case Q_EQUAL_STRING:
            nb_used_const = stringComparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "equal_string");
            break;
        case Q_NOT_EQUAL_STRING:
            nb_used_const = stringComparison(i, nb_used_const, current_frame_list, nb_nested_declaration, "not_equal_string");
            break;
        case Q_AFFECT:
            nb_used_const = affect(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        case Q_AFFECT_STACK:
            nb_used_const = affectStack(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        case Q_GOTO:
            fprintf(output_file, "j Label%ld\n", global_code[i].res.qval.addr);
            break;
        case Q_ECHO:
            nb_used_const = echo_(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        case Q_READ:
            break;
        case Q_FUNCTION_BEGIN:
            nb_used_const = functionBegin(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        case Q_FUNCTION_END:
            nb_nested_declaration--;
            break;
        case Q_CALL:
            break;
        case Q_RETURN:
            break;
        case Q_EXIT:
            nb_used_const = exit_(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        case Q_ARRAY_GET:
            nb_used_const = arrayGet(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        default:
            printError("Quad non reconnu");
            exit(1);
        }
    }
    // Inclure bibliothèque MIPS
    fprintf(output_file, "\n.include \"mips/string.asm\"\n");
}

size_t echo_(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration)
{
    if (global_code[i].op1.kind == QO_CST)
    {
        fprintf(output_file, "la $a0, const_%ld\n", nb_used_const++); // Charger l'adresse de l'unique argument d'echo
    }
    else
    {
        printError("Argument invalide pour echo");
        exit(1);
    }

    fprintf(output_file, "jal string_to_int # Convertir le nombre de chaine en entier\n");
    fprintf(output_file, "move $a0, $v0 # Placer le nombre de chaine en argument de fonction\n");
    fprintf(output_file, "jal echo_string # Appeler la fonction echo_string\n");

    return nb_used_const;
}

size_t affect(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration)
{
    int offset = 0;
    // Recherche constante à affecter (à droite du égal)
    if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
    {
        fprintf(output_file, "la $t0, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $t0
    }
    // Recherche variable à affecter (à droite du égal)
    else
    {
        if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $t0, %d($sp)\n", offset); // Charger la valeur de la variable
        }
        else if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
            fprintf(output_file, "lw $t0, %d($t1)\n", offset); // Charger la valeur de la variable
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    // Recherche de l'offset dans la variable à affecter (à gauche du égal)
    if (global_code[i].op2.kind == QO_EMPTY)
    {
        fprintf(output_file, "li $t2, 0\n");
    }
    else if (global_code[i].op2.kind == QO_CST)
    {
        fprintf(output_file, "la $a0, const_%ld\n", nb_used_const++);
        fprintf(output_file, "jal string_to_int\n"); // Erreur si ce n'est pas un entier
        fprintf(output_file, "move $t2, $v0\n");
    }
    else if (global_code[i].op2.kind == QO_VAR)
    {
        if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $a0, %d($sp)\n", offset); // Charger l'adresse
            fprintf(output_file, "jal string_to_int\n");       // Erreur si ce n'est pas un entier
            fprintf(output_file, "move $t2, $v0\n");
        }
        else if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");
            fprintf(output_file, "lw $a0, %d($t1)\n", offset); // Charger l'offset
            fprintf(output_file, "jal string_to_int\n");       // Erreur si ce n'est pas un entier
            fprintf(output_file, "move $t2, $v0\n");
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }
    fprintf(output_file, "mul $t2, $t2, %d\n", SIZE_MIPS_WORD); // Conversion de l'offset MIPS en octet

    // Recherche de variable à affecter (à gauche du égal)
    if ((offset = isInContext(global_code[i].res.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
    {
        fprintf(output_file, "add $t2, $t2, $sp\n");       // Combiner les offsets (offset dans la variable et dans la pile)
        fprintf(output_file, "sw $t0, %d($t2)\n", offset); // Affectation
    }
    else if ((offset = isInContext(global_code[i].res.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
    {
        fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
        fprintf(output_file, "add $t1, $t1, $t2\n");       // Combiner les offsets (offset dans la variable et dans la pile)
        fprintf(output_file, "sw $t0, %d($t1)\n", offset); // Affectation
    }
    else
    {
        printError("Variable inconnue dans les contextes accessibles");
        exit(1);
    }

    return nb_used_const;
}

size_t affectStack(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration)
{
    int offset = 0;
    // Recherche constante à affecter (à droite du égal)
    if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
    {
        fprintf(output_file, "la $t0, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $t0
    }
    // Recherche variable à affecter (à droite du égal)
    else
    {
        if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            offset += (atoi(global_code[i].res.qval.value) - 1) * SIZE_MIPS_WORD;
            fprintf(output_file, "lw $t0, %d($sp)\n", offset); // Charger la valeur de la variable
        }
        else if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
            fprintf(output_file, "lw $t0, %d($t1)\n", offset); // Charger la valeur de la variable
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    // Enregistrer dans la stack
    fprintf(output_file, "sub $sp, $sp, %d # Ajouter de l'espace dans la pile\n", SIZE_MIPS_WORD);
    fprintf(output_file, "sw $t0, 0($sp) # Enregistrer $t0 dans la pile\n");

    return nb_used_const;
}

size_t exit_(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration)
{
    int offset = 0;

    // recuperer le code de retour dans $t0
    if (global_code[i].op1.kind == QO_EMPTY)
    {
        fprintf(output_file, "li $a0, 0\n");
    }
    else if (global_code[i].op1.kind == QO_CST)
    {
        fprintf(output_file, "la $a0, const_%ld\n", nb_used_const++);
        fprintf(output_file, "jal string_to_int\n"); // Erreur si ce n'est pas un entier
        fprintf(output_file, "move $a0, $v0\n");
    }
    else if (global_code[i].op2.kind == QO_VAR)
    {
        if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $a0, %d($sp)\n", offset); // Charger l'adresse
            fprintf(output_file, "jal string_to_int\n");       // Erreur si ce n'est pas un entier
            fprintf(output_file, "move $a0, $v0\n");
        }
        else if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");
            fprintf(output_file, "lw $a0, %d($t1)\n", offset); // Charger l'offset
            fprintf(output_file, "jal string_to_int\n");       // Erreur si ce n'est pas un entier
            fprintf(output_file, "move $a0, $v0\n");
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }
    fprintf(output_file, "li $v0, 17\n");
    fprintf(output_file, "syscall\n");

    return nb_used_const;
}

size_t operation(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *arithm_op)
{
    //$t0 adresse de chaine src1
    //$t2 adresse de la chaine src2

    int offset = 0;

    if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
    {
        fprintf(output_file, "la $t0, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $t0
    }
    // Recherche variable à affecter (à droite du égal)
    else
    {
        if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $t0, %d($sp)\n", offset); // Charger la valeur de la variable
        }
        else if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
            fprintf(output_file, "lw $t0, %d($t1)\n", offset); // Charger la valeur de la variable
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    if (global_code[i].op2.kind == QO_CST || global_code[i].op2.kind == QO_STRING)
    {
        fprintf(output_file, "la $t2, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $t0
    }
    // Recherche variable à affecter (à droite du égal)
    else
    {
        if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $t2, %d($sp)\n", offset); // Charger la valeur de la variable
        }
        else if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
            fprintf(output_file, "lw $t2, %d($t1)\n", offset); // Charger la valeur de la variable
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    fprintf(output_file, "move $a0, $t0\n");
    fprintf(output_file, "move $a1, $t2\n");
    fprintf(output_file, "jal %s_string\n", arithm_op);

    if ((offset = isInContext(global_code[i].res.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
    {
        fprintf(output_file, "lw $t1, global_stack\n");
        fprintf(output_file, "sw $v0, %d($t1)\n", offset); // Charger la valeur de la variable
    }

    return nb_used_const;
}

size_t comparison(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *comp_op)
{
    //$t0 adresse de chaine src1
    //$t2 adresse de la chaine src2

    int offset = 0;

    // Première opérande
    if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
    {
        fprintf(output_file, "la $t0, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $t0
    }
    else
    {
        if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $t0, %d($sp)\n", offset); // Charger la valeur de la variable
        }
        else if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
            fprintf(output_file, "lw $t0, %d($t1)\n", offset); // Charger la valeur de la variable
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    // Deuxième opérande
    if (global_code[i].op2.kind == QO_CST || global_code[i].op2.kind == QO_STRING)
    {
        fprintf(output_file, "la $t2, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $t2
    }
    else
    {
        if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $t2, %d($sp)\n", offset); // Charger la valeur de la variable
        }
        else if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
            fprintf(output_file, "lw $t2, %d($t1)\n", offset); // Charger la valeur de la variable
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    fprintf(output_file, "move $a0, $t0\n");                                                // Placer la première chaine en argument de fonction
    fprintf(output_file, "jal string_to_int\n");                                            // Convertir la première chaine en entier
    fprintf(output_file, "move $t0, $v0\n");                                                // Enregistrer l'entier correspondant à la première chaine dans $t0
    fprintf(output_file, "move $a0, $t2\n");                                                // Placer la première chaine en argument de fonction
    fprintf(output_file, "jal string_to_int\n");                                            // Convertir la première chaine en entier
    fprintf(output_file, "move $t2, $v0\n");                                                // Enregistrer l'entier correspondant à la première chaine dans $t0
    fprintf(output_file, "%s $t0, $t2, Label%ld\n", comp_op, global_code[i].res.qval.addr); // Effectuer l'opération booléenne

    return nb_used_const;
}

size_t stringComparison(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *comp_op)
{
    // Première chaine de caractère
    if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
    {
        fprintf(output_file, "la $a0, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $a0
    }
    else
    {
        printError("Argument incorrect (chaine de caractère attendue)");
        exit(1);
    }

    // Deuxième chaine de caractère
    if (global_code[i].op2.kind == QO_CST || global_code[i].op2.kind == QO_STRING)
    {
        fprintf(output_file, "la $a1, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $a1
    }
    else
    {
        printError("Argument incorrect (chaine de caractère attendue)");
        exit(1);
    }

    fprintf(output_file, "jal %s\n", comp_op);
    fprintf(output_file, "beq $v0, 1, Label%ld\n", global_code[i].res.qval.addr);

    return nb_used_const;
}

size_t stringTest(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *test_op)
{
    // Chaine de caractère à tester
    if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
    {
        fprintf(output_file, "la $a0, const_%ld\n", nb_used_const++); // Charger l'adresse de la valeur dans $a0
    }
    else
    {
        printError("Argument incorrect (chaine de caractère attendue)");
        exit(1);
    }

    fprintf(output_file, "jal %s\n", test_op);
    fprintf(output_file, "beq $v0, 1, Label%ld\n", global_code[i].res.qval.addr);

    return nb_used_const;
}

size_t arrayGet(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration)
{
    int offset;

    // $t0 Adresse du tableau
    // $t2 Offset dans le tableau

    // Adresse du tableau dans $t0
    if ((offset = isInContext(global_code[i].op1.qval.value, current_frame_list[0])) != -1) // Tableau dans le contexte global
    {
        fprintf(output_file, "lw $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
        fprintf(output_file, "addi $t0, $t1, %d\n", offset); // Charger l'adresse du tableau dans $t0
    }
    else
    {
        printError("Tableau inconnu dans le contexte global");
        exit(1);
    }

    // Offset dans le tableau
    if (global_code[i].op2.kind == QO_CST)
    {
        fprintf(output_file, "la $a0, const_%ld\n", nb_used_const++);
        fprintf(output_file, "jal string_to_int\n"); // Erreur si ce n'est pas un entier
        fprintf(output_file, "move $t2, $v0\n");
    }
    else if (global_code[i].op2.kind == QO_VAR)
    {
        if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[nb_nested_declaration])) != -1) // Variable dans le contexte courant
        {
            fprintf(output_file, "lw $a0, %d($sp)\n", offset); // Charger l'adresse
            fprintf(output_file, "jal string_to_int\n");       // Erreur si ce n'est pas un entier
            fprintf(output_file, "move $t2, $v0\n");
        }
        else if ((offset = isInContext(global_code[i].op2.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
        {
            fprintf(output_file, "lw $t1, global_stack\n");    // Charger le pointeur vers le contexte global
            fprintf(output_file, "lw $a0, %d($t1)\n", offset); // Charger l'offset
            fprintf(output_file, "jal string_to_int\n");       // Erreur si ce n'est pas un entier
            fprintf(output_file, "move $t2, $v0\n");
        }
        else
        {
            printError("Variable inconnue dans les contextes accessibles");
            exit(1);
        }
    }

    fprintf(output_file, "mul $t2, $t2, %d  # Convertir l'offset en octet\n", SIZE_MIPS_WORD);
    fprintf(output_file, "add $t0, $t0, $t2 # Adresse de l'élément du tableau\n");
    fprintf(output_file, "lw $t3, 0($t0)    # Charger la valeur dans $t3\n");
    
    if ((offset = isInContext(global_code[i].res.qval.value, current_frame_list[0])) != -1) // Variable dans le contexte global
    {
        fprintf(output_file, "lw $t1, global_stack # Charger l'adresse du pointeur vers le contexte global\n");
        fprintf(output_file, "sw $t3, %d($t1)\n", offset); // Affectation
    }
    else
    {
        printError("Variable temporaire manquante dans le contexte global");
        exit(1);
    }

    return nb_used_const;
}

size_t functionBegin(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration)
{
    fprintf(output_file, "%s:\n", global_code[i].res.qval.value);
    current_frame_list[++nb_nested_declaration] = findContext(global_code[i].res.qval.value);
    return nb_used_const;
}
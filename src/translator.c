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
            break;
        case Q_ADD:
            break;
        case Q_SUB:
            break;
        case Q_MUL:
            break;
        case Q_DIV:
            break;
        case Q_MOD:
            break;
        case Q_EQUAL:
            break;
        case Q_NOT_EQUAL:
            break;
        case Q_GT:
            break;
        case Q_GE:
            break;
        case Q_LT:
            break;
        case Q_LE:
            break;
        case Q_EMP:
            break;
        case Q_N_EMP:
            break;
        case Q_EQUAL_STRING:
            break;
        case Q_NOT_EQUAL_STRING:
            break;
        case Q_AFFECT:
            nb_used_const = affect(i, nb_used_const, current_frame_list, nb_nested_declaration);
            break;
        case Q_GOTO:
            break;
        case Q_DECLARE:
            break;
        case Q_LOCAL:
            break;
        case Q_ECHO:
            break;
        case Q_READ:
            break;
        case Q_FUNCTION_BEGIN:
            fprintf(output_file, "%s:\n", global_code[i].res.qval.value);
            current_frame_list[++nb_nested_declaration] = findContext(global_code[i].res.qval.value);
            break;
        case Q_FUNCTION_END:
            nb_nested_declaration--;
            break;
        case Q_CALL:
            break;
        case Q_RETURN:
            break;
        case Q_EXIT:
            break;
        case Q_ARRAY_GET:
            break;
        case Q_STACK_GROW:
            break;
        default:
            printError("Quad non reconnu");
            exit(1);
        }
    }
    // Inclure bibliothèque MIPS
    fprintf(output_file, "\n.include \"mips/string.asm\"\n");
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
            fprintf(output_file, "la $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
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
            fprintf(output_file, "la $t1, global_stack\n");
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
        fprintf(output_file, "la $t1, global_stack\n");    // Charger l'adresse du pointeur vers le contexte global
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

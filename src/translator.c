#include "translator.h"

FILE *output_file = NULL;

void translator()
{
    size_t nb_const = 0;
    size_t nb_used_const = 0;
    struct stack_frame current_frame_list[MAX_NESTED_DECLARATION];
    size_t nb_nested_declaration = 0;
    struct stack_frame current_frame_list[0] = findContext("global");
    if (!output_file)
    {
        CHK_NULL(output_file = fopen(OUTPUT_NAME, "w"));
    }

    // Segment data
    fprintf(output_file, ".data\n\n");
    fprintf(output_file, "global_stack: .space 4");
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
    fprintf(output_file, "addi $sp, $sp, -%ld # Empiler contexte global\n", current_frame_list[0]);
    fprintf(output_file, "la $t0, global_stack\n");
    fprintf(output_file, "sw $sp, $t0 # Enregistrer l'adresse du contexte global dans global_stack\n");
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
        // Distinguer affectation avec tableau ou variables
            if (global_code[i].op1.kind == QO_CST || global_code[i].op1.kind == QO_STRING)
            {
                fprintf(output_file, "la $t0, const_%ld\n", nb_used_const++);
                // ecrire une fonction qui cherche si une variable est dans un certain contexte (-1 si ce n'est pas le cas et offset en octet si c'est le cas)

            }
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
            if (nb_nested_declaration == MAX_NESTED_DECLARATION - 1)
            {
                printError("Trop de déclarations imbriquées : maximum %d", MAX_NESTED_DECLARATION);
                exit(1);
            }
            fprintf(output_file, "%s:\n", global_code[i].res.qval.value);
            current_frame_list[++nb_nested_declaration] = findContext(global_code[i].res.qval.value);
            break;
        case Q_FUNCTION_END:
            nb_nested_declaration--;
            break;
        case Q_CALL:
            fprintf(output_file, "");
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
    fprintf(output_file, ".include \"mips/string.asm\"\n");
}
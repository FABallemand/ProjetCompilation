#ifndef __DEF_TRANSLATOR_H__
#define __DEF_TRANSLATOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "error_handling.h"
#include "code.h"
#include "quad.h"
#include "symbol_table.h"

#define OUTPUT_NAME "code.asm"

#define MAX_NESTED_DECLARATION 64

extern char *name_global;

/**
 * \brief Convertit le code intermédiaire (tableau de quadruplets) en code MIPS
 * 
 */
void translator();

// Les fonction suivantes servent à écrire le code MIPS correspondant à chaque quadruplet dans le fichier sortie

size_t echo_(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t echoFunction(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t read_(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t affect(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t affectStack(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t operation(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *arithm_op);

size_t comparison(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *comp_op);

size_t stringComparison(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *comp_op);

size_t stringTest(int i, size_t nb_used_const, struct stack_frame *current_frame_list, size_t nb_nested_declaration, char *test_op);

size_t exit_(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t arrayGet(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t functionBegin(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t functionCall(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

size_t return_(int i, size_t nb_used_const, struct stack_frame* current_frame_list, size_t nb_nested_declaration);

#endif
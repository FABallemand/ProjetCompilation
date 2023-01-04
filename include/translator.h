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

#endif
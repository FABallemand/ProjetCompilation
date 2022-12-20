#ifndef __DEF_ERROR_HANDLING_H__
#define __DEF_ERROR_HANDLING_H__

#include <stdio.h>
#include <stdarg.h>

#define RED "\033[1;31m"   // BOLD
#define GREEN "\033[1;32m" // BOLD
#define BLUE "\033[0;34m"
#define WHITE "\033[1;37m" // BOLD
#define BLACK "\033[1;30m" // BOLD
#define ORANGE "\033[0;33m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[1;36m" // BOLD
#define RESET "\e[0m"

#define CHK_NULL(x)           \
    do                        \
    {                         \
        if ((x) == NULL)      \
        {                     \
            printf("NULL\n"); \
            exit(1);          \
        }                     \
    } while (0)

/**
 * \brief Affiche un message d'erreur dans la sortie d'erreur
 */
void printError(char *msg, ...);

/**
 * \brief Affiche un message d'avertissement dans la sortie d'erreur
 */
void printWarning(char *msg, ...);

#endif
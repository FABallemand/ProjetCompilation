#include "error_handling.h"

void printError(char *msg)
{
    fprintf(stderr, RED "Erreur: %s\n" RESET, msg);
}

void printWarning(char *msg)
{
    fprintf(stderr, ORANGE "Attention: %s\n" RESET, msg);
}
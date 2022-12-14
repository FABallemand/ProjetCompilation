#include "error_handling.h"

void printError(char *msg, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);
    fprintf(stderr, RED "Erreur: %s\n" RESET, buffer);
}

void printWarning(char *msg, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);
    fprintf(stderr, ORANGE "Attention: %s\n" RESET, buffer);
}

void printCall(char *msg, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);
    fprintf(stderr, GREEN "Calling: %s\n" RESET, buffer);
}

void printRule(char *msg, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);
    fprintf(stderr, CYAN "Rule: %s\n" RESET, buffer);
}

void printInfo(char *msg, ...)
{
    char buffer[4096];
    va_list args;
    va_start(args, msg);
    vsnprintf(buffer, sizeof(buffer), msg, args);
    va_end(args);
    fprintf(stdout, PURPLE "Info: %s\n" RESET, buffer);
}
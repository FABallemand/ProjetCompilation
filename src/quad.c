#include "quad.h"

void printQuadop(struct quadop q)
{
    switch (q.kind)
    {
    case QO_CST:
        printf("(cst) %d", q.valeur.cst);
        break;
    case QO_STRING:
        printf("(string) %s", q.valeur.string);
        break;
    default:
        printf("(...) ?");
        break;
    }
}

void printQuad(struct quad q)
{
    if(q.kind == Q_GOTO)
    {
        printf("goto ");
        printQuadop(q.op1);
    }
    else
    {
        printQuadop(q.op1);
        switch (q.kind)
        {
        case Q_ADD:
            printf(" + ");
            break;
        case Q_SUB:
            printf(" - ");
            break;
        case Q_MUL:
            printf(" * ");
            break;
        case Q_DIV:
            printf(" / ");
            break;
        case Q_MOD:
            printf(" %% ");
            break;
        case Q_EQUAL:
            printf(" -eq ");
            break;
        case Q_NOT_EQUAL:
            printf(" -ne ");
            break;
        case Q_GT:
            printf(" -gt ");
            break;
        case Q_GE:
            printf(" -ge ");
            break;
        case Q_LT:
            printf(" -lt ");
            break;
        case Q_LE:
            printf(" -le ");
            break;
        case Q_EMP:
            printf(" -n ");
            break;
        case Q_N_EMP:
            printf(" -z ");
            break;
        case Q_EQUAL_STRING:
            printf(" = ");
            break;
        case Q_NOT_EQUAL_STRING:
            printf(" != ");
            break;
        default:
            printf(" ??? ");
        }
        printQuadop(q.op2);
        printf(" -> ");
        printQuadop(q.res);
    }
    printf("\n");
}
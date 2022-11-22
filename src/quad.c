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
    printQuadop(q.op1);
    switch (q.kind)
    {
    case Q_ADD:
        printf(" + ");
        break;
    }
    printQuadop(q.op2);
    printf(" -> ");
    printQuadop(q.res);
}
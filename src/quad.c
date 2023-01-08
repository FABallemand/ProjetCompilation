#include "quad.h"

void printQuadop(struct quadop q)
{
    switch (q.kind)
    {
    case QO_CST:
        printf("(cst) %s", q.qval.value);
        break;
    case QO_STRING:
        printf("(string) %s", q.qval.value);
        break;
    case QO_VAR:
        printf("(ID) %s", q.qval.value);
        break;
    case QO_ADDR:
        printf("(ADDR) %ld", q.qval.addr);
        break;
    default:
        printf("(...) ?");
        break;
    }
}

void printQuad(struct quad q)
{
    if (q.kind == Q_GOTO)
    {
        printf("goto ");
        printQuadop(q.res);
    }
    else if (q.kind == Q_GOTO_FUN)
    {
        printf("goto ");
        printQuadop(q.res);
    }
    else if (q.kind == Q_AFFECT)
    {
        printQuadop(q.res);
        printf(" := ");
        printQuadop(q.op1);
    }
    else if (q.kind == Q_AFFECT_STACK)
    {
        printf("(stack) (offset ");
        printQuadop(q.res);
        printf(") := ");
        printQuadop(q.op1);
    }
    else if (q.kind == Q_ECHO || q.kind == Q_ECHO_FUNCTION)
    {
        printf("echo : nombre arg(");
        printQuadop(q.op1);
        printf(")");
    }
    else if (q.kind == Q_READ)
    {
        printf("read : ");
        printQuadop(q.res);
        if(q.op2.kind != QO_EMPTY)
        {
            printf("[");
            printQuadop(q.op2);
            printf("]");
        }
    }
    else if (q.kind == Q_EXIT)
    {
        printf("exit ");
        if(q.op1.kind != QO_EMPTY)
        {
            printQuadop(q.op1);
        }
    }
    else if (q.kind == Q_FUNCTION_BEGIN)
    {
        printf("Début de fonction");
    }
    else if (q.kind == Q_FUNCTION_END)
    {
        printf("Fin de fonction");
    }
    else if (q.kind == Q_CALL)
    {
        printQuadop(q.op1);
        printf("()");
    }
    else if (q.kind == Q_RETURN)
    {
        printf("return ");
        if(q.op1.kind != QO_EMPTY)
        {
            printQuadop(q.op1);
        }
    }
    else
    {
        printQuadop(q.op1);
        switch (q.kind)
        {
        case Q_CONCAT:
            printf(" concat ");
            break;
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
            printf(" -z ");
            break;
        case Q_N_EMP:
            printf(" -n ");
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

// ajouter différents cas (goto dans les test et monovariable)


#include "arbol_tipos.h"



Expr *expr_numero(Token* tok)
{
    Expr *res = malloc(sizeof(Expr));
    size_t len = strlen(tok->text);
    res->linea = tok->linea;
    res->text = tok->text;
    res->num = strToInt(tok->text, len);
    res->expr_tipo = numero;
    return res;
}

Expr *expr_logico(Token* tok)
{
    Expr *res = malloc(sizeof(Expr));
    size_t len = strlen(tok->text);
    res->linea = tok->linea;
    res->text = tok->text;
    if(tok->tok_tipo == logf)
    {
        res->num = 0;
    }
    else
    {
        res->num = 1;
    }

    res->expr_tipo = val_log;
    return res;
}

Expr *expr_numeroreal(Token* tok)
{
    Expr *res = malloc(sizeof(Expr));
    size_t len = strlen(tok->text);
    res->linea = tok->linea;
    res->text = tok->text;
    res->num = strToFloat(tok->text, len);
    res->expr_tipo = flotante;
    return res;
}

Expr *expr_variable(Token* tok)
{
    Expr *res = malloc(sizeof(Expr));
    int len = strlen(tok->text)+1;
    res->linea = tok->linea;
    res->text = tok->text;
    res->variable = calloc(len, sizeof(char));
    strncpy(res->variable, tok->text, len);
    res->expr_tipo = variable;

    return res;
}

Expr *expr_unop(Token* tok, Expr* op1, uint8_t opera)
{
    Expr *res = malloc(sizeof(Expr));
    res->linea = tok->linea;
    res->text = strdup(tok->text);
    if(opera == menos)
    {
        res->op_unaria.u_res_tipo = t_entero;
    }
    if(opera == not)
    {
        res->op_unaria.u_res_tipo = t_logico;
    }
    res->op_unaria.op = op1;

    res->text = strncat(res->text, op1->text, strlen(op1->text));

    res->op_unaria.u_operador = opera;
    res->expr_tipo = unop;

    return res;
}

Expr *expr_binop(Token* tok, Expr* op1, uint8_t opera, Expr* op2)
{
    Expr *res = malloc(sizeof(Expr));
    res->linea = tok->linea;
    res->text = strdup(op1->text);
    if(opera == mas || opera == menos || opera == por || opera == divr)
    {
        res->op_binaria.b_res_tipo = t_entero;
    }
    else if(opera == menor || opera == mayor || opera == igual || opera == distinto)
    {
        res->op_binaria.b_res_tipo = t_logico;
    }
    res->op_binaria.op1 = op1;
    res->op_binaria.op2 = op2;

    res->text = strncat(res->text, tok->text, strlen(tok->text));
    res->text = strncat(res->text, op2->text, strlen(op2->text));

    res->op_binaria.b_operador = opera;
    res->expr_tipo = binop;

    return res;
}

void printExpr(Expr* expr, int nivel)
{
    if(expr)
    {
        switch(expr->expr_tipo)
        {
            case numero:
                printf("%*cnumero: %d\n", nivel, ' ' ,expr->num);
                break;
            case num_flotante:
                printf("%*cnumero: %f\n", nivel, ' ' ,expr->rnum);
                break;
            case val_log:
                printf("%* logico: %d\n", nivel, ' ' ,expr->num);
                break;
            case variable:
                printf("%*cvariable: %s\n",  nivel, ' ' , expr->variable);
                break;
            case binop:
                printf("%*cOperador: %d\n",  nivel, ' ' , expr->op_binaria.b_operador);
                printExpr(expr->op_binaria.op1, nivel+4);
                printExpr(expr->op_binaria.op2, nivel+4);
                break;
            case unop:
                printf("%*cOperador: %d\n",  nivel, ' ' , expr->op_unaria.u_operador);
                printExpr(expr->op_unaria.op, nivel+4);
                break;
        }
    }
}
void printSent(Sent* sent)
{
    if(sent)
    {
        ;
    }
}
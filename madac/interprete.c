#include "interprete.h"


Interprete* newInterprete()
{
    Interprete* interprete = malloc(sizeof(Interprete));
    interprete->tipos = newHashmap();
    interprete->vars = newHashmap();

    return interprete;
}

Variable* newVariable()
{
    Variable* v = malloc(sizeof(Variable));
    v->tipo_id = NULL;
    return v;
}

uint8_t check_expr(Expr* expr)
{
    switch(expr->expr_tipo)
    {
        case binop:

            break;
        case numero:
            break;
        case variable:
            break;
    }
    return 0;
}

uint8_t is_operacion(Expr* op)
{
    if(op->expr_tipo == binop || op->expr_tipo == unop)
    {
        return op->expr_tipo;
    }
    return 0;
}

byte semantica_expr(byte* retorno_tipo ,Expr* expr)
{
    byte res=0;
    switch(expr->expr_tipo)
    {
        case binop:
            res+=semantica_expr_binop(retorno_tipo, expr);
            break;
        case unop:
            res+=semantica_expr_unop(retorno_tipo, expr);
            break;
        case val_log:
            *retorno_tipo = t_logico;
            break;
        case numero:
            *retorno_tipo = t_entero;
            break;
        case num_flotante:
            *retorno_tipo = t_real;
            break;
    }
    return res;
}

byte semantica_expr_unop(byte* retorno_tipo, Expr* expr)
{
    byte tipo_op=0;
    byte res=0;

    res += semantica_expr(&tipo_op, expr->op_unaria.op);

    if(expr->op_unaria.u_operador == not)
    {
        if(tipo_op != t_logico)
        {
            reportError(SEMERR_TIPOSINVALID, expr->text, expr->linea);
            advertencia("los operadores deben ser de tipo logico (verdadero o falso)");
            exit(1);
        }
        *retorno_tipo = t_logico;
    }
    else if(expr->op_unaria.u_operador == menos)
    {

    }
    return res;
}

byte semantica_expr_binop(byte* retorno_tipo, Expr* expr)
{
    byte tipo_op1=0, tipo_op2=0;
    byte res = 0;

    res += semantica_expr(&tipo_op1, expr->op_binaria.op1);
    res += semantica_expr(&tipo_op2, expr->op_binaria.op2);

    if(expr->op_binaria.b_operador == and || expr->op_binaria.b_operador == or)
    {
        if(tipo_op1 != t_logico || tipo_op2 != t_logico)
        {
            reportError(SEMERR_TIPOSINVALID, expr->text, expr->linea);
            advertencia("los operadores deben ser de tipo logico (verdadero o falso)");
            exit(1);
        }
		else
		{
			*retorno_tipo = t_logico;
		}
    }
    else if(expr->op_binaria.b_operador == menor || expr->op_binaria.b_operador == mayor || 
            expr->op_binaria.b_operador == menigual || expr->op_binaria.b_operador == mayigual)
    {

        if(tipo_op1 == t_logico || tipo_op2 == t_logico)
        {
            reportError(SEMERR_TIPOSINVALID, expr->text, expr->linea);
            advertencia("los operadores de una operacion relacional deben ser reales o enteros");
            advertencia("Uno de los operadores contiene un valor logico");
            exit(1);
        }
        if(tipo_op1 == t_entero || tipo_op2 == t_entero || tipo_op1 == t_real || tipo_op2 == t_real)
        {
            *retorno_tipo = t_logico;
        }
        else
        {
            reportError(SEMERR_TIPOSINVALID, expr->text, expr->linea);
            advertencia("los operadores de una operacion relacional deben ser reales o enteros");
            exit(1);
        }
    }
    else if(expr->op_binaria.b_operador == mas || expr->op_binaria.b_operador == menos || expr->op_binaria.b_operador == por )
    {

    }
    else if(expr->op_binaria.b_operador == divr || expr->op_binaria.b_operador == dive || expr->op_binaria.b_operador == mod)
    {

    }

    return res;
}

Valor interpret_expr(Interprete* interp, Expr* expr)
{
    Valor res;
    Variable* x;
	byte retorno_tipo=0;
    semantica_expr(&retorno_tipo, expr);
    switch(expr->expr_tipo)
    {
        case binop:

            if(expr->op_binaria.b_operador == mas)
            {
                res.ent_val = interpret_expr(interp, expr->op_binaria.op1).ent_val + interpret_expr(interp, expr->op_binaria.op2).ent_val;
                return res;
            }
            if(expr->op_binaria.b_operador == por)
            {
                res.ent_val = interpret_expr(interp, expr->op_binaria.op1).ent_val * interpret_expr(interp, expr->op_binaria.op2).ent_val;
                return res;
            }
            break;
        case unop:

            if(expr->op_unaria.u_operador == menos)
            {
                res.ent_val = -interpret_expr(interp, expr->op_unaria.op).ent_val;
                return res;
            }
            else if(expr->op_unaria.u_operador == not)
            {
                res.ent_val = !interpret_expr(interp, expr->op_unaria.op).ent_val;
                return res;
            }
            break;
        case numero:
            res.ent_val = expr->num;
            res.val_tipo = t_entero;
            return res;
            break;
        case num_flotante:
            res.real_val = expr->rnum;
            res.val_tipo = t_real;
            return res;
        case variable:

            x = hashmap_get(interp->vars, expr->variable);
            if(x)
            {
                res.val_tipo = x->valor.val_tipo;
                res.ent_val = x->valor.ent_val;
                return res;
            }
            reportError(SEMERR_VARNODECL, expr->variable, expr->linea);
            exit(1);

    }
    return res;
}

void interpret_sent(Sent* sent)
{
    switch(sent->sent_tipo)
    {
        case asign_var:
            break;
    }
}

Interprete* interpret_algoritmo(Arbol* alg)
{
    assert(alg != NULL);

    Interprete* interp = newInterprete();

    lista_nodo* vardecs = alg->arbol_data.algoritmo_data.algoritmo_decl_var;
    if(vardecs)
    {
        lista_nodo* cur = vardecs;
        while(cur!=NULL)
        {
            lista_nodo* cur2 = ((Arbol*)(cur->obj))->arbol_data.var_decl_data.ids;
            char* vartipo_id = ((Arbol*)(cur->obj))->arbol_data.var_decl_data.vtipo_id;
            //uint8_t vartipo = ((Arbol*)(cur->obj))->arbol_data.var_decl_data.vtipo;

            while(cur2 != NULL)
            {
                char* varid = (char*)cur2->obj;
                printf("%s\n",varid);

                Variable* new_var = newVariable();
                new_var->tipo_id = strdup(vartipo_id);

                hashmap_set(interp->vars, varid, new_var);

                cur2 = cur2->next;
            }
            cur = cur->next;
        }
    }

    return interp;
}
/*
int interpret_op(Ast* ast)
{
    Ast *op1, *op2;
    int op1n, op2n, aux=0;

    switch(ast->tipo)
    {
        case operacion:

            op1 = (Ast*)ast->op1;
            op2 = (Ast*)ast->op2;
            op1n = interpret_op(op1);
            op2n = interpret_op(op2);

            if(ast->operador == suma)
            {
                aux = op1n + op2n;
                printf("Suma %d + %d: %d\n", op1n, op2n, aux);
                return aux;
            }
            else if(ast->operador == mult)
            {
                aux = op1n * op2n;
                printf("Producto %d x %d: %d\n", op1n, op2n, aux);
                return aux;
            }
            break;
        case numero:
            return ast->num;
            break;
        case funcion:
            break;

    }
}*/

#include "lexico.h"
#include "sintatico.h"

int indice, pindice, pflag, param_tipo;
static TokenArray* toks;
static Token curToken, prevToken;
static char* buffer;

#define NEXT_TOKEN  indice++; \
                    curToken = toks->token[indice]; \
                    pindice = (indice-1)<0 ? 0 : indice-1; \
                    prevToken = toks->token[pindice]



void avanzar()
{
    NEXT_TOKEN;
    if(curToken.tok_tipo == eof)
    {
        //printf("Fin.\n");
    }
}

int check(int t)
{
    if(curToken.tok_tipo == t)
    {
        return 1;
    }
    return 0;
}

int check_linea(int linea)
{
    if(curToken.linea == linea)
    {
        return 1;
    }
    return 0;
}

int check_estricto(int t)
{
    //indice = (indice-1)<0 ? indice-1 : 0;
    if(check(t))
    {
        return 1;
    }
    reportError(SINERR_SIMINESP, prevToken.text, prevToken.linea);
    return 0;
}

int ident()
{
    if(check(identificador))
    {
        return 1;
    }
    return 0;
}

int nat_tipos()
{
    if(check(entero))
    {
        return t_entero;
    }
    else if(check(real))
    {
        return t_real;
    }
    else if(check(logico))
    {
        return t_logico;
    }
    else if(check(caracter))
    {
        return t_caracter;
    }
    return 0;
}

//------------>> Sintaxis de expresiones logicas y aritmeticas <<------------------
Expr* primario()
{
   switch(curToken.tok_tipo)
   {
    case identificador:
        avanzar();
        if(curToken.tok_tipo == pabierto)
        {
            Expr* res;
            //Por hacer: llamada de funcion
        }
        return expr_variable(&prevToken);
    case decimal:
        avanzar();
        return expr_numero(&prevToken);
    case flotante:
        avanzar();
        return expr_numeroreal(&prevToken);
    case logf:
        avanzar();
        return expr_logico(&prevToken);
        break;
    case logv:
        avanzar();
        return expr_logico(&prevToken);
        break;
    case pabierto:
        avanzar();
        Expr* res = expresion();
        avanzar();
        return res;
    default:
        avanzar();
        reportError(SINERR_EXPRINVALID, prevToken.text, prevToken.linea);
   }
   return NULL;
}

Expr* unario()
{
    switch(curToken.tok_tipo)
    {
        case menos:
            avanzar();
            return expr_unop(&prevToken, primario(), menos);
        case not:
            avanzar();
            return expr_unop(&prevToken, primario(), not);
        default:
            return primario();
    }
}

Expr* factor()
{
    Expr* izq = unario();

    if(curToken.tok_tipo == por || curToken.tok_tipo == divr)
    {
        avanzar();
        uint8_t op = prevToken.tok_tipo;
        return expr_binop(&prevToken, izq, op, factor());
    }
    return izq;
}

Expr* termino()
{
    Expr* izq = factor();
    if(curToken.tok_tipo == mas || curToken.tok_tipo == menos)
    {
        avanzar();
        uint8_t op = prevToken.tok_tipo;
        return expr_binop(&prevToken, izq, op, termino());
    }
    return izq;
}

Expr* comparacion()
{
    Expr* izq = termino();
    if(curToken.tok_tipo == menor || curToken.tok_tipo == mayor)
    {
        avanzar();
        uint8_t op = prevToken.tok_tipo;
        Token op_tok = prevToken;
        return expr_binop(&op_tok, izq, op, comparacion());
    }
    return izq;
}

Expr* igualdad()
{
    Expr* izq = comparacion();
    if(curToken.tok_tipo == igual || curToken.tok_tipo == distinto)
    {
        avanzar();
        uint8_t op = prevToken.tok_tipo;
        Token op_tok = prevToken;
        return expr_binop(&op_tok, izq, op, igualdad());
    }
    return izq;

}

Expr* logicos()
{
    Expr* izq = igualdad();
    if(check(and) || check(or))
    {
        avanzar();
        uint8_t op = prevToken.tok_tipo;
        Token op_tok = prevToken;
        return expr_binop(&op_tok, izq, op, logicos());
    }
    return izq;
}

Expr* expresion()
{

    return logicos();
    //pflag=0;
}

//<<<<<<<<<----------------------------------------------------------------->>>>>>>>>

Sent* asign()	//sintaxis de asignacion
{
    Sent* res=malloc(sizeof(Sent));
    if(curToken.tok_tipo != identificador)
    {
        //avanzar();
        goto err;
    }
    avanzar();
    res->asign_var.var = expr_variable(&prevToken);
    if(curToken.tok_tipo != asignacion)
    {
        goto err;
    }
    avanzar();
    Expr* valor = expresion();
    printExpr(valor, 0);
    if(valor)
    {
        res->sent_tipo = asign_var;
        res->asign_var.valor = valor;
        return res;
    }
    err:
        free(res);
        return NULL;
}

Arbol* vardec()
{
    Arbol* res = malloc(sizeof(Arbol));
    res->arbol_tipo = Tlista_arbol;
    res->arbol_data.var_decl_data.ids = NULL;
    lista_nodo* top=NULL;

    uint8_t hay_un_ident = 0;

    while(check(identificador))
    {
        hay_un_ident++;
        if(top)
        {
            top = pushNodo(top, newNodo(curToken.text, Tlista_cadena));
        }
        else
        {
            res->arbol_data.var_decl_data.ids = newNodo(curToken.text, Tlista_cadena);
            top = res->arbol_data.var_decl_data.ids;
        }

        avanzar();
        if(check(coma) && check_linea(prevToken.linea))
        {
            avanzar();
            continue;
        }
        break;
    }
    if(!hay_un_ident)
    {
        reportError(SINERR_DECINVALID, curToken.text, curToken.linea);
        advertencia("Faltan los identificadores de las variables");
        free(res);
        return NULL;
    }
    if(!check(dpuntos))
    {
        reportError(SINERR_DECINVALID, curToken.text, curToken.linea);
        advertencia("Faltan dos puntos (:) antes del tipo de dato");
        free(res);
        return NULL;
    }
    if(!check_linea(prevToken.linea))
    {
        reportError(SINERR_DECINVALID, curToken.text, curToken.linea);
        advertencia("Los dos puntos deben estar en la misma linea donde se declaran las variables");
        free(res);
        return NULL;
    }
    avanzar();

    uint8_t nat_tipo = nat_tipos();
    if(nat_tipo)
    {
        res->arbol_data.var_decl_data.vtipo = nat_tipo;
        res->arbol_data.var_decl_data.vtipo_id = curToken.text;
    }
    else if(check(identificador))
    {
        res->arbol_data.var_decl_data.vtipo = t_no_nativo;
        res->arbol_data.var_decl_data.vtipo_id = curToken.text;
    }
    else
    {
        reportError(SINERR_DECINVALID, curToken.text, curToken.linea);
        advertencia("Se esperaba un tipo de dato valido para la declaracion de variables");
        advertencia("Los tipos de dato no deben ser palabras reservadas o numeros");
        free(res);
        return NULL;
    }
     // Comprobacion de tipos

    return res;

}

lista_nodo* vardec_bloque()
{
    lista_nodo* res = NULL, *top=NULL;
    Arbol* declaracion;
    while(!check(inicio))
    {

        if(check(eof))
        {

            return NULL;
        }

        Arbol* declaracion= vardec();
        if(declaracion == NULL)
        {
            return NULL;
        }
        if(res)
        {
            top = pushNodo(top, newNodo(declaracion, Tlista_arbol));
        }
        else
        {
            res = newNodo(declaracion, Tlista_arbol);
            top = res;
        }
        avanzar();

    }

    return res;
}

Arbol* bloque_algoritmo()
{
    Arbol* res=malloc(sizeof(Arbol));
    res->arbol_tipo = t_algoritmo;
    res->arbol_data.algoritmo_data.algoritmo_decl_var = NULL;

    if(check(algoritmo))
    {
        avanzar();
        if(check(identificador))
        {

            while(!check(inicio))
            {
                if(check(eof))
                {
                    free(res);
                    return NULL;
                }
                avanzar();
                switch(curToken.tok_tipo)
                {
                    case var:
                        avanzar();
                        res->arbol_data.algoritmo_data.algoritmo_decl_var = vardec_bloque();
                        break;
                }
            }


            while(!check(fin))
            {
                if(check(eof))
                {
                    reportError(SINERR_BLOQUEINCOMPLETO, prevToken.text, prevToken.linea);
					advertencia("Falto cerrar el bloque de codigo con \"fin\"");
                    free(res);
                    return NULL;
                }
                avanzar();
                Sent* r=NULL;
                switch(curToken.tok_tipo)
                {
                    case identificador:
                        r = asign();
                        res->arbol_data.algoritmo_data.cuerpo_sentencias = r;
                        break;
                }
            }

            return res;
        }
    }

    free(res);
    return NULL;
}

Arbol* anl_sintactico(TokenArray* tokens)
{
    toks = tokens;
    indice = -1;
    pflag= -1;
    avanzar();

    Arbol* v = bloque_algoritmo();
    if(v)
    {
        printLista(v->arbol_data.algoritmo_data.algoritmo_decl_var);
    }

    //printf("Eval res: %d\n", r);
    /*
    algorit();
    Hashmap_it it = hashmap_iterador(vars);
    while(hashmap_it_next(&it))
    {
        printf("Var:%s Tipo:%s\n", it.llave, ((Variable*)it.valor)->tipo);
        free(it.valor);
    }
    it = hashmap_iterador(tipos);
    while(hashmap_it_next(&it))
    {
        printf("Tipo:%s Codigo:%d\n", it.llave, *(int*)it.valor);
        free(it.valor);
    }*/
    //printf("%d\n", indice);

    return v;
}

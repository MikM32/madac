

#include <stdio.h>
#include <stdlib.h>
#include "errores.h"
#include "sintatico.h"
#include "hashmap.h"

typedef struct
{
    uint8_t val_tipo;
    union
    {
        int32_t ent_val;
        float real_val;
        char* cad_val;
    };
}Valor;


typedef struct
{
    char* tipo_id;
    Valor valor;

} Variable;

typedef struct
{
    Hashmap* vars;
    Hashmap* tipos;
} Interprete;

Valor interpret_expr(Interprete* interp, Expr* expr);
Interprete* interpret_algoritmo(Arbol* alg);

byte semantica_expr(byte* retorno_tipo ,Expr* expr);
byte semantica_expr_binop(byte* retorno_tipo, Expr* expr);
byte semantica_expr_unop(byte* retorno_tipo, Expr* expr);




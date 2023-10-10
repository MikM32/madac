
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.h"
#include "interprete.h"

#define DEBUG 1

int main()
{
    TokenArray* tokens = malloc(sizeof(TokenArray));
    initTokenArray(tokens);

    if(anl_lexico(tokens, "test.mc"))
    {
        return 1;
    }

    Arbol* x = anl_sintactico(tokens);
	
    Interprete* f = interpret_algoritmo(x);
	
    interpret_expr(f, x->arbol_data.algoritmo_data.cuerpo_sentencias->asign_var.valor);
    /*
    Variable* res = (Variable*)hashmap_get(f->vars, "x3");
    if(res)
    {
        printf("x2->>>%s\n", res->tipo_id);
    }
    else
    {
        printf("Esta variable no esta declarada\n");
    }*/

    #if DEBUG == 1 // Ve el valor de cada token (su tipo y su cadena respectiva)
    for(int i=0; i<tokens->cont; i++)
    {
        printf("Tok: %s || id: %d\n", tokens->token[i].text, tokens->token[i].tok_tipo);
    }
    #endif // DEBUG

    freeTokenArray(tokens);
    return 0;

}

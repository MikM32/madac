
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol_tipos.h"

#define MAX_DEFTIPOS 125
#define GET_TOKEN(tokens, i) tokens->token[i]
//#define NEXT_TOKEN(tokens) tokens->token[curToken]

Expr* expresion();
Expr* igualdad();
Expr* comparacion();
Expr* termino();
Expr* factor();
Expr* primario();

int checkTipo(Token*, int);
Arbol* anl_sintactico(TokenArray*);



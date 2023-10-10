

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utiles.h"
#include "errores.h"
#include "tokens.h"



/*------- Prototipos -----------*/

int isDecimal(char);
int isAlpha(char);
int isReserv(char*);
int anl_lexico(TokenArray*,char*);



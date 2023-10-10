
#include <stdio.h>

#define LEXERR_CARACINVALID 1 //Caracter Invalido
#define LEXERR_IDENTINVALID 2 //Identificador Invalido
#define SINERR_DECINVALID 3   //Declaracion invalida
#define SINERR_MALPARENT 4    //Mal parentizado
#define SINERR_EXPRINVALID 5  //Expresion Invalida
#define SINERR_ASIGNINVALID 6 //Asignacion invalida
#define SEMERR_TIPOSINVALID 7 //Tipos invalidos
#define SINERR_SIMINESP 8     //Simbolo inesperado
#define SINERR_ALGNOMBRE 9    //Falta el nombre del algoritmo
#define SEMERR_VARNODECL 10   //Variable no declarada
#define SINERR_BLOQUEINCOMPLETO 11 //Bloque inicio-fin incompleto

extern void reportError(int err_codigo, char* text, int linea);
extern void advertencia(char* txt);


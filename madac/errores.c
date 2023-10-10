#include "errores.h"

void reportError(int err_codigo, char* text, int linea)
{
    switch(err_codigo)
    {
        case LEXERR_CARACINVALID:
            printf("[!] Error de tipeado en linea %d [!]= caracter '%c' no permitido\n", linea, text);
            break;
        case LEXERR_IDENTINVALID:
            printf("[!]Error de tipeado en linea %d [!]= identificador '%s' invalido\n", linea, text);
            break;
        case SINERR_DECINVALID:
            printf("[!]Error de sintaxis en linea %d [!]= declaracion invalida en '%s'\n", linea, text);
            break;
        case SINERR_MALPARENT:
            printf("[!]Error de sintaxis en linea %d [!]= expresion mal parentizada en '%s'\n", linea, text);
            break;
        case SINERR_EXPRINVALID:
            printf("[!]Error de sintaxis en linea %d [!]= expresion invalida en '%s'\n", linea, text);
            break;
        case SINERR_ASIGNINVALID:
            printf("[!]Error de sintaxis en linea: %d [!]= asignacion invalida en '%s'\n", linea, text);
            break;
        case SINERR_SIMINESP:
            printf("[!]Error de sintaxis en linea: %d [!]= Simbolo inesperado '%s'\n", linea, text);
            break;
        case SEMERR_TIPOSINVALID:
            printf("[!]Error de expresion en linea %d[!]= los tipos no coinciden con el tipo de dato esperado en '%s'\n", linea, text);
            break;
        case SINERR_ALGNOMBRE:
            printf("[!]Error de sintaxis en linea %d[!]= No se le asigno un nombre o se le asigno un nombre invalido al algoritmo\n", linea, text);
            break;
		case SINERR_BLOQUEINCOMPLETO:
			printf("[!]Error de sintaxis en linea %d[!]= El bloque de codigo inicio-fin esta incompleto\n", linea);
			break;
        case SEMERR_VARNODECL:
            printf("[!]Error de semantica en linea %d[!]= La variable %s no existe o no esta declarada\n", linea, text);
            break;
        default:
            printf("Codigo de error desconocido\n");
            break;
    }
    //exit(1);
}

void advertencia(char* txt)
{
    printf("\t\t[-] %s [-]\n", txt);
}

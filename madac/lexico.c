
#include "lexico.h"

int isDecimal(char c)
{
    if(c>47 && c<58)
    {
        return 1;
    }
    return 0;
}

int isAlpha(char c)
{
    if(c>64 && c<91) //Mayuscula A-Z
    {
        return 1;
    }
    else if(c>96 && c<123) //Minuscula a-z
    {
        return 1;
    }
    return 0;
}

int isReserv(char* texto)
{
    int len = strlen(texto);
    if(!strncmp(texto, "verdadero", len) && len == 9)
    {
        return logv;
    }
    else if(!strncmp(texto, "falso", len) && len == 5)
    {
        return logf;
    }
    else if(!strncmp(texto, "and", len) && len == 3)
    {
        return and;
    }
    else if(!strncmp(texto, "or", len) && len == 2)
    {
        return or;
    }
    else if(!strncmp(texto, "not", len) && len == 3)
    {
        return not;
    }
    else if(!strncmp(texto, "div", len) && len == 3)
    {
        return dive;
    }
    else if(!strncmp(texto, "mod", len) && len == 3)
    {
        return mod;
    }
    else if(!strncmp(texto, "proc", len) && len == 4)
    {
        return proc;
    }else if(!strncmp(texto, "func", len) && len == 4)
    {
        return func;
    }else if(!strncmp(texto, "entero", len) && len == 6)
    {
        return entero;
    }
    else if(!strncmp(texto, "algoritmo", len) && len == 9)
    {
        return algoritmo;
    }
    else if(!strncmp(texto, "var", len) && len == 3)
    {
        return var;
    }
    else if(!strncmp(texto, "tipo", len) && len == 4)
    {
        return tipo;
    }
    else if(!strncmp(texto, "const", len) && len == 5)
    {
        return constant;
    }
    else if(!strncmp(texto, "inicio", len) && len == 6)
    {
        return inicio;
    }
    else if(!strncmp(texto, "fin", len) && len == 3)
    {
        return fin;
    }
    else if(!strncmp(texto, "fproc", len) && len == 5)
    {
        return fproc;
    }
    else if(!strncmp(texto, "ref", len) && len == 3)
    {
        return ref;
    }
    else if(!strncmp(texto, "val", len) && len == 3)
    {
        return val;
    }
    else if(!strncmp(texto, "ffunc", len) && len == 5)
    {
        return ffunc;
    }
    else
    {
        return 0;
    }
}

int anl_lexico(TokenArray* tokens, char*txt)
{
    char *buffer = calloc(BUFFER_SIZE, sizeof(char));
    int linea_cont=1, errores=0, error=0;
    int aux=0;
    char c;

    FILE *fp = fopen(txt, "r");

    if(fp==NULL)
    {
        fprintf(stderr,"Error al abrir el archivo --> %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    NEXTCHAR(c, fp);

    while(1)
    {
                                //c== TAB
        if(c == ' ' || c == '\r' || c=='\0' || c==9)
        {
            NEXTCHAR(c, fp);
            continue;
        }
        else if(c=='\n')
        {
            linea_cont++;
            NEXTCHAR(c, fp);
            continue;
        }
        else if(c=='{')
        {
            while(c!=EOF && c!='}')
            {

                NEXTCHAR(c, fp);
                if(c=='\n')
                {
                    linea_cont++;
                }
            }
            NEXTCHAR(c, fp);
            continue;
        }
        else if(isDecimal(c))
        {
            aux=1;
            uint8_t numtipo=decimal;
            while(aux)
            {
                strncat(buffer, &c, 1);
                NEXTCHAR(c, fp);
                if(isDecimal(c))
                {
                    continue;
                }
                else if(c == '.')
                {
                    numtipo=flotante;
                    continue;
                }
                else if(isAlpha(c) && c!='_')
                {
                    error++;
                }
                else
                {
                    aux=0;
                }

            }
            if(error)
            {
                reportError(LEXERR_IDENTINVALID, buffer, linea_cont);
                error=0;
                errores++;
                NEXTCHAR(c, fp);
            }
            else
            {
                appendTokenArray(tokens, buffer, numtipo, linea_cont);

            }
            CLEAR_BUFFER(buffer, BUFFER_SIZE);

        }
        else if(isAlpha(c) || c == '_')
        {
            while(c!=EOF && (isAlpha(c) || isDecimal(c) || c == '_' ))
            {
                strncat(buffer, &c, 1);
                c=fgetc(fp);
            }

            aux = isReserv(buffer); //Comprueba si la cadena obtenida es una palabra reservada, si lo es devuelve el tipo de token correspondiente
            if(aux)
            {
                appendTokenArray(tokens, buffer, aux, linea_cont);
            }
            else
            {
                appendTokenArray(tokens, buffer, identificador, linea_cont);
            }

            CLEAR_BUFFER(buffer, BUFFER_SIZE);
        }
        else if(c=='<')
        {
            NEXTCHAR(c, fp);
            if(c == '-')
            {
                appendTokenArray(tokens, "<-", asignacion, linea_cont);
                NEXTCHAR(c, fp);
            }
            else if(c == '=')
            {
                appendTokenArray(tokens, "<=", menigual, linea_cont);
                NEXTCHAR(c, fp);
            }
            else if(c== '>')
            {
                appendTokenArray(tokens, "<>", distinto, linea_cont);
                NEXTCHAR(c, fp);
            }
            else
            {
                appendTokenArray(tokens, "<", menor, linea_cont);
            }
            //c=fgetc(fp);
            continue;
        }
        else if(c=='>')
        {
            NEXTCHAR(c, fp);
            if(c == '=')
            {
                appendTokenArray(tokens, ">=", mayigual, linea_cont);
                NEXTCHAR(c, fp);
            }
            else
            {
                appendTokenArray(tokens, ">", mayor, linea_cont);
            }
            //c=fgetc(fp);
            continue;
        }
        else if(c=='+')
        {
            appendTokenArray(tokens, "+", mas, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c=='-')
        {
            appendTokenArray(tokens, "-", menos, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c=='*')
        {
            appendTokenArray(tokens, "*", por, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c=='/')
        {
            appendTokenArray(tokens, "/", divr, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c==':')
        {
            appendTokenArray(tokens, ":", dpuntos, linea_cont);
            NEXTCHAR(c, fp);
        } else if(c=='(')
        {
            appendTokenArray(tokens, "(", pabierto, linea_cont);
            NEXTCHAR(c, fp);
        } else if(c==')')
        {
            appendTokenArray(tokens, ")", pcerrado, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c=='=')
        {
            appendTokenArray(tokens, "=", igual, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c==',')
        {
            appendTokenArray(tokens, ",", coma, linea_cont);
            NEXTCHAR(c, fp);
        }
        else if(c==EOF)
        {
            appendTokenArray(tokens, "<EOF>", eof, linea_cont);
            break;
        }
        else
        {
            errores++;
            reportError(LEXERR_CARACINVALID, &c, linea_cont);
            NEXTCHAR(c, fp);
        }
    }

    fclose(fp);
    free(buffer);
    return errores;
}

void freeTokens(Token* tokens, int toklen)
{
    for(int i=0; i<toklen; i++)
    {
        free(tokens[i].text);
    }
    free(tokens);
}

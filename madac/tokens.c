#include "tokens.h"

extern void* realojar(void* puntero, size_t oldSize, size_t newSize)
{
    if(newSize == 0)
    {
		if(puntero!=NULL)
		{
			free(puntero);
		}
        return NULL;
    }

    void* res = realloc(puntero, newSize);
    if(res==NULL)
    {
		printf("Error al reservar memoria, espacio insuficiente\n");
        exit(1);
    }
    return res;
}

extern void assignToken(Token* token,char*text, int tp, int linea)
{
    token->text = calloc(strlen(text)+1, sizeof(char));
    strncpy(token->text, text, strlen(text)+1);
    token->tok_tipo = tp;
    token->linea = linea;
}

extern void initTokenArray(TokenArray* toks)
{
    toks->cont = 0;
    toks->capacidad = 0;
    toks->token = NULL;
}

extern void appendTokenArray(TokenArray* toks,  char* txt, int tp, int linea)
{
    if(toks->capacidad < toks->cont + 1)
    {
        int antCapacidad = toks->capacidad;
        toks->capacidad = AUMENTAR_CAP(antCapacidad);
        toks->token = AUMENTAR_ARR(Token, toks->token, antCapacidad, toks->capacidad);
    }

    assignToken(&toks->token[toks->cont], txt, tp, linea);
    toks->cont++;
}

extern void freeTokenArray(TokenArray* toks)
{
    if(toks->cont>0)
    {
            for(int i=0; i<toks->cont; i++)
            {
                free(toks->token[i].text);
            }
    }
    if(toks->token != NULL) free(toks->token);

    FREE_ARR(TokenArray, toks, toks->capacidad);
    initTokenArray(toks);
}



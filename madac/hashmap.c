#include "hashmap.h"

uint64_t hash_func(char* llave, size_t llav_len)
{
    uint64_t hash = FNV_OFFSET;
    for(size_t i=0; i<llav_len; i++)
    {
        hash ^= (uint64_t)(unsigned char )(llave[i]);
        hash *= FNV_PRIME;
    }
    return hash;
}

Hashmap* newHashmap()
{
    Hashmap *res = malloc(sizeof(Hashmap));
    if(res == NULL)
    {
        return NULL;
    }
    res->capacidad = 16;
    res->cont = 0;
    res->entradas = (Entrada*)calloc(res->capacidad, sizeof(Entrada));
    if(res == NULL)
    {
        free(res);
        return NULL;
    }
    return res;
}

void freeHashmap(Hashmap* hm)
{
    for(size_t i=0; i< hm->capacidad; i++)
    {
        free((void*)hm->entradas[i].llave);
    }

    free(hm->entradas);
    free(hm);
}

void* hashmap_get(Hashmap* hm, char* llave)
{
    size_t llave_len = strlen(llave);
    uint64_t hash = hash_func(llave, llave_len);
    size_t indice = (size_t)(hash & (hm->capacidad-1));
    char* acum;

    while(hm->entradas[indice].llave != NULL)
    {
        acum = hm->entradas[indice].llave;
        if(strlen(acum) == llave_len)
        {
            if(strncmp(acum, llave, llave_len) == 0)
            {
                return hm->entradas[indice].valor;
            }
        }

        indice++;
        if(indice >= hm->capacidad)
        {
            indice=0;
        }
    }

    return NULL;
}

static uint8_t hashmap_expandir(Hashmap* hm)
{
    size_t n_capacidad = hm->capacidad * 2;
    if(n_capacidad < hm->capacidad)
    {
        return 0;
    }

    Entrada* n_entradas = calloc(n_capacidad, sizeof(Entrada));
    if(n_entradas == NULL)
    {
        return 0;
    }

    return 0;

}

static char * hashmap_set_entrada(Entrada* entradas, size_t capacidad, char* llave, void* valor, size_t* len)
{
    size_t llave_len = strlen(llave);
    uint64_t hash = hash_func(llave, llave_len);
    size_t indice = (size_t)(hash & (capacidad-1));
    char* acum;

    while(entradas[indice].llave != NULL)
    {
        acum = entradas[indice].llave;

        if(strlen(acum) == llave_len)
        {
            if(strncmp(acum, llave, llave_len) == 0)
            {
                entradas[indice].valor = valor;
                return acum;
            }
        }

        indice++;
        if(indice >= capacidad)
        {
            indice = 0;
        }
    }
        if(len != NULL)
        {
            llave = strdup(llave);
            if(llave == NULL)
            {
                return NULL;
            }
            (*len)++;
        }

    entradas[indice].valor = valor;
    entradas[indice].llave = llave;
    return llave;
}

char* hashmap_set(Hashmap* hm, char* llave, void* valor)
{
    assert(valor != NULL);
    if(valor == NULL)
    {
        return NULL;
    }

    if(hm->cont >= hm->capacidad / 2)
    {
        if(!hashmap_expandir(hm))
        {
            return NULL;
        }

    }

    return hashmap_set_entrada(hm->entradas, hm->capacidad, llave, valor, &hm->cont);
}

Hashmap_it hashmap_iterador(Hashmap* hm)
{
    Hashmap_it it;
    it.hm = hm;
    it.indice= 0;
    return it;
}

uint8_t hashmap_it_next(Hashmap_it* it)
{
    Hashmap* hm = it->hm;
    while(it->indice < hm->capacidad)
    {
        size_t pos = it->indice;
        it->indice++;
        if(hm->entradas[pos].llave != NULL)
        {
            it->llave = hm->entradas[pos].llave;
            it->valor = hm->entradas[pos].valor;
            return 1;
        }
    }

    return 0;
}

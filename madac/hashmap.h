
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Estructura para entradas o items de un hashmap
typedef struct
{
    char* llave;
    void* valor;
} Entrada;

typedef struct
{
    size_t capacidad;
    size_t cont;
    Entrada* entradas;
}Hashmap;

// Estructura iterador para hashmaps
typedef struct
{
    Hashmap* hm;
    size_t indice;

    char* llave;
    void* valor;
}Hashmap_it;

extern uint64_t hash_func(char* llave, size_t llav_len);
extern char* hashmap_set(Hashmap* hm, char* llave, void* valor);
extern void* hashmap_get(Hashmap* hm, char* llave);
extern Hashmap* newHashmap();
extern void freeHashmap(Hashmap* hm);

Hashmap_it hashmap_iterador(Hashmap* hm);
uint8_t hashmap_it_next(Hashmap_it* it);

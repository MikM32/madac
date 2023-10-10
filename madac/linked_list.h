#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

extern enum lndt
{
    Tlista_arbol=1,
    Tlista_sent,
    Tlista_expr,
    Tlista_cadena,
    Tlista_otro
}lista_nodo_tipos;

typedef struct lista lista_nodo;
typedef struct lista
{
    uint8_t tlista;
    void* obj;
    lista_nodo* next;
}lista_nodo;

lista_nodo* newNodo(void* obj, uint8_t ltipo);
lista_nodo* pushNodo(lista_nodo* top, lista_nodo* obj_nuevo);
lista_nodo* borrarNodo(lista_nodo* nodo, lista_nodo* prev);

void borrarLista(lista_nodo* top);
void printLista(lista_nodo* top);
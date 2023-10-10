#include "linked_list.h"

lista_nodo* newNodo(void* obj, uint8_t ltipo)
{
    lista_nodo* res = malloc(sizeof(lista_nodo));
    res->obj = obj;
    res->next = NULL;
    res->tlista = ltipo;
    return res;
}

lista_nodo* pushNodo(lista_nodo* top, lista_nodo* obj_nuevo)
{
    lista_nodo* cur = top;
    assert(top != NULL);
    assert(obj_nuevo != NULL);

    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = obj_nuevo;
    return top;
}

lista_nodo* borrarNodo(lista_nodo* nodo, lista_nodo* prev)
{
    lista_nodo* next;
    assert(nodo!= NULL);

    next = nodo->next;
    if(prev != NULL)
    {
        prev->next = next;
    }
    free(nodo);
    return next;
}

void borrarLista(lista_nodo* top)
{
    lista_nodo *cur;
    cur = top;
    while(cur != NULL)
    {
        cur = borrarNodo(cur, NULL);
    }
}

void printLista(lista_nodo* top)
{
    lista_nodo* cur = top;

    while(cur != NULL)
    {
        printf("%d, ", cur->tlista);
        cur = cur->next;
    }
    printf("\n");
}

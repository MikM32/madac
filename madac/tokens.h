#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int tok_tipo;
    int linea;
    char* text;
} Token;

typedef struct 
{
    int cont;
    int capacidad;
    Token* token;
} TokenArray;


extern enum simb_enum
{
    decimal=1,
    flotante,
    identificador,
    menor,
    mayor,
    menigual,
    mayigual,
    igual,
    distinto,
    mas,
    menos, //=10
    por,
    dive,
    divr,
    mod,
    logv,
    logf,
    and,
    or,
    not,
    func,
    proc,   //=20
    pabierto,
    pcerrado,
    dpuntos,
    entero,
    real,
    logico,
    caracter,
    arreglo,
    de,
    punto,  //=30
    cabierto,
    ccerrado,
    asignacion,
    algoritmo,
    var,
    tipo,
    constant,
    inicio,
    fin,
    ffunc,  //=40
    fproc,
    eof,
    error,
    coma,
    ref,
    val,
}simbolo;

#define AUMENTAR_CAP(capacidad) ((capacidad) < 8  ? 8 : (capacidad)*2)
extern void assignToken(Token* token,char*text, int tp, int linea);

extern void initTokenArray(TokenArray* toks);
extern void appendTokenArray(TokenArray* toks,  char* txt, int tp, int linea);

extern void freeTokenArray(TokenArray* toks);
extern void* realojar(void* puntero, size_t oldSize, size_t newSize);
#define AUMENTAR_ARR(tipo, puntero, antCont, nCont) \
                    (tipo *)realojar(puntero, sizeof(tipo)*antCont, sizeof(tipo)*nCont)

#define FREE_ARR(tipo, puntero, antCont) realojar(puntero, sizeof(tipo)*antCont, 0)
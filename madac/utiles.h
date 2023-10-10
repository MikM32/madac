#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define BUFFER_SIZE 128
#define NEXTCHAR(c, fp) c=fgetc(fp)

extern enum opsenum
{
    suma,
    resta,
    mult,
    div_real,
    div_entera,
    modulo,
    asigna,
}ops;




int strToInt(char* str, size_t len);
float strToFloat(char* str, size_t len);


#define CLEAR_BUFFER(buffer, size) memset(buffer, 0, size)
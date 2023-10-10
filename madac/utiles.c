#include "errores.h"
#include "hashmap.h"
#include "utiles.h"


int strToInt(char* str, size_t len)
{
    int res=0;
    int bas=1;
    for(int i=len-1; i>=0; i--)
    {
        if(str[i] >= 0x30 && str[i] <= 0x39)
        {
            res+= ((str[i] & 0xF))*(bas);
            bas*=10;
        }
        else
        {
            printf("Error al transformar cadena a entero: la cadena contiene caracteres no numericos\n");
            return 0;
        }

    }

    return res;
}

float strToFloat(char* str, size_t len)
{
    float res=0;
    float bas=0;

    int punto_pos=-1;

    for(int i=0; i<len; i++)
    {
        if(str[i]=='.')
        {
            punto_pos=i;
            break;
        }
        else if(i==0)
        {
            bas=1;
        }
        else
        {
            bas*=10;
        }

    }


    for(int i=0; i<punto_pos; i++)
    {
        if(str[i] >= 0x30 && str[i] <= 0x39)
        {
            res+= (float)((str[i] & 0xF))*(bas);
            bas/=10;
        }
        else
        {
            printf("Error al transformar cadena a entero: la cadena contiene caracteres no numericos\n");
            return 0;
        }

    }

    bas = 10;
    for(int i=punto_pos+1; i<len; i++)
    {
        if(str[i] >= 0x30 && str[i] <= 0x39)
        {
            res+= (float)((str[i] & 0xF))/(bas);

            bas*=10;
        }
        else
        {
            printf("Error al transformar cadena a entero: la cadena contiene caracteres no numericos\n");
            return 0;
        }
    }

    return res;

}

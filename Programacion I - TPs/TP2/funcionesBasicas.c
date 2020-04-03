#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesBasicas.h"
#include "ArrayEmployees.h"
#include "funcionesAuxiliares.h"
#define TAMANIOEMPLEADOS 100
#define TAMANIOSECTOR 7
#define UP 1
#define DOWN 0

//Funciones para pedir y validar enteros

int getEntero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while(reintentos>0)
    {
        printf(mensaje);

        if(auxiliarGetEntero(&num)==1)
        {
            if(num<=maximo && num>=minimo)
                break;
        }

        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=0;
    }
    else
    {
        ret=1;
        *pResultado = num;
    }

    return ret;
}




int auxiliarGetEntero(int* pResultado)
{
    int ret=0;
    char buffer[20];
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        ret=1;
    }

    return ret;
}




int esNumerica(char* cadena)
{
    int ret=0;
    int i=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }

    return ret;
}


//Funciones para pedir y validar flotantes

int getFlotante(float* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while(reintentos>0)
    {
        printf(mensaje);
        if(auxiliarEsFlotante(&num)==1)
        {
            if(num<=maximo && num>=minimo)
                break;
        }
        reintentos--;
        printf(mensajeError);
    }

    if(reintentos==0)
    {
        ret=0;
    }
    else
    {
        ret=1;
        *pResultado = num;
    }
    return ret;
}



int auxiliarEsFlotante(float* pResultado)
{
    int ret=0;
    char buffer[30];
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esFlotante(buffer))
    {
        *pResultado = atof(buffer);
        ret=1;
    }

    return ret;
}



int esFlotante(char* cadena)
{
    int ret=0;
    int i=0;
    int flagPunto=0;

    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(((cadena[i]<'0' || cadena[i]>'9') && cadena[i]!='.') ||(cadena[i]=='.' && flagPunto==1))
            {
                break;
            }
            if(cadena[i]=='.')
            {
                flagPunto=1;
            }



            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}

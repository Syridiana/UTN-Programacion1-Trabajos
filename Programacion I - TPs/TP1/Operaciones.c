#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

//-------funcion para pedir un caracter del menu y validarlo------------
void getChar(char* input, char mensaje[], char eMensaje[], char minimo, char maximo)
{
    char letra;

    printf(mensaje);
    fflush(stdin);
    scanf("%c", &letra);

    while(letra<minimo || letra>maximo)
    {
        printf(eMensaje);
        fflush(stdin);
        scanf("%c", &letra);
    }

    *input = letra;



}

//-------------funcion para pedir operandos---------
char getFloat(float* numero, char mensaje[], char eMensaje[], int reintentos)
{
    char exitoso;
    float num;

    while(reintentos>0)
    {

        printf(mensaje);
        if(scanf("%f", &num)==1)
        {
            break;
        }
        fflush(stdin);
        reintentos--;
        printf(eMensaje);
    }
    if(reintentos==0)
    {
        exitoso='n';

    }
    else
    {
        exitoso = 's';
        *numero = num;
    }
    return exitoso;

}


void suma(float* suma, float x, float y)
{
    float resultado = x+y;
    *suma=resultado;
}


void resta(float* resta, float x, float y)
{
    float resultado = x-y;
    *resta=resultado;
}



void multiplicacion(float* producto, float x, float y)
{
    float resultado = x*y;
    *producto=resultado;
}


int division(float* cociente, float x, float y)
{
    int ret;

    if(y==0)
    {
        ret = -1;
    }
    else
    {
        float resultado = x/y;
        *cociente=resultado;
        ret = 1;
    }

    return ret;
}

int factorial(long long int* fact, float x)
{
    int j=1;
    int resultado=1;
    int ret;

    if(x==0)
    {
        resultado = 1;
        *fact = (int) resultado;
        ret=1;
    }
    else if(x>0)
    {
        while(j<x)
        {
            j++;
        }

        if(x<j)
        {
            ret=-1;
        }
        else
        {
            for(int i=x; i>=1; i--)
            {
                resultado = resultado*i;
            }

            *fact = (long long int) resultado;
            ret = 1;
        }
    }
    else
    {
        ret=-1;
    }

    return ret;
}



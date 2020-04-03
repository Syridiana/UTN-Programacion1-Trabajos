#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesValidacion.h"



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

int pedirTexto(char pResultado[], char* mensaje, char* mensajeError, int reintentos)
{
    int ret=0;
    char buffer[128];
    int esAlfabe;
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    esAlfabe = esAlfabetica(buffer);

    while(esAlfabe!=1 && reintentos>0)
    {
        reintentos--;
        printf(mensajeError);
        fflush(stdin);
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';
        esAlfabe = esAlfabetica(buffer);


    }
    if(esAlfabe)
    {
        strcpy(pResultado, buffer);
        ret=1;

    }

    return ret;
}


int pedirChar(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int ret=0;
    char sexo;
    printf(mensaje);
    fflush(stdin);
    scanf("%c", &sexo);

    while(sexo!='f' && sexo!='m' && sexo!='o' && reintentos>0)
    {
        printf(mensajeError);
        fflush(stdin);
        scanf("%c", &sexo);
        reintentos--;

    }
    if(reintentos>0)
    {
        *pResultado = sexo;

        ret=1;
    }

    return ret;
}

int pedirTelefono(char pResultado[], char* mensaje, char* mensajeError, int reintentos)
{
    int ret=0;
    char buffer[21];
    int esTel;
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    esTel = esTelefono(buffer);
    while(esTel!=1 && reintentos>0)
    {
        printf(mensajeError);
        fflush(stdin);
        fgets(buffer,sizeof(buffer),stdin);
        buffer[strlen(buffer)-1]='\0';
        esTel = esTelefono(buffer);
        reintentos--;


    }
    if(reintentos>0)
    {
        strcpy(pResultado, buffer);
        ret=1;
    }

    return ret;
}


int pedirDomicilio(char domicilio[], char* mensaje, char* mensajeError)
{
    char buffer[51];
    printf(mensaje);
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    strcpy(domicilio, buffer);


    return 1;
}



int esFlotante(char* cadena)
{
    int ret=0;
    int i=0;
    int flag=1;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(((cadena[i]<'0' || cadena[i]>'9') && cadena[i]!='.')||( cadena[i]=='.'&&flag==0))
                break;

            if(cadena[i]=='.')
            {
                flag=0;
            }

            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}








int esAlfabetica(char* cadena)
{
    int ret=0;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if((cadena[i]<'A' || cadena[i]>'Z')&&(cadena[i]<'a' || cadena[i]>'z')&& cadena[i]!=' ')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}



/*
int esTelefono(char* cadena)
{
    int ret=0;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if((cadena[i]<'0' || cadena[i]>'9')&& cadena[i]!='-')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}
*/


/*
int pedirNombre(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
    int ret;
    char nombre[51];
    while(reintentos>0)
    {
        printf(mensaje);
        if(pedirNombreCliente(nombre)!=1)
        {
            reintentos--;
            printf(mensajeError);
        }

    }
    if(reintentos==0)
    {
        ret=0;
    }
    else
    {
        ret=1;
        *pResultado = nombre;
    }
    return ret;
}
*/
/*int pedirChar(char* caracter, char* mensaje, char* mensajeError, int reintentos)
{
    int ret;
    char sexo;
    printf(mensaje);
    while(reintentos>0)
    {
        scanf("%c", &sexo);
        while (sexo!='f' && sexo!='m' && sexo!='o')
        {
            printf(mensajeError);
            reintentos--;
        }
    }
    if(sexo=='f' || sexo=='m' || sexo=='o')
    {
        ret=1;
    }
    else if (reintentos==0)
    {
        ret =0;
    }
    return ret;
}*/
/*
int pedirTelefono(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
int ret;
    char telefono[21];
    while(reintentos>0)
    {
        printf(mensaje);
        if(pedirNombreCliente(telefono)!=1)
        {
            reintentos--;
            printf(mensajeError);
        }

    }
    if(reintentos==0)
    {
        ret=0;
    }
    else
    {
        ret=1;
        *pResultado = telefono;
    }
    return ret;
}*/

int pedirTelefonoDelCliente(char* pResultado)
{
    int ret=0;
    char buffer[21];
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(esAlfabetica(buffer))
    {
        *pResultado = buffer;
        ret=1;
    }
    return ret;
}

int esTelefono(char* cadena)
{
    int ret=0;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if((cadena[i]<'0' || cadena[i]>'9')  && cadena[i]!='-')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}






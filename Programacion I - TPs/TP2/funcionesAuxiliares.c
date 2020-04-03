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


void harcodearSectores(eSector listaSectores[], int cantidad)
{
    int i;

    eSector suplentes[]=
    {
        {1, "Marketing"},
        {2, "IT"},
        {3, "Ventas"},
        {4, "Comercial"},
        {5, "Investigacion"},
        {6, "Contabilidad"},
        {7, "Disenio"},


    };

    for(i=0; i<cantidad; i++)
    {
        listaSectores[i] = suplentes[i];

    }
}


void hardcodearEmpleados(eEmployee listaEmpleados[], int cantidad)
{
    int i;

    eEmployee suplentes[]=
    {
        {1, "Jose", "Garcia", 15321, 7, 0},
        {2, "Julia", "Lopez", 20564.2, 3, 0},
        {3, "Norberto", "Herrero", 20358, 4, 0},
        {4, "Lucia", "Leren", 25641.25, 4, 0},
        {5, "Mariana", "Lini", 56413, 7, 0},
        {6, "Lucas", "Jok", 65413.5, 2, 0},
        {7, "Eva", "Jeronsky", 54984, 1, 0},


    };

    for(i=0; i<cantidad; i++)
    {
        listaEmpleados[i] = suplentes[i];

    }
}


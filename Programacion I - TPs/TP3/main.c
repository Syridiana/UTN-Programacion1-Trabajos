#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir

*****************************************************/


int main()
{
    char option = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");

        switch(controller_menu())
        {

        case 1:
            if(!ll_isEmpty(listaEmpleados))
            {
                printf("\n******** ERROR. Ya hay un archivo cargado. ********\n\n");

            }
            else
            {
                controller_loadFromText("data.csv",listaEmpleados);
            }
            system("pause");
            break;

        case 2:
            if(!ll_isEmpty(listaEmpleados))
            {
                printf("\n******** ERROR. Ya hay un archivo cargado. ********\n\n");

            }
            else
            {
                controller_loadFromBinary("data.bin", listaEmpleados);
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }

            system("pause");
            break;

        case 4:
            system("cls");
            if(!ll_isEmpty(listaEmpleados))
            {
                printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n\n");
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if(!ll_isEmpty(listaEmpleados))
            {
                printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n\n");
                controller_ListEmployee(listaEmpleados);
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            printf("\n\n");
            system("pause");
            break;

        case 6:
            system("cls");
            if(!ll_isEmpty(listaEmpleados))
            {
                printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n\n");
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            printf("\n\n");
            system("pause");
            break;

        case 7:
            system("cls");
            if(!ll_isEmpty(listaEmpleados))
            {
                if(controller_sortEmployee(listaEmpleados))
                {
                    system("cls");
                    printf("**** Empleados ordenados *****\n\n");
                    printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n\n");
                    controller_ListEmployee(listaEmpleados);
                    printf("\n\n");

                }
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            printf("\n\n");
            system("pause");
            break;

        case 8:
            if(!ll_isEmpty(listaEmpleados))
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            system("pause");
            break;

        case 9:
            if(ll_isEmpty(listaEmpleados))
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********");
            }
            system("pause");
            break;

        case 10:
            printf("\nSi sale del programa se perderan todas las modificaciones que no hayan sido guardadas.\nDesea continuar? s/n: ");
            fflush(stdin);
            scanf("%c", &option);
            if(option=='s')
            {
                printf("\n\n//----------- Saliendo ------------//\n\n");
            }
            break;
        }
    }
    while(option != 's');

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

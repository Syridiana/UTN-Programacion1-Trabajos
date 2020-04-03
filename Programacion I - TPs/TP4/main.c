#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funcionesValidacion.h"

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
    char optionClear = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* segundaListaEmpleados=NULL;

    do
    {
        system("cls");

        switch(controller_menu())
        {

        case 1:
            if(!ll_isEmpty(listaEmpleados) && listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
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
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
            {
                printf("\nSi borra la LinkedList se perderan todas las modificaciones que no hayan sido guardadas.\nDesea continuar? s/n: ");
                fflush(stdin);
                scanf("%c", &optionClear);
                if(optionClear=='s')
                {
                    if (ll_clear(listaEmpleados)==0)
                    {
                        printf("\nLinkedList vaciada con exito.\n\n");

                    }
                    else
                    {
                        printf("\nNo se ha conseguido vaciar la LinkedList\n\n");
                    }
                }
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            printf("\n\n");
            system("pause");
            break;
        case 11:
            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
            {
                printf("\n\n******* Clonando LinkedList ******\n");
                segundaListaEmpleados = ll_clone(listaEmpleados);
                if(ll_containsAll(listaEmpleados, segundaListaEmpleados)==1)
                {
                    printf("\nLista clonada correctamente\n\n");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    controller_ListEmployee(segundaListaEmpleados);
                    printf("\n\n********* Nueva Lista ********\n");
                }
                else
                {
                    printf("\nNo se clono correctamente la lista\n");
                }
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            printf("\n\n");
            system("pause");
            break;

        case 12:

            if(!ll_isEmpty(listaEmpleados)&& listaEmpleados!=NULL)
            {
                segundaListaEmpleados = controller_subLista(listaEmpleados);
            }
            else
            {
                printf("\n********* Error. Debe cargar un archivo primero. *********\n\n");
            }
            printf("\n\n");
            system("pause");
            break;

        case 20:
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

    ll_clear(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

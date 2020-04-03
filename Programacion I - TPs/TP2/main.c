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


int main()
{
    //Inicio listas de empleados y de sectores
    eEmployee listaDeEmpleados[TAMANIOEMPLEADOS];
    eSector listaDeSectores[TAMANIOSECTOR];

    //Inicializo todas las posiciones del array de empleados en isEmpty=1
    initEmployees(listaDeEmpleados, TAMANIOEMPLEADOS);

    //Hardcodeos
    harcodearSectores(listaDeSectores, TAMANIOSECTOR);


    //Defino variables a utilizar en el main
    int opcion;
    int idEmpleado;
    int indexEmpleado;
    char confirma='n';
    int opcionOrdernar;
    int proximoIdAAsignar=101;
    int opcionAModificar;
    int opcionInformes;
    float sumaTotalSalarios;
    float promedioSalarios;
    int flagCargoAlgunEmpleado=0;



    //Menu de opciones y switch
    do
    {
        system("cls");
        printf("1.Alta empleado\n2.Modificar empleado\n3.Baja de empleado\n4.Informar\n9.Salir\n\nIngrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);


        switch(opcion)
        {

        //Alta empleados
        case 1:
            system("cls");
            printf("SECTORES");
            if(cargarEmpleado(listaDeEmpleados, TAMANIOEMPLEADOS, listaDeSectores, TAMANIOSECTOR, proximoIdAAsignar)==0)
            {
                proximoIdAAsignar++;
                flagCargoAlgunEmpleado=1;
            }

            break;


        //Modificar empleados
        case 2:


            if(flagCargoAlgunEmpleado)
            {
                system("cls");
                printEmployees(listaDeEmpleados, TAMANIOEMPLEADOS); //imprimo empleados para que el usuario seleccione
                getEntero(&idEmpleado, "\n\nIngrese id de Empleado a modificar: ", "\nError. Ingrese un id valido.\n",0, 20000, 10);
                indexEmpleado = findEmployeeById(listaDeEmpleados, TAMANIOEMPLEADOS, idEmpleado);

                system("cls");

                if(indexEmpleado>-1)
                {
                    printf("ID          APELLIDO           NOMBRE      SALARIO     SECTOR");
                    mostrarUnSoloEmployee(listaDeEmpleados[indexEmpleado], listaDeSectores, TAMANIOSECTOR); //Muestro al empleado seleccionado
                    getEntero(&opcionAModificar, "\n\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n\nQue desea modificar?: ", "\nError. Ingrese una opcion valida.\n",1, 4, 10); //Solicito que campo se quiere modificar

                    listaDeEmpleados[indexEmpleado] = modificarEmployee(listaDeEmpleados[indexEmpleado], opcionAModificar, listaDeSectores, TAMANIOSECTOR); //Modifico el campo y muestro al empleado

                    printf("\n\n");
                }
                else
                {
                    printf("No existe un empleado con esa id.\n\n");

                }

            }
            else
            {
                printf("\nError. Debe cargar al menos un empleado primero.\n\n");
            }

            break;


        //Baja de empleados
        case 3:


            if(flagCargoAlgunEmpleado)
            {
                system("cls");
                mostrarEmployeesConNombreDelSector(listaDeEmpleados, TAMANIOEMPLEADOS, listaDeSectores, TAMANIOSECTOR); //Muestro lista de empleados asi el usuario selecciona cual quiere dar de baja
                getEntero(&idEmpleado, "\n\nIngrese id de Empleado a dar de baja: ", "\nError. Ingrese un id valido.\n",0, 20000, 10);

                printf("\n");
                indexEmpleado = findEmployeeById(listaDeEmpleados, TAMANIOEMPLEADOS, idEmpleado);
                mostrarUnSoloEmployee(listaDeEmpleados[indexEmpleado], listaDeSectores, TAMANIOSECTOR);


                printf("\n\nSeguro desea dar de baja? s/n: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma=='s')
                {
                    removeEmployee(listaDeEmpleados, TAMANIOEMPLEADOS, idEmpleado);
                    printf("\n\nLegajo de empleado removido con exito.\n\n");
                }
            }
            else
            {
                printf("\nError. Debe cargar al menos un empleado primero.\n\n");
            }

            break;

        //Informar
        case 4:

            if(flagCargoAlgunEmpleado)
            {
                system("cls");
                getEntero(&opcionInformes, "\n1.Listado de empleados ordenados por apellido y sector.\n2.Total y promedio de los salarios y cuantos empleados estan por encima del salario promedio.\n\nElija una opcion: ",
                          "\nError. Ingrese una opcion valida.\n",1, 2, 10);


                switch(opcionInformes)
                {
                case 1:
                    system("cls");
                    printf("1.Ordenar de forma ascendente\n2.Ordenar de forma descente\n\n");
                    getEntero(&opcionOrdernar, "Elija una opcion: ", "\nError. Ingrese una opcion valida.\n",1, 2, 10);

                    if(opcionOrdernar==1)
                    {
                        sortEmployees(listaDeEmpleados, TAMANIOEMPLEADOS, UP);
                    }
                    else
                    {
                        sortEmployees(listaDeEmpleados, TAMANIOEMPLEADOS, DOWN);
                    }

                    system("cls");
                    mostrarEmployeesConNombreDelSector(listaDeEmpleados, TAMANIOEMPLEADOS, listaDeSectores, TAMANIOSECTOR);

                    printf("\n\n");

                    break;

                case 2:
                    sumaTotalSalarios = sumaSalarios(listaDeEmpleados, TAMANIOEMPLEADOS);
                    promedioSalarios = promedioDeSalarios(sumaTotalSalarios, TAMANIOEMPLEADOS, listaDeEmpleados);

                    system("cls");
                    printf("\n\nTotal de salarios: %f\n\nPromedio de salarios: %f\n", sumaTotalSalarios, promedioSalarios);
                    printf("\n\nEmpleados con salarios sobre el promedio: \n");
                    printf("ID          APELLIDO           NOMBRE      SALARIO     SECTOR");
                    buscarYmostrarEmployeesSobrePromedio(listaDeEmpleados, promedioSalarios, TAMANIOEMPLEADOS, listaDeSectores, TAMANIOSECTOR);
                    printf("\n\n");

                    break;
                }

            }
            else
            {
                printf("\nError. Debe cargar al menos un empleado primero.\n\n");
            }
            break;

        //Salir
        case 9:

            system("cls");

            printf("\nSaliendo del programa...\n\n");

            break;

        default:
            printf("\nOpcion Invalida!\n\n");


        }
        system("pause");
    }
    while(opcion!=9);



    return 0;
}















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


int firstEmptyIndexInEmployeeList(eEmployee listaDeEmpleados[], int tamanioEmpleados)
{
    int index=-1;
    int i;

    for(i=0; i<tamanioEmpleados; i++)
    {
        if(listaDeEmpleados[i].isEmpty == 1)
        {
            index=i;
            break;
        }
    }
    return index;



}



int addEmployee(eEmployee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int ret=-1;
    int primerIndexLibre = firstEmptyIndexInEmployeeList(list, len);

    if(primerIndexLibre>-1)
    {
        list[primerIndexLibre].id = id;
        strcpy(list[primerIndexLibre].name,name);
        strcpy(list[primerIndexLibre].lastName,lastName);
        list[primerIndexLibre].salary = salary;
        list[primerIndexLibre].sector = sector;
        list[primerIndexLibre].isEmpty = 0;
        ret = 0;
    }

    return ret;
}



int cargarEmpleado(eEmployee listaEmpleados[],int tamanioEmpleados,eSector listaSectores[], int tamanioSectores, int id)
{
    int numeroSector;
    int i;
    char nombre[51];
    char apellido[51];
    float salario;
    int ret;

    for(i=0; i<tamanioSectores; i++)
    {

        mostrarSectores(listaSectores, tamanioSectores);
        break;

    }

    getEntero(&numeroSector,"\n\nIngrese numero de sector: ","\nError. Ingrese un id valido.\n\n",1,7,10);
    getFlotante(&salario, "\nIngrese salario: ", "Error. Ingrese un salario valido.\n\n", 0, 500000000, 10);

    printf(("\nIngrese nombre del empleado: "));
    fflush(stdin);
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strlen(nombre)-1]='\0';

    printf(("\nIngrese apellido del empleado: "));
    fflush(stdin);
    fgets(apellido,sizeof(apellido),stdin);
    apellido[strlen(apellido)-1]='\0';

    ret = addEmployee(listaEmpleados, TAMANIOEMPLEADOS, id, nombre, apellido, salario, numeroSector);

    return ret;


}




int initEmployees(eEmployee listaEmpleados[], int tamanioEmpleados)
{
    for(int i=0; i<tamanioEmpleados; i++)
    {
        listaEmpleados[i].isEmpty=1;
    }
    return 0;
}



int mostrarUnSoloEmployee(eEmployee empleado, eSector listaSectores[],int tamanioSectores)
{
    int ret=0;

    char nombreSector[20];
    if(empleado.isEmpty==0)
    {

        cargarNombreDelSector(listaSectores, empleado.sector, nombreSector, tamanioSectores);
        printf("\n%4.4d %15s %15s %15.3f     %s",
               empleado.id,
               empleado.lastName,
               empleado.name,
               empleado.salary,
               nombreSector);
        ret = 1;
    }

    return ret;
}




int mostrarEmployeesConNombreDelSector(eEmployee listaEmpleados[], int tamanioEmpleados, eSector sectores[], int tamanioSectores)
{
    int i;
    int ret=0;
    printf("  ID         APELLIDO          NOMBRE      SALARIO       SECTOR\n");
    for(i=0; i<tamanioEmpleados; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            mostrarUnSoloEmployee(listaEmpleados[i], sectores, tamanioSectores);
            ret=1;
        }

    }

    return ret;
}




int findEmployeeById(eEmployee* list, int len, int id)
{
    int ret=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {


            if(list[i].id == id)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}


int removeEmployee(eEmployee* list, int len, int id)
{
    int ret=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(id==list[i].id)
        {
            list[i].isEmpty=1;
            ret = 0;
            break;
        }
    }

    return ret;

}



int sortEmployees(eEmployee* list, int len, int order)
{
    int i;
    int j;
    eEmployee aux;

    if(order)
    {


        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {

                if(list[i].sector>list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else
                {
                    if(list[i].sector==list[j].sector)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)>0)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }

        }
    }
    else
    {

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {

                if(list[i].sector<list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                else
                {
                    if(list[i].sector==list[j].sector)
                    {
                        if(strcmp(list[i].lastName, list[j].lastName)<0)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                }
            }

        }

    }
    return 0;

}


int printEmployees(eEmployee* list, int length)
{
    int i;
    int ret=0;
    printf("ID          APELLIDO           NOMBRE      SALARIO      CODIGO DE SECTOR");

    for(i=0; i<length; i++)
    {

        if(list[i].isEmpty==0)
        {
            ret = 1;

            printf("\n%4.4d %15s %15s %15.3f %10.4d",
                   list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector
                  );
        }
    }
    printf("\n\n");

    return ret;

}




int cargarNombreDelSector(eSector listaSectores[], int idSector, char vectorParaNombreDelSector[], int tamanioListaSectores)
{
    int i;
    int ret=0;

    for(i=0; i<tamanioListaSectores; i++)
    {
        if((listaSectores[i].id == idSector) && listaSectores[i].isEmpty==0)
        {
            ret = 1;
            strcpy(vectorParaNombreDelSector, listaSectores[i].name);
            break;
        }
    }

    return ret;

}




int mostrarSectores(eSector listaSectores[], int tamanioSectores)
{
    int i;
    int ret=0;

    for(i=0; i<tamanioSectores; i++)
    {
        if(listaSectores[i].isEmpty==0)
        {
            printf("\n%d. %s", listaSectores[i].id, listaSectores[i].name);
            ret=1;
        }

    }

    return ret;
}



eEmployee modificarEmployee(eEmployee empleado, int opcionAModificar, eSector sectores[], int tamanioSectores)
{

    char apellido[51];
    char nombre[51];
    float salario;
    int numeroSector;
    eEmployee employeeAuxiliar = empleado;

    switch(opcionAModificar)
    {
    case 1:
        printf(("\nIngrese nombre del empleado: "));
        fflush(stdin);
        fgets(nombre,sizeof(nombre),stdin);
        nombre[strlen(nombre)-1]='\0';
        strcpy(employeeAuxiliar.name, nombre);
        break;

    case 2:
        printf(("\nIngrese apellido del empleado: "));
        fflush(stdin);
        fgets(apellido,sizeof(apellido),stdin);
        apellido[strlen(apellido)-1]='\0';
        strcpy(employeeAuxiliar.lastName, apellido);
        break;

    case 3:
        getFlotante(&salario, "\nIngrese salario: ", "\Error. Ingrese un valor valido\n", 0, 1000000, 10);
        employeeAuxiliar.salary = salario;
        break;
    case 4:
        system("cls");
        mostrarSectores(sectores, tamanioSectores);
        getEntero(&numeroSector,"\n\nIngrese numero de sector: ","\nError. Ingrese un id valido.\n\n",1,7,10);
        employeeAuxiliar.sector = numeroSector;
        break;
    }
    printf("\n\n******Modificacion realizada*****\n\nID          APELLIDO           NOMBRE      SALARIO     SECTOR");
    mostrarUnSoloEmployee(employeeAuxiliar, sectores, tamanioSectores);

    return employeeAuxiliar;
}


float sumaSalarios(eEmployee listaEmpleados[], int tamanioEmpleados)
{
    float sumaDeSalarios=0;
    int i;

    for(i=0; i<tamanioEmpleados; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            sumaDeSalarios+=listaEmpleados[i].salary;

        }
    }

    return sumaDeSalarios;
}

float promedioDeSalarios(float sumaTotalSalarios, int tamanioEmpleados, eEmployee listaEmpleados[])
{
    int contadorEmpleadosActivos=0;
    int i;

    float promedioSalary;
    for(i=0; i<tamanioEmpleados; i++)
    {
        if(listaEmpleados[i].isEmpty==0)
        {
            contadorEmpleadosActivos++;

        }

    }
    promedioSalary = sumaTotalSalarios / contadorEmpleadosActivos;


    return promedioSalary;
}


int buscarYmostrarEmployeesSobrePromedio(eEmployee listaEmpleados[], float promedio, int tamanioEmpleados, eSector sectores[], int tamanioSectores)
{
    int ret=0;
    int i;
    for(i=0; i<tamanioEmpleados; i++)
    {
        if(listaEmpleados[i].salary>promedio && listaEmpleados[i].isEmpty==0)
        {
            mostrarUnSoloEmployee(listaEmpleados[i], sectores, tamanioSectores);
            ret =1;
        }
    }

    return ret;
}

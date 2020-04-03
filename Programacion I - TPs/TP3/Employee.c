#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"


Employee* employee_new(void)
{
    Employee* employee = (Employee*) malloc(sizeof(Employee));
    if(employee!=NULL)
    {
        employee->id=0;
        strcpy(employee->nombre, " ");
        employee->horasTrabajadas=0;
        employee->sueldo=0;
    }
    return employee;
}



int employee_setId(Employee* this,int id)
{
    int ret=0;
    if(this != NULL && id>=1 && id<= 2000 )
    {
        this->id = id;
        ret=1;
    }
    return ret;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=0;

    if (this !=NULL && horasTrabajadas>0 && horasTrabajadas<=10000)
    {
        this->horasTrabajadas = horasTrabajadas;
        ret=1;
    }

    return ret;

}


int employee_setNombre(Employee* this,char* nombre)
{

    int ret=0;

    if(this !=NULL && strlen(nombre)>2)
    {
        strcpy(this->nombre, nombre);
        ret=1;
    }

    return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ret=0;

    if (this!=NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        ret=1;
    }

    return ret;
}



void employee_toString(Employee* empleado)
{
    printf("\nId: %d -- Nombre: %s -- Horas Trabajadas: %d -- Sueldo: %d", empleado->id, empleado->nombre,
           empleado->horasTrabajadas, empleado->sueldo);
}



int employee_getId(Employee* this,int* id)
{
    int ret=0;
    if(this!=NULL)
    {
        *id = this->id;
        ret=1;
    }

    return ret;

}



int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret=0;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret=1;

    }
    return ret;
}



int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret=0;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        ret=1;
    }
    return ret;
}



int employee_getNombre(Employee* this,char* nombre)
{
    int ret=0;
    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);

        ret=1;
    }
    return ret;
}


int employee_mostrarUnEmpleado(Employee* empleado)
{
    int ret=0;
    int id;
    int horas;
    int sueldo;
    char nombre[128];

    if(empleado!=NULL  && employee_getId(empleado, &id) && employee_getNombre(empleado, nombre)
       && employee_getHorasTrabajadas(empleado, &horas) && employee_getSueldo(empleado, &sueldo)  )
    {
        printf("\n%5d   %20s      %10d      %10d", id, nombre, horas, sueldo);
        ret=1;
    }

    return ret;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* empleado=NULL;

        if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
        {
            empleado = employee_new();

            if(empleado != NULL)
            {
                if( !(employee_setId(empleado, atoi(idStr)) && employee_setNombre(empleado, nombreStr)
                      && employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr))
                      && employee_setSueldo(empleado, atoi(sueldoStr)) ))
                {
                        employee_delete(empleado);
                        empleado = NULL;
                }
            }
        }

    return empleado;
}



void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

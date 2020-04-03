#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret=0;
    int cant;
    char buffer[4][128];
    Employee* empleado=NULL;


    if(pFile!=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant<4)
            {
                break;
            }
            else
            {
                empleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(empleado !=NULL)
                {
                    ll_add(pArrayListEmployee, empleado);
                    ret=1;
                }

            }
        }
    }

    return ret;
}




int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret=0;
    Employee* empleado=NULL;

    if(pFile !=NULL && pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            empleado=employee_new();
            if(empleado!=NULL)
            {
                if(fread(empleado, sizeof(Employee), 1, pFile))
                {
                    ll_add(pArrayListEmployee, empleado);
                    ret=1;
                }

            }

        }
    }

    return ret;
}

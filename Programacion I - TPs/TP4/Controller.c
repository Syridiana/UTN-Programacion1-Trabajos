#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesValidacion.h"
#include "parser.h"
#include "Controller.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;
    FILE* miArchivo=fopen(path, "r");

    if(miArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        if(parser_EmployeeFromText(miArchivo, pArrayListEmployee))
        {
            ret=1;
            printf("\n\n****** Datos cargados de data.csv correctamente ******\n\n");
        }
    }
    else
    {
        printf("\n/------ No se pudo cargar el archivo. -------/\n");
    }

    fclose(miArchivo);
    return ret;
}




int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;
    FILE* miArchivo = fopen(path, "rb");

    if(path!=NULL && miArchivo!=NULL)
    {
        if(parser_EmployeeFromBinary(miArchivo, pArrayListEmployee))
        {
            ret=1;
            printf("\n\n****** Datos cargados de data.bin correctamente ******\n\n");
        }
    }
    else
    {
        printf("\n/------ No se pudo cargar el archivo. -------/\n");
    }

    fclose(miArchivo);
    return ret;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    Employee* empleado=employee_new();
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int reintentos=3;

    if(pArrayListEmployee!=NULL && empleado!=NULL)
    {

        pedirTexto(nombre, "\nIngrese nombre: ", "Error. Ingrese un nombre valido: ", 3);
        getEntero(&horasTrabajadas, "\nIngrese Horas Trabajadas: ", "Error. Ingrese un monto valido: ", 0, 25000, 3);
        getEntero(&sueldo, "\nIngrese Sueldo: ", "Error. Ingrese un monto valido: ", 1, 500000, 3);

        if( ( (
                    employee_setId(empleado, -1) &&
                    employee_setNombre(empleado, nombre) &&
                    employee_setHorasTrabajadas(empleado, horasTrabajadas) &&
                    employee_setSueldo(empleado, sueldo) ) == 1 ) && reintentos>0 )
        {
            ll_add(pArrayListEmployee, empleado);
            printf("\n\n************ Carga exitosa ***********\n\n");
            printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n");
            employee_mostrarUnEmpleado(empleado);
            printf("\n\n");
            ret=1;
        }
    }

    return ret;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int idEmpleadoAModificar;
    int index;
    int reintentos=3;
    int tamanioArray;
    int i;
    int idEmpleado;
    int opcionMenu;
    int nuevoValorEntero;
    char nuevoNombre[128];
    char confirma='n';
    Employee* empleado=NULL;

    controller_ListEmployee(pArrayListEmployee);

    printf("\n");
    getEntero(&idEmpleadoAModificar, "\nIngrese Id de empleado a modificar: ", "Error. Ingrese un monto valido.", 1, 500000, 3);
    index = controller_existeId(pArrayListEmployee, idEmpleadoAModificar);

    while(index<0 && reintentos>0)
    {
        printf("\n//--------- No existe ningun empleado con ese Id --------//\n");
        getEntero(&idEmpleadoAModificar, "\nIngrese Id de empleado a modificar: ", "Error. Ingrese un monto valido.", 1, 500000, 3);
        index = controller_existeId(pArrayListEmployee, idEmpleadoAModificar);
        reintentos--;
    }

    if(reintentos>0 && index>=0)
    {
        tamanioArray = ll_len(pArrayListEmployee);
        for(i=0; i<tamanioArray; i++)
        {
            empleado = ll_get(pArrayListEmployee, index);
            employee_getId(empleado, &idEmpleado);

            if(empleado!=NULL && idEmpleado==idEmpleadoAModificar)
            {
                system("cls");
                printf("  ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n");
                employee_mostrarUnEmpleado(empleado);
                getEntero(&opcionMenu,"\n\nSeleccione que desea modificar:\n\n1.Nombre\n2.Horas Trabajadas\n3.Sueldo\n4.Salir\n\n", "Error. Ingrese un numero valido", 1, 5, 3 );

                switch(opcionMenu)
                {
                case 1:
                    if(pedirTexto(nuevoNombre, "\nIngrese nuevo nombre: ", "Error. Ingrese un nombre valido.", 3))
                    {
                        printf("\nConfirma que desea aplicar cambio? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirma);

                        if(confirma == 's' && employee_setNombre(empleado, nuevoNombre))
                        {

                            printf("\n//------ Modificacion realizada con exito -----//\n\n");
                            printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n");
                            employee_mostrarUnEmpleado(empleado);
                            printf("\n\n");
                            system("pause");
                            ret=1;
                        }
                    }
                    break;

                case 2:
                    if(getEntero(&nuevoValorEntero, "\nIngrese nuevo valor para Horas Trabajadas: ", "Error. Ingrese un monto valido.", 1, 500000, 3))
                    {
                        printf("\nConfirma que desea aplicar cambio? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirma);

                        if(confirma == 's' && employee_setHorasTrabajadas(empleado, nuevoValorEntero))
                        {
                            printf("\n//------ Modificacion realizada con exito -----//\n\n");
                            printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n");
                            employee_mostrarUnEmpleado(empleado);
                            printf("\n\n");
                            system("pause");
                            ret=1;
                        }
                    }
                    break;

                case 3:
                    if(getEntero(&nuevoValorEntero, "\nIngrese nuevo Sueldo: ", "Error. Ingrese un monto valido.", 1, 500000, 3))
                    {
                        printf("\nConfirma que desea aplicar cambio? s/n: ");
                        fflush(stdin);
                        scanf("%c", &confirma);

                        if(confirma == 's' && employee_setSueldo(empleado, nuevoValorEntero))
                        {
                            printf("\n//------ Modificacion realizada con exito -----//\n\n");
                            printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n\n");
                            employee_mostrarUnEmpleado(empleado);
                            printf("\n\n");
                            system("pause");
                            ret=1;
                        }
                    }
                    break;

                case 4:
                    return ret;
                    break;
                }
            }
        }
    }

    return ret;
}




int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int idEmpleadoAEliminar;
    int index;
    int reintentos=3;
    char confirma='n';
    Employee* empleado=NULL;

    controller_ListEmployee(pArrayListEmployee);

    printf("\n");
    getEntero(&idEmpleadoAEliminar, "\nIngrese Id de empleado a dar de baja: ", "Error. Ingrese un Id valido.", 1, 500000, 3);
    index = controller_existeId(pArrayListEmployee, idEmpleadoAEliminar);

    while(index<0 && reintentos>0)
    {
        printf("\n//--------- No existe ningun empleado con ese Id --------//\n");
        getEntero(&idEmpleadoAEliminar, "\nIngrese Id de empleado a dar de baja: ", "Error. Ingrese un Id valido.", 1, 500000, 3);
        index = controller_existeId(pArrayListEmployee, idEmpleadoAEliminar);
        reintentos--;
    }

    system("cls");
    empleado = ll_get(pArrayListEmployee, index);

    if(empleado!=NULL)
    {
        printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n");
        employee_mostrarUnEmpleado(empleado);
    }

    printf("\n\nConfirma que desea dar de baja? s/n: ");
    fflush(stdin);
    scanf("%c", &confirma);

    if(reintentos>0 && index>=0 && confirma=='s')
    {
        if((ll_remove(pArrayListEmployee, index))==0)
        {
            printf("\n*** Baja realizada con exito ***");
            ret=1;
        }
    }

    return ret;
}




int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int largo = ll_len(pArrayListEmployee);
    int i;
    int contador;

    if(pArrayListEmployee!=NULL && !ll_isEmpty(pArrayListEmployee))
    {
        for(i=0; i<largo; i++)
        {
            employee_mostrarUnEmpleado((Employee*) ll_get(pArrayListEmployee, i));
            contador++;
        }
        if(contador==ll_len(pArrayListEmployee))
        {
            ret=1;
        }
    }
    return ret;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;
    int orden;
    int opcionOrdenar;

    if(pArrayListEmployee!=NULL)
    {
        printf("*** Ordenar empleados ****\n\n1.Por Sueldo\n2.Por Horas Trabajadas\n3.Por Nombre\n4.Por Id\n");
        getEntero(&opcionOrdenar, "\nSeleccione una opcion: ", "Error. Ingrese un numero valido", 1, 4, 3);

        printf("\n0. Orden Descendente\n1. Orden Ascendente\n");
        getEntero(&orden, "\nSeleccione una opcion: ", "\nError. Ingrese una opcion valida", 0, 1, 3);

        switch(opcionOrdenar)
        {
        case 1:
            printf("\n\n****** Ordenando Empleados ******\n\nPuede tomar algunos minutos...\n\n");
            if (ll_sort(pArrayListEmployee, controller_funcionOrdenarPorSueldo, orden)==0)
            {
                ret = 1;
            }
            break;

        case 2:
            printf("\n\n****** Ordenando Empleados ******\n\nPuede tomar algunos minutos...\n\n");
            if (ll_sort(pArrayListEmployee, controller_funcionOrdenarPorHoras, orden)==0)
            {
                ret = 1;
            }
            break;

        case 3:
            printf("\n\n****** Ordenando Empleados ******\n\nPuede tomar algunos minutos...\n\n");
            if (ll_sort(pArrayListEmployee, controller_funcionOrdenarPorNombre, orden)==0)
            {
                ret = 1;
            }
            break;

        case 4:
            printf("\n\n****** Ordenando Empleados ******\n\nPuede tomar algunos minutos...\n\n");
            if (ll_sort(pArrayListEmployee, controller_funcionOrdenarPorId, orden)==0)
            {
                ret = 1;
            }
            break;
        }
    }

    return ret;
}



int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;
    int i;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int contador=0;
    FILE* miArchivo=NULL;
    int tamanio;
    Employee* auxEmpleado=employee_new();

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        tamanio = ll_len(pArrayListEmployee);
        miArchivo = fopen(path, "w");

        if(miArchivo!=NULL)
        {
            for(i=0; i<tamanio; i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                employee_getId(auxEmpleado, &id);
                employee_getNombre(auxEmpleado, nombre);
                employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas);
                employee_getSueldo(auxEmpleado, &sueldo);
                fprintf(miArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
                contador++;
            }

            fclose(miArchivo);
            if(contador==tamanio)
            {
                ret=1;
                printf("\n\n****** Datos guardados en data.bin correctamente ******\n\n");
            }
        }
    }
    return ret;
}




int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;
    int i;
    int contador=0;
    int tamanio = ll_len(pArrayListEmployee);

    FILE* miArchivo=fopen(path, "wb");

    if(miArchivo!=NULL && pArrayListEmployee!=NULL)
    {
        for(i=0; i<tamanio; i++)
        {
            contador += fwrite(ll_get(pArrayListEmployee, i), sizeof(Employee), 1, miArchivo);
        }
        if(contador==tamanio)
        {
            ret=1;
            printf("\n\n****** Datos guardados en data.bin correctamente ******\n\n");
        }
    }
    fclose(miArchivo);
    return ret;
}




int controller_menu(void)
{
    int opcion;

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).");
    printf("\n10. Vaciar LinkedList");
    printf("\n11. Clonar LinkedList");
    printf("\n12. Clonar una parte de LinkedList");
    printf("\n20. Salir");

    getEntero(&opcion, "\n\nIngrese una opcion: ", "\nError. Ingrese una opcion valida", 1, 20, 10);

    return opcion;

}




int controller_existeId(LinkedList* pArrayListEmployee, int id)
{
    int i;
    int index=-1;
    int idEmpleado;
    Employee* empleado=NULL;
    int tamanio = ll_len(pArrayListEmployee);

    for(i=0; i<tamanio; i++)
    {
        empleado = ll_get(pArrayListEmployee, i);
        employee_getId(empleado, &idEmpleado);
        if(idEmpleado == id)
        {
            index = ll_indexOf(pArrayListEmployee, empleado);
        }
    }
    return index;
}


int controller_funcionOrdenarPorSueldo(void* empleado1, void* empleado2)
{

    int sueldo1;
    int sueldo2;

    Employee* emp1 = (Employee*) empleado1;
    Employee* emp2 = (Employee*) empleado2;

    employee_getSueldo(emp1, &sueldo1);
    employee_getSueldo(emp2, &sueldo2);

    if(sueldo1>sueldo2)
    {
        return 1;
    }
    if(sueldo1<sueldo2)
    {
        return -1;
    }
    return 0;
}


int controller_vaciarLinkedList(LinkedList* pArrayListEmployee)
{
    int ret;

    ret = ll_deleteLinkedList(pArrayListEmployee);

    return ret;
}


int controller_funcionOrdenarPorId(void* empleado1, void* empleado2)
{
    int id1;
    int id2;

    Employee* emp1 = (Employee*) empleado1;
    Employee* emp2 = (Employee*) empleado2;

    employee_getId(emp1, &id1);
    employee_getId(emp2, &id2);

    if(id1>id2)
    {
        return 1;
    }
    if(id1<id2)
    {
        return -1;
    }

    return 0;

}


int controller_funcionOrdenarPorHoras(void* empleado1, void* empleado2)
{
    int horas1;
    int horas2;

    Employee* emp1 = (Employee*) empleado1;
    Employee* emp2 = (Employee*) empleado2;

    employee_getHorasTrabajadas(emp1, &horas1);
    employee_getHorasTrabajadas(emp2, &horas2);

    if(horas1>horas2)
    {
        return 1;
    }
    if(horas1<horas2)
    {
        return -1;
    }
    return 0;
}


int controller_funcionOrdenarPorNombre(void* empleado1, void* empleado2)
{
    char nombre1[128];
    char nombre2[128];

    Employee* emp1 = (Employee*) empleado1;
    Employee* emp2 = (Employee*) empleado2;

    employee_getNombre(emp1, nombre1);
    employee_getNombre(emp2, nombre2);

    if((strcmp(nombre1, nombre2))>0)
    {
        return 1;
    }
    if((strcmp(nombre1, nombre2))<0)
    {
        return -1;
    }
    return 0;
}

LinkedList* controller_subLista(LinkedList* pArrayListEmployee)
{
    int nuevaListaFrom;
    int nuevaListaTo;
    int reintentos=3;
    int existeId1;
    int existeId2;
    LinkedList* listaAux=NULL;

    printf("\nAguarde unos minutos...");
    if(ll_sort(pArrayListEmployee, controller_funcionOrdenarPorId, 1)==0)
    {

        system("cls");
        printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\n\n");
        getEntero(&nuevaListaFrom, "\nSeleccione el id desde donde comenzar a copiar la nueva lista: ", "\nError. Ingrese un valor valido", 1, 500000, 3);
        existeId1 = controller_existeId(pArrayListEmployee, nuevaListaFrom);
        printf("%d--\n", existeId1);

        while(reintentos>0 && existeId1<0)
        {
            printf("\nError. Ingrese un numero que se encuentre en la lista\n");
            getEntero(&nuevaListaFrom, "\nSeleccione el id desde donde comenzar a copiar la nueva lista: ", "\nError. Ingrese un valor valido", 1, 500000, 3);
            existeId1 = controller_existeId(pArrayListEmployee, nuevaListaFrom);
            reintentos--;

        }

        getEntero(&nuevaListaTo, "\nSeleccione el id desde donde terminar a copiar la nueva lista (no inclusive): ", "\nError. Ingrese un valor valido", 1, 500000, 3);
        existeId2 = controller_existeId(pArrayListEmployee, nuevaListaTo);

        while(reintentos>0 && ( nuevaListaTo<=nuevaListaFrom || existeId2<0))
        {
            printf("\nError. Ingrese un numero que se encuentre en la lista y que sea mayor al anterior\n");
            getEntero(&nuevaListaFrom, "\nSeleccione el id desde donde comenzar a copiar la nueva lista: ", "\nError. Ingrese un valor valido", 1, 500000, 3);
            existeId2 = controller_existeId(pArrayListEmployee, nuevaListaTo);
            reintentos--;
        }

        if(reintentos>0)
        {

            listaAux = ll_newLinkedList();

            if(listaAux!=NULL)
            {
                listaAux = ll_subList(pArrayListEmployee, existeId1, existeId2);

                if(ll_containsAll(pArrayListEmployee, listaAux))
                {
                    printf("\n***** Lista copiada con exito! ******");
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    printf("    ID                NOMBRE      HORAS TRABAJADAS     SUELDO\n");
                    controller_ListEmployee(listaAux);
                    printf("\n\n***** Nueva lista ******");
                }
                else
                {
                    printf("\n********* Ha ocurrido un error. *********\n\n");
                    printf("\n\n");
                    system("pause");
                }
            }
        }


    }
    else
    {
        printf("\n********* Ha ocurrido un error. *********\n\n");
    }

    return listaAux;

}



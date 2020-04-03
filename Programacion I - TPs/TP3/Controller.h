#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 sino se pudo cargar el archivo, 1 si se pudo
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 sino se pudo cargar el archivo, 1 si se pudo
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si se agrego correctamente, 0 sino
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si se realizo correctamente la modificacion, 0 sino
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si se realizo la baja correctamente, 0 sino
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);



/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si se mostraron todos los empleados, 0 sino
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si se realizo correctamente el ordenamiento, 0 sino
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int, devuelve 1 si se guardaron todos los empleados correctamente, 0 sino
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int, devuelve 1 si se guardaron todos los empleados correctamente, 0 sino
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


/** \brief Menu de opciones
 *
 * \param void
 * \return int, devuelve el numero de la opcion seleccionada
 *
 */
int controller_menu(void);


/** \brief Busca si el Id solicitado ya existe en la LinkedList
 *
 * \param pArrayListEmployee LinkedList*
 * \param int, id a buscar
 * \return int, devuelve el indice donde se encontro el Id buscado y -1 si no lo encontro
 *
 */
int controller_existeId(LinkedList* pArrayListEmployee, int id);



/** \brief Compara los valores de sueldo de dos empleados
 *
 * \param Puntero a void para cargar un empleado a comparar
 * \param Puntero a void para cargar un empleado a comparar
 * \return int, devuelve 1 si el sueldo del primer empleado es mayor y -1 si es menor, 0 si son iguales
 *
 */
int controller_funcionOrdenarPorSueldo(void* empleado1, void* empleado2);



/** \brief Compara el nombre de dos empleados de forma alfabetica
 *
 * \param Puntero a void para cargar un empleado a comparar
 * \param Puntero a void para cargar un empleado a comparar
 * \return int, devuelve 1 si el nombre del primer empleado esta antes en el alfabato y -1 si esta despues, 0 si son iguales
 *
 */
int controller_funcionOrdenarPorNombre(void* empleado1, void* empleado2);


/** \brief Compara los valores de id de dos empleados
 *
 * \param Puntero a void para cargar un empleado a comparar
 * \param Puntero a void para cargar un empleado a comparar
 * \return int, devuelve 1 si el Id del primer empleado es mayor y -1 si es menor, 0 si son iguales
 *
 */
int controller_funcionOrdenarPorId(void* empleado1, void* empleado2);



/** \brief Compara los valores de horas trabajadas de dos empleados
 *
 * \param Puntero a void para cargar un empleado a comparar
 * \param Puntero a void para cargar un empleado a comparar
 * \return int, devuelve 1 si las horas del primer empleado son mayores y -1 si es menor, 0 si son iguales
 *
 */
int controller_funcionOrdenarPorHoras(void* empleado1, void* empleado2);

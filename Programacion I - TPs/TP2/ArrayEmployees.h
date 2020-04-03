#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defino estructua eEmployee
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;


//Defino estructura eSector
typedef struct
{
    int id;
    char name[20];
    int isEmpty;

} eSector;

/** \brief firstEmptyIndexInEmployeeList busca el primer indice libre en el array de empleados (osea que tenga el campo "isEmpty" en 1)
 *
 * \param recibe el array de empleados
 * \param recibe el tamanio del array de empleados
 * \return devuelve el numero del primer indice libre, no hay mas espacio libre devuelve -1
 *
 */
int firstEmptyIndexInEmployeeList(eEmployee listaDeEmpleados[], int );


/** \brief addEmployee agregar a la lista de empleados una estructura de empleado con los datos recibidos en el primer indice disponible
 *
 * \param puntero a lista de empleados, eEmpleado*
 * \param tamanio de lista de empleados, int
 * \param numero de id del empleado, int
 * \param nombre del empleado, char[]
 * \param apellido del empleado, char[]
 * \param salario, float
 * \param numero del sector, int
 * \return devuelve -1 si hubo un error o no habia indices disponibles en el array de empleados y 0 y pudo cargar correctamente al empleado
 *
 */
int addEmployee(eEmployee list[], int, int, char name[],char lastName[],float,int );


/** \brief cargarEmpleado, solicita al usuario y valida los datos ingresados para pasarselos a la funciona addEmployee para dar de alta un nuevo empleado
 *
 * \param puntero a lista de empleados, eEmpleado*
 * \param tamanio de lista de empleados, int
 * \param puntero a la lista de sectores, eSector*
 * \param tamanio del array de sectores, int
 * \param numero de id que se asignara al empleado a cargar, in
 * \return devuelve -1 si hubo un error o no habia indices disponibles en el array de empleados y 0 y pudo cargar correctamente al empleado
 *
 */
int cargarEmpleado(eEmployee listaEmpleados[],int,eSector listaSectores[], int, int);



/** \brief initEmployees, funcion que inicializa el listado de empleados con "isEmpty" en 1
 *
 * \param lista de empleados
 * \param tamanio de la lista de empleados
 * \return devuelve 0 al finalizar
 *
 */
int initEmployees(eEmployee listaEmpleados[], int );


/** \brief mostrarUnSoloEmployee muestra por pantalla los datos de una estructura eEmployee pasado por parametro
 *
 * \param un empleado, estructura eEmployee
 * \param lista de sectores, array de estructura eSector
 * \param tamanio de la lista de sectores, int
 * \return si el empleado estaba como baja logica (isEmpty = 1) devuelve 0, si lo puedo mostrar correctamente devuelve 1
 *
 */
int mostrarUnSoloEmployee(eEmployee empleado, eSector listaSectores[],int tamanioSectores);



/** \brief mostrarEmployeesConNombreDelSector recorre todo el array de empleados y muestra sus datos
 *
 * \param lista de empleados, array de eEmployee
 * \param tamanio de la lista de empleados, int
 * \param lista de sectores, array de eSector
 * \param tamanio de la lista de sectores, int
 * \return si encontro empleados para mostrar devuelve 1, devuelve 0 si no encontro ningun empleado activo
 *
 */
int mostrarEmployeesConNombreDelSector(eEmployee listaEmpleados[], int, eSector sectores[], int );


/** \brief findEmployeeById busca un empleado de acuerdo a su numero de Id
 *
 * \param puntero a array de empleados
 * \param tamanio del array de empleados, int
 * \param Id del empleado que estoy buscando, int
 * \return devuelve -1 si no encontro el Id. Si encontro el Id devuelve el indice donde se encontro al empleado en la lista
 *
 */
int findEmployeeById(eEmployee* list, int len, int id);



/** \brief removeEmployee da baja logica al empleado solicitado
 *
 * \param puntero a array de empleados
 * \param tamanio del array de empleados, int
 * \param id del empleado a dar de baja, int
 * \return devuelve 0 si dio de baja exitosamente al empleado y -1 si no encontro a ningun empleado con esa id
 *
 */
int removeEmployee(eEmployee* list, int len, int id);


/** \brief sortEmployees ordena la lista de empleados por sector y dentro de cada sector por apellido alfabeticamente de forma descendente o ascendente segun lo solicitado
 *
 * \param puntero a lista de empleados
 * \param tamanio de la lista de empleados
 * \param orden de ordenamiento, 1 para ascendente y 0 para descendente
 * \return devuelve 0 al finalizar
 *
 */
int sortEmployees(eEmployee* list, int len, int order);


/** \brief printEmployees muestra por pantalla a todos los empleados activos del array de empleados
 *
 * \param puntero al array de empleados
 * \param tamanio del array de empleados
 * \return devuelve 1 si encontro al empleado a mostrar, devuelve 0 si el empleado buscado tenia una baja logica (isEmpty es igual a 1)
 *
 */
int printEmployees(eEmployee* list, int );


/** \brief cargarNombreDelSector esta funcion busca el sector al que pretenece cada empleado en el array de sectores y asigna a un vector de caracteres pasado por parametro la descripcion de este sector para que pueda ser mostrado en pantalla
 *
 * \param array de sectores
 * \param id del sector que deseo mostrar
 * \param vector de caracteres donde cargare la descripcion del sector buscado
 * \param tamanio de la lista de sectores
 * \return la funcion devuelve 1 si encontro el sector buscado y 0 si no encontro un sector activo con el id pedido
 *
 */
int cargarNombreDelSector(eSector listaSectores[], int idSector, char vectorParaNombreDelSector[], int tamanioListaSectores);



/** \brief mostrarSectores, esta funcion muestra por pantalla todos los sectores del array de sectores
 *
 * \param lista de sectores a mostrar
 * \param tamanio del array de sectores a mostrar
 * \return devuelve 1 si logro mostrar los sectores y devuelve 0 si ningun sector estaba activo en la lista
 *
 */
int mostrarSectores(eSector listaSectores[], int tamanioSectores);


/** \brief funcion para modificar empleados
 *
 * \param empleado a modificar, eEmployee
 * \param campo que se desae modificar del empleado, int
 * \param lista de sectores para que puedan mostrar por pantalla, eSector lista[]
 * \param tamanio de la lista de sectores, int
 * \return la funcion devuelve una estructura de tipo eEmployee para ser asignada al index donde se encuentra el empleado que se quizo modificar
 *
 */
eEmployee modificarEmployee(eEmployee empleado, int opcionAModificar, eSector sectores[], int tamanioSectores);



/** \brief funcion que suma los salarios de todos los empleados que figuran activos en la lista
 *
 * \param array de empleados, eEmployee lista[]
 * \param tamanio del array de empleados, int
 * \return la funcion de vuelve un numero flotante que corresponde a la suma de los salarios
 *
 */
float sumaSalarios(eEmployee listaEmpleados[], int tamanioEmpleados);



/** \brief funcion que saca el promedio de los salarios de todos los empleados que figuran activos en la lista
 *
 * \param suma de todos los salrios, float
 * \param tamanio del array de empleados, int
 * \param array de empleados, eEmployee lista[]
 * \return la funcion de vuelve un numero flotante que corresponde al promedio de los salarios de los empleados activos
 *
 */
float  promedioDeSalarios(float sumaTotalSalarios,int tamanioEmpleados, eEmployee listaEmpleados[]);



/** \brief funcion que busca a los empleados activos con salarios por encima del promedio y los muestra en pantalla
 *
 * \param lista de empleados, eEmployee lista[]
 * \param promedio de los salarios, float
 * \param tamanio del array de empleados, int
 * \param array de sectores para que puedan ser mostrados en pantalla, eSector lista[]
 * \param tamanio del array de sectores, int
 * \return la funcion devuelve 1 si hallo a al menos un empleado activo y 0 si no hallo a ninguno
 *
 */
int buscarYmostrarEmployeesSobrePromedio(eEmployee listaEmpleados[], float promedio, int tamanioEmpleados, eSector sectores[], int tamanioSectores);


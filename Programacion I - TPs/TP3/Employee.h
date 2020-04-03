#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;



/** \brief Solicita un espacio en memoria para una estructura Employee y lo inicializa en 0
 *
 * \param void
 * \return Employee*, retorna un puntero a una estructura Employee o NULL si no se pudo conseguir correctamente
 *
 */
Employee* employee_new();


/** \brief Recibe los campos en formato string para cargar a la estrucura empleado y los carga a la misma
 *
 * \param char* sting del id
 * \param char* sting del nombre
 * \param char* sting de las horas
 * \param char* sting del sueldo
 * \return Employee*, retorna un puntero a una estructura Employee con los datos cargados o NULL en caso de que no se hayan podido cargar los datos correctamente
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/** \brief Libera el espacio en memoria de un empleado seleccionado
 *
 * \param Employee* puntero a empleado a borrar
 * \return void
 */
void employee_delete(Employee* this);


/////////////// Setters y Getters ///////////////////////////

/** \brief Setea el campo del id al empleado
 *
 * \param Employee* puntero a empleado
 * \param int, id
 * \return int, si lo pudo setear devuelve 1 sino 0
 */
int employee_setId(Employee* this,int id);



/** \brief Solicita el valor del campo id del empleado y lo carga a la variable
 *
 * \param Employee* puntero a empleado
 * \param int*, puntero donde cargar el valor
 * \return int, si lo pudo encontrar devuelve 1 sino 0
 */
int employee_getId(Employee* this,int* id);


/** \brief Setea el campo del nombre al empleado
 *
 * \param Employee* puntero a empleado
 * \param char*, nombre
 * \return int, si lo pudo setear devuelve 1 sino 0
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief Solicita el valor del campo nombre del empleado y lo carga a la variable
 *
 * \param Employee* puntero a empleado
 * \param char*, donde guardar el valor conseguido
 * \return int, si lo pudo encontrar devuelve 1 sino 0
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief Setea el campo de horas al empleado
 *
 * \param Employee* puntero a empleado
 * \param int, horas
 * \return int, si lo pudo setear devuelve 1 sino 0
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief Solicita el valor del campo horasTrabajadas del empleado y lo carga a la variable
 *
 * \param Employee* puntero a empleado
 * \param int*, puntero donde cargar el valor
 * \return int, si lo pudo encontrar devuelve 1 sino 0
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);



/** \brief Setea el campo del sueldo al empleado
 *
 * \param Employee* puntero a empleado
 * \param int, sueldo
 * \return int, si lo pudo setear devuelve 1 sino 0
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief Solicita el valor del campo sueldo del empleado y lo carga a la variable
 *
 * \param Employee* puntero a empleado
 * \param int*, puntero donde cargar el valor
 * \return int, si lo pudo encontrar devuelve 1 sino 0
 */
int employee_getSueldo(Employee* this,int* sueldo);


//////////////////// Mostrar Empleado /////////////////////////

/** \brief Muestra por pantalla un empleado
 *
 * \param Employee* puntero a empleado
 * \return int, devuelve 1 si lo pudo mostrar y 0 si no pudo
 */
int employee_mostrarUnEmpleado(Employee* empleado);

#endif // employee_H_INCLUDED

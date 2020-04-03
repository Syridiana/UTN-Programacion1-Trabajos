/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*, puntero al archivo
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si lo pudo parsear, 0 sino
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*, puntero al archivo
 * \param pArrayListEmployee LinkedList*
 * \return int, 1 si lo pudo parsear, 0 sino
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

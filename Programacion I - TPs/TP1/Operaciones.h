
/** \brief Funcion que suma dos flotantes ingresados ycarga el resultado en la variable resultadoSuma
 *
 * \param Puntero de variable del resultado
 * \param Flotante 1
 * \param Flotante 2
 *
 */
void suma(float*, float, float);


/** \brief Funcion que resta dos flotantes ingresados y carga el resultado en la variable resto
 *
 * \param Puntero de variable del resultado
 * \param Flotante 1
 * \param Flotante 2
 *
 */
void resta(float*,float, float);


/** \brief Funcion que multiplica dos flotantes ingresados y carga el resultado en la variable producto
 *
 * \param Puntero de variable del resultado
 * \param Flotante 1
 * \param Flotante 2
 *
 */
void multiplicacion(float*,float, float);

/** \brief Funcion que divide dos flotantes ingresados y carga el resultado en la variable cociente
 *
 * \param Puntero de variable del resultado
 * \param Flotante 1
 * \param Flotante 2
 * \return retorna 1 si se pudo realizar la division (el divisor no puede ser 0) y -1 si no se logro realizar la division (el divisor es 0)
 *
 */
int division(float*,float, float);

/** \brief Funcion que calcula el factorial
 *
 * \param Puntero de variable del resultado
 * \param Flotante ingresado
 * \return retorna 1 si se pudo realizar la operacion y -1 si no se pudo realizar (en caso de que el numero no fuera entero o fuera negativo).
 *
 */
int factorial(long long int*,float);

/** \brief Funcion que solicita un caracter para operar en el menu y valida el dato ingresado y lo almacena en una variable
 *
 * \param Puntero de variable la variable menu que alamcena el dato ingresado
 * \param Mensaje que se muestra al pedir el dato
 * \param Mensaje de error en caso de que el dato ingresado no sea correcto.
 * \param Minimo valido
 * \param Maximo valido.
 *
 */
void getChar(char*, char[], char[],char, char);

/** \brief Funcion que solicita un caracter para operar en el menu y valida el dato ingresado y lo almacena en una variable
 *
 * \param Solicita un numero flotante y lo almacena en una variable.
 * \param Puntero a la variable.
 * \param Mensaje que se muestra al pedir el dato
 * \param Mensaje de error en caso de que el dato ingresado no sea correcto.
 * \param Cantidad de intentos de ingreso permitidos
 * \return Devuelve un dato de tipo char que indica si el numero se cargo correctamente o no
 *
 */
char getFloat(float*, char[], char[], int);

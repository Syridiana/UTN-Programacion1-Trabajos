//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>



//Funciones de validacion y carga de datos

/** \brief getEntero, para pedir y validar enteros.
 *
 * \param pResultado, puntero al entero que se cargara con el valor pedido
 * \param mensaje, mensaje para pedir el dato
 * \param mensajeError, mensaje de error en caso de que se ingrese un valor no valido
 * \param int, valor minimo permitido
 * \param int, valor maximo permitido
 * \param int, cantidad de intentos
 * \return Devuelve 1 si no se logro cargar correctamente el dato y 0 si se cargo correctamente
 *
 */
int getEntero(int* pResultado,char* mensaje,char* mensajeError,int,int,int );


/** \brief getFlotante, para pedir y validar numeros flotantes
 *
 * \param pResultado, puntero al entero que se cargara con el valor pedido
 * \param mensaje, mensaje para pedir el dato
 * \param mensajeError, mensaje de error en caso de que se ingrese un valor no valido
 * \param int, valor minimo permitido
 * \param int, valor maximo permitido
 * \param int, cantidad de intentos
 * \return Devuelve 0 si no se logro cargar correctamente el dato y 1 si se cargo correctamente
 *
 */
int getFlotante(float* pResultado,char* mensaje,char* mensajeError,int,int,int );


/** \brief auxiliarGetEntero recibe el valor ingresado por el usuario por teclado evitando que rebalse el espacio asignado y valida que sea un numero entero pasandole el valor a la funcion esNumerica, si el valor es numerico lo convierte a un entero
 *
 * \param pResultado, puntero al entero que se cargara con el valor pedido
 * \return Devuelve 0 si no se logro cargar correctamente el dato y 1 si se cargo correctamente
 *
 */
int auxiliarGetEntero(int*); //funciones auxiliares a getNumero

/** \brief esNumerica recorre la cadena de caracteres recibida y revisa que sea un valor numerico
 *
 * \param cadena, cadena de caracteres ingresada por el usuario a traves del teclado
 * \return Devuelve 0 si no se logro cargar correctamente el dato y 1 si se cargo correctamente
 *
 */
int esNumerica(char[]);//funciones auxiliares a getNumero



/** \brief esFlotante recorre la cadena de caracteres recibida y revisa que sea un valor numerico, entero o flotante
 *
 * \param cadena, cadena de caracteres ingresada por el usuario a traves del teclado
 * \return Devuelve 0 si no se logro cargar correctamente el dato y 1 si se cargo correctamente
 *
 */
int esFlotante(char* cadena);//funciones auxiliares a getFlotante



/** \brief auxiliarEsFlotante recibe el valor ingresado por el usuario por teclado evitando que rebalse el espacio asignado y valida que sea un numero flotante pasandole el valor a la funcion esFlotante, si el valor es numerico lo convierte a un flotante
 *
 * \param pResultado, puntero al entero que se cargara con el valor pedido
 * \return Devuelve 0 si no se logro cargar correctamente el dato y 1 si se cargo correctamente
 *
 */
int auxiliarEsFlotante(float* pResultado);//funciones auxiliares a getFlotante


/** \brief solicita una cadena de caracteres al usuario y chequea que los datos ingresados sean exclusivamente alfabeticos
            (o espacios). Evita que se desborden los datos ingresados del tamaño asignado a dicha variable. Si el dato ingresado
            es correcto lo carga a la cadena de caracteres correspondiente.
 *
 * \param puntero a cadena de caracteres donde cargar el dato
 * \param cadena de caracteres para mensaje que se mostrara al solicitar el dato
 * \param cadena de caracteres para mensaje que se mostrara en caso de que el dato ingresado no sea del formato correcto
 * \param cantidad de reitentos permitidos
 * \return devuelve 0 si no se logro cargar el dato correctamente y 1 si se logro cargar correctamente
 *
 */
int pedirTexto(char* pResultado, char* mensaje, char* mensajeError, int);

//int esAlfabetica(char* cadena);

//int pedirNombreCliente(char* pResultado);
//int pedirNombre(char* pResultado,char* mensaje,char* mensajeError,int reintentos);

//int pedirChar(char* caracter, char* mensaje, char* mensajeError, int reintentos);
//int pedirTelefono(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
//int esTelefono(char* cadena);
//int pedirTelefonoDelCliente(char* pResultado);


/** \brief solicita un dato de tipo char y verifica que el dato ingresado sea del tipo correcto
 *
 * \param puntero a variable char donde guardar el dato ingresado
 * \param cadena de caracteres para mensaje que se mostrara al solicitar el dato
 * \param cadena de caracteres para mensaje que se mostrara en caso de que el dato ingresado no sea del formato correcto
 * \param cantidad de reitentos permitidos
 * \return devuelve 0 si no se logro cargar el dato correctamente y 1 si se logro cargar correctamente
 *
 */
int pedirChar(char* pResultado, char* mensaje, char* mensajeError, int);


/** \brief solicita un dato de formato telefono y verifica que el dato ingresado sea del tipo correcto
 *
 * \param cadena de caracteres donde se guardara el dato ingresado
 * \param cadena de caracteres para mensaje que se mostrara al solicitar el dato
 * \param cadena de caracteres para mensaje que se mostrara en caso de que el dato ingresado no sea del formato correcto
 * \param cantidad de reitentos permitidos
 * \return devuelve 0 si no se logro cargar el dato correctamente y 1 si se logro cargar correctamente
 *
 */
int pedirTelefono(char pResultado[], char* mensaje, char* mensajeError, int);


/** \brief pide y valida los datos de domicilio evitando que los datos ingresados sobrepasen el espacio asignado
 *
 * \param cadena de caracteres para el domicilio
 * \param mensaje a mostrar
 * \param mensaje a mostrar en caso de error
 * \return retorna 0 al finalizar
 *
 */
int pedirDomicilio(char domicilio[], char* mensaje, char* mensajeError);


/** \brief chequea que la cadena de caracteres pasada solo contengo letras o espacios en blanco
 *
 * \param cadena de caracters a analizar
 * \return devuelve 1 la cadena solo contiene letras y espacios y 0 si contiene otro tipo de caracteres
 *
 */
int esAlfabetica(char* cadena);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Funciones de validacion y carga de datos

/** \brief getEntero, para pedir y validar enteros.
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


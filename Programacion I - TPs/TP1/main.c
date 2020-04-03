#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"


int main()
{
    float numA; //variable float para guardar primer operando
    float numB; //variable float para guardar primer operando
    char menu; //opcion del menu elegida
    char seguir='s'; //variable para seguir ejecutando el programa o salir
    
    // ---- defino variables para almacenar los resultados de las operaciones-------
    float resultadoSuma;
    float resto;
    float cociente;
    float producto;
    long long int factorialA;
    long long int factorialB;
    
    // ---- banderas para chequear si se cargaron ambos operandos -------
    char flagNumeroACargado='n';
    char flagNumeroBCargado='n';
    
    // ---- bandera para chequear si se calcularon los resultados antes de informar -------
    char flagCalculado='n';
    
    /* ---- cargaran los return de algunas funciones de las operaciones para ver 
    si se pudo calcular o los valores de los operandos no eran correctos -------*/
    int checkDivision;
    int checkFactA;
    int checkFactB;


    //---- inicio el programa con do while -------
    do
    {
        //---- se carga el menu-------
        printf("1.Ingresar primer operando.");
        
        //---- si el primer operando fue cargado se muestra en pantalla -------
        if(flagNumeroACargado=='s')
        {
            printf(" (A=%.2f)", numA);
        }
        
        printf("\n2.Ingresar segundo operando.");
        
        //---- si el segundo operando fue cargado se muestra en pantalla -------
        if(flagNumeroBCargado=='s')
        {
            printf(" (B=%.2f)", numB);
        }
        
        printf("\n3.Calcular todo.\n");
        printf("4.Informar resultados.\n");
        printf("5.Salir.\n");
        //---- fin del menu-------

        //---- solicito que se ingrese una opcion del menu-------
        getChar(&menu, "\nIngrese una opcion: ", "\nError. Ingrese una opcion correcta: ", '1', '5');

        //---- switch para ejecutar las distintas opciones del menu-------
        switch(menu)
        {
        case '1':
            //cargo el return de la funcion en la variable segun si el dato se cargo correctamente
            flagNumeroACargado=getFloat(&numA, "\nIngrese el primer operando: ", "\nError. Ingrese un valor correcto: ", 5);
            break;
                
        case '2':
            //cargo el return de la funcion en la variable segun si el dato se cargo correctamente
            flagNumeroBCargado = getFloat(&numB, "\nIngrese el segundo operando: ", "\nError. Ingrese un valor correcto: ", 5);
            break;
                
        case '3':
            //si ambos operandos fueron cargados continuo ejecutando las funciones de las operaciones
            if(flagNumeroBCargado=='s' && flagNumeroACargado=='s')
            {
                suma(&resultadoSuma, numA, numB);
                resta(&resto, numA, numB);
                multiplicacion(&producto, numA, numB);
                checkDivision = division(&cociente, numA, numB);
                checkFactA = factorial(&factorialA, numA);
                checkFactB = factorial(&factorialB, numB);
                flagCalculado='s';
                printf("\n----------------Calculando----------------\n\n");
            }
            else
            {
                //si los operandos no fueron cargados se avisa en un mensaje de error
                printf("\n!!!***Error. Debe ingresar ambos operandos primero.***!!!\n\n");
            }
            break;
                
        case '4':
            //si ya se han calculado los resultado prosigo a informarlos por pantalla
            if(flagCalculado=='s')
            {
                printf("\nLa suma de %.2f+%-.2f es: %.2f \nLa esta de %.2f-%-.2f es: %.2f \nEl producto de %.2f*%.2f es: %.2f", numA, numB, resultadoSuma, numA, numB, resto, numA, numB, producto);
                                
                //segun lo que haya sucedido en la funcion de division muestro el resultado o informo que no se puede divir por cero
                if(checkDivision>0)
                {
                    printf("\nLa division de %.2f/%.2f es: %.2f", numA, numB, cociente);
                }
                else
                {
                    printf("\nNo se puede dividir por cero.");
                }
                
                //segun lo que haya sucedido en la funcion de factorial muestro el resultado o informo error
                if(checkFactA>0)
                {
                    printf("\nEl factorial de %.f es: %lld", numA, factorialA);;
                }
                else
                {
                    printf("\nNo se pueden factorizar numeros negativos ni con decimales.");
                }
                
                //segun lo que haya sucedido en la funcion de factorial muestro el resultado o informo error
                if(checkFactB>0)
                {
                    printf("\nEl factorial de %.f es: %lld\n\n", numB, factorialB);;
                }
                else
                {
                    printf("\nNo se pueden factorizar numeros negativos ni con decimales.\n\n");
                }
            }
            else
            {
                //si no se han calculado los resultados muestro mensaje de error
                printf("\n!!!***Error. Debe calcular primero.***!!!\n\n");
            }
            break;
                
        case '5':
            //si el usuario desae salir modifico el valor de la bandera para salir del while
            seguir='n';
            break;
        }

        system("pause");
        
        //limpio la pantalla
        system("cls");


    }
    while(seguir=='s');

    return 0;
}

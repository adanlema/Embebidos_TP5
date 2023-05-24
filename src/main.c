/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

/*==================[inclusions]=============================================*/
#include "calculadora.h"
#include <stdlib.h>
#include <stdio.h>
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
static int suma(int a, int b);
static int resta(int a, int b);
static int producto(int a, int b);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
static int suma(int a, int b) {
    return (a + b);
}
static int resta(int a, int b) {
    return (a - b);
}
static int producto(int a, int b) {
    return (a * b);
}

/*==================[external functions definition]==========================*/
int main(void) {
    int            resultado = 0;
    calculadora_pt AL        = CrearCalculadora();

    AgregarOperacion(AL, '+', suma);
    resultado = CalcularOperacion(AL, "10+22");
    printf("El resultado es %i\n", resultado);

    AgregarOperacion(AL, '-', resta);
    resultado = CalcularOperacion(AL, "10-22");
    printf("El resultado es %i\n", resultado);

    AgregarOperacion(AL, '*', producto);
    resultado = CalcularOperacion(AL, "10*22");
    printf("El resultado es %i\n", resultado);

    return 0;
}
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
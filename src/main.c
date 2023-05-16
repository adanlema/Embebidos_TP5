/*==================[inclusions]=============================================*/
#include "calculadora.h"
#include <stdio.h>
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/
int suma(int a, int b);
int resta(int a, int b);
int producto(int a, int b);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
int suma(int a, int b) {
    return (a + b);
}
int resta(int a, int b) {
    return (a - b);
}
int producto(int a, int b) {
    return (a * b);
}

/*==================[external functions definition]==========================*/
int main(void) {
    int            resultado;
    calculadora_pt AL = CrearCalculadora();
    AgregarOperacion(AL, '+', suma);

    resultado = CalcularOperacion(AL, "2+2");
    printf("El resultado es %i\n", resultado);
    return 0;
}
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
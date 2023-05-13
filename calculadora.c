/*==================[inclusions]=============================================*/
#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

struct operacion_s {
    char         operador;
    funcion_pt   funcion;
    operacion_pt siguiente;
};

struct calculadora_s {
    operacion_pt operaciones;
};
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/
operacion_pt BuscarOperacion(calculadora_pt AL, char operador) {
    operacion_pt buscar = NULL;
    if (AL != NULL) {
        for (operacion_pt actual = AL->operaciones; actual->siguiente != NULL;
             actual              = actual->siguiente) {
            if (actual->operador == operador) {
                buscar = actual;
                break;
            }
        }
    }
    return buscar;
}
/*==================[external functions definition]==========================*/
calculadora_pt CrearCalculadora(void) {
    calculadora_pt AL = malloc(sizeof(struct calculadora_s));
    if (AL)
        memset(AL, 0, sizeof(struct calculadora_s));
    return AL;
}

bool AgregarOperacion(calculadora_pt AL, char operador, funcion_pt funcion) {
    operacion_pt operacion = malloc(sizeof(struct operacion_s));
    if ((operacion) && !BuscarOperacion(AL, operador)) {
        operacion->funcion   = funcion;
        operacion->operador  = operador;
        operacion->siguiente = AL->operaciones;
        AL->operaciones      = operacion;
    }
    return (operacion != NULL);
}

int CalcularOperacion(calculadora_pt AL, char * cadena) {
    int  n1, n2;
    char operador;
    int  result = 0;

    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] < '0') {
            operador = cadena[i];
            n1       = atoi(cadena);
            n2       = atoi(cadena + i + 1);
        }
    }
    operacion_pt op = BuscarOperacion(AL, operador);
    if (op)
        result = op->funcion(n1, n2);

    return result;
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
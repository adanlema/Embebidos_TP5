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
    operacion_pt anterior;
};
struct calculadora_s {
    operacion_pt operaciones;
};

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

calculadora_pt CrearCalculadora(void) {
    calculadora_pt self = malloc(sizeof(struct calculadora_s));
    if (self != NULL)
        memset(self, 0, sizeof(struct calculadora_s));
    return self;
}

operacion_pt BuscarOperacion(calculadora_pt self, char operador) {
    operacion_pt buscar = NULL;
    if (self != NULL) {
        for (operacion_pt actual = self->operaciones; actual != NULL; actual = actual->anterior) {
            if (actual->operador == operador) {
                buscar = actual;
                break;
            }
        }
    }
    return buscar;
}

bool AgregarOperacion(calculadora_pt self, char operador, funcion_pt funcion) {
    operacion_pt operacion = malloc(sizeof(struct operacion_s));
    if (!(BuscarOperacion(self, operador))) {
        if ((operacion)) {
            self->operaciones->funcion  = funcion;
            self->operaciones->operador = operador;
            operacion->anterior         = self->operaciones;
            self->operaciones           = operacion;
        }
    }
    return (operacion != NULL);
}

int CalcularOperacion(calculadora_pt self, char * cadena) {
    int  n1, n2;
    char operador;
    int  result = 0;

    for (int i = 0; i < strlen(cadena); i++) {
        if (cadena[i] < '0') {
            operador = cadena[i];
            n1       = atoi(cadena);
            n2       = atoi(cadena + i + 1);
            break;
        }
    }
    operacion_pt calcular = BuscarOperacion(self, operador);
    if (calcular)
        result = calcular->funcion(n1, n2);

    return result;
}

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
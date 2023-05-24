/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

/*==================[inclusions]=============================================*/
#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/
/**
 * @brief Estructura de una operacion.
 *  Espacio de memoria de una operacion, contiene su operador, la funcion asociada y un puntero a la
 * operacion anterior agregada.
 *
 * @param operador  Operador de la operacion.
 * @param funcion   Funcion asociada al operador.
 * @param anterior  Puntero a la operacion anterior agregada.
 */
struct operacion_s {
    char         operador;
    funcion_pt   funcion;
    operacion_pt anterior;
};

/**
 * @brief Estructura de la calculadora.
 *  Es una estructura que contiene un puntero a la ultima operacion agregada. Cuando se crea la
 * calculadora esta no contiene ninguna operacion.
 *
 * @param operaciones Puntero a la ultima operacion agregada.
 */
struct calculadora_s {
    operacion_pt operaciones;
};

/*==================[internal functions declaration]=========================*/
static operacion_pt BuscarOperacion(calculadora_pt self, char operador);
/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

static operacion_pt BuscarOperacion(calculadora_pt self, char operador) {
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

/*==================[external functions definition]==========================*/

calculadora_pt CrearCalculadora(void) {
    calculadora_pt self = malloc(sizeof(struct calculadora_s));
    if (self != NULL)
        memset(self, 0, sizeof(struct calculadora_s));
    return self;
}

bool AgregarOperacion(calculadora_pt self, char operador, funcion_pt funcion) {
    operacion_pt operacion = malloc(sizeof(struct operacion_s));
    if (!(BuscarOperacion(self, operador))) {
        if ((operacion)) {
            operacion->funcion  = funcion;
            operacion->operador = operador;
            operacion->anterior = self->operaciones;
            self->operaciones   = operacion;
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
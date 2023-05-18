/*==================[inclusions]=============================================*/
#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/*==================[macros and definitions]=================================*/

#ifndef OPERACIONES
#define OPERACIONES 10
#endif
/*==================[internal data declaration]==============================*/
/*
struct operacion_s {
    char         operador;
    funcion_pt   funcion;
    operacion_pt siguiente;
};
*/

struct operacion_s {
    char       operador;
    funcion_pt funcion;
};

struct calculadora_s {
    operacion_pt operaciones;
};
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
static struct operacion_s op[OPERACIONES];
static struct calculadora_s AL;
/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

calculadora_pt CrearCalculadora(void) {
    /*
    calculadora_pt AL = malloc(sizeof(struct calculadora_s));
    if (AL != NULL)
        memset(AL, 0, sizeof(struct calculadora_s));
    return AL;
    */
    AL.operaciones = op;
    memset(&AL, 0, sizeof(struct calculadora_s));
    return &AL;
}

operacion_pt BuscarOperacion(calculadora_pt self, char operador) {
    /*
    operacion_pt buscar = NULL;
    if (self != NULL) {
        for (operacion_pt actual = self->operaciones; actual->siguiente != NULL;
             actual              = actual->siguiente) {
            if (actual->operador == operador) {
                buscar = actual;
                break;
            }
        }
    }
    return buscar;
    */
    operacion_pt buscar = NULL;
    if (self != NULL) {
        for (int i = 0; i < OPERACIONES; i++) {
            if (self->operaciones[i].operador == operador) {
                buscar->operador = self->operaciones[i].operador;
                buscar->funcion  = self->operaciones[i].funcion;
                break;
            }
        }
    }
    return buscar;
}

bool AgregarOperacion(calculadora_pt self, char operador, funcion_pt funcion) {
    /*
    operacion_pt operacion = malloc(sizeof(struct operacion_s));
    if ((operacion) && !BuscarOperacion(self, operador)) {
        operacion->funcion   = funcion;
        operacion->operador  = operador;
        operacion->siguiente = self->operaciones;
        self->operaciones      = operacion;
    }
    return (operacion != NULL);
    */
    operacion_pt agregar = BuscarOperacion(self, operador);
    if (self != NULL) {
        if ((operador != '\0') && (agregar == NULL)) {
            for (int i = 0; i < OPERACIONES; i++) {
                if (self->operaciones[i].operador == '\0') {
                    self->operaciones[i].operador = operador;
                    self->operaciones[i].funcion  = funcion;
                    break;
                }
            }
        }
    }
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
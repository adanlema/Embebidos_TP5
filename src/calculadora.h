/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef CALCULADORA_H
#define CALCULADORA_H

/*==================[inclusions]=============================================*/
#include <stdbool.h>

/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
typedef struct operacion_s *   operacion_pt;
typedef struct calculadora_s * calculadora_pt;
typedef int (*funcion_pt)(int, int);
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
calculadora_pt CrearCalculadora(void);
bool           AgregarOperacion(calculadora_pt AL, char operador, funcion_pt funcion);
int            CalcularOperacion(calculadora_pt AL, char * cadena);
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif
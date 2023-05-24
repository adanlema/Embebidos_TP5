/* Copyright 2023, Adan Lema <adanlema@hotmail.com> */

#ifndef CALCULADORA_H
#define CALCULADORA_H

/*==================[inclusions]=============================================*/
#include <stdbool.h>
/*==================[macros]=================================================*/

/*==================[typedef]================================================*/
/**
 * @brief Puntero a la estructura operacion_s
 *  Tipo de dato que es un puntero a la estructura que se encarga de guardar una operacion.
 */
typedef struct operacion_s * operacion_pt;

/**
 * @brief Puntero a la estructura calculadora
 *  Tipo de dato que es un puntero a la estructura calculadora, la cual contiene un puntero a un
 * struct operacion_s.
 */
typedef struct calculadora_s * calculadora_pt;

/**
 * @brief Funcion de Callback
 *  Definifimos un tipo de dato que es una funcion de callback, la misma se denomina funcion_pt. Las
 * funciones que pueden ser usadas deben ser del tipo "int" y deben recibir dos parametros del
 * tipo "int".
 */
typedef int (*funcion_pt)(int, int);
/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
/**
 * @brief Puntero a la estructura de una calculadora dinamica.
 *  Se encarga de crear un puntero a una estructura calculadora_s, la cual contiene un puntero
 * a una estructura que guarda una primera operacion. Cuando creamos la calculadora esta operacion
 * es nula.
 * @return calculadora_pt
 */
calculadora_pt CrearCalculadora(void);

/**
 * @brief Agregar una operacion a la calculadora.
 *  Se encarga de agregar una nueva operacion a la calculadora. Como esta implementada utilizando
 * memoria dinamica, cada que vez que creo una nueva operacion se concatena un nuevo struct
 * operacion_s a las operaciones creadas anteriormente, y el puntero de la calculadora siempre
 * apunta a la ultima operacion implementada.
 *
 * @param AL    Puntero a la calculadora.
 * @param operador El operador de la nueva operacion a agregar.
 * @param funcion Funcion que representa al operador.
 * @return true   Si se pudo agregar con exito.
 * @return false  Si no se pudo agregar la operacion solicitada.
 */
bool AgregarOperacion(calculadora_pt AL, char operador, funcion_pt funcion);

/**
 * @brief Calcular Operacion.
 *  Se encarga de calcular la operacion solicitada por la cadena enviada, segun su operador busca la
 * funcion asociada en la calculadora y realiza el calculo.
 *
 * @param AL    Puntero a la calculadora.
 * @param cadena Cadena que contiene la operacion a realizar.
 * @return int El resultado de la operacion.
 */
int CalcularOperacion(calculadora_pt AL, char * cadena);

/** @ doxygen end group definition */
/** @ doxygen end group definition */
/** @ doxygen end group definition */
/*==================[end of file]============================================*/
#endif
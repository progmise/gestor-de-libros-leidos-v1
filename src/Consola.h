#ifndef CONSOLA_H_
#define CONSOLA_H_

#include "Util.h"
#include <iostream>
#include <sstream>

/*
 * PRE:  No tiene
 * POST: Imprime por consola, un mensaje de bienvenida
 */
void mostrarBienvenida();

/*
 * PRE:  No tiene
 * POST: Imprime por consola, un mensaje de despedida
 */
void mostrarDespedida();

/*
 * PRE:  No tiene
 * POST: Imprime por consola, el string pasado por parámetro,
 * 		 destacándolo en un formato para captar atención
 */
void mostrarMensaje(std::string mensaje);

/*
 * PRE:  elementos debe ser un vector con punteros a string
 * 		 inicializados. cantidadDeElementos debe ser mayor o
 * 		 igual a 0
 * POST: Imprime por consola, cada elemento del vector de elementos
 */
void mostrarElementos(std::string ** elementos, int cantidadDeElementos);

/*
 * PRE:  No tiene
 * POST: Valida, dada una entrada, si no está vacía y si no
 * 		 representa únicamente a espacios
 */
bool esEntradaValida(std::string entrada);

/*
 * PRE:  minimoValor y maximoValor, deben ser números mayores o iguales a 0,
 * 		 y minimoValor puede ser menor o igual a maximoValor
 * POST: Valida, dada una entrada, si se trata de un entero y si se encuentra
 * 		 entre los valores de minimoValor y maximoValor.
 */
bool esNumeroValido(std::string entrada, int minimoValor, int maximoValor);

/*
 * PRE:  items no debe ser un vector vacío. cantidadDeItems debe ser
 * 		 mayor o igual a 0
 * POST: Devuelve un vector de punteros a string, con los items
 * 		 como opciones
 */
std::string ** generarOpciones(std::string items[], int cantidadDeItems);

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que representa al puntaje de un
 * 		 libro, solicitado al usuario
 */
std::string solicitarPuntaje();

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que representa al título de un
 * 		 libro, solicitado al usuario
 */
std::string solicitarTitulo();

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que representa a una opción
 * 		 de un menú, solicitado al usuario
 */
std::string solicitarOpcion(std::string ** opciones, int cantidadDeOpciones);

/*
 * PRE:  minimoValor y maximoValor, deben ser números mayores o iguales a 0,
 * 		 y minimoValor puede ser menor o igual a maximoValor
 * POST: Devuelve un entero, que representa al puntaje de un libro
 *		 que el usuario ingresó y que ha sido validado
 */
int validarPuntaje(std::string entrada, int minimoValor, int maximoValor);

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que representa al título de un libro
 *		 que el usuario ingresó y que ha sido validado
 */
std::string validarTitulo(std::string entrada);

/*
 * PRE:  items no debe ser un vector vacío. cantidadDeItems, minimaOpcion
 * 		 y maximaOpcion, deben ser números enteros positivos y minimoValor
 * 		 puede ser menor o igual a maximoValor
 * POST: Devuelve un entero, que representa a uno de los items, que
 *		 el usuario eligió y que ha sido validada
 */
int validarOpcion(std::string items[], int cantidadDeItems, int minimaOpcion, int maximaOpcion);

/*
 * PRE:  minimoValor y maximoValor, deben ser números enteros mayores o
 * 		 iguales a 0, y minimoValor puede ser menor o igual a maximoValor
 * POST: Devuelve el título ingresado por el usuario
 */
int ingresarPuntaje(int minimoValor, int maximoValor);

/*
 * PRE:  No tiene
 * POST: Devuelve el título ingresado por el usuario
 */
std::string ingresarTitulo();

/*
 * PRE:  Opciones no debe ser un vector vacío. cantidadDeElementos debe ser
 * 		 mayor o igual a 0
 * POST: Devuelve la opción ingresada por el usuario, que puede ser el
 * 		 índice de alguna opción
 */
int ingresarOpcion(std::string opciones[], int cantidadDeElementos);

#endif /* CONSOLA_H_ */

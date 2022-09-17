#ifndef UTIL_H_
#define UTIL_H_

#include <iostream>

/*
 * PRE:  El número flotante debe ser mayor a 0
 * POST: Devuelve el número flotante pasado por parámetro, que
 * 		 ha sido redondeado para arriba y a dos decimales
 */
float redondear(float numero);

/*
 * PRE:  No tiene
 * POST: Devuelve un boolean, que representa si la entrada dada
 * 		 representa a un número
 */
bool esNumero(std::string entrada);

/*
 * PRE:  No tiene
 * POST: Devuelve un boolean, que representa si la entrada dada
 *	 	 representa a caracteres alfanuméricos
 */
bool esAlfanumerico(std::string entrada);

/*
 * PRE:  No tiene
 * POST: Devuelve un boolean, que representa si la entrada dada
 *	 	 representa a espacios en blanco
 */
bool esEspacio(std::string entrada);

/*
 * PRE:  valorMinimo debe ser igual o menor a valorMaximo
 * POST: Devuelve un boolean, que representa si el número dado,
 * 		 se encuentra dentro del rango de un valor mínimo y otro
 * 		 máximo
 */
bool validarNumeroAcotado(int numero, int valorMinimo, int valorMaximo);

/*
 * PRE:  No tiene
 * POST: Devuelve el número menor, de 3 números dados
 */
int obtenerMenorDeTres(int numero1, int numero2, int numero3);

#endif /* UTIL_H_ */

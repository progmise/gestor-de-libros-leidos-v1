#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include "Constantes.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

/*
 * PRE:  registros debe ser una matriz de strings inicializada. cantidadDeFilas, cantidadDeColumnas
 * 		 y anteriorCantidadDeFilas deben ser enteros mayor a 0. anteriorCantidadDeFilas debe ser
 * 		 igual o menor a cantidadDeFilas
 * POST: Devuelve una matriz de strings inicializada, la cual a comparación de la matriz registros,
 * 		 está doblada en tamaño y almacena los mismos datos
 */
std::string ** redimensionarMatriz(std::string ** registros, int cantidadDeFilas,
								   int cantidadDeColumnas, int anteriorCantidadDeFilas);

/*
 * PRE:  registroConEncabezados debe ser una matriz de strings inicializada. encabezadosPorDefecto
 * 		 debe ser un vector de strings inicializada. tamanioDeVector y cantidadDeDatos deben
 * 		 ser enteros mayores a 0. cantidadDeRegistros debe ser un entero mayor o igual a 0
 * POST: Devuelve una matriz de strings inicializada, con los valores que se corresponden con los
 * 		 registros almacenados en registroConEncabezados. Modifica el valor en -1 de
 * 		 cantidadDeRegistros, en caso de que la matriz dada este inicializada
 */
std::string ** obtenerRegistros(std::string ** registrosConEncabezados, int tamanioDeVector,
								int & cantidadDeRegistros, int cantidadDeDatos);

/*
 * PRE:  registroConEncabezados debe ser una matriz de strings inicializada. encabezadosPorDefecto
 * 		 debe ser un vector de strings inicializada. cantidadDeRegistros y cantidadDeDatos deben
 * 		 ser enteros mayores a 0
 * POST: Devuelve una matriz de strings inicializada, con los valores que se corresponden con los
 * 		 encabezados almacenados en registroConEncabezados o, en caso de no contar con ningún valor,
 * 		 con los valoores almacenados en encabezadosPorDefecto
 */
std::string ** obtenerEncabezados(std::string ** registrosConEncabezados, std::string * encabezadosPorDefecto,
								  int cantidadDeRegistros, int cantidadDeDatos);

/*
 * PRE:  rutaDeArchivo debe tener un valor distinto al vacío. cantidadDeRegistros
 * 	     y tamanioDeVector deben ser enteros iguales a 0. cantidadDeDatos debe ser
 * 	     un entero con un valor mayor a 0
 * POST: Devuelve una matriz de strings inicializada, con los valores que se leyeron
 * 		 del archivo en la rutaDeArchivo dada. Actualiza los valores de cantidadDeRegistros
 * 		 y tamanioDeVector de acuerdo al volumen de información del archivo
 */
std::string ** leerArchivoCsv(std::string rutaDeArchivo, int & cantidadDeRegistros, int cantidadDeDatos,
							  int & tamanioDeVector, bool hayQueOmitirEncabezados);

/*
 * PRE:  rutaDeArchivo debe tener un valor distinto al vacío. encabezados y
 * 	     registros, deben ser matrices inicializadas y que contengan valores.
 * 	     cantidadDeRegistros y cantidadDeDatos deben ser enteros mayores a 0
 * 		 mayor o igual a 0
 * POST: Escribe un archivo csv en la ruta de archivo especificada, con los
 * 		 encabezados y registros dados
 */
void escribirArchivoCsv(std::string rutaDeArchivo, std::string ** encabezados,
						std::string ** registros, int cantidadDeRegistros,
						int cantidadDeDatos);

#endif /* ARCHIVO_H_ */

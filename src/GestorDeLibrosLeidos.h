#ifndef GESTORDELIBROSLEIDOS_H_
#define GESTORDELIBROSLEIDOS_H_

#include "Archivo.h"
#include "Constantes.h"
#include "Consola.h"
#include "Genero.h"
#include "Libro.h"
#include "TipoDeGenero.h"

const int CANTIDAD_DE_DATOS = 3;
const int CANTIDAD_DE_LIBROS_CON_MENOR_PUNTAJE = 3;
const int PUNTAJE_MINIMO = 0;
const int PUNTAJE_MAXIMO = 100;
const std::string RUTA_DE_ARCHIVO = "data/libros.csv";

/*
 * PRE:  genero únicamente puede tomar valor de alguno de los siguientes elementos:
 * 		 { "A", "C", "D", "P", "R", "T" }
 * POST: Devuelve un enum de TipoDeGenero, de acuerdo al genero dado
 */
TipoDeGenero obtenerEnum(std::string genero);

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que representa la descripción del genero dado
 */
std::string obtenerValor(TipoDeGenero genero);

/*
 * PRE:  No tiene
 * POST: Devuelve un string, que representa la notación de un genero dado
 */
std::string obtenerLlave(TipoDeGenero genero);

/*
 * PRE:  p y q deben ser punteros de punteros de Genero inicializados
 * POST: Intercambia las direcciones de memoria a la que apuntan p y q
 * 		 el uno con el otro
 */
void intercambiar(Genero ** p, Genero ** q);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado. inicio y
 * 		 fin deben ser enteros mayores a 0, inicio puede ser igual o menor a fin. tituloBuscado
 * 		 debe tomar un valor distinto a vacío
 * POST: Devuelve un entero, el cual representa la posición en la que se encuentra
 * 		 tituloBuscado respecto de libros. De no encontrarse, devuelve -1
 */
int buscarPorBusquedaBinaria(Libro ** libros, int inicio, int fin, std::string tituloBuscado);

/*
 * PRE:  generos debe ser un vector no vacío de punteros a Genero inicializado. cantidadDeGeneros
 * 		 debe ser un entero mayor a 0
 * POST: Ordena de manera descendente el vector de punteros a Genero, de acuerdo a la
 * 		 cantidadDeLibros de cada elemento del vector
 */
void ordenarPorBurbuja(Genero ** generos, int cantidadDeGeneros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado. cantidadDeLibros
 * 		 debe ser un entero mayor a 0
 * POST: Ordena, como primer criteria, de manera ascendente el vector de punteros a Libro, de
 * 		 acuerdo al puntaje, y como segunda criteria, de manera ascendente de acuerdo al
 * 		 titulo de cada elemento del vector
 */
void ordenarPorInsercion(Libro ** libros, int cantidadDeLibros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado. tamanioDeVector
 * 		 y cantidadDeLibros deben ser enteros mayores a 0
 * POST: Devuelve una vector de punteros a Libro inicializado, la cual a comparación del
 * 		 vector libros está doblado en tamaño y almacena los mismos datos
 */
Libro ** redimensionarVector(Libro ** libros, int tamanioDeVector, int cantidadDeLibros);

/*
 * PRE:  generos debe ser un vector no vacío de punteros a Genero inicializado.
 * 		 cantidadDeGeneros debe ser un entero mayor a 0
 * POST: Devuelve un puntero a Genero, el cual representa al genero elegido
 * 		 por el usuario
 */
Genero * ingresarGenero(Genero ** generos, int cantidadDeGeneros);

/*
 * PRE:  tiposDeGeneros debe ser un vector no vacío de strings inicializado.
 * 		 cantidadDeGeneros debe ser un entero mayor a 0
 * POST: Devuelve una vector de punteros a Genero inicializado, la cual se creó
 * 		 a partir de los valores de tiposDeGeneros
 */
Genero ** generarGeneros(std::string * tiposDeGeneros, int cantidadDeGeneros);

/*
 * PRE:  generos debe ser un vector no vacío de punteros a Genero inicializado.
 * 		 cantidadDeGeneros debe ser un entero mayor a 0. tipoDeGenero únicamente
 * 		 puede tomar valor de alguno de los siguientes elementos:
 * 		 { "A", "C", "D", "P", "R", "T" }
 * POST: Devuelve un puntero a Genero, el cual representa al genero encontrado, de
 * 		 acuerdo al tipoDeGenero del vector de generos
 */
Genero * asignarGenero(Genero ** generos, int cantidadDeGeneros, std::string tipoDeGenero);

/*
 * PRE:  registros debe ser una matriz no vacía de strings inicializado.
 * 		 cantidadDeLibros, tamanioDeVector y cantidadDeGeneros deben ser enteros
 * 		 mayores a 0. generos debe ser un vector no vacío de punteros a Genero
 * POST: Devuelve una vector de punteros a Libro inicializado, la cual se basa
 * 		 en los datos almacenados en la matriz registros
 */
Libro ** cargarLibros(std::string ** registros, int cantidadDeLibros, int tamanioDeVector,
					  Genero ** generos, int cantidadDeGeneros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado.
 * 		 cantidadDeLibros debe ser un entero mayor a 0
 * POST: Imprime por consola todos los libros con su titulo, genero en forma
 * 		 completa y puntaje
 */
void listarLibros(Libro ** libros, int cantidadDeLibros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado.
 * 		 tamanioDeVector, cantidadDeLibros y cantidadDeGeneros deben ser enteros
 * 		 mayores a 0. generos debe ser un vector no vacío de punteros a Genero
 * POST: Agrega un libro nuevo, que no exista previamente en libros de acuerdo al
 * 		 titulo ingresado por el usuario. Los datos del nuevo libro son ingresados
 * 		 por el usuario. Actualiza el valor de tamanioDeVector, de acuerdo a si ya
 * 		 se lleno el vector libros, también actualiza el valor de cantidadDeLibros
 * 		 en 1
 */
void agregarLibro(Libro ** libros, int & tamanioDeVector, int & cantidadDeLibros,
				  Genero ** generos, int cantidadDeGeneros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado.
 * 		 cantidadDeLibros debe ser un entero mayor a 0
 * POST: Edita el puntaje de un libro a elección del usuario, de acuerdo al
 * 		 titulo que se ingrese
 */
void editarPuntaje(Libro ** libros, int cantidadDeLibros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado.
 * 		 cantidadDeLibros debe ser un entero mayor a 0
 * POST: Imprime por consola el titulo del libro con mayor puntaje. Si hay un
 *		 empate, se muestran todos los titulos de libros que compartan dicho
 *		 puntaje
 */
void mostrarLibroFavorito(Libro ** libros, int cantidadDeLibros);

/*
 * PRE:  libros debe ser un vector no vacío de punteros a Libro inicializado.
 * 		 cantidadDeLibrosConMenorPuntaje debe ser un entero mayor a 0
 * POST: Imprime por consola los tres titulos de libros con los menores puntajes.
 * 		 Si hay un empate en el tercer puesto se mostrará el título que aparecería
 * 		 primero si fuera en orden alfabético
 */
void mostrarLibrosConMenorPuntaje(Libro ** libros, int cantidadDeLibrosConMenorPuntaje);

/*
 * PRE:  generos debe ser un vector no vacío de punteros a Genero inicializado.
 * 		 cantidadDeGeneros debe ser un entero mayor a 0
 * POST: Imprime por consola el genero que aparece más veces, en relación a
 * 		 la cantidadDeLibros de cada genero. Si hay un empate se muestran todos
 * 		 los que compartan dicho máximo valor de cantidadDeLibros
 */
void mostrarGeneroMasLeido(Genero ** generos, int cantidadDeGeneros);

/*
 * PRE:  generos debe ser un vector no vacío de punteros a Genero inicializado.
 * 		 cantidadDeGeneros y cantidadTotalDeLibros debes ser enteros mayores a 0
 * POST: Imprime por consola el genero con el mayor promedio, en relación a
 * 		 cantidadTotalDeLibros y a la cantidadDeLibros de cada genero. Si hay
 * 		 un empate se muestran todos los que compartan este promedio
 */
void mostrarGeneroFavorito(Genero ** generos, int cantidadDeGeneros, int cantidadTotalDeLibros);

/*
 * PRE:  encabezados debe ser una matriz de strings inicializada. libros debe ser
 * 		 un vector no vacío de punteros a Libro inicializado. tamanioDeVector y
 * 		 cantidadDeLibros deben ser enteros mayores a 0
 * POST: Escribe un archivo de 0, en la ruta dada por la constante RUTA_DE_ARCHIVO
 * 		 y guarda en ella los encabezados y los datos de los libros
 */
void guardarLibros(std::string ** encabezados, Libro ** libros,
				   int tamanioDeVector, int cantidadDeLibros);

/*
 * PRE:  No tiene
 * POST: Inicia el programa y muestra el menú de acciones al usuario
 */
void iniciar();

#endif /* GESTORDELIBROSLEIDOS_H_ */

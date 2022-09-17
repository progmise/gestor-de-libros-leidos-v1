#ifndef LIBRO_H_
#define LIBRO_H_

#include "Genero.h"
#include <string>

struct Libro {
	std::string titulo;
	Genero * genero;
	int puntaje;
};

#endif /* LIBRO_H_ */

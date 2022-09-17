#ifndef GENERO_H_
#define GENERO_H_

#include "TipoDeGenero.h"
#include <string>

struct Genero {
	std::string descripcion;
	TipoDeGenero tipo;
	int cantidadDeLibros;
};

#endif /* GENERO_H_ */

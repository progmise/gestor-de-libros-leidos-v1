#include "GestorDeLibrosLeidos.h"

using namespace std;

TipoDeGenero obtenerEnum(string genero) {
	const char * caracter = genero.c_str();

	switch (caracter[0]) {
		case 'A':
			return TipoDeGenero::A;
		case 'C':
			return TipoDeGenero::C;
		case 'D':
			return TipoDeGenero::D;
		case 'P':
			return TipoDeGenero::P;
		case 'R':
			return TipoDeGenero::R;
		case 'T':
			return TipoDeGenero::T;
		default:
			return TipoDeGenero::A;
	}

	delete caracter;
}

string obtenerValor(TipoDeGenero genero) {
	switch (genero) {
		case TipoDeGenero::A:
			return "Aventura";
		case TipoDeGenero::C:
			return "Ciencia Ficción";
		case TipoDeGenero::D:
			return "Didáctica";
		case TipoDeGenero::P:
			return "Policíaca";
		case TipoDeGenero::R:
			return "Romance";
		case TipoDeGenero::T:
			return "Terror";
		default:
			return "Tipo de género inválido";
	}
}

string obtenerLlave(TipoDeGenero genero) {
	switch (genero) {
		case TipoDeGenero::A:
			return "A";
		case TipoDeGenero::C:
			return "C";
		case TipoDeGenero::D:
			return "D";
		case TipoDeGenero::P:
			return "P";
		case TipoDeGenero::R:
			return "R";
		case TipoDeGenero::T:
			return "T";
		default:
			return "Tipo de género inválido";
	}
}

void intercambiar(Genero ** p, Genero ** q) {
	Genero * aux = *p;
	*p = *q;
	*q = aux;
}

int buscarPorBusquedaBinaria(Libro ** libros, int inicio, int fin, string tituloBuscado) {
	int centro;

	if (inicio <= fin) {
		centro = (fin + inicio) / 2;

		if ((libros[centro]->titulo.compare(tituloBuscado)) == 0) {
			return centro;

		} else if ((tituloBuscado.compare(libros[centro]->titulo)) < 0) {
			return buscarPorBusquedaBinaria(libros, inicio, centro - 1, tituloBuscado);

		} else {
			return buscarPorBusquedaBinaria(libros, centro + 1, fin, tituloBuscado);
		}
	} else {
		return -1;
	}
}

void ordenarPorBurbuja(Genero ** generos, int cantidadDeGeneros) {
	for (int i = 0; i < cantidadDeGeneros - 1; i++) {
		for (int j = 0; j < cantidadDeGeneros - i - 1; j++) {
			if (generos[j]->cantidadDeLibros < generos[j + 1]->cantidadDeLibros) {
				intercambiar(&generos[j], &generos[j + 1]);
			}
		}
	}
}

void ordenarPorInsercion(Libro ** libros, int cantidadDeLibros) {
	Libro * aux = nullptr;
	int i, j;

	for (i = 1; i < cantidadDeLibros; i++) {
		aux = libros[i];
		j = i - 1;

		while (j >= 0 && (libros[j]->puntaje > aux->puntaje ||
			   (libros[j]->puntaje == aux->puntaje && libros[j]->titulo.compare(aux->titulo) > 0))) {
			libros[j + 1] = libros[j];
			j -= 1;
		}

		libros[j + 1] = aux;
	}
}

Libro ** redimensionarVector(Libro ** libros, int tamanioDeVector, int cantidadDeLibros) {
	Libro ** librosRedimensionados = new Libro*[tamanioDeVector];

	for (int i = 0; i < tamanioDeVector; i++) {
		if (i < cantidadDeLibros) {
			Libro * libro = libros[i];

			librosRedimensionados[i] = libro;
		}
	}

	delete [] libros;

	return librosRedimensionados;
}

Genero * ingresarGenero(Genero ** generos, int cantidadDeGeneros) {
	string descripciones[cantidadDeGeneros];
	Genero * genero = nullptr;
	int opcion = 0;

	for (int i = 0; i < cantidadDeGeneros; i++) {
		descripciones[i] = generos[i]->descripcion;
	}

	mostrarMensaje("GENEROS");

	opcion = ingresarOpcion(descripciones, cantidadDeGeneros);
	genero = generos[opcion - 1];

	return genero;
}

Genero ** generarGeneros(string * tiposDeGeneros, int cantidadDeGeneros) {
	Genero ** generos = new Genero*[cantidadDeGeneros];
	Genero * genero = nullptr;

	for (int i = 0; i < cantidadDeGeneros; i++) {
		genero = new Genero;
		genero->tipo = obtenerEnum(tiposDeGeneros[i]);
		genero->descripcion = obtenerValor(genero->tipo);
		genero->cantidadDeLibros = 0;

		generos[i] = genero;
	}

	return generos;
}

Genero * asignarGenero(Genero ** generos, int cantidadDeGeneros, string tipoDeGenero) {
	Genero * genero = nullptr;
	int indice = 0;
	bool seEncontroGenero = false;

	while (!seEncontroGenero && indice < cantidadDeGeneros) {
		genero = generos[indice];

		if (genero->tipo == obtenerEnum(tipoDeGenero)) {
			genero->cantidadDeLibros++;
			seEncontroGenero = true;

		} else {
			indice++;
		}
	}

	return genero;
}

Libro ** cargarLibros(string ** registros, int cantidadDeLibros, int tamanioDeVector,
					  Genero ** generos, int cantidadDeGeneros) {
	Libro ** libros = nullptr;
	Libro * libro = nullptr;

	libros = new Libro*[tamanioDeVector];

	for (int i = 0; i < cantidadDeLibros; i++) {
		libro = new Libro;
		libro->titulo = registros[i][0];
		libro->genero = asignarGenero(generos, cantidadDeGeneros, registros[i][1]);
		libro->puntaje = atoi(registros[i][2].c_str());
		libros[i] = libro;

		ordenarPorInsercion(libros, i + 1);
		ordenarPorBurbuja(generos, cantidadDeGeneros);
	}

	for (int i = 0; i < tamanioDeVector; i++) {
		delete [] registros[i];
	}

	delete [] registros;

	return libros;
}

void listarLibros(Libro ** libros, int cantidadDeLibros) {
	string ** librosFormateados = new string*[cantidadDeLibros];
	string * libroFormateado = NULL;
	stringstream buffer;

	for (int i = 0; i < cantidadDeLibros; i++) {
		libroFormateado = new string();

		buffer << i + 1 << ". " << libros[i]->titulo << " - " << libros[i]->genero->descripcion
			   << " - " << libros[i]->puntaje << endl;

		*libroFormateado = string(buffer.str());

		buffer.str(string());
		buffer.clear();

		librosFormateados[i] = libroFormateado;
	}

	cout << endl;
	mostrarElementos(librosFormateados, cantidadDeLibros);

	for (int i = 0; i < cantidadDeLibros; i++) {
		delete librosFormateados[i];
	}

	delete [] librosFormateados;
}

void agregarLibro(Libro ** libros, int & tamanioDeVector, int & cantidadDeLibros,
				  Genero ** generos, int cantidadDeGeneros) {
	Libro * libro = nullptr;
	Genero * genero = nullptr;
	string titulo;
	int puntaje = 0;
	int indice = 0;
	bool existeTitulo = true;

	do {
		titulo = ingresarTitulo();
		indice = buscarPorBusquedaBinaria(libros, 0, cantidadDeLibros, titulo);

		if (indice == -1) {
			existeTitulo = false;
		} else {
			cout << "\n¡El título del libro que ingresó, ya fue agregado al listado!"
				 << "\n" << endl;
		}
	} while (existeTitulo);

	genero = ingresarGenero(generos, cantidadDeGeneros);
	puntaje = ingresarPuntaje(PUNTAJE_MINIMO, PUNTAJE_MAXIMO);

	genero->cantidadDeLibros++;

	libro = new Libro;
	libro->titulo = titulo;
	libro->genero = genero;
	libro->puntaje = puntaje;

	if (cantidadDeLibros == tamanioDeVector - 1) {
		tamanioDeVector *= 2;
		libros = redimensionarVector(libros, tamanioDeVector, cantidadDeLibros);
	}

	libros[cantidadDeLibros] = libro;
	cantidadDeLibros++;

	ordenarPorInsercion(libros, cantidadDeLibros);
	ordenarPorBurbuja(generos, cantidadDeGeneros);
}

void editarPuntaje(Libro ** libros, int cantidadDeLibros) {
	string titulo;
	int puntaje = 0;
	int indice = 0;
	bool noExisteTitulo = true;

	do {
		titulo = ingresarTitulo();
		indice = buscarPorBusquedaBinaria(libros, 0, cantidadDeLibros, titulo);

		if (indice != -1) {
			noExisteTitulo = false;
		} else {
			cout << "\n¡El título del libro que ingresó, no existe en el listado!"
				 << "\n" << endl;
		}
	} while (noExisteTitulo);

	puntaje = ingresarPuntaje(PUNTAJE_MINIMO, PUNTAJE_MAXIMO);
	libros[indice]->puntaje = puntaje;
}

void mostrarLibroFavorito(Libro ** libros, int cantidadDeLibros) {
	Libro ** librosFavoritos = new Libro*[cantidadDeLibros];
	int indiceDeLibros = cantidadDeLibros - 1;
	int cantidadDeLibrosFavoritos = 0;
	int mayorPuntaje = libros[indiceDeLibros]->puntaje;
	bool hayLibrosConMismoPuntaje = true;

	while (hayLibrosConMismoPuntaje && indiceDeLibros >= 0) {
		Libro * libro = libros[indiceDeLibros];

		if (libro->puntaje == mayorPuntaje) {
			librosFavoritos[cantidadDeLibrosFavoritos] = libro;
			indiceDeLibros--;
			cantidadDeLibrosFavoritos++;

			ordenarPorInsercion(librosFavoritos, cantidadDeLibrosFavoritos);

		} else {
			hayLibrosConMismoPuntaje = false;
		}
	}

	listarLibros(librosFavoritos, cantidadDeLibrosFavoritos);

	delete [] librosFavoritos;
}

void mostrarLibrosConMenorPuntaje(Libro ** libros, int cantidadDeLibrosConMenorPuntaje) {
	listarLibros(libros, cantidadDeLibrosConMenorPuntaje);
}

void mostrarGeneroMasLeido(Genero ** generos, int cantidadDeGeneros) {
	int indice = 0;
	int cantidadDeAparicionesMaxima = generos[indice]->cantidadDeLibros;
	bool hayGenerosConMismoPuntaje = true;

	cout << endl;

	while (hayGenerosConMismoPuntaje && indice < cantidadDeGeneros) {
		Genero * genero = generos[indice];

		if (genero->cantidadDeLibros == cantidadDeAparicionesMaxima) {
			indice++;
			cout << genero->descripcion << " - " << genero->cantidadDeLibros << endl;

		} else {
			hayGenerosConMismoPuntaje = false;
		}
	}
}

void mostrarGeneroFavorito(Genero ** generos, int cantidadDeGeneros, int cantidadTotalDeLibros) {
	int indice = 0;
	float mayorPromedioDeGeneros = redondear(
		(float)(generos[indice]->cantidadDeLibros * 100) / (float)cantidadTotalDeLibros
	);
	bool hayGenerosConMismoPromedio = true;

	cout << endl;

	while (hayGenerosConMismoPromedio && indice < cantidadDeGeneros) {
		Genero * genero = generos[indice];
		float promedioDeGenero = redondear(
			(float)(genero->cantidadDeLibros * 100) / (float)cantidadTotalDeLibros
		);

		if (promedioDeGenero == mayorPromedioDeGeneros) {
			indice++;
			cout << genero->descripcion << " - " << promedioDeGenero << endl;

		} else {
			hayGenerosConMismoPromedio = false;
		}
	}
}

void guardarLibros(string ** encabezados, Libro ** libros,
				   int tamanioDeVector, int cantidadDeLibros) {
	string ** registros = new string*[cantidadDeLibros];

	for (int i = 0; i < cantidadDeLibros; i++) {
		registros[i] = new string[CANTIDAD_DE_DATOS];
		registros[i][0] = libros[i]->titulo;
		registros[i][1] = obtenerLlave(libros[i]->genero->tipo);
		registros[i][2] = to_string(libros[i]->puntaje);

		delete libros[i];
	}

	delete [] libros;

	escribirArchivoCsv(
		RUTA_DE_ARCHIVO,
		encabezados,
		registros,
		cantidadDeLibros,
		CANTIDAD_DE_DATOS
	);

	for (int i = 0; i < 1; i++) {
		delete [] encabezados[i];
	}

	delete [] encabezados;

	for (int i = 0; i < cantidadDeLibros; i++) {
		delete [] registros[i];
	}

	delete [] registros;
}

void iniciar() {
	string opciones[] = {
		"Listar libros leídos",
		"Agregar libro",
		"Editar puntaje de un libro por título",
		"Mostrar libro favorito",
		"Mostrar los 3 libros con menor puntaje",
		"Mostrar género más leído",
		"Mostrar género favorito",
		"Guardar y salir"
	};

	string tiposDeGeneros[] = { "A", "C", "D", "P", "R", "T" };

	string encabezadosPorDefecto[] = {
		"título",
		"género",
		"puntaje",
	};

	string ** registrosConEncabezados = nullptr;
	string ** encabezados = nullptr;
	string ** registros = nullptr;
	Libro ** libros = nullptr;
	Genero ** generos = nullptr;
	int tamanioDeVector = 0;
	int cantidadDeLibros = 0;
	int opcion = 0;
	int cantidadDeOpciones = sizeof(opciones) / sizeof(string);
	int cantidadDeGeneros = sizeof(tiposDeGeneros) / sizeof(string);

	registrosConEncabezados = leerArchivoCsv(
		RUTA_DE_ARCHIVO,
		cantidadDeLibros,
		CANTIDAD_DE_DATOS,
		tamanioDeVector,
		false
	);

	encabezados = obtenerEncabezados(
		registrosConEncabezados,
		encabezadosPorDefecto,
		cantidadDeLibros,
		CANTIDAD_DE_DATOS
	);

	registros = obtenerRegistros(
		registrosConEncabezados,
		tamanioDeVector,
		cantidadDeLibros,
		CANTIDAD_DE_DATOS
	);

	for (int i = 0; i < tamanioDeVector; i++) {
		delete [] registrosConEncabezados[i];
	}

	delete [] registrosConEncabezados;

	generos = generarGeneros(tiposDeGeneros, cantidadDeGeneros);
	libros = cargarLibros(
		registros,
		cantidadDeLibros,
		tamanioDeVector,
		generos,
		cantidadDeGeneros
	);

	mostrarBienvenida();

	do {
		mostrarMensaje("MENU");
		opcion = ingresarOpcion(opciones, cantidadDeOpciones);

		switch (opcion) {
			case 1:
				listarLibros(libros, cantidadDeLibros);
				break;
			case 2:
				agregarLibro(
					libros,
					tamanioDeVector,
					cantidadDeLibros,
					generos,
					cantidadDeGeneros
				);
				break;
			case 3:
				editarPuntaje(libros, cantidadDeLibros);
				break;
			case 4:
				mostrarLibroFavorito(libros, cantidadDeLibros);
				break;
			case 5:
				mostrarLibrosConMenorPuntaje(libros, CANTIDAD_DE_LIBROS_CON_MENOR_PUNTAJE);
				break;
			case 6:
				mostrarGeneroMasLeido(generos, cantidadDeGeneros);
				break;
			case 7:
				mostrarGeneroFavorito(generos, cantidadDeGeneros, cantidadDeLibros);
				break;
			case 8:
				guardarLibros(encabezados, libros, tamanioDeVector, cantidadDeLibros);
				break;
			default:
				cout << "Opción inválida" << endl;
				break;
		}
	} while(opcion != 8);

	mostrarDespedida();

	for (int i = 0; i < cantidadDeGeneros; i++) {
		delete generos[i];
	}

	delete [] generos;
}

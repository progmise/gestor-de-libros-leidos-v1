#include "Archivo.h"

using namespace std;

string ** redimensionarMatriz(string ** registros, int cantidadDeFilas,
							  int cantidadDeColumnas, int anteriorCantidadDeFilas) {
	string ** registrosRedimensionados = new string*[cantidadDeFilas];
	string * registro = nullptr;

	for (int i = 0; i < cantidadDeFilas; i++) {
		registrosRedimensionados[i] = new string[cantidadDeColumnas];

		if (registros != NULL && i < anteriorCantidadDeFilas) {
			registro = registros[i];

			for (int j = 0; j < cantidadDeColumnas; j++) {
				registrosRedimensionados[i][j] = registro[j];
			}

			delete [] registros[i];
		}
	}

	if (registros != nullptr) {
		delete [] registros;
	}

	return registrosRedimensionados;
}

string ** obtenerRegistros(std::string ** registrosConEncabezados, int tamanioDeVector,
						   int & cantidadDeRegistros, int cantidadDeDatos) {
	string ** registros = new string*[tamanioDeVector];

	for (int i = 0; i < tamanioDeVector; i++) {
		registros[i] = new string[cantidadDeDatos];

		if (i > 0 && i < cantidadDeRegistros) {
			for (int j = 0; j < cantidadDeDatos; j++) {
				registros[i - 1][j] = registrosConEncabezados[i][j];
			}
		}
	}

	if (cantidadDeRegistros != 0) {
		cantidadDeRegistros--;
	}

	return registros;
}

string ** obtenerEncabezados(string ** registrosConEncabezados, string * encabezadosPorDefecto,
							 int cantidadDeRegistros, int cantidadDeDatos) {
	string ** encabezados = new string*[1];

	for (int i = 0; i < 1; i++) {
		encabezados[i] = new string[cantidadDeDatos];

		for (int j = 0; j < cantidadDeDatos; j++) {
			if (cantidadDeRegistros == 0) {
				encabezados[i][j] = encabezadosPorDefecto[j];

			} else {
				encabezados[i][j] = registrosConEncabezados[i][j];
			}
		}
	}

	return encabezados;
}

string ** leerArchivoCsv(string rutaDeArchivo, int & cantidadDeRegistros, int cantidadDeDatos,
						 int & tamanioDeVector, bool hayQueOmitirEncabezados) {
	string ** registros = nullptr;
	tamanioDeVector = MINIMO_TAMANIO;
	fstream archivo(rutaDeArchivo, ios::in);

	registros = redimensionarMatriz(
		registros,
		MINIMO_TAMANIO,
		cantidadDeDatos,
		tamanioDeVector
	);
	cantidadDeRegistros = 0;

    if(!archivo.is_open()){
        cout << "No se encontró el archivo \"" << rutaDeArchivo
			 << "\", se va a crear el mismo" << endl;

        archivo.open(rutaDeArchivo, ios::out);
        archivo.close();
        archivo.open(rutaDeArchivo, ios::in);
    }

	string fila, dato;
	int indice = 0;

	do {
		getline(archivo, fila);

		if (!fila.empty() && !hayQueOmitirEncabezados) {
			stringstream buffer(fila);
			indice = 0;

			while (getline(buffer, dato, ',') && indice < cantidadDeDatos) {
				registros[cantidadDeRegistros][indice] = dato;
				indice++;
			}

			cantidadDeRegistros++;

			if (cantidadDeRegistros == tamanioDeVector) {
				registros = redimensionarMatriz(
					registros,
					tamanioDeVector * 2,
					cantidadDeDatos,
					tamanioDeVector
				);
				tamanioDeVector *= 2;
			}
		}

		hayQueOmitirEncabezados = false;
	} while(!fila.empty());

	archivo.close();

	return registros;
}

void escribirArchivoCsv(string rutaDeArchivo, string ** encabezados,
						string ** registros, int cantidadDeRegistros,
						int cantidadDeDatos) {
	ofstream archivo;
	stringstream buffer;
	string * registro = nullptr;

	archivo.open(rutaDeArchivo.c_str(), ios::trunc);

	for (int i = 0; i < cantidadDeDatos; i++) {
		if (i == cantidadDeDatos - 1) {
			buffer << encabezados[0][i] << endl;
		} else {
			buffer << encabezados[0][i] << ',';
		}
	}

	archivo << buffer.str();
	buffer.str("");
	buffer.clear();

	for (int i = 0; i < cantidadDeRegistros; i++) {
		registro = registros[i];

		for (int j = 0; j < cantidadDeDatos; j++) {
			if (j == cantidadDeDatos - 1) {
				buffer << registro[j] << endl;
			} else {
				buffer << registro[j] << ',';
			}
		}
	}

	archivo << buffer.str();
	buffer.clear();

	archivo.flush();
	archivo.close();
}

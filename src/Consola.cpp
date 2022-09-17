#include "Consola.h"

using namespace std;

void mostrarBienvenida() {
	cout << "Algoritmos y Programacion II - T.P. Nro. 1 - EL eterno dilema del lector" << endl;
	cout << "####### Bienvenidos #######" << endl << endl;
	cout << "Aplicación para ayudar a gestionar los libros leídos" << endl;
}

void mostrarDespedida() {
	cout << endl << "¡Hasta la próxima! Programa finalizado!" << endl;
	cout << "####### Adiós #######" << endl;
}

void mostrarMensaje(string mensaje) {
	cout << endl << "########## " << mensaje << " ##########" << endl;
}

void mostrarElementos(string ** elementos, int cantidadDeElementos) {
	for (int i = 0; i < cantidadDeElementos; i++) {
		cout << *elementos[i];
	}
}

bool esEntradaValida(string entrada) {
	bool flagEsValido = false;

	if (!entrada.empty()) {
		if(!esEspacio(entrada)) {
			flagEsValido = true;

		} else {
			cout << "\n¡Se debe ingresar algún valor, no solo espacios!"
				 << "\n" << endl;
		}
	} else {
		cout << "\n¡No se ingresó ningún valor!"
			 << "\n" << endl;
	}

	return flagEsValido;
}


bool esNumeroValido(string entrada, int minimoValor, int maximoValor) {
	int numero = 0;
	bool flagEsValido = false;
	stringstream buffer;

	if (esNumero(entrada)) {
		buffer << entrada;
		buffer >> numero;
		buffer.clear();

		if (validarNumeroAcotado(numero, minimoValor, maximoValor)) {
			flagEsValido = true;

		} else {
			cout << "\n¡Sólo se pueden ingresar numeros entre el "
				 << minimoValor << " y el " << maximoValor
				 << "!\n" << endl;
		}
	} else {
		if (entrada.empty()) {
			cout << "\n¡No se ingresó ningún valor!"
				 << "\n" << endl;
		} else {
			cout << "\n¡Sólo se pueden ingresar numeros enteros positivos y sin espacios!"
				 << "\n" << endl;
		}
	}

	return flagEsValido;
}

string ** generarOpciones(string items[], int cantidadDeItems) {
	string ** opciones = new string*[cantidadDeItems];
	string * opcion = nullptr;
	stringstream buffer;

	for (int i = 0; i < cantidadDeItems; i++) {
		opcion = new string;

		buffer << i + 1 << " - " << items[i] << endl;

		*opcion = string(buffer.str());

		buffer.str(string());
		buffer.clear();

		opciones[i] = opcion;
	}

	return opciones;
}

string solicitarPuntaje() {
	string entrada = "";

	cout << endl << "Ingrese la puntuación del libro del 0 al 100: ";
	getline(cin, entrada);

	return entrada;
}

string solicitarTitulo() {
	string entrada = "";

	cout << endl << "Ingrese el título del libro: ";
	getline(cin, entrada);

	return entrada;
}

string solicitarOpcion(string ** opciones, int cantidadDeOpciones) {
	string entrada = "";

	mostrarMensaje("OPCIONES");

	mostrarElementos(opciones, cantidadDeOpciones);

	cout << endl << "Ingrese una opción: ";
	getline(cin, entrada);

	return entrada;
}

int validarPuntaje(string entrada, int minimoValor, int maximoValor) {
	stringstream buffer;
	int puntaje = 0;
	bool flagEsValido = false;

	while (!flagEsValido) {
		if (esNumeroValido(entrada, minimoValor, maximoValor)) {
			flagEsValido = true;
		} else {
			entrada = solicitarPuntaje();
		}
	}

	buffer << entrada;
	buffer >> puntaje;
	buffer.clear();

	return puntaje;
}

string validarTitulo(string entrada) {
	bool flagEsValido = false;

	while (!flagEsValido) {
		if (esEntradaValida(entrada)) {
			flagEsValido = true;
		} else {
			entrada = solicitarTitulo();
		}
	}

	return entrada;
}

int validarOpcion(string items[], int cantidadDeItems, int minimaOpcion, int maximaOpcion) {
	stringstream buffer;
	string entrada;
	string ** opciones = nullptr;
	int opcion = 0;
	bool flagEsValido = false;

	opciones = generarOpciones(items, cantidadDeItems);

	do {
		entrada = solicitarOpcion(opciones, cantidadDeItems);

		if(esNumeroValido(entrada, minimaOpcion, maximaOpcion)) {
			flagEsValido = true;
		}

	} while (!flagEsValido);

	buffer << entrada;
	buffer >> opcion;
	buffer.clear();

	for (int i = 0; i < cantidadDeItems; i++) {
		delete opciones[i];
	}

	delete [] opciones;

	return opcion;
}

int ingresarPuntaje(int minimoValor, int maximoValor) {
	string entrada = "";
	int puntaje = 0;

	entrada = solicitarPuntaje();
	puntaje = validarPuntaje(entrada, minimoValor, maximoValor);

	return puntaje;
}

string ingresarTitulo() {
	string entrada = "";
	string titulo = "";

	entrada = solicitarTitulo();
	titulo = validarTitulo(entrada);

	return titulo;
}

int ingresarOpcion(string opciones[], int cantidadDeOpciones) {
	int opcion = 0;

	opcion = validarOpcion(opciones, cantidadDeOpciones, 1, cantidadDeOpciones);

	return opcion;
}

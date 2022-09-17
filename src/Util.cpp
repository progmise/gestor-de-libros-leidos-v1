#include "Util.h"

using namespace std;

float redondear(float numero) {
    float valor = (float)(int)(numero * 100 + .5);

    return valor / 100;
}

bool esNumero(string entrada) {
    string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, representa a un dígito
     */
    while (it != entrada.end() && isdigit(*it)) {
    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool esAlfanumerico(string entrada) {
    string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, es alfanumérico
     */
    while (it != entrada.end() && isalnum(*it)) {
    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool esEspacio(string entrada) {
    string::const_iterator it = entrada.begin();

    /*
     * Se itera sobre cada carácter del string dado, y se evalua
     * si cada uno de ellos, representa a un espacio
     */
    while (it != entrada.end() && isspace(*it)) {
    	++it;
    }

    return !entrada.empty() && it == entrada.end();
}

bool validarNumeroAcotado(int numero, int valorMinimo, int valorMaximo) {
	return numero >= valorMinimo && numero <= valorMaximo;
}

int obtenerMenorDeTres(int numero1, int numero2, int numero3) {
	int menor = 0;

	if (numero1 == numero2 && numero2 == numero3) {
		menor = numero1;

	} else if (numero1 < numero2 && numero1 < numero3) {
		menor = numero1;

	} else if (numero2 < numero3) {
		menor = numero2;

	} else {
		menor = numero3;
	}

	return menor;
}

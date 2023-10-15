#include "Auxiliares.h"
#include "Constantes.h"

using namespace std;

void limpiarPantalla() {
	cout << endl << endl << endl << endl << endl << endl << endl << endl <<	endl << endl <<
			endl << endl << endl <<	endl << endl << endl << endl << endl <<	endl << endl << endl;

}

void turnosInhabilitados(Tablero *tablero) {
	Casillero *casillero;
	string imprimir = "- ";

	for(unsigned int numeroFila = 0; numeroFila < tablero->ancho; numeroFila++) {
		for(unsigned int numeroColumna = 0; numeroColumna < tablero->alto; numeroColumna++) {
			casillero = &(tablero->casilla[numeroFila][numeroColumna]);

			if(casillero->imprimir == "X ") {
				if(casillero->inhabilitado == 6) {
					modificarCasillero(*casillero, false, 0, 0, imprimir);

					for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
						Jugador *jugador = &(casillero->jugador[numeroJugador]);
						modificarJugador(*jugador, jugador->cantidadEspias, jugador->cantidadTesoros, imprimir);
					}

				} else {
					casillero->inhabilitado++;
				}

			}

		}
	}

}


void inhabilitarCasilla(Casillero &casillero) {

	string imprimir = "X ";

	modificarCasillero(casillero, casillero.ocupado, casillero.inhabilitado, 0, imprimir);

	for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		modificarJugador(casillero.jugador[numeroJugador], 0, 0, imprimir);
	}

}


bool seguirJugando(TesoroBinario &juego) { //se pasa por referencia
	for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		if(juego.jugador[numeroJugador].cantidadTesoros == 0) {
			return false;
		}
	}
	return true;
}


void intercambiarCasilleros(Casillero &actual, Casillero &nuevo) {
	Casillero auxiliar = actual;

	actual = nuevo;
	nuevo = auxiliar;
}


void intToStringRecursivo(int numero, int posicion, char *cadena) {
	if(posicion < 0) {
		return;
	} else {
		cadena[posicion] = numero%10 + '0';
		intToStringRecursivo(numero/10, --posicion, cadena);
	}

}


string intToString(int numero) {
	int cantidadDigitos = 0;

	int auxiliar = numero;
	while(auxiliar > 0) {
		cantidadDigitos++;
		auxiliar = auxiliar / 10;
	}

	char *cadena = new char[cantidadDigitos+1];

	cadena[cantidadDigitos] = '\0';

	intToStringRecursivo(numero, cantidadDigitos-1, cadena);

	string nuevaCadena = (string) cadena;

	delete [] cadena;

	return nuevaCadena;
}



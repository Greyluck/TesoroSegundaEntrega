#include "Tablero.h"
#include "Constantes.h"


Tablero *inicializarTablero() {
	Tablero *tablero = new Tablero;

	tablero->ancho = ANCHO;
	tablero->alto = ALTO;

	tablero->casilla = new Casillero *[tablero->ancho];

	for(unsigned int numeroFila = 0; numeroFila < tablero->ancho; numeroFila++) {
		tablero->casilla[numeroFila] = new Casillero[tablero->alto];

		for(unsigned int numeroColumna = 0; numeroColumna < tablero->alto; numeroColumna++) {
			inicializarCasillero(tablero->casilla[numeroFila][numeroColumna]);
		}

	}

	return tablero;
}


void eliminarTablero (Tablero *tablero) {
	for(unsigned int numeroFila = 0; numeroFila < tablero->ancho; numeroFila++) {
		delete [] tablero->casilla[numeroFila];
	}

	delete [] tablero->casilla;

	delete tablero;
}



#include "tablero.h"

Tablero *inicializarTablero() {

	Tablero *tablero = new Tablero();
	tablero->alto = ALTO;
	tablero->ancho = ANCHO;

	tablero->matriz = new Registro*[tablero->ancho];
	for(int fila = 0; fila < tablero->ancho; fila++) {
            tablero->matriz[fila] = new Registro[tablero->alto];
		for(int columna = 0; columna < tablero->alto; columna++) {
			inicializarRegistro(&tablero->matriz[fila][columna]);
		}
	}
	return tablero;
}

bool esCasilleroOcupado(Tablero *tablero, int fila, int columna){
    if(tablero->matriz[fila][columna].ocupada == true){
        return true;
    }

    return false;
}

void destruirTablero(Tablero *tablero){
    for(int fila = 0; fila < tablero->ancho; fila++) {
		for(int columna = 0; columna < tablero->alto; columna++) {
			delete &tablero->matriz[fila][columna];
		}
		delete tablero->matriz[fila];
	}

    delete tablero;
}

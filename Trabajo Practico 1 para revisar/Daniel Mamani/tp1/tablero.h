#ifndef TABLERO_H_
#define TABLERO_H_

#include "Registro.h"

static const int ALTO = 20;
static const int ANCHO= 20;

typedef struct{
    Registro **matriz;
    int ancho;
    int alto;
}Tablero;

/**
* Reserva la memoria necesaria para crear un tablero y luego inicializa sus casilleros.
*/
Tablero *inicializarTablero();

/**
* Devuelve true si el casillero en la posición fila-columna está ocupado; false sino.
**/
bool esCasilleroOcupado(Tablero *tablero, int fila, int columna);

/**
* Libera la memoria reservada para el tablero.
*/
void destruirTablero(Tablero *tablero);

#endif // TABLERO_H_

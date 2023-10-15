#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"


typedef struct {
	Casillero **casilla;
	unsigned int alto;
	unsigned int ancho;
}Tablero;


/*
 * Inicializa el tablero, lo que implica inicializar a los casilleros.
 * pre: -
 * post: devuelve un puntero a tablero inicializado.
 */
Tablero *inicializarTablero();


/*
 * pre: fue pedida memoria dinámica en la funcion inicializarTablero
 * post: libera memoria dinámica.
 */
void eliminarTablero (Tablero *tablero);


#endif /* TABLERO_H_ */

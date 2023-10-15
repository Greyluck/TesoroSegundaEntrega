#ifndef CASILLERO_H_
#define CASILLERO_H_

#include "Bibliotecas.h"
#include "Constantes.h"
#include "Jugador.h"

typedef struct {
	bool ocupado;
	unsigned int inhabilitado;
	Jugador jugador[CANTIDAD_JUGADORES];
	unsigned int jugadorActual;
	std::string imprimir;
}Casillero;

/*
 * pre: debe existir un el tablero, habiendo pedido memoria dinámica para cada casillero.
 * post: se inicializa un casillero por referencia.
 */
void inicializarCasillero(Casillero &casillero);


/*
 * pre: casillero fue inicializado.
 * post: se modifican los datos de un casillero por referencia.
 */
void modificarCasillero(Casillero &casillero, bool ocupado, unsigned int turnosInhabilitado, unsigned int numeroJugador, std::string imprimir);


#endif /* CASILLERO_H_ */

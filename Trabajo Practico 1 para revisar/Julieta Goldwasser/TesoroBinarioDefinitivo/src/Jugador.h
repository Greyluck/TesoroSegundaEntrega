#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Bibliotecas.h"

typedef struct {
	unsigned int cantidadTesoros;
	unsigned int cantidadEspias;
	std::string imprimir;
	std::string mensajePrincipal;
	std::string mensajeSecundario;
}Jugador;

/*
 * pre: debe existir una variable de tipo struct TesoroBinario.
 * post: se inicializa un jugador por referencia.
 */
void inicializarJugador(Jugador &jugador, unsigned int numeroJugador);


/*
 * pre: jugador fue inicializado.
 * post: se modifican los datos de un jugador por referencia.
 */
void modificarJugador(Jugador &jugador, unsigned int espias, unsigned int tesoros, std::string imprimir);


#endif /* JUGADOR_H_ */

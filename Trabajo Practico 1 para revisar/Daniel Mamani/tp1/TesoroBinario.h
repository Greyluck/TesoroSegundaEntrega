#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "tablero.h"
#include "Jugador.h"

typedef struct {
	Tablero *tablero;
	bool finalizado;
	Jugador *jugador1;
	Jugador *jugador2;
} TesoroBinario;

/**
* Reserva la memoria necesaria para una estructura TesoroBinario e incializa todos sus campos.
**/
TesoroBinario *inicializarTesoroBinario(std::string nombreJugador1, std::string nombreJugador2);

/**
* Prepara el tablero con los tesoros de los jugadores escondidos es las posiciones que ellos indicaron.
**/
void iniciarJuego(TesoroBinario *tesoroBinario);

/**
* Muestra por pantalla el estado general del tablero después del turno de ambos jugadores.
**/
void mostrarEstadoTableroGeneral(Tablero *tablero);

/**
* Ejecuta el juego para cada jugador mediante turnos.
**/
void jugar(TesoroBinario *tesoroBinario);

/**
* Libera toda la memoria reservada por TesoroBinario.
**/
void finalizarJuego(TesoroBinario *tesoroBinario);

#endif // TESOROBINARIO_H_

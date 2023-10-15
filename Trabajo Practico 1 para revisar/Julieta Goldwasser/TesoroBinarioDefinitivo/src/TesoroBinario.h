#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

//#include "Bibliotecas.h"
#include "Constantes.h"


#include "Jugador.h"
#include "Tablero.h"


typedef struct {
	Tablero *matriz;
	Jugador jugador[CANTIDAD_JUGADORES]; //usado para poder determinar la cantidad de tesoros y espías que tiene
										//cada jugador en total, y poder usar el nombre para crear el archivo.
}TesoroBinario;


/*
 * pre: debe existir una variable de tipo struct TesoroBinario
 * post: se inicializa tanto el tablero (con inicializarTablero) como cada uno de los jugadores (con inicializarJugador).
 */
void inicializarJuego(TesoroBinario &juego);


/*
 * pre: juego inicializado
 * post: cada jugador elige las posiciones de sus tesoros.
 */
void iniciarJuego(TesoroBinario &juego);


/*
 * pre: tesoros fueron ingresados.
 * post: devuelve al ganador, una vez que el otro jugador se quedó sin tesoros.
*/
unsigned int jugarTesoroBinario(TesoroBinario &juego);


#endif /* TESOROBINARIO_H_ */

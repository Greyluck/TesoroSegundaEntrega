#ifndef INTERACCIONES_H_
#define INTERACCIONES_H_

#include "Bibliotecas.h"
#include "Constantes.h"
#include "Tablero.h"
#include "TesoroBinario.h"


/*
 * Da un mensaje de bienvenida, y recuerda algunas reglas básicas.
 */
void mensajeBienvenida();

/*
 * Mensaje final
 * Avisa que el juego ha terminado, y quién fue el ganador.
 */
void terminarJuego(TesoroBinario &juego, unsigned int ganador);

/*
 * pre: tablero inicializado.
 * post: imprime el tablero completo en pantalla (espías y tesoros de todos los jugadores)
 */
void mostrarTablero(Tablero *tablero);

/*
 * pre: juego inicializado
 * post: genera archivos individuales (cada jugador puede ver solamente sus tesoros y espías).
 */
void generarArchivos(TesoroBinario &juego);

/*
 * pre: -
 * post: pasa por referencia la posición ingresada por teclado por el jugador.
 */
void ingresarTesoroOEspia(unsigned int &fila, unsigned int &columna);

/*
 * Pide la posicion de un tesoro, invocando a la función ingresarTesoroOEspia
 * pre: tablero inicializado
 * post: devuelve true si la casilla está ocupada
 */
bool pedirTesoro(Tablero* tablero, unsigned int numeroTesoro, unsigned int &fila, unsigned int &columna);

/*
 * pre: casillero contiene un espía.
 * post: casillero vacío.
 */
void eliminarEspias(TesoroBinario &juego, unsigned int fila, unsigned int columna);

/*
 * pre: casillero[fila][columna] tiene un tesoro.
 * post: baja la cantidad de tesoros del jugador; inhabilita el casillero.
 */
void tesoroEncontrado(TesoroBinario &juego, unsigned int numeroJugador, int fila, int columna);

/*
 * pre: tesoros ya ingresados.
 * post: cambia el tesoro de lugar (también está la posibilidad de que el jugador no quiera mover su tesoro).
 */
void moverTesoro(TesoroBinario &juego, unsigned int numeroJugador);

/*
 * pre: jugadores ya ingresaron sus tesoros.
 * post: muestra en pantalla la cantidad de tesoros que le queda a cada jugador.
 */
void mostrarEstadoTablero(TesoroBinario &juego);


#endif /* INTERACCIONES_H_ */

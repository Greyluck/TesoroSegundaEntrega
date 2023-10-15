#ifndef AUXILIARES_H_
#define AUXILIARES_H_

#include "Tablero.h"
#include "TesoroBinario.h"

/*
 * Imprime varios endl.
 */
void limpiarPantalla();

/*
 * pre:tablero inicializado.
 * post: cuenta los 5 turnos durante los que un casillero está inhabilitado.
 * Al llegar al sexto turno, se covierte en un casillero vacío.
 */
void turnosInhabilitados(Tablero *tablero);

/*
 * pre: tesoro encontrado.
 * post: se modifican los datos del casillero, cambiando así la visualización de la casilla.
 */
void inhabilitarCasilla(Casillero &casilla);

/*
 * pre: se ingresó un espía.ermina si algún jugador se quedó con 0 tesoros.
 * post: si algún jugador se quedó con 0 tesoros, devuelve false, para terminar el juego.
 */
bool seguirJugando(TesoroBinario &juego);

/*
 * pre: jugador decidió mover un tesoro propio.
 * post: intercambia los casilleros (cuyas posiciones son ingresadas por el usuario).
 */
void intercambiarCasilleros(Casillero &actual, Casillero &nuevo);

/*
 * pre: se le pasa un número entero, la posición por la que empezar el proceso recursivo, y un puntero a cadena.
 * post: guarda en el puntero a cadena la dirección de la cadena creada a partir de numero.
 */
void intToStringRecursivo(int numero, int posicion, char *cadena);

/*
 * pre: se le pasa un número entero.
 * post: devuelve un std::string con la conversión del número a cadena (llama a la función intToStringRecursivo).
 */
std::string intToString(int numero);


#endif /* AUXILIARES_H_ */

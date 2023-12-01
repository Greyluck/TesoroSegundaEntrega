#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "Bibliotecas.h"
#include "Tablero.h"
#include "Jugador.h"

using namespace std;

const string NOMBRE_JUEGO = "TESORO BINARIO";

class Tablero;
class Jugador;

class Interfaz{
public:
	/*
        * pre: -
        * post: Crea un a interfaz y pide los datos necesarios para configurar el juego.
        * */
       Interfaz(int &cantidadDeJugadores, int &cantidadDeTesoros, 
       		int &anchoTablero, int &altoTablero, int &largoTablero);

       /*
        * pre: -
        * post: -
        * */
       virtual ~Interfaz();

	/*
	* pre:
	* post:
	* */
	void pedirJugadores(Jugador **jugadores, int cantidadDeJugadores, 
			    int cantidadDeTesoros);

	/*
	* pre: -
	* post: presenta el juego a los jugadores.
	* */
	void mensajeBienvenida(int cantidadDeTesoros, int cantidadDeJugadores);

	/*
	* pre: jugador no puede ser nulo.
	*	cantidadDeTesoros debe ser mayor a 0.
	* post: Esconde todos los tesoros del jugador en el tablero al iniciar el juego.
	* */
	void esconderTesorosInciales(Jugador *jugador, 
				     int cantidadDeTesoros, Tablero *tablero);

	/*
	* pre: ganador no puede ser nulo.
	* post: Felicita al ganador del juego e informa que el juego ha finalizado.
	* */
	void mensajeDeDespedida(Jugador *ganador);

	/*
	* pre: victima y tablero no pueden ser nulos.
	*	idTesoroVictima debe ser mayor a 0.
	* post: Si el tesoro idTesoroVictima de victima no está protegido, lo marca como
        *       ENCONTRADO y lo descuenta de su cantidad de tesoros.
	* */
	void destruirTesoro(Jugador *victima, int idTesoroVictima, Tablero *tablero);
};

#endif //INTERFAZ_H_

#include "Casillero.h"

using namespace std;


void inicializarCasillero(Casillero &casillero) {

	casillero.ocupado = false;
	casillero.inhabilitado = 0;
	casillero.jugadorActual = 0;

	for(int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		casillero.jugador[numeroJugador].cantidadEspias = 0;
		casillero.jugador[numeroJugador].cantidadTesoros = 0;

		casillero.jugador[numeroJugador].imprimir = "- ";
	}

	casillero.imprimir = "- ";

}


void modificarCasillero(Casillero &casillero, bool ocupado, unsigned int turnosInhabilitado, unsigned int numeroJugador, string imprimir) {
	casillero.ocupado = ocupado;
	casillero.inhabilitado = turnosInhabilitado;
	casillero.jugadorActual = numeroJugador;
	casillero.imprimir = imprimir;

}








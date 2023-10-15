#include "Jugador.h"
#include "Auxiliares.h"

using namespace std;

void inicializarJugador(Jugador &jugador, unsigned int numeroJugador) { //se pasa por referencia

	jugador.cantidadEspias = 0;
	jugador.cantidadTesoros = CANTIDAD_TESOROS;

	jugador.imprimir = "Jugador" + intToString(numeroJugador+1);
	jugador.mensajePrincipal = "";
	jugador.mensajeSecundario = "";

}


void modificarJugador(Jugador &jugador, unsigned int espias, unsigned int tesoros, string imprimir) {
	jugador.cantidadEspias = espias;
	jugador.cantidadTesoros = tesoros;
	jugador.imprimir = imprimir;

}



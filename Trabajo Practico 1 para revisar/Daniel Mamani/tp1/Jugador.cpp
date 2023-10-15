#include "Jugador.h"

static const int CANTIDAD_TESOROS_INICIAL = 4;
static const std::string NOMBRE_ARCHIVO = "estadoTablero.txt";

Jugador *inicializarJugador(std::string nombre){
    Jugador *jugador = new Jugador();

    jugador->nombre = nombre;
    jugador->cantidadTesoros = CANTIDAD_TESOROS_INICIAL;
    jugador->cantidadTesorosDescubiertos = 0;
    jugador->estadoTablero = NOMBRE_ARCHIVO;
    jugador->encontroTesoro = false;
    jugador->encontroEspia = false;
    jugador->gano = false;

    for(int i = 0; i < jugador->cantidadTesoros; i++){
        jugador->tesoros[i] = inicializarTesoro(i+1);
        jugador->tesorosDescubiertos[i] = inicializarTesoro(0);
    }

    return jugador;
}

void destruirJugador(Jugador *jugador){

    for(int i = 0; i < jugador->cantidadTesoros; i++){
        destruirTesoro(jugador->tesoros[i]);
        destruirTesoro(jugador->tesorosDescubiertos[i]);
    }

    delete jugador;
}

#ifndef _JUGADOR_H_
#define _JUGADOR_H_

#include "Tesoro.h"
#include <iostream>

typedef struct{
    std::string nombre;
    int cantidadTesoros;
    int cantidadTesorosDescubiertos;
    Tesoro *tesorosDescubiertos[4];
    Tesoro *tesoros[4];
    std::string estadoTablero;
    bool encontroTesoro;
    bool encontroEspia;
    bool gano;
}Jugador;

/**
* Reserva la memoria necesaria para crear un jugador e inicializa todos sus campos.
**/
Jugador *inicializarJugador(std::string nombre);

/**
* Libera la memoria reservada para el jugador.
**/
void destruirJugador(Jugador *jugador);

#endif // _JUGADOR_H_

#include "Jugador.h"

Jugador::Jugador(std::string nombre, int cantidadDeTesoros){

}

void Jugador::escoderTesoro(int idTesoro, int fila, int columna, int altura)
{
}

void Jugador::ponerEspia(int fila, int columna, int altura)
{
}

void Jugador::usarCarta(Carta *carta)
{
}

void Jugador::descartaCartaUsada(Carta *carta)
{
}

bool Jugador::encontroEspia(int fila, int columna, int altura)
{
        return false;
}

bool Jugador::encontroTesoro(int fila, int columna, int altura)
{
        return false;
}

bool Jugador::ganoElJuego()
{
        return false;
}

void Jugador::setCantidadDeTesoros(int cantidadActual)
{
}

std::string Jugador::getNombre()
{
        return std::string();
}

std::string Jugador::getEstadoTablero()
{
        return this->estadoTablero;
}

Jugador::~Jugador()
{
}
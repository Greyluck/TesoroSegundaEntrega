#include "Jugador.h"

// definir cantidad maxima de cartas guardadas definitiva.
const int CANTIDAD_MAXIMA_CARTAS_GUARDADAS = 3;
const std::string ARCHIVO = "estadoTablero.bmp";

Jugador::Jugador(int id, std::string nombre, int cantidadDeTesoros)
{
        if(id <= 0){
                throw "El id debe ser mayor a 0";
        }

        this->id = id;
        this->nombre = nombre;
        
        this->cantidadDeTesoros = cantidadDeTesoros;
        this->tesoros = new Tesoro*[cantidadDeTesoros]();
        for(int i = 0; i < this->cantidadDeTesoros; i++){
                this->tesoros[i] = new Tesoro(i+1);
        }
        
        // this->cartaActiva = NULL;
        this->cantidadCartasGuardadas = CANTIDAD_MAXIMA_CARTAS_GUARDADAS;
        this->cartasGuardadas = new Carta*[this->cantidadCartasGuardadas]();
        for(int i = 0; i < this->cantidadCartasGuardadas; i++){
                this->cartasGuardadas[i] = new Carta();
        }

        this->estadoTablero = ARCHIVO;
        this->gano = false;
}

void Jugador::escoderTesoro(int idTesoro, int fila, int columna, int altura)
{
}

void Jugador::ponerEspia(int fila, int columna, int altura)
{
}

// void Jugador::sacarCartaDelMazo(Mazo * mazo)
// {
//         this->cartasGuardadas[0] = mazo->desapilarCarta();
// }

void Jugador::usarCarta(Carta *carta)
{
        // carta->aplicarCarta(tablero);
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
        return this->nombre;
}

int Jugador::getId()
{
        return this->id;
}

std::string Jugador::getEstadoTablero()
{
        return this->estadoTablero;
}

Jugador::~Jugador()
{
        for(int i = 0; i < this->cantidadCartasGuardadas; i++){
                delete this->cartasGuardadas[i];
        }
        delete []cartasGuardadas;

        for(int i = 0; i < this->cantidadDeTesoros; i++){
                delete this->tesoros[i];
        }
        delete []tesoros;
}
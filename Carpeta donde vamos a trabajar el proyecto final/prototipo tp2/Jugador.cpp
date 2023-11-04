#include "Jugador.h"
#include <iostream>

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
        
        this->cartaActiva = NULL;
        this->cantidadCartasGuardadas = 0;
        this->cartasGuardadas = new Carta*[CANTIDAD_MAXIMA_CARTAS_GUARDADAS]();
        for(int i = 0; i < this->cantidadCartasGuardadas; i++){
                this->cartasGuardadas[i] = new Carta();
        }

        this->estadoTablero = ARCHIVO;
        this->gano = false;
}

void Jugador::escoderTesoro(int idTesoro, int fila, int columna, int altura)
{
        if(idTesoro <= 0){
                throw "El id del tesoro debe ser mayor a 0";
        }

        this->tesoros[idTesoro-1]->definirPosicion(fila, columna, altura);
}

void Jugador::ponerEspia(int fila, int columna, int altura)
{
}

void Jugador::guardarCarta(Carta * carta)
{
        this->cartasGuardadas[this->cantidadCartasGuardadas] = carta;
        this->cantidadCartasGuardadas++;
}

void Jugador::usarCarta(Carta *carta, Tablero *tablero)
{
        carta->aplicarCarta(tablero);
}

Carta * Jugador::elegirCartaAUsar()
{
        int numeroCartaElegida = 0;
        std::cout << "Ingrese el número de la carta a utilizar: " << std::endl;
        std::cin >> numeroCartaElegida;
        while(!(numeroCartaElegida > 0 && numeroCartaElegida <= this->cantidadCartasGuardadas)){
                std::cout << "El numero debe estar entre 1 y la cantidad de cartas guardadas inclusive" << std::endl;
                std::cin >> numeroCartaElegida;
        }
        
        return this->cartasGuardadas[numeroCartaElegida-1];
}

void Jugador::descartaCartaUsada(Carta *carta)
{
        this->cantidadCartasGuardadas--;
}

void Jugador::verCartasGuardadas()
{
        std::cout << "Cantidad de cartas guardadas: " << this->cantidadCartasGuardadas << std::endl;
        for(int i = 0; i < this->cantidadCartasGuardadas; i++){
                std::cout << i+1 << ": " << this->cartasGuardadas[i]->getNombreCarta() << std::endl;
        }
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
        for(int i = 0; i < CANTIDAD_MAXIMA_CARTAS_GUARDADAS; i++){
                delete this->cartasGuardadas[i];
        }
        delete []cartasGuardadas;

        for(int i = 0; i < this->cantidadDeTesoros; i++){
                delete this->tesoros[i];
        }
        delete []tesoros;
}
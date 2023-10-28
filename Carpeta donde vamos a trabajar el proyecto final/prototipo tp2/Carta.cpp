#include "Carta.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

Carta::Carta() {
    //devuelve un valor random del 0, 5
    int valorAleatorio = std::rand() % 6;
    switch (valorAleatorio) {
        case 0:
            this->tipoDeCarta = TipoCarta::Blindaje;
            this->nombreCarta = "Blindaje";
            this->tiempoDeUso = 3;
            break;
        case 1:
            this->tipoDeCarta = TipoCarta::Radar;
            this->nombreCarta = "Radar";
            this->tiempoDeUso = 0;
            break;
        case 2:
            this->tipoDeCarta = TipoCarta::PartirTesoro;
            this->nombreCarta = "Partir Tesoro";
            this->tiempoDeUso = 0;
            break;
//        case 3:
//        case 4:
//        case 5:

    }
}

//agregar las logicas
void Carta::blindaje() {
    std::cout << "Blindaje";
}

void Carta::radar() {
    std::cout << "Radar";
}

void Carta::partirTesoro() {
    std::cout << "Partir Tesoro";
}

std::string Carta::getNombreCarta() {
    return this->nombreCarta;
}

void Carta::aplicarCarta() {

    switch (this->tipoDeCarta) {
        case TipoCarta::Blindaje:
            this->blindaje();
            break;

        case TipoCarta::Radar:
            this->radar();
            break;

        case TipoCarta::PartirTesoro:
            this->partirTesoro();
            break;
    }
}

Carta::~Carta() {

}

int Carta::getTiempoDeUso() {
    return this->tiempoDeUso;
}

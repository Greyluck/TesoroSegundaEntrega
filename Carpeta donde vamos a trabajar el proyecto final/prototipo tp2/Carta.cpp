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

//Protege un tesoro para que no pueda ser agarrado por el rival
void Carta::blindaje(Tablero *tablero) {
    //para este, creo que lo mejor seria agregar un atributo a la clase Tesoro tipo "blindado" y luego cuando se haga un turno comprobar si esta blindado o no
    std::cout << "Blindaje";
}

//Busca tesoros en 3 celdas a la redonda de donde aplico la carta el usuario.
void encontrarTesoros(Tablero* tablero, int x,int y,int z){
    int filas = tablero->getAncho();
    int columnas = tablero->getAlto();
    int profundidad = tablero->getDistancia();
    for (int fila = x-3; fila < x + 3 + 1; i++) {
        for (int columna = y-3; columna < y + 3 + 1; j++) {
            for (int distancia = z - 3; distancia < z + 3 + 1; k++) {
                //chequea que este dentro del rango, y despues si hay un tesoro.
                if ( 0 <= fila && fila < filas && 0 <= columna && columna < columnas && 0 <= distancia && distancia < profundidad){
                    if(tablero->getCasillero(fila,columna,distancia)->obtenerEstado() == TESORO){
                        std::cout << fila << "," << columna << "," << distancia << std::endl;
                    }
                }
            }
        }
    }
}

//Aplica la carta de radar.
void Carta::radar(Tablero *tablero) {
    int x,y,z;
    std::cout << "Esta utilizando la carta radar, a continuacion le pedire donde lo quiere colocar" << std::endl;
    std::cout << "Ingrese la fila: " << std::endl;
    std::cin >> x;
    std::cout << "Ingrese la columna: " << std::endl;
    std::cin >> y;
    std::cout << "Ingrese la distancia: " << std::endl;
    std::cin >> z;
    encontrarTesoros(tablero,x,y,z);
}

//parte un tesoro, es decir, se le suma un tesoro mas al jugador que la utilizo
void Carta::partirTesoro(Tablero *tablero) {
    std::cout << "Partir Tesoro";
}

std::string Carta::getNombreCarta() {
    return this->nombreCarta;
}

void Carta::aplicarCarta(Tablero* tablero) {
    switch (this->tipoDeCarta) {
        case TipoCarta::Blindaje:
            this->blindaje(tablero);
            break;

        case TipoCarta::Radar:
            this->radar(tablero);
            break;

        case TipoCarta::PartirTesoro:
            this->partirTesoro(tablero);
            break;
    }
}

Carta::~Carta() {

}

int Carta::getTiempoDeUso() {
    return this->tiempoDeUso;
}

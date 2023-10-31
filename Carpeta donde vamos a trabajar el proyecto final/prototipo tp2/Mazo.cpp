#include "Mazo.h"

void Mazo::refill() {
    //3n cartas, siendo n = cantJugadores
    for (int i = 0; i < 3 * this->cantJugadores; i++) {
        Carta *carta = new Carta();
        this->mazo->apilar(carta);
    }
}

Mazo::Mazo(int cantJugadores) {
    if (cantJugadores < 2){
        throw "Los jugadores debe ser mas de dos!";
    }
    Pila<Carta *> *pilaCartas = new Pila<Carta *>();
    this->mazo = pilaCartas;
    this->cantJugadores = cantJugadores;
    this->refill();
}

Carta *Mazo::desapilarCarta() {
    if (this->mazo->estaVacia()) {
        refill();
    }
    return this->mazo->desapilar();
}

Mazo::~Mazo() {
    //al ser una pila ya tiene su metodo de descontructor
    delete this->mazo;
}


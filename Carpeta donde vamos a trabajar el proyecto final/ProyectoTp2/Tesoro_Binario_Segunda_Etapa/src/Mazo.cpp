#include "Mazo.h"

void Mazo::refill() {
    //3n cartas, siendo n = cantJugadores
    for (int i = 0; i < this->cantidadCartas; i++) {
        this->mazo->apilar(new Carta());
    }
}

Mazo::Mazo(int cantJugadores) {
    if (cantJugadores < 2){
        throw std::string("Los jugadores deben ser mas de dos!");
    }
    this->mazo = new Pila<Carta *>();
    this->cantidadCartas = cantJugadores*3;
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
    while(!mazo->estaVacia()){
        delete this->mazo->desapilar();
    }
    
    delete this->mazo;
}


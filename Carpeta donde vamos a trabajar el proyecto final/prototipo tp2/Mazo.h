#ifndef TRABAJO_PRACTICO_2_MAZO_H
#define TRABAJO_PRACTICO_2_MAZO_H
#include "Pila.h"
#include "Carta.h"

class Carta;

class Mazo {
private:
    Pila<Carta*> *mazo;
    int cantidadCartas;
    //se encarga de refillear la cantidad de cartas,
    void refill();
public:
    /*
    * pre: La cantidad de jugadores debe ser > 2
    * post: Crea un instancia de la clase Mazo, al crearse ya viene con 3*cantJugadores de cartas
    */
    Mazo(int cantJugadores);

    /*
    * pre: -
    * post: Destruye la instancia de la clase Mazo
    */
    ~Mazo();

    /*
    * pre: -
    * post: Devulve un puntero a una carta que estaba en el mazo, en el caso de que esta vacia se agregan mas cartas.
    */
    Carta* desapilarCarta();

};


#endif //TRABAJO_PRACTICO_2_MAZO_H

#ifndef TRABAJO_PRACTICO_2_CARTA_H
#define TRABAJO_PRACTICO_2_CARTA_H

#include "Bibliotecas.h"
#include "Tablero.h"
#include "Jugador.h"

class Tablero;
class Jugador;

enum TipoCarta {
    BLINDAJE,
    RADAR,
    PARTIR_TESORO,
    TELETRANSPORTACION,
    CONGELACION,
    SUSPENCION_INDISCRIMINADA
};

enum EstadoCarta{
    USADA,
    NO_USADA
};

class Carta {
private:
    TipoCarta tipoDeCarta;
    std::string nombreCarta;
    int tiempoDeUso;
    EstadoCarta estadoCarta;

    void blindaje(Tablero*, Jugador*);

    void radar(Tablero*);

    void partirTesoro(Tablero*,Jugador* jugador);

    void teletransportacion(Tablero*, int idJugador, Jugador** jugadores);

    void congelacion(int idJugador, Jugador** jugadores, int cantidadJugadores);

    void suspensionIndiscriminada(Jugador** jugadores, int cantidadJugadores);

    //agregar otras tres
public:
    /*
     * pre: -
     * post: Crea una instancia de la clase Carta, cuando se crea se elige un tipo de carta de manera aleatoria
     */
    Carta();

    /*
     * pre: -
     * post: Destruye una instancia de la clase carta.
     */
    virtual ~Carta();

    /*
    * pre: -
    * post: Devuelve el nombre de la carta.
    */
    std::string getNombreCarta();

    /*
     * pre: -
     * post: Devuelve el tiempo de uso de la carta
     */
    int getTiempoDeUso();

    /*
     * pre: -
     * post: Aplica la carta segun del tipo que sea, luego de esto la carta se destruye
     */
    void aplicarCarta(Tablero* tablero, int idJugador, Jugador** jugadores, int cantJugadores);


    /*
     * pre: -
     * post: Devuelve el estado de la carta, si esta usada o no
     */
    EstadoCarta checkEstadoCarta();

};


#endif //TRABAJO_PRACTICO_2_CARTA_H

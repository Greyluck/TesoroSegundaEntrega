#ifndef TRABAJO_PRACTICO_2_CARTA_H
#define TRABAJO_PRACTICO_2_CARTA_H

#include <string>
#include "Tablero.h"

enum class TipoCarta {
    Blindaje,
    Radar,
    PartirTesoro,
    //agregar
};

class Carta {
private:
    TipoCarta tipoDeCarta;
    std::string nombreCarta;
    int tiempoDeUso;

    void blindaje(Tablero*);

    void radar(Tablero*);

    void partirTesoro(Tablero*);
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
    ~Carta();

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
    void aplicarCarta(Tablero*);

};


#endif //TRABAJO_PRACTICO_2_CARTA_H

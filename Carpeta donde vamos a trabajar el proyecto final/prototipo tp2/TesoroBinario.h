#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"

class TesoroBinario {
private:
        Tablero *tablero;
        Jugador **jugadores;
        //el maso lo recibe por parámetro en el contructor?
        Mazo *mazo;
        unsigned int cantidadDeJugadores;

public:
        /*
        * pre: tablero no puede ser nulo.
                cantidadDeJugadores debe ser mayor a 1.
        * post: Crea una instancia del TDA TesoroBinario con el tablero 
        *       y los jugadores recibido por parámetro
        */
        TesoroBinario(Tablero *tablero, unsigned int cantidadDeJugadores);

        /*
        * pre: -
        * post: Cada jugador esconde sus tesoros dentro por todo el tablero.
        * */
        void inciarJuego();

        /*
        * pre: -
        * post: Devuelve al ganador una vez que el resto de los jugadores se quedaron sin tesoros.
        * */
        int jugarJuego();

        /*
        * pre: -
        * post: -
        * */
        void finalizarJuego();

        /*
        * pre: -
        * post: Libera la memoria reservada por el TDA TesoroBinario.
        * */
        virtual ~TesoroBinario();
};

#endif //TESOROBINARIO_H_
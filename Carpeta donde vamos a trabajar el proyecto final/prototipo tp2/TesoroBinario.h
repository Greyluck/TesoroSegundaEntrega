#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "Tablero.h"
#include "Jugador.h"
//#include "Mazo.h"

class TesoroBinario {
private:
        Tablero *tablero;
        Jugador **jugadores; //vector dinámico de los jugadores que habrán en el juego
        /*Mazo *mazo;*/ //definir como se obtiene el maso
        unsigned int cantidadDeJugadores;

        /*
        * pre: -
        * post: Pide al usuario los datos necesarios para configurar el juego.
        */
        void pedirDatosParaJugar(int &cantidadDeJugadores, int &cantidadDeTesoros,
                                 int &anchoTablero, int &altoTablero, int &largoTablero);

        /*
        * pre: estado y jugador no pueden ser nulos. 
        * post: Define el estado que tendrá el casillero en la posición (fila, columna, altura).
        *       Si idTesoro es mayor a 0 indica que el tesoro con ese id del jugador está en ese casillero.
        */
        void definirEstadoCasillero(int fila, int columna, int altura,
                                    EstadoRegistro estado, Jugador *jugador,
                                    int idTesoro);

        /*
        * pre:
        * post: exporta el estado del tablero de jugador a estadoTablero.
        * */
        void exportarEstadoTablero(Jugador *jugador, std::string estadoTablero);
public:
        /*
        * pre: -
        * post: Crea una instancia del TDA TesoroBinario con el tablero 
        *       y los jugadores recibido por parámetro
        */
        TesoroBinario();

        /*
        * pre: cantidadDeTesorsos debe ser mayor a 0.
        * post: Cada jugador esconde sus tesoros dentro por todo el tablero.
        * */
        void inciarJuego(int cantidadDeJugadores);

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
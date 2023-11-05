#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"

class TesoroBinario {
private:
        Tablero *tablero;
        Jugador **jugadores; //vector dinámico de los jugadores que habrán en el juego
        Mazo *mazo;
        unsigned int cantidadDeJugadores;
        unsigned int cantidadDeTesoros;

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
        // void definirEstadoCasillero(int fila, int columna, int altura,
        //                             EstadoRegistro estado, Jugador *jugador,
        //                             int idTesoro);

        /*
        * pre:
        * post: exporta el estado del tablero de jugador a estadoTablero.
        * */
        void exportarEstadoTablero(Jugador *jugador, std::string estadoTablero);

        /*
        * pre: jugador no puede ser nulo.
        * post: Saca una carta del mazo y la almacena en las cartas guardadas del jugador.
        */
        // void sacarCartaDelMazo(Jugador *jugador);

        /*
        * pre: jugador no puede ser nulo.
        * post: Posiciona una mina en un casillero del tablero, si no tiene un tesoro.
        *       En caso de haber un tesoro deja inhabilitado el casillero tanto
        *       turnos como el poder de la mina.
        */
        // void atacarCasillero(Jugador *jugador);

        /*
        * pre: idTesoroVictima y idVictima deben ser mayor a 0.
        * post: Marca el tesoro idTesoroVictima del jugador idVictima como
        *       ENCONTRADO y lo descuenta de la cantidad de tesoros del jugador.
        * */
       void destruirTesoro(int idTesoroVictima, int idVictima);

        /*
        * pre: jugador no puede ser nulo.
        * post: Realiza todas las operaciones que puede hacer un jugador durante su turno.
        * */
        void jugarTurno(Jugador *jugador);

public:
        /*
        * pre: -
        * post: Crea una instancia del TDA TesoroBinario con el tablero 
        *       y los jugadores recibido por parámetro
        */
        TesoroBinario();

        /*
        * pre: -
        * post: Cada jugador esconde sus tesoros dentro por todo el tablero.
        * */
        void inciarJuego();

        /*
        * pre: -
        * post: Devuelve el id del ganador una vez que el resto de los jugadores se quedaron sin tesoros.
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
#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"

enum EstadoJuego {
        JUGABLE,
        FINALIZADO
};

class TesoroBinario {
private:
        Tablero *tablero;
        Jugador **jugadores; //vector dinámico de los jugadores que habrán en el juego
        Mazo *mazo;
        unsigned int cantidadDeJugadores;
        unsigned int cantidadDeJugadoresJugando;
        unsigned int cantidadDeTesoros;
        EstadoJuego estado;
        int idGanador;

        /*
        * pre: -
        * post: Pide al usuario los datos necesarios para configurar el juego.
        */
        void pedirDatosParaJugar(int &cantidadDeJugadores, int &cantidadDeTesoros,
                                 int &anchoTablero, int &altoTablero, int &largoTablero);

        /*
        * pre: estado y jugador no pueden ser nulos. 
        * post: Devuelve como se verá el casillero según estado.
        */
        std::string definirEstadoCasillero(EstadoRegistro estado);

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

        /*
        * pre: -
        * post: Devuelve el estado del juego
        * */
        EstadoJuego getEstado();

        /*
        * pre: estado debe ser JUGABLE O FINALIZADO
        * post: Cambia el estado actual del juego al recibido por parámetro.
        * */
        void setEstado(EstadoJuego estado);

        /*
        * pre:- 
        * post: Define si se puede seguir jugando. En caso de que no se pueda
        *       almacena el id del jugador ganador en idGandor y marca a estado
        *       como FINALIZADO.
        * */
        void revisarJuego();

public:
        /*
        * pre: -
        * post: Crea una instancia del TDA TesoroBinario con el tablero 
        *       y los jugadores recibido por parámetro.
        *       El estado se inicializa en JUGABLE.
        *       idGandor se inicializa en 0.
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
        * post: En caso de haber un ganador lo felicita e informa que el juego
        *       ha finalizado correctamente. Caso contrario informa que juego de forma inesperada.  
        * */
        void finalizarJuego();

        /*
        * pre: -
        * post: Libera la memoria reservada por el TDA TesoroBinario.
        * */
        virtual ~TesoroBinario();
};

#endif //TESOROBINARIO_H_
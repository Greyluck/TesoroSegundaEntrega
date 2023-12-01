#ifndef TESOROBINARIO_H_
#define TESOROBINARIO_H_

#include "Tablero.h"
#include "Jugador.h"
#include "Mazo.h"
#include "Interfaz.h"
#include "Imagen.h"

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
        Interfaz *interfaz; //Interfaz que interactuará con los jugadores
        Imagen *imagen;

        /*
        * pre: estado no puede ser nulo. 
        * post: Devuelve como se verá el casillero según estado.
        */
        std::string definirEstadoCasillero(EstadoRegistro estado);

        /*
        * pre: estado no puede ser nulo. 
        * post: Devuelve el bitmap a copiar según estado.
        */
       std::string definirBitmapACopiar(EstadoRegistro estado);

        /*
        * pre: - 
        * post: exporta el estado del tablero de jugador a estadoTablero.
        * */
        void exportarEstadoTablero(Jugador *jugador, std::string estadoTablero);

        /*
        * pre:
        * post: muestra el estado del tablero en general.
        * */
        void mostrarTablero();

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
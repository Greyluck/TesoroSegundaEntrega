#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Tesoro.h"
#include "Tablero.h"
#include "Carta.h"
#include "Mazo.h"

enum EstadoJugador {
        NORMAL,
        PERDIO_TURNO, //definir si tiene este nombre o se lo cambia por otro
        ELIMINADO
};

class Jugador{
private:
        int id;
        std::string nombre;
        EstadoJugador estado;
        int cantidadDeTesoros; //definir si sólo debe ser mayor a 0 ó debe estar dentro de un rango.
        Tesoro **tesoros;
        // int cantidadTesorosDescubiertos;
        std::string estadoTablero; //archivo donde se exportará el estado del tablero del jugador
        Carta *cartaActiva;
        int cantidadCartasGuardadas;
        Carta **cartasGuardadas; //definir cuantas cartas guardadas puede tener un jugador durante el juego
        bool gano;
public:
        /*
        * pre: nombre no puede ser nulo.
        *       cantidadDeTesoros debe ser mayor a 0.
        * post: Crea una instancia de un jugador con el nombre y la cantidad de tesoros recibida por parámetro.
        *       El estado del jugador se inicializa en NORMAL. 
        */
        Jugador(int id, std::string nombre, int cantidadDeTesoros);

        /*
        * pre: idTesoro debe estar dentro del rango 1 - cantidadDeTesoros inclusives.
        *      fila, columna y altura deben estar dentro de los limites del tablero.
        *      tablero no puede ser nulo.
        * post: Esconde el tesoro con el id recibido en la fila, columna y
        *       altura indicadas por parámetro
        * */
        void escoderTesoro(int idTesoro, int fila, int columna, int altura, Tablero *tablero);

        /*
        * pre: fila, columna y altura deben estar dentro de los limites del tablero.
        * post: Coloca un espia en la fila, columna y altura indicadas.
        * */
        void ponerEspia(int fila, int columna, int altura);

        /*
        * pre: mazo y tablero no pueden ser nulos.
        * post: Saca una carta del mazo y la almacena en cartasGuardadas.
        * */
       void sacarCartaDelMazo(Mazo *mazo, Tablero *tablero);

        /*
        * pre: carta no puede ser nula.
        * post: Guarda la carta recibida en cartasGuardadas y aumenta la cantidad de cartas guardadas.
        * */
        void guardarCarta(Carta *carta);

        /*
        * pre: carta debe ser una carta válida dentro del juego.
        * post: Activa la carta recibida por parámetro.
        * */
        void usarCarta(Carta* carta, Tablero *tablero);

        /*
        * pre: -
        * post: Elige una carta de las que están guardadas y luego la devuelve.
        * */
        Carta *elegirCartaAUsar();

        /*
        * pre: carta debe ser una carta válida dentro del juego.
        * post: Descarta la carta recibida por parámetro de las cartas 
        *       guardadas, y reduce la cantidad, si ya fue activada.
        * */
        void descartaCartaUsada(Carta* carta);

        /*
        * pre: -
        * post: Muestra al jugador el nombre de las cartas que tiene guardadas.
        * */
        void verCartasGuardadas();

        /*
        * pre: tablero no puede ser nulo.
        * post: Posiciona una mina en un casillero del tablero, si no tiene un tesoro.
        *       En caso de haber un tesoro deja inhabilitado el casillero tanto
        *       turnos como el poder de la mina.
        *       Si ya había una mina en esa posición, el jugador que la encontró pierde un turno.
        * */
       void atacarCasillero(Tablero *tablero, int &idTesoroVictima, int &idVictima);

        /*
        * pre: -
        * post: Devuelve el poder de la mina que el jugador usará.
        * */
        int usarMina();

        /*
        * pre: idTesoro debe estar entre 1 y la cantidad de tesoros.
        * post: Marca al tesoro idTesoro como ENCONTRADO.
        *       Disminuye en uno la cantidad de tesoros.
        * */
        void descartarTesoro(int idTesoro);

        /*
        * pre: fila, columna y altura deben estar dentro de los limites del tablero.
        * post: Devuelve true si hay un espia en la fila, columna y altura 
        *       indicadas; false sino.
        * */
        bool encontroEspia(int fila, int columna, int altura);

        /*
        * pre: fila, columna y altura deben estar dentro de los limites del tablero.
        * post: Devuelve true si hay un tesoro en la fila, columna y altura 
        *       indicadas; false sino.
        * */
        bool encontroTesoro(int fila, int columna, int altura);

        /*
        * pre: -
        * post: Devuelve true si el jugador ganó el juego; false sino.
        * */
        bool ganoElJuego();

        /*
        * pre: nombre no puede ser nulo.
        * post: modifica el nombre del jugador.
        * 
        void setNombre(std::string nombre);
        */

        /*
        * pre: cantidadActual debe ser mayor o igual a 0;
        * post: Modifica la cantidad de tesoros que tiene el jugador a la actual.
        * */
        void setCantidadDeTesoros(int cantidadActual);

        /*
        * pre: -
        * post: Devuelve el nombre del jugador.
        * */
        std::string getNombre();

        /*
        * pre: -
        * post: Devuelve el estado del jugador.
        * */
        EstadoJugador getEstado();

        /*
        * pre: estado debe ser NORMAL, PERDIO_TURNO ó ELIMINADO.
        * post: Devuelve el estado del jugador.
        * */
        void setEstado(EstadoJugador estado);

        /*
        * pre: -
        * post: Devuelve el id del jugador.
        * */
        int getId();

        /*
        * pre: -
        * post: Devuelve el archivo que contiene el estado del tablero del jugador.
        * */
        std::string getEstadoTablero();

        /*
        * pre: -
        * post: Libera toda la memoria reservada por el jugador.
        * */
        virtual ~Jugador();
};

#endif //JUGADOR_H_
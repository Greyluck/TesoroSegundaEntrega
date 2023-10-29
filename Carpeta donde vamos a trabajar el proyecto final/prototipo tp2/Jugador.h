#ifndef JUGADOR_H_
#define JUGADOR_H_

class Jugador{
private:
        std::string nombre;
        int cantidadDeTesoros;
public:
        /*
        * pre: -
        * post: Crea una instancia de un jugador.
        */
        Jugador();

        /*
        * pre: nombre no puede ser nulo.
        * post: modifica el nombre del jugador.
        * */
        void setNombre(std::string nombre);

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
};

#endif //JUGADOR_H_
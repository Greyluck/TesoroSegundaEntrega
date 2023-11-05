#ifndef TESORO_H_
#define TESORO_H_

enum EstadoTesoro {
        ESCONDIDO,
        PROTEGIDO,
        ENCONTRADO,
        NEUTRO
        };

class Tesoro{
private:
        unsigned int id;
        EstadoTesoro estado;
        unsigned int fila;
        unsigned int columna;
        unsigned int altura;

public:
        /*
        * pre: id debe ser mayor a 0.
        * post: Crea un tesoro con el id recibido, lo incializa en estado
        *       NUETRO y fila, columna y altura en 0.
        */
       Tesoro(int id);

       /*
        * pre: fila, columna y altura deben ser mayores a 0.
        * post: Asigna al tesoro la posición recibida.
        */
       void definirPosicion(unsigned int fila, unsigned int columna, unsigned int altura);

       /*
        * pre: -
        * post: cambia el estado del tesoro al recbido.
        */
       void cambiarEstado(EstadoTesoro estado);

        /*
        * pre: -
        * post: Devuelve el estado del tesoro.
        */
        EstadoTesoro obtenerEstado();

        /*
        * pre: -
        * post: Devuelve la fila en donde está el tesoro.
        * */
        unsigned int getFila();

        /*
        * pre: -
        * post: Devuelve la columna en donde está el tesoro.
        * */
        unsigned int getColumna();

        /*
        * pre: -
        * post: Devuelve la altura en donde está el tesoro.
        * */
        unsigned int getAltura();

       /*
        * pre: -
        * post: -
        */
       virtual ~Tesoro();
};

#endif //TESORO_H_
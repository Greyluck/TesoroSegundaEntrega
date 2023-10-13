#ifndef _TESORO_H_
#define _TESORO_H_

typedef struct{
    int id;
    int fila;
    int columna;
    int turnosEnRecuperacion;
}Tesoro;

/**
* Reserva la memoria necesaria para un tesoro e inicializa todos sus campos en 0,
* excepto el id que lo recibe por parametro.
**/
Tesoro *inicializarTesoro(int id);

/**
* Libera la memoria reservada para tesoro.
**/
void destruirTesoro(Tesoro *tesoro);

#endif // _TESORO_H_

#include "Tesoro.h"

Tesoro *inicializarTesoro(int id){
    Tesoro *tesoro = new Tesoro();

    tesoro->id = id;
    tesoro->columna = 0;
    tesoro->fila = 0;
    tesoro->turnosEnRecuperacion = 0;

    return tesoro;
}

void destruirTesoro(Tesoro *tesoro){
    delete tesoro;
}

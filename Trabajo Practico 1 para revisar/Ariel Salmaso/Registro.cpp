#ifndef REGISTROTP1_H_
#define REGISTROTP1_H_

#include "Registro.h"

void inicializarRegistro(Registro &registro){
    registro.ocupada = false;
    registro.ficha = '-';
}

void setFicha(Registro &registro, char ficha){
    registro.ocupada = true;
    registro.ficha = ficha;
}

void setFicha(Registro *registro, char ficha){
    registro->ocupada = true;
    registro->ficha = ficha;
}

bool isOcupada(Registro &registro){
    return registro.ocupada;
}

bool isAnulada(Registro &registro){
    return registro.isAnulada;
}

//el primer registro de quien hizo la jugada, y el segundo es quien pierde el tesoro r
//si el jugador 1 mueve su tesoro, al tesoro del jugador 2, el jugador 1 no pierde su tesoro, pero si lo mantiene
//"debajo" de la celda anulada, en cambio el jugador 2 lo pierde
void anularRegistro(Registro &registroInicioJugada, Registro &registroPierdeTesoro){
    if (!isAnulada(registroInicioJugada) && !isAnulada(registroPierdeTesoro)){
        registroInicioJugada.isAnulada = true;
        registroPierdeTesoro.isAnulada = true;
        //la ficha que queda por debajo del que perdio el tesoro es el default '-'
        registroPierdeTesoro.fichaAntesDeSerAnulada = '-';
        //el que inicio la jugada simplemente queda la ficha que movio ahi, un 'E', 'T'
        registroInicioJugada.fichaAntesDeSerAnulada = registroInicioJugada.ficha;
        //simplemente anulo ambas tambien
        registroInicioJugada.cantTurnosAnulada = 1;
        registroPierdeTesoro.cantTurnosAnulada = 1;
        //y le pongo que la ficha sean una 'X' diciendo que esta anuladas.
        setFicha(registroInicioJugada, 'X');
        setFicha(registroPierdeTesoro, 'X');
    }
}

#endif /* REGISTROTP1_H_ */
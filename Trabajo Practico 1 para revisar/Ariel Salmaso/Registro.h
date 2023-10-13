#ifndef TP_1_REGISTRO_H
#define TP_1_REGISTRO_H
#include <iostream>


typedef struct {
    bool ocupada;
    char ficha;

    bool isAnulada;
    int cantTurnosAnulada;
    char fichaAntesDeSerAnulada;
} Registro;

//inicaliza el registro, ocupada = false, ficha = '-'
void inicializarRegistro(Registro &registro);

//setea el atributo ficha con el parametro pasado, y ocupada = true.
void setFicha(Registro &registro, char ficha);

//setea el atributo ficha con el parametro pasado, y ocupada = true.
void setFicha(Registro *registro, char ficha);

//anula un registro.
void anularRegistro(Registro &registroInicioJugada, Registro &registroPierdeTesoro);

//devuelve si esta ocupada o no
bool isOcupada(Registro &registro);

//devuelve si esta anulada o no
bool isAnulada(Registro &registro);



#endif //TP_1_REGISTRO_H


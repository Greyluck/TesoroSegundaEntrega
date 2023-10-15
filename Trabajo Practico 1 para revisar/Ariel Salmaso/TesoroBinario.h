#ifndef TP_1_TESOROBINARIO_H
#define TP_1_TESOROBINARIO_H
#include "Tablero.h"

typedef struct {
    Tablero * tablero1;
    Tablero * tablero2;
    int turno;
}TesoroBinario;

//inicializa el struct Tesoro binario
TesoroBinario *iniciarJuego();

//ciclo para jugar
void jugar(TesoroBinario *juego);

//realizar un turno
void hacerTurno(Tablero *tableroTurnoActual, Tablero *tableroRival);

//finaliza el juego, liberando memoria y demas.
void finalizarJuego(TesoroBinario *juego);
#endif //TP_1_TESOROBINARIO_H

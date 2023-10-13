#ifndef TP_1_TABLERO_H
#define TP_1_TABLERO_H
#include <iostream>
#include <string>
#include <vector>
#include "Registro.h"

typedef struct {
    Registro ** matriz;
    int ancho;
    int alto;
    std::string nombreJugador;
    std::vector<Registro*> * punteroRegistrosAnulados;
    int cantidadTesoros;

} Tablero;

//incializa el ancho,alto y la matriz del tablero
Tablero * inicializarTablero(int ancho, int alto, std::string nombreJugador, int cantidadDeTesoros);

//muestra por consola el tablero
void mostrarTablero(Tablero *tablero);

//se encarga de colocar los tesoros
void colocarTesoros(Tablero *tablero);

//Se encarga de fijarse si la partida sigue en curso; false -> si gano alguien
bool isPartidainCurso(Tablero *tablero1, Tablero *tablero2);

//Se encarga de mover un tesoro
void moverTesoro(Tablero *tableroTurnoactual, Tablero *tableroRival);

//Se encarga de colcar espia
void colocarEspia(Tablero *tablero, Tablero *tableroRival);

//libera la memoria utilizada para la matriz
void liberarMemoria(Tablero *tablero);

//verifica quien gano
std::string checkGanador(Tablero *tablero1, Tablero *tablero2);

//exporta el tablero en un archivo de texto.
void exportarTablero(Tablero *tablero, int turno);
#endif //TP_1_TABLERO_H

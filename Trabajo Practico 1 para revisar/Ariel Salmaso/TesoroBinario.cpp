#include <iostream>
#include <string>
#include <vector>
#include "TesoroBinario.h"
#include "Tablero.h"
using namespace std;
TesoroBinario * iniciarJuego(){
    TesoroBinario *juego = new TesoroBinario();

    int ancho,alto;
    string nombre1,nombre2;

    cout << "Bienvenido al Tesoro binario! Diganme sus dos nombres: " << endl;

    cout << "Primer nombre: " << endl;
    cin >> nombre1;

    cout << "Segundo nombre: " << endl;
    cin >> nombre2;

    cout << "Perfecto! ahora indiquen con el tablero que quieren jugar: " << endl;

    cout << "Numero de filas: " << endl;
    cin >> alto;

    cout << "Numero de columnas: " << endl;
    cin >> ancho;

    juego->tablero1 = inicializarTablero(ancho,alto,nombre1,4);
    juego->tablero2 = inicializarTablero(ancho,alto,nombre2,4);
    cout<< "Los tableros fueron iniciados ahora pasaremos a colocar los tesoros!" << endl;
    cout << "Primer jugador colocara sus tesoros" << endl;
    colocarTesoros(juego->tablero1);
    cout << "Ahora el segundo jugador colocara sus tesoros" << endl;
    colocarTesoros(juego->tablero2);
    cout<< "El juego ahora si, comenzara!" << endl;
    juego->turno = 1;
    return juego;
}

void hacerTurno(Tablero *tableroTurnoActual, Tablero *tableroRival){
    std::string entrada;
    cout << "Primero colocara un espia" << endl;
    colocarEspia(tableroTurnoActual,tableroRival);

    cout << "Puede mover un tesoro si-no" << endl;
    cin >> entrada;

    if ( entrada == "si" || entrada == "SI" ){
        moverTesoro(tableroTurnoActual, tableroRival);
    }
}

void finalizarJuego(TesoroBinario *juego){
    string ganador = checkGanador(juego->tablero1, juego->tablero2);
    liberarMemoria(juego->tablero1);
    liberarMemoria(juego->tablero2);
    cout << "El juego ha terminado! Ha ganado: " << ganador << " En un total de: " << juego->turno << " Gracias por jugar! " << endl;
}

void incrementarTurnoRegistrosAnulados(Tablero *tablero){
    std::vector<Registro*> *vectorTablero = tablero->punteroRegistrosAnulados;
    for (int i = 0; i < vectorTablero->size(); i++) {
        Registro *registro = (*vectorTablero)[i];
        if (registro->cantTurnosAnulada < 5) {
            registro->cantTurnosAnulada++;
        } else {
            setFicha(registro, registro->fichaAntesDeSerAnulada);
            registro->cantTurnosAnulada = 0;
            vectorTablero->erase(vectorTablero->begin() + i);
            i--;
        }
    }
}


void jugar(TesoroBinario *juego){
    while(isPartidainCurso(juego->tablero1, juego->tablero2)){
        //turno par primer jugador, turno impar segundo jugador
        if (juego->turno % 2 == 0){
//            for (int i = 0; i < juego->tablero1->punteroRegistrosAnulados->size(); ++i) {
//                Registro  *registro = (*juego->tablero1->punteroRegistrosAnulados)[i];
//                std::cout << "Ficha ahora: " << registro->ficha << endl;
//                std::cout << "Ficha antes de ser anulada:  " << registro->fichaAntesDeSerAnulada << endl;
//                std::cout << "Cantidad de turnos antes de dejar de ser anulada:  " << registro->cantTurnosAnulada << endl;
//            }
            cout << "Es el turno de: " << juego->tablero1->nombreJugador << endl;
            cout << "Turno: " << juego->turno << endl;
            mostrarTablero(juego->tablero1);
            hacerTurno(juego->tablero1,juego->tablero2);
            incrementarTurnoRegistrosAnulados(juego->tablero1);
            exportarTablero(juego->tablero1, juego->turno);
        }
        else{
//            for (int i = 0; i < juego->tablero2->punteroRegistrosAnulados->size(); ++i) {
//                Registro  *registro = (*juego->tablero2->punteroRegistrosAnulados)[i];
//                std::cout << "Ficha ahora: " << registro->ficha << endl;
//                std::cout << "Ficha antes de ser anulada:  " << registro->fichaAntesDeSerAnulada << endl;
//                std::cout << "Cantidad de turnos antes de dejar de ser anulada:  " << registro->cantTurnosAnulada << endl;
//            }
            cout << "Es el turno de: " << juego->tablero2->nombreJugador << endl;
            cout << "Turno: " << juego->turno <<endl;
            mostrarTablero(juego->tablero2);
            hacerTurno(juego->tablero2, juego->tablero1);
            incrementarTurnoRegistrosAnulados(juego->tablero2);
            exportarTablero(juego->tablero2,juego->turno);
        }
        juego->turno++;
    }
    finalizarJuego(juego);
}
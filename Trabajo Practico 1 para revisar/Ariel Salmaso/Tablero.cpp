#include "Tablero.h"
#include "Registro.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

Tablero *inicializarTablero(int ancho, int alto, std::string nombreJugador, int cantidadTesoros) {
    Tablero *tablero = new Tablero();
    tablero->ancho = ancho;
    tablero->alto = alto;
    tablero->nombreJugador = nombreJugador;
    tablero->cantidadTesoros = cantidadTesoros;
    tablero->punteroRegistrosAnulados = new std::vector<Registro*>();
    //array de punteros que apuntan a structs registro.
    tablero->matriz = new Registro*[alto];

    for (int fila = 0; fila < alto; fila++) {
        tablero->matriz[fila] = new Registro[ancho];
        for (int columna = 0; columna < ancho; columna++) {
            Registro &registro = tablero->matriz[fila][columna];
            inicializarRegistro(registro);
        }
    }
    return tablero;
}

void mostrarTablero(Tablero *tablero) {
    //muestra la columnas
    std::cout << "  ";
    for (int columna = 0; columna < tablero->ancho; columna++) {
        std::cout << "| " << (columna + 1) << " ";
    }
    std::cout << "|" << std::endl;

    //muesta el contenido de la matriz
    for (int fila = 0; fila < tablero->alto; fila++) {
        std::cout << (fila + 1) << "|"; //filas

        for (int columna = 0; columna < tablero->ancho; columna++) {
            Registro &registro = tablero->matriz[fila][columna];

            std::cout << " " << registro.ficha << " ";
            std::cout << "|";
        }

        std::cout << std::endl;
    }
}

void colocarTesoros(Tablero *tablero){
    for (int i = 0; i < 4; i++) {
        int fila, columna;
        bool celdaOcupada = true;

        while (celdaOcupada) {
            mostrarTablero(tablero);
            std::cout << "Ingrese la fila para el tesoro " << (i + 1) << ": " << std::endl;
            std::cin >> fila;

            std::cout << "Ingrese la columna para el tesoro " << (i + 1) << ": " << std::endl;
            std::cin >> columna;

            celdaOcupada = isOcupada(tablero->matriz[fila-1][columna-1]);

            //verifico si esta ocupada la fila,columna
            if (celdaOcupada) {
                std::cout << "La celda ya esta ocupada por otro tesoro..." << std::endl;
            }
        }

        //coloco la el tesoro
        setFicha(tablero->matriz[fila-1][columna-1], 'T');
    }
}

bool isPartidainCurso(Tablero *tablero1,Tablero *tablero2){
    return (tablero1->cantidadTesoros > 0 && tablero2->cantidadTesoros > 0);
}

std::string checkGanador(Tablero *tablero1, Tablero *tablero2){
    if(tablero1->cantidadTesoros == 0){
        return tablero2->nombreJugador;
    }else{
        return tablero1->nombreJugador;
    }
}

void moverTesoro(Tablero *tablero, Tablero *tableroRival){
    int filaAntigua,columnaAntigua,filaNueva,columnaNueva;
    std::cout << "Ingrese la fila del tesoro que quiere mover: ";
    std::cin >> filaAntigua;
    std::cout << "Ingrese la columna del tesoro que quiere mover: ";
    std::cin >> columnaAntigua;

    std::cout << "Ingrese la fila a donde quiere mover el tesoro elegido: ";
    std::cin >> filaNueva;
    std::cout << "Ingrese la columna a donde quiere mover el tesoro elegido: ";
    std::cin >> columnaNueva;

    //les resto uno a cada una, para que no se salga de rango de la matriz.
    filaAntigua--, columnaAntigua--;
    //el usuario queria mover algo que no era un tesoro
    if(tablero->matriz[filaAntigua][columnaAntigua].ficha != 'T'){
        std::cout<< "Solamente puedes mover tesoros!" << std::endl;
        return;
    }
    filaNueva--,columnaNueva--;

    inicializarRegistro(tablero->matriz[filaAntigua][columnaAntigua]);
    Registro &registroJugadorActual = tablero->matriz[filaNueva][columnaNueva], &registroRival = tableroRival->matriz[filaNueva][columnaNueva];

    if (!isAnulada(registroJugadorActual)){
        setFicha(registroJugadorActual,'T');
        //verifico si puedo hacer el movimiento
        if ( !isOcupada(registroJugadorActual) && tableroRival->matriz[filaNueva][columnaNueva].ficha != 'T'){
            std::cout<< "Se mueve el tesoro a " << filaNueva << "-" <<columnaNueva<< std::endl;
        }else if(registroRival.ficha == 'T'){
            //el que esta haciendo el turno encontro un tesoro, hay que enviar un espia y anular la celda.
            std::cout << "Has encontrado un tesoro!" << std::endl;
            //anulo los registros de sus respectivos tableros
            anularRegistro(registroJugadorActual, registroRival);
            tablero->punteroRegistrosAnulados->push_back(&registroJugadorActual);
            tableroRival->punteroRegistrosAnulados->push_back(&registroRival);

            //le descuento un tesoro al rival
            tableroRival->cantidadTesoros--;

        }else if (registroRival.ficha == 'E'){
            //el jugador acutal movio donde habia un espia rival
            std::cout << "Has movido tu tesoro donde habia un espia!, la celda sera anulada y se te descontara un cofre!" << std::endl;
            anularRegistro(registroRival, registroJugadorActual);
            tablero->punteroRegistrosAnulados->push_back(&registroJugadorActual);
            tableroRival->punteroRegistrosAnulados->push_back(&registroRival);
            tablero->cantidadTesoros--;
        }
    }else{
        //pierde el turno
        std::cout<<"Esa celda esta anulada...";
    }
}

void colocarEspia(Tablero *tablero, Tablero *tableroRival){
    int filaEspia, columnaEspia;
    std::cout << "Ingrese la fila a donde quiere colocar el espia: ";
    std::cin >> filaEspia;
    std::cout << "Ingrese la columna a donde quiere colocar el espia: ";
    std::cin >> columnaEspia;
    filaEspia--, columnaEspia--;
    if(!isAnulada(tablero->matriz[filaEspia][columnaEspia])){

        if (!isOcupada(tablero->matriz[filaEspia][columnaEspia])){
            setFicha(tablero->matriz[filaEspia][columnaEspia], 'E');

            //se encontro un tesoro
            if(tableroRival->matriz[filaEspia][columnaEspia].ficha == 'T'){
                std::cout<< "Has encontrado un tesoro!, la celda sera anulada y el rival perdera un tesoro!" << std::endl;
                //anulo los registros y le descuento un tesoro al rival
                anularRegistro(tablero->matriz[filaEspia][columnaEspia],tableroRival->matriz[filaEspia][columnaEspia]);
                tablero->punteroRegistrosAnulados->push_back(&tablero->matriz[filaEspia][columnaEspia]);
                tableroRival->punteroRegistrosAnulados->push_back(&tableroRival->matriz[filaEspia][columnaEspia]);
                tableroRival->cantidadTesoros--;
            }

            //se encontro un espia hay que eliminar ambos
            if(tableroRival->matriz[filaEspia][columnaEspia].ficha == 'E'){
                inicializarRegistro(tablero->matriz[filaEspia][columnaEspia]);
                inicializarRegistro(tableroRival->matriz[filaEspia][columnaEspia]);
            }
        }
        else{
            std::cout<< "La fila, columna elegida esta ocupada..." << std::endl;
        }
    }
}

void liberarMemoria(Tablero *tablero){
    for (int fila = 0; fila < tablero->alto; fila++) {
        delete[] tablero->matriz[fila];
    }
    delete[] tablero->matriz;
    delete tablero->punteroRegistrosAnulados;
    delete tablero;
}

void exportarTablero(Tablero *tablero, int turno){
    std::string nombreArchivo;
    nombreArchivo = "tablero_" + tablero->nombreJugador + "_turno_" + std::to_string(turno) + ".txt";
    std::ofstream archivo(nombreArchivo);

    for (int fila = 0; fila < tablero->alto; fila++) {
        for (int columna = 0; columna < tablero->ancho; columna++) {
            Registro &registro = tablero->matriz[fila][columna];
            archivo << registro.ficha << " ";
        }
        archivo << std::endl; //salto de linea
    }

    archivo.close();
}
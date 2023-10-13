#include "TesoroBinario.h"
#include <iostream>
#include <fstream>

static const std::string CELDA_LIBRE = "-";
static const std::string CELDA_TESORO = "T";
static const std::string CELDA_ESPIA = "E";
static const std::string CELDA_NO_DISPONIBLE = "X";
static const std::string CELDA_OCUPADA = "O";
static const std::string SIN_JUGADOR = " ";
static const int ALTO_MAXIMO = ALTO;
static const int ANCHO_MAXIMO = ANCHO;
static const int ALTO_MINIMO = 0;
static const int ANCHO_MINIMO = 0;
static const int SIN_TESORO = 0;
static const int TESORO_RECUPERADO = 5;
static const char MOVER_TESORO = 'S';

TesoroBinario *inicializarTesoroBinario(std::string nombreJugador1, std::string nombreJugador2){
    TesoroBinario *tesoroBinario = new TesoroBinario();

    tesoroBinario->tablero = inicializarTablero();
    tesoroBinario->jugador1 = inicializarJugador(nombreJugador1);
    tesoroBinario->jugador2 = inicializarJugador(nombreJugador2);
    tesoroBinario->finalizado = false;

    return tesoroBinario;
}

/**
* Devuelve true si fila y columna son validas, false sino.
**/
bool esPosicionValida(int fila, int columna){

    if(fila <= ANCHO_MINIMO || columna <= ALTO_MINIMO){
        std::cout << "Esa posicion no es valida, ingrese otra" << std::endl;
        return false;
    }
    else if(fila > ANCHO_MAXIMO || columna > ALTO_MAXIMO){
        std::cout << "Esa posicion no es valida, ingrese otra" << std::endl;
        return false;
    }
    else{
        return true;
    }
}

/**
* Pide una posición valida para un casillero.
**/
void pedirPosicion(int &fila, int &columna){
    std::cout << "Ingrese una posición" << std::endl;
    bool valida = false;
    while(valida == false){
        std::cin >> fila >> columna;
        valida = esPosicionValida(fila, columna);
    }
}

/**
* Le asigna el estado y el nombre del jugador recibidos por parametro a la posición recibida.
**/
void cargarCasillero(Tablero *tablero, std::string jugador, int fila, int columna, EstadoDeRegistro estado, int tesoroId){
    if(tablero->matriz[fila][columna].estado == TESORO){
        tablero->matriz[fila][columna].tesoroId = tesoroId;
    }

    tablero->matriz[fila][columna].estado = estado;

    if(estado != NO_DISPONIBLE){
        tablero->matriz[fila][columna].ocupada = true;
    }

    tablero->matriz[fila][columna].jugador = jugador;
}

/**
* Define como se verá el estador recibido por parametro en el tablero.
**/
std::string definirCasillero(EstadoDeRegistro estado){
    switch(estado){
        case LIBRE:
            return CELDA_LIBRE;
            break;
        case TESORO:
            return CELDA_TESORO;
            break;
        case ESPIA:
            return CELDA_ESPIA;
            break;
        case NO_DISPONIBLE:
            return CELDA_NO_DISPONIBLE;
            break;
        case OCUPADA:
            return CELDA_OCUPADA;
            break;
    }
}

/**
* Carga el estado actual del tablero en un archivo y lo guarda en estadoTablero.
**/
void cargarEstadoTablero(Tablero *tablero, std::string estadoTablero, Jugador *jugador){
    std::ofstream estado;
    estado.open(estadoTablero.c_str());

    for(int fila = 0; fila < tablero->ancho; fila++) {
		for(int columna = 0; columna < tablero->alto; columna++) {
            if(tablero->matriz[fila][columna].jugador == jugador->nombre || tablero->matriz[fila][columna].jugador == SIN_JUGADOR){
                estado << " " << definirCasillero(tablero->matriz[fila][columna].estado) << " ";
            }
            else if(tablero->matriz[fila][columna].ocupada == true){
                estado << " " << CELDA_LIBRE << " ";
            }
		}
		estado << std::endl;
	}

	estado << "Tesoros disponibles: " << jugador->cantidadTesoros << " Tesoros descubiertos: " << jugador->cantidadTesorosDescubiertos << std::endl;

    for(int i = 0; i < jugador->cantidadTesoros; i++){
        estado << "Tesoro " << jugador->tesoros[i]->id << " posición: " << jugador->tesoros[i]->fila << " " << jugador->tesoros[i]->columna << std::endl;
    }

	estado.close();
}

/**
* Muestra el estado actual del tablero del jugador de turno en pantalla.
**/
void mostrarTablero(std::string estadoTablero){
    std::ifstream lecturaEstado;
    lecturaEstado.open(estadoTablero.c_str());

    std::string linea;
    while(!lecturaEstado.eof()){
        std::getline(lecturaEstado, linea);
        std::cout << linea << std::endl;
    }

    lecturaEstado.close();
}

/**
* Esconde los tesoros del jugador en las posiciones que este indica, al iniciar el juego.
**/
void esconderTesoros(Jugador *jugador, Tablero *tablero){

    std::cout << "Ingrese nombre del jugador" << std::endl;
    std::cin >> jugador->nombre;
    std::cout << jugador->nombre << " ingresá las posiciones donde esconderás tus tesoros" << std::endl;
    for(int i = 0; i < jugador->cantidadTesoros; i++){
        pedirPosicion(jugador->tesoros[i]->fila, jugador->tesoros[i]->columna);
        cargarCasillero(tablero, jugador->nombre, jugador->tesoros[i]->fila-1, jugador->tesoros[i]->columna-1, TESORO, jugador->tesoros[i]->id);
    }

    cargarEstadoTablero(tablero, jugador->estadoTablero, jugador);
    mostrarTablero(jugador->estadoTablero);
}

void iniciarJuego(TesoroBinario *tesoroBinario){
    std::cout << "Bienvenidos al juego Tesoro Binario (V1.0)" << std::endl;
    esconderTesoros(tesoroBinario->jugador1, tesoroBinario->tablero);
    esconderTesoros(tesoroBinario->jugador2, tesoroBinario->tablero);
}

void mostrarEstadoTableroGeneral(Tablero *tablero){
    std::cout << "Estado general de la partida:" << std::endl;
    for(int fila = 0; fila < tablero->ancho; fila++) {
		for(int columna = 0; columna < tablero->alto; columna++) {
                std::cout << definirCasillero(tablero->matriz[fila][columna].estado);
		}
		std::cout << "\n";
	}
}

/**
* Marca el casillero con el tesoro recuperado como no disponible durante 5 turnos.
**/
void recuperarTesoro(Tablero *tablero, int fila, int columna, Jugador *jugador){

    jugador->tesorosDescubiertos[jugador->cantidadTesorosDescubiertos]->id = tablero->matriz[fila][columna].tesoroId;
    jugador->tesorosDescubiertos[jugador->cantidadTesorosDescubiertos]->fila = fila;
    jugador->tesorosDescubiertos[jugador->cantidadTesorosDescubiertos]->columna = columna;
    jugador->tesorosDescubiertos[jugador->cantidadTesorosDescubiertos]->turnosEnRecuperacion++;
    jugador->cantidadTesorosDescubiertos++;
    jugador->encontroTesoro = true;

    cargarCasillero(tablero, SIN_JUGADOR, fila, columna, NO_DISPONIBLE, SIN_TESORO);
}

/**
* Le indica al jugador el estado del casillero en la posición recibida.
**/
void verEstadoCasillero(Tablero *tablero, int fila, int columna, Jugador *jugador, EstadoDeRegistro nuevoEstado){
    switch(tablero->matriz[fila][columna].estado){
            case TESORO:
                if(nuevoEstado == ESPIA){
                    std::cout << "Encontro un tesoro, recuperando..." << std::endl;
                    std::cout << "El casillero no estara no disponible durante 5 turnos" << std::endl;
                    recuperarTesoro(tablero, fila, columna, jugador);
                }else if(nuevoEstado == TESORO){
                    std::cout << "Encontró un tesoro en la posición " << fila+1 << " " << columna+1 << std::endl;
                    cargarCasillero(tablero, jugador->nombre, fila, columna, OCUPADA, SIN_TESORO);
                }

                break;
            case ESPIA:
                if(nuevoEstado == TESORO){
                    std::cout << "Encontró un espia enemigo en la posición " << fila+1 << " " << columna+1 << std::endl;
                    std::cout << "El casillero no estara no disponible durante 5 turnos" << std::endl;
                    jugador->encontroEspia = true;
                }
                else{
                std::cout << "Encontro un espia enemigo, ambos fueron borrados del tablero" << std::endl;
                cargarCasillero(tablero, SIN_JUGADOR, fila, columna, LIBRE, SIN_TESORO);
                }
                break;
            case NO_DISPONIBLE:
                std::cout << "El casillero no está disponible" << std::endl;
                pedirPosicion(fila, columna);
                cargarCasillero(tablero, jugador->nombre, fila, columna, nuevoEstado, SIN_TESORO);
                break;
        }
}

/**
* Coloca un espia en la posicón que indica el jugador.
**/
void ponerEspia(Tablero *tablero, Jugador *jugador){
    int fila, columna;

    std::cout << "Ingrese la pocion donde pondrá al espia" << std::endl;
    pedirPosicion(fila, columna);
    if(esCasilleroOcupado(tablero, fila-1, columna-1)){
        verEstadoCasillero(tablero, fila-1, columna-1, jugador, ESPIA);
    }
    else{
        cargarCasillero(tablero, jugador->nombre, fila-1, columna-1, ESPIA, SIN_TESORO);
        std::cout << "El espia fue colocado" << std::endl;
    }
}

/**
* Devuelve true si el tesoro fue recuperado; false sino.
**/
bool seRecuperoTesoro(Tesoro &tesoro){
    if(tesoro.turnosEnRecuperacion == TESORO_RECUPERADO){
        std::cout << "El casillero está disponible de nuevo" << std::endl;
        return true;
    }

    if(tesoro.turnosEnRecuperacion > 0){
        tesoro.turnosEnRecuperacion++;
    }

    return false;
}

/**
* Verifica si el tesoro fue recuperado para dejar el casillero libre.
**/
void verificarTesorosRecuperados(Tablero *tablero, Tesoro *tesoros, int cantidadTesorosDescubiertos){
    for(int i = 0; i < cantidadTesorosDescubiertos; i++){
        if(seRecuperoTesoro(tesoros[i])){
            cargarCasillero(tablero, SIN_JUGADOR, tesoros[i].fila, tesoros[i].columna, LIBRE, SIN_TESORO);
        }
    }
}

/**
* Devuelve true si tesoroId es valida; false sino.
**/
bool esIdTesoroValido(int tesoroId, int cantidadTesoros){
    std::cin >> tesoroId;
    if(tesoroId >= 1 && tesoroId <= cantidadTesoros){
        return true;
    }

    std::cout << "Ese id no es valido, ingrese otro" << std::endl;
    return esIdTesoroValido(tesoroId, cantidadTesoros);
}

/**
* Mueve un tesoro a la posición recibida por parametro.
**/
void moverTesoro(Tablero *tablero, Jugador *jugador, int nuevaFila, int nuevaColumna, Jugador *oponente){
    int tesoroId = 0;
    std::cout << "Ingrese el id del tesoro que desea mover (Debe ser entre 1 y " << jugador->cantidadTesoros << ")" << std::endl;
    esIdTesoroValido(tesoroId, jugador->cantidadTesoros);

    pedirPosicion(nuevaFila, nuevaColumna);
    if(esCasilleroOcupado(tablero, nuevaFila-1, nuevaColumna-1)){
        verEstadoCasillero(tablero, nuevaFila-1, nuevaColumna-1, jugador, TESORO);
        if(jugador->encontroEspia){
            recuperarTesoro(tablero, nuevaFila-1, nuevaColumna-1, oponente);
        }
    }
    else{
        cargarCasillero(tablero, jugador->nombre, nuevaFila-1, nuevaColumna-1, TESORO, tesoroId);
        std::cout << "El tesoro con el id" << tesoroId << " fue movido de posición" << std::endl;
    }

    jugador->tesoros[tesoroId-1]->fila = nuevaFila;
    jugador->tesoros[tesoroId-1]->columna = nuevaColumna;
}

/**
* Informa al jugador opnente si jugador principal encontró un tesoro y verifica si alguno de los dos ganó el juego.
**/
void finalizarTurno(Tablero *tablero, Jugador *principal, Jugador *oponente){
    if(principal->encontroTesoro == true){
        oponente->cantidadTesoros--;
        std::cout << oponente->nombre << ", " << principal->nombre << " encontró un tesoro tuyo" << std::endl;
    }

    principal->encontroTesoro = false;
}

/**
* Define si uno de los jugadores ganó el juego.
**/
void definirGanador(Jugador *jugador1, Jugador *jugador2){
    if(jugador1->cantidadTesoros == SIN_TESORO){
        jugador2->gano = true;
    }else if(jugador2->cantidadTesoros == SIN_TESORO){
        jugador1->gano = true;
    }
}

/**
* Devuelve true si uno de los jugadores ganó el juego; false sino.
**/
bool seFinalizoTesoroBinario(bool ganoJugador1, bool ganoJugador2){
    if(ganoJugador1 || ganoJugador2){
        return true;
    }

    return false;
}

/**
* Ejecuta las acciones posibles que puede hacer un jugador durante su turno.
**/
void jugarTurno(Tablero *tablero, Jugador *principal, Jugador *oponente){
    definirGanador(principal, oponente);
    if(seFinalizoTesoroBinario(principal->gano, oponente->gano)){
        return;
    }
    verificarTesorosRecuperados(tablero, *principal->tesorosDescubiertos, principal->cantidadTesorosDescubiertos);
    char opcion;
    int fila, columna;
    std::cout << principal->nombre << " ingresá la posición para poner un espia" << std::endl;
    ponerEspia(tablero, principal);

    std::cout << principal->nombre << " querés mover un tesoro? (Pulse S para si, N para no)" << std::endl;
    std::cin >> opcion;

    if(opcion == MOVER_TESORO){
        moverTesoro(tablero, principal, fila, columna, oponente);
    }

    cargarEstadoTablero(tablero, principal->estadoTablero, principal);
    mostrarTablero(principal->estadoTablero);
    finalizarTurno(tablero, principal, oponente);
}

void jugar(TesoroBinario *tesoroBinario){

    while(tesoroBinario->finalizado == false){
        jugarTurno(tesoroBinario->tablero, tesoroBinario->jugador1, tesoroBinario->jugador2);
        jugarTurno(tesoroBinario->tablero, tesoroBinario->jugador2, tesoroBinario->jugador1);
        mostrarEstadoTableroGeneral(tesoroBinario->tablero);
        tesoroBinario->finalizado = seFinalizoTesoroBinario(tesoroBinario->jugador1->gano, tesoroBinario->jugador2->gano);
    }
}

void finalizarJuego(TesoroBinario *tesoroBinario){

    if(tesoroBinario->jugador1->gano){
        std::cout << "!Felicidades " << tesoroBinario->jugador1->nombre << " ganaste¡" << std::endl;
    }
    else if(tesoroBinario->jugador2->gano){
        std::cout << "!Felicidades " << tesoroBinario->jugador2->nombre << " ganaste¡" << std::endl;
    }

    destruirJugador(tesoroBinario->jugador1);
    destruirJugador(tesoroBinario->jugador2);
    destruirTablero(tesoroBinario->tablero);

    delete tesoroBinario;

    std::cout << "El juego tesoro binario ha finalizado, gracias por jugar" << std::endl;
}

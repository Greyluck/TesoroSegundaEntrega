#include "Carta.h"
const int TIEMPO_RECUPERANDO_TESORO = 5;
Carta::Carta() {
    //devuelve un valor random del 0, 5
    int valorAleatorio = std::rand() % 6;
    switch (valorAleatorio) {
        case 0:
            this->tipoDeCarta = BLINDAJE;
            this->nombreCarta = "Blindaje";
            this->tiempoDeUso = 3;
            break;
        case 1:
            this->tipoDeCarta = RADAR;
            this->nombreCarta = "Radar";
            this->tiempoDeUso = 0;
            break;
        case 2:
            this->tipoDeCarta = PARTIR_TESORO;
            this->nombreCarta = "Partir Tesoro";
            this->tiempoDeUso = 0;
            break;
       case 3:
            this->tipoDeCarta = TELETRANSPORTACION;
            this->nombreCarta = "Teletransportacion";
            this->tiempoDeUso = 0;
            break;
       case 4:
            this->tipoDeCarta = CONGELACION;
            this->nombreCarta = "Congelacion";
            this->tiempoDeUso = 5;
            break;
       case 5:
            this->tipoDeCarta = SUSPENCION_INDISCRIMINADA;
            this->nombreCarta = "Suspención indirscriminada";
            this->tiempoDeUso = 0;
            break;
    }
    this->estadoCarta = NO_USADA;
}

//Protege un tesoro para que no pueda ser agarrado por el rival
void Carta::blindaje(Tablero *tablero,Jugador* jugador) {
    //si el usuario ya tiene un tesoro blindado, no hago nada y la carta no se gasta.
    if (jugador->getTesoroBlindado() != nullptr){
        this->estadoCarta = NO_USADA;
        return;
    }
    int x,y,z,idTesoro;
    while(true){
        std::cout << "Ingrese las coordenadas (x, y, z) del tesoro que quiere proteger." << std::endl;
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
        std::cout << "z: ";
        std::cin >> z;
        if (tablero->getCasillero(x,y,z)->obtenerJugadorId() == jugador->getId() && tablero->getCasillero(x,y,z)->obtenerEstado() == TESORO){
            idTesoro = tablero->getCasillero(x,y,z)->obtenerTesoroId();
            break;
        }
    }
    //metodo getter para los tesoro
    Tesoro* tesoro = jugador->getTesoro(idTesoro);
    tesoro->cambiarEstado(PROTEGIDO);
    tesoro->setCantidadTurnosBlinadado(this->tiempoDeUso);
    std::cout<< "El tesoro " << x << "," << y << "," << z << " se ha protegido correctamente" << std::endl;
}

//Busca tesoros en 3 celdas a la redonda de donde aplico la carta el usuario.
void encontrarTesoros(Tablero* tablero, unsigned int x, unsigned int y,unsigned int z){
    unsigned int filas = tablero->getAlto();
    unsigned int columnas = tablero->getAncho();
    unsigned int profundidad = tablero->getLargo();

    for (unsigned int fila = x-3; fila < x + 4; fila++) {
        for (unsigned int columna = y-3; columna < y + 4; columna++) {
            for (unsigned int distancia = z - 3; distancia < z + 4; distancia++) {
                //chequea que este dentro del rango, y despues si hay un tesoro.
                if (fila < filas && columna < columnas && distancia < profundidad){
                    if(tablero->getCasillero(fila,columna,distancia)->obtenerEstado() == TESORO){
                        std::cout << "Se encuentra un tesoro en la: " << fila << "," << columna << "," << distancia << std::endl;
                    }
                }
            }
        }
    }
}

//Aplica la carta de radar.
void Carta::radar(Tablero *tablero) {
    unsigned int x,y,z;
    std::cout << "Esta utilizando la carta radar, a continuacion le pedire donde lo quiere colocar" << std::endl;
    std::cout << "Ingrese la fila: " << std::endl;
    std::cin >> x;
    std::cout << "Ingrese la columna: " << std::endl;
    std::cin >> y;
    std::cout << "Ingrese la distancia: " << std::endl;
    std::cin >> z;
    encontrarTesoros(tablero,x,y,z);
}

Tesoro** reedimensionarArray(Tesoro** arrayAReedimensionar, int cantTesoros,Tesoro* TesoroNuevo){
    Tesoro** nuevoArray = new Tesoro*[cantTesoros+1];

    for (int i = 0; i < cantTesoros; i++) {
        //aca no va a tirar error, porque itero hasta la cantidad vieja.
        nuevoArray[i] = arrayAReedimensionar[i];
    }
    nuevoArray[cantTesoros] = TesoroNuevo;
    //liberar memoria del viejo array
    // for (int i = 0; i < cantTesoros; i++) {
    //     delete arrayAReedimensionar[i];
    // }
    delete[] arrayAReedimensionar;
    return nuevoArray;
}

//Parte un tesoro, es decir, se le suma un tesoro mas al jugador que la utilizo
void Carta::partirTesoro(Tablero *tablero,Jugador* jugador) {
    int x,y,z;
    int cantTesoros = jugador->getCantidadTesoros();
    Tesoro* tesoroNuevo = new Tesoro(cantTesoros+1);
    Tesoro** tesoros = reedimensionarArray(jugador->getTesoros(), cantTesoros, tesoroNuevo);
    jugador->setTesoros(tesoros);
    jugador->setCantidadDeTesoros(cantTesoros+1);
    bool tesoroMovido = false;
    while (!(tablero->esPosicionValida(x, y, z)
            && !tesoroMovido)){
        std::cout << "Ingrese las coordenadas (x, y, z) de donde quiere colocar el nuevo tesoro" << std::endl;
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
        std::cout << "z: ";
        std::cin >> z;
        //chequear que no haya un espia para mover o una mina
        if(tablero->getCasillero(x,y,z)->obtenerEstado() != MINA
        || tablero->getCasillero(x,y,z)->obtenerEstado() != ESPIA
        || tablero->getCasillero(x,y,z)->obtenerJugadorId() != jugador->getId()){
            std::cout << "Donde se queria telestransportar el tesoro habia una mina o un espia, busque unas nuevas coordenas" << std::endl;
            break;
        }
    }
    std::cout << "Se ha partido un tesoro de manera existosa.";
    //esconde el tesoro nuevo
    jugador->escoderTesoro(cantTesoros+1, 0, 0, 0, tablero);
}

//Aplica la carta teletransportacion (puede mover el tesoro donde quiera), en caso de que donde quiera mover haya un espia
// o una mina, se le pide otras coordenadas
void Carta::teletransportacion(Tablero* tablero,int idJugador,Jugador** jugadores) {
    int x,y,z,idTesoro;
    //chequear que ingrese un tesoro a mover valido
    while(true){
        std::cout << "Ingrese las coordenadas (x, y, z) del tesoro que quiere mover" << std::endl;
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;
        std::cout << "z: ";
        std::cin >> z;
        if (tablero->esPosicionValida(x, y, z) && tablero->getCasillero(x,y,z)->obtenerEstado() == TESORO && tablero->getCasillero(x,y,z)->obtenerJugadorId() == idJugador){
            idTesoro = tablero->getCasillero(x,y,z)->obtenerTesoroId();
            break;
        }

    }

    int filaAMover = 0, columnaAMover = 0, distanciaAmover = 0;
    bool tesoroMovido = false;
    while (!(tablero->esPosicionValida(filaAMover, columnaAMover, distanciaAmover)
            && !tesoroMovido)){
        std::cout << "Ingrese la fila de a donde quiere mover el tesoro" << std::endl;
        std::cin >> filaAMover;
        std::cout << "Ingrese la columna de a donde quiere mover el tesoro" << std::endl;
        std::cin >> columnaAMover;
        std::cout << "Ingrese la distancia de a donde quiere mover el tesoro" << std::endl;
        std::cin >> distanciaAmover;
        //chequear que no haya un espia para mover o una mina
        if(tablero->getCasillero(filaAMover,columnaAMover,distanciaAmover)->obtenerEstado() != MINA
        || tablero->getCasillero(filaAMover,columnaAMover,distanciaAmover)->obtenerEstado() != ESPIA
        || tablero->getCasillero(filaAMover,columnaAMover,distanciaAmover)->obtenerJugadorId() != idJugador){
            std::cout << "Donde se queria telestransportar el tesoro habia una mina o un espia, busque unas nuevas coordenas" << std::endl;
            tesoroMovido = false;
        }else
        {
            tesoroMovido = true;
        }
    }

    if(tablero->getCasillero(filaAMover,columnaAMover,distanciaAmover)->obtenerEstado() != TESORO){
        jugadores[idJugador-1]->escoderTesoro(idTesoro,filaAMover,columnaAMover,distanciaAmover,tablero);
    }else{
        tablero->getCasillero(filaAMover, columnaAMover, distanciaAmover)->inhabilitarRegistro(TIEMPO_RECUPERANDO_TESORO);
    }
}

//La carta congelacion, congela a un usuario que tenga como estado NORMAL, y no le deja usar cartas, durante 5 turnos
//Puse que solamente se le pueda aplicar a jugadores con estado NORMAL, para no crear conflictos con otros estados mas importantes como
//suspendido, etc.
void Carta::congelacion(int idJugador, Jugador **jugadores,int cantidadJugadores) {
    std::cout << "Elija a quien le quiere aplicar la carta congelacion";
    for (int i = 0; i < cantidadJugadores; i++) {
        Jugador* jugador = jugadores[i];
        std::cout << jugador->getNombre() << ":" << jugador->getId();
    }
    int entrada;
    //ver que pasaria si todos los jugadores tienen un estado != normal.
    while(true){
        std::cout << "Elija una jugador colocando su id: ";
        std::cin >> entrada;
        if (entrada > 0 && entrada < cantidadJugadores){
            Jugador* jugadorAfectado = jugadores[entrada-1];
            if(jugadorAfectado->getEstado() == JUGANDO){
                jugadorAfectado->setEstado(CONGELADO);
                jugadorAfectado->setTiempoCongelado(this->tiempoDeUso);
                break;
            }else{
                continue;
            }
        }
    }
}

void Carta::suspensionIndiscriminada(Jugador **jugadores, int cantidadJugadores) {

    // define un número al azar entre 0 y cantidadJugadores y le suma 1
    int idJugadorCongelado = ((std::rand() % cantidadJugadores) + 1);
    
    std::cout << "El jugador " << jugadores[idJugadorCongelado-1]->getNombre() << " ha sido congelado." << std::endl;
    jugadores[idJugadorCongelado-1]->setEstado(SUSPENDIDO);
}

std::string Carta::getNombreCarta() {
    return this->nombreCarta;
}

void Carta::aplicarCarta(Tablero* tablero,int idJugador, Jugador** jugadores, int cantidadJugadores) {
    this->estadoCarta = USADA;
    switch (this->tipoDeCarta) {
        case BLINDAJE:
            this->blindaje(tablero,jugadores[idJugador-1]);
            break;

        case RADAR:
            this->radar(tablero);
            break;

        case PARTIR_TESORO:
            this->partirTesoro(tablero,jugadores[idJugador-1]);
            break;

        case TELETRANSPORTACION:
            this->teletransportacion(tablero,idJugador, jugadores);
            break;

        case CONGELACION:
            this->congelacion(idJugador,jugadores, cantidadJugadores);
            break;
        
        case SUSPENCION_INDISCRIMINADA:
        this->suspensionIndiscriminada(jugadores, cantidadJugadores);
    }
}

Carta::~Carta() {

}

int Carta::getTiempoDeUso() {
    return this->tiempoDeUso;
}

EstadoCarta Carta::checkEstadoCarta() {
    return this->estadoCarta;
}


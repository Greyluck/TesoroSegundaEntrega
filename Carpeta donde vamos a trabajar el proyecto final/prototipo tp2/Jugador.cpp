#include "Jugador.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// definir cantidad maxima de cartas guardadas definitiva.
const int CANTIDAD_MAXIMA_CARTAS_GUARDADAS = 3;
const std::string ARCHIVO = "estadoTablero.txt";
const int TIEMPO_RECUPERANDO_TESORO = 5;

void Jugador::pedirPosicion(Tablero * tablero, int & fila, int & columna, int & altura)
{
        while(!tablero->esPoscionValida(fila, columna, altura)){
                std::cout << "Ingrese la fila: ";
                std::cin >> fila;
                std::cout << "Ingrese la columna: ";
                std::cin >> columna;
                std::cout << "Ingrese la distancia: ";
                std::cin >> altura;
        }
}

void Jugador::definirNuevaPosicionTesoro(int idTesoro, unsigned int &fila,
                                         unsigned int &columna, unsigned int &altura)
{
        unsigned int filaAnterior = this->tesoros[idTesoro-1]->getFila();
        unsigned int columnaAnterior = this->tesoros[idTesoro-1]->getColumna();
        unsigned int AlturaAnterior = this->tesoros[idTesoro-1]->getAltura();
        int direccion;

        // Consulta la nueva cordenada basada en la anterior
        std::cout << " Se esta moviendo el cofre en la posicion ("<< filaAnterior <<"|"<< columnaAnterior << "|" << AlturaAnterior << ")"<< std::endl;
        std::cout << " - Hacia donde movera el tesoro" << std::endl;
        std::cout << " (1) Arriba (2) Abajo (3) Izquierda (4) Derecha (5) Atras (6) Adelante: ";
        std::cin >> direccion;
        switch(direccion) {
                case 1:     // Arriba
                std::cout << " - Se desea mover hacia arriba";
                fila = filaAnterior;
                columna = columnaAnterior-1;
                altura = AlturaAnterior;
                break;
                case 2:     // Abajo
                std::cout << " - Se desea mover abajo";
                fila = filaAnterior;
                columna = columnaAnterior+1;
                altura = AlturaAnterior;
                break;
                case 3:     // Izq
                std::cout << " - Se desea mover la izquierda";
                fila = filaAnterior;
                columna = columnaAnterior;
                altura = AlturaAnterior-1;
                break;
                case 4:     // Der
                std::cout << " - Se desea mover hacia la derecha";
                fila = filaAnterior;
                columna = columnaAnterior+1;
                altura = AlturaAnterior;
                break;
                case 5: //Atras
                std::cout << " - Se desea mover hacia atras";
                fila = filaAnterior-1;
                columna = columnaAnterior;
                altura = AlturaAnterior;
                break;
                case 6: //Adelante
                std::cout << " - Se desea mover hacia adelante";
                fila = filaAnterior+1;
                columna = columnaAnterior;
                altura = AlturaAnterior;
                break;
                default:    // Default
                break;
        }        
}

Jugador::Jugador(int id, std::string nombre, int cantidadDeTesoros)
{
        if(id <= 0){
                throw "El id debe ser mayor a 0";
        }

        this->id = id;
        this->nombre = nombre;
        this->estado = JUGANDO;
        this->tiempoSuspendido = 0;
        
        this->cantidadDeTesoros = cantidadDeTesoros;
        this->tesoros = new Tesoro*[cantidadDeTesoros]();
        for(int i = 0; i < this->cantidadDeTesoros; i++){
                this->tesoros[i] = new Tesoro(i+1);
        }
        this->cantidadDeTesorosDisponibles = cantidadDeTesoros;
        
        this->cartaActiva = NULL;
        this->cantidadCartasGuardadas = 0;
        this->cartasGuardadas = new Carta*[CANTIDAD_MAXIMA_CARTAS_GUARDADAS]();
        for(int i = 0; i < this->cantidadCartasGuardadas; i++){
                this->cartasGuardadas[i] = new Carta();
        }

        this->estadoTablero = ARCHIVO;
        this->gano = false;
}

void Jugador::escoderTesoro(int idTesoro, int fila, int columna, int altura, Tablero * tablero)
{
        if(idTesoro <= 0){
                throw "El id del tesoro debe ser mayor a 0";
        }

        this->tesoros[idTesoro-1]->definirPosicion(fila, columna, altura);

        tablero->getCasillero(fila, columna, altura)->cambiarEstado(TESORO);
        tablero->getCasillero(fila, columna, altura)->definirTesoroId(idTesoro);
        tablero->getCasillero(fila, columna, altura)->definirJugadorId(this->id);
}

void Jugador::moverTesoro(Tablero * tablero, int & idTesoroVictima, int & idVictima)
{
        if(this->estado == JUGANDO){
                int idTesoro;
                unsigned int nuevaFila, nuevaColumna, nuevaAltura;

                std::cout << "\nIngrese el id del tesoro que moverá" << std::endl;
                std::cout << "Debe estar entre 1 y " << this->cantidadDeTesorosDisponibles << std::endl;
                std::cin >> idTesoro;
                while(!(idTesoro > 0 && idTesoro <= this->cantidadDeTesorosDisponibles)){
                        std::cout << "Es tesoro no es válido, pruebe con otro" << std::endl;
                        std::cin >> idTesoro;
                }

                unsigned int filaAnterior = this->tesoros[idTesoro-1]->getFila();
                unsigned int columnaAnterior = this->tesoros[idTesoro-1]->getColumna();
                unsigned int AlturaAnterior = this->tesoros[idTesoro-1]->getAltura();

                bool tesoroMovido = false;
                while(!tesoroMovido){
                        definirNuevaPosicionTesoro(idTesoro, nuevaFila, nuevaColumna, nuevaAltura);                
                        std::cout << " desde ("<< filaAnterior <<"|"<< columnaAnterior << "|" << AlturaAnterior << ") --> (" << nuevaFila <<"|"<< nuevaColumna <<  "|" << nuevaAltura <<")."<< std::endl;

                        // Verifica que la nueva posición este dentro del tablero. Sino lo esta, pregunta de nuevo.
                        if (tablero->esPoscionValida(nuevaFila, nuevaColumna, nuevaAltura)){
                                if(tablero->getCasillero(nuevaFila, nuevaColumna, nuevaAltura)->obtenerEstado() == TESORO){
                                std::cout<<"Encontró un tesoro en la posición ("<<nuevaFila<<"|"<<nuevaColumna<<"|"<<nuevaAltura<<")"<<std::endl;         
                                tablero->getCasillero(nuevaFila, nuevaColumna, nuevaAltura)->cambiarEstado(OCUPADA);
                                }else if(tablero->getCasillero(nuevaFila, nuevaColumna, nuevaAltura)->obtenerEstado() == MINA){
                                        std::cout << "Encontraste una mina de otro jugador" << std::endl;
                                        std::cout << "Perdiste un turno" << std::endl;
                                        setEstado(SUSPENDIDO);
                                }else if(tablero->getCasillero(nuevaFila, nuevaColumna, nuevaAltura)->obtenerEstado() == ESPIA){
                                        std::cout << "El tesoro fue encontrado por un espía de otro jugador" << std::endl;
                                        descartarTesoro(idTesoro);
                                        tablero->getCasillero(nuevaFila, nuevaColumna, nuevaAltura)->inhabilitarRegistro(TIEMPO_RECUPERANDO_TESORO);
                                }
                                else{
                                        std::cout << "Se movio el cofre hacia "<< "(" << nuevaFila <<"|"<< nuevaColumna <<  "|" << nuevaAltura <<")."<< std::endl;
                                        tablero->getCasillero(filaAnterior, columnaAnterior, AlturaAnterior)->cambiarEstado(LIBRE);
                                        escoderTesoro(idTesoro, nuevaFila, nuevaColumna, nuevaAltura, tablero);
                                }
                                tesoroMovido = true;
                        }
                        else{
                                std::cout << "Esa posicion esta fuera del tablero.\n"<< std::endl;
                        }
                }
        }
}

void Jugador::sacarCartaDelMazo(Mazo *mazo, Tablero *tablero)
{
        std::string respuesta;

        guardarCarta(mazo->desapilarCarta());
        std::cout << "Has sacado una carta del mazo" << std::endl;
        verCartasGuardadas();
        std::cout << "Desea usar una carta? [s/n]" << std::endl;
        std::cin >> respuesta;

        if(respuesta == "s"){
                usarCarta(elegirCartaAUsar(), tablero);
        }
}

void Jugador::guardarCarta(Carta * carta)
{
        if(this->cantidadCartasGuardadas == 3){
                for(int i = 0; i < CANTIDAD_MAXIMA_CARTAS_GUARDADAS; i++){
                        if(this->cartasGuardadas[i]){
                                descartaCartaUsada(this->cartasGuardadas[i]);
                        }
                }
        }

        this->cartasGuardadas[this->cantidadCartasGuardadas] = carta;
        this->cantidadCartasGuardadas++;
}

void Jugador::usarCarta(Carta *carta, Tablero *tablero)
{
        carta->aplicarCarta(tablero);
}

Carta * Jugador::elegirCartaAUsar()
{
        int numeroCartaElegida = 0;
        std::cout << "Ingrese el número de la carta a utilizar: " << std::endl;
        std::cin >> numeroCartaElegida;
        while(!(numeroCartaElegida > 0 && numeroCartaElegida <= this->cantidadCartasGuardadas)){
                std::cout << "El numero debe estar entre 1 y la cantidad de cartas guardadas inclusive" << std::endl;
                std::cin >> numeroCartaElegida;
        }
        
        return this->cartasGuardadas[numeroCartaElegida-1];
}

void Jugador::descartaCartaUsada(Carta *carta)
{
        // if(this->cartasGuardadas[i]->checkEstado() == USADA){
                this->cantidadCartasGuardadas--;    
        // }
}

void Jugador::verCartasGuardadas()
{
        std::cout << "Cantidad de cartas guardadas: " << this->cantidadCartasGuardadas << std::endl;
        for(int i = 0; i < CANTIDAD_MAXIMA_CARTAS_GUARDADAS; i++){
                if(this->cartasGuardadas[i]){
                        // if(this->cartasGuardadas[i]->checkEstado() == DIPONIBLE){
                                std::cout << i+1 << ": " << this->cartasGuardadas[i]->getNombreCarta() << std::endl;
                        // }
                }
        }
}

//definir si queda esté nombre, la función sirve tanto para espías como para minas
void Jugador::atacarCasillero(EstadoRegistro estado, Tablero * tablero, int & idTesoroVictima, int & idVictima)
{
        int fila = 0, columna = 0, altura = 0;
        int poderMina = usarMina();

        if(estado == MINA){
                std::cout << "\nIngrese la posición donde pondrá la mina" << std::endl;
        }else
        {
                std::cout << "\nIngrese la posición donde pondrá al espía" << std::endl;
        }
        
        pedirPosicion(tablero, fila, columna, altura);

        if(tablero->getCasillero(fila, columna, altura)->obtenerEstado() == TESORO){
                idVictima = tablero->getCasillero(fila, columna, altura)->obtenerJugadorId();
                idTesoroVictima = tablero->getCasillero(fila, columna, altura)->obtenerTesoroId();
                if(estado == MINA){
                        tablero->getCasillero(fila, columna, altura)->inhabilitarRegistro(poderMina);
                }else
                {
                        tablero->getCasillero(fila, columna, altura)->inhabilitarRegistro(TIEMPO_RECUPERANDO_TESORO);
                }
        }else if(tablero->getCasillero(fila, columna, altura)->obtenerEstado() == MINA){
                setEstado(SUSPENDIDO);
                tablero->getCasillero(fila, columna, altura)->cambiarEstado(LIBRE);
                std::cout << "Encontraste una mina de otro jugador" << std::endl;
                std::cout << "Perdiste un turno" << std::endl;
        }else if(tablero->getCasillero(fila, columna, altura)->obtenerEstado() == ESPIA){
                if(estado == ESPIA){
                        tablero->getCasillero(fila, columna, altura)->cambiarEstado(LIBRE);
                        std::cout << "Encontraste un espia de otro jugador" << std::endl;
                        std::cout << "Ambos espias fueron eliminados" << std::endl;
                }
        }else
        {
                tablero->getCasillero(fila, columna, altura)->cambiarEstado(estado);
                tablero->getCasillero(fila, columna, altura)->definirJugadorId(this->id);

                if(estado == MINA){
                        std::cout << "La mina ha sido colocada... vayan con cuidado" << std::endl;
                }else
                {
                        std::cout << "El espía fue colocado en la posición indicada" << std::endl;
                }
        }
}

int Jugador::usarMina()
{
        //Devuelve un valor random entre 1 y 5.
        int poderMina = (std::rand() % 5) + 1;
        return poderMina;
}

void Jugador::descartarTesoro(int idTesoro)
{
        this->tesoros[idTesoro-1]->cambiarEstado(ENCONTRADO);
        this->cantidadDeTesorosDisponibles--;

        //si el jugador se queda sin tesoros queda eliminado del juego
        if(this->cantidadDeTesorosDisponibles == 0){
                std::cout << this->getNombre() << " te has quedado sin tesoros disponibles, fuiste eliminado" << std::endl;
                setEstado(ELIMINADO);
        }
}

bool Jugador::encontroEspia(int fila, int columna, int altura)
{
        return false;
}

bool Jugador::encontroTesoro(int fila, int columna, int altura)
{
        return false;
}

bool Jugador::ganoElJuego()
{
        return false;
}

void Jugador::setCantidadDeTesoros(int cantidadActual)
{
}

std::string Jugador::getNombre()
{
        return this->nombre;
}

void Jugador::setEstado(EstadoJugador estado)
{
        this->estado = estado;

        if(estado == SUSPENDIDO){
                this->tiempoSuspendido = 1;
        }
}

EstadoJugador Jugador::getEstado()
{
        return this->estado;
}

int Jugador::getId()
{
        return this->id;
}

std::string Jugador::getEstadoTablero()
{
        return this->estadoTablero;
}

bool Jugador::estaSuspendido()
{
        if(this->estado != ELIMINADO && this->tiempoSuspendido == 0){
                setEstado(JUGANDO);
        }else
        {
                this->tiempoSuspendido--;
        }

        return this->estado == SUSPENDIDO;
}

Jugador::~Jugador()
{
        for(int i = 0; i < CANTIDAD_MAXIMA_CARTAS_GUARDADAS; i++){
                delete this->cartasGuardadas[i];
        }
        delete []cartasGuardadas;

        for(int i = 0; i < this->cantidadDeTesoros; i++){
                delete this->tesoros[i];
        }
        delete []tesoros;
}
#include "Registro.h"

static const std::string NOMBRE_VACIO = " ";
static const int ID_TESORO_NULO = 0;
static const int MIN_TIEMPO_INHABILITADO = 0;
static const int MAX_TIEMPO_INHABILITADO = 5;

Registro::Registro(unsigned int x, unsigned int y, unsigned z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->estado = LIBRE;
    this->jugador = NOMBRE_VACIO;
    this->tesoroId = ID_TESORO_NULO;
    this->tiempoInhabilitado = MIN_TIEMPO_INHABILITADO;
}

Registro::~Registro(){
}

EstadoRegistro Registro::obtenerEstado(){
    estaInhabilitado();
    return this->estado;
}

bool Registro::estaLibre(){
    return (this->estado == LIBRE);
}

bool Registro::estaInhabilitado(){
    if(this->tiempoInhabilitado > MAX_TIEMPO_INHABILITADO){
        this->tiempoInhabilitado = MIN_TIEMPO_INHABILITADO;
        this->estado = LIBRE;
    }
    else if(this->tiempoInhabilitado > MIN_TIEMPO_INHABILITADO){
        contarTiempoInhabilitado();
    }

    return (this->estado == NO_DISPONIBLE);
}

void Registro::contarTiempoInhabilitado(){
        this->tiempoInhabilitado++;
}

void Registro::cambiarEstado(EstadoRegistro estado){
    if(estaInhabilitado()){
        throw "No se puede cambiar el estado del registro mientras está inhabilitado";
    }
    else{
        this->estado = estado;
        if(estaInhabilitado()){
         contarTiempoInhabilitado();
        }
    }
}

std::string Registro::obtenerJugador(){
    return this->jugador;
}

void Registro::definirJugador(std::string jugador){
    this->jugador = jugador;
}

int Registro::obtenerTesoroId(){
    return this->tesoroId;
}

void Registro::definirTesoroId(int id){
    if(id < 0){
        throw "El id debe ser positivo.";
    }

    this->tesoroId = id;
}

unsigned int Registro::getX(){
    return this->x;
}

unsigned int Registro::getY(){
    return this->y;
}

unsigned int Registro::getz(){
    return this->z;
}

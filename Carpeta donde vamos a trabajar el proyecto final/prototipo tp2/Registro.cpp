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
    this->jugador->getNombre() = NOMBRE_VACIO;
    this->tesoroId = ID_TESORO_NULO;
    this->tiempoInhabilitado = MIN_TIEMPO_INHABILITADO;
}

Registro::~Registro(){
}

EstadoRegistro Registro::obtenerEstado(){
    return this->estado;
}

bool Registro::estaLibre(){
    return (this->estado == LIBRE);
}

bool Registro::estaInhabilitado(){
    if(this->tiempoInhabilitado > MIN_TIEMPO_INHABILITADO){
        contarTiempoInhabilitado();
    }
    else
    {
        this->estado = LIBRE;
    }

    return (this->estado == NO_DISPONIBLE);
}

void Registro::inhabilitarRegistro(int tiempoInhabilitado)
{
    if(tiempoInhabilitado <= MIN_TIEMPO_INHABILITADO){
        throw "El tiempo que el resgistro está inhabilitado debe ser mayor a 0";
    }
    
    this->estado = NO_DISPONIBLE;
    this->tiempoInhabilitado = tiempoInhabilitado;

}

void Registro::contarTiempoInhabilitado(){
        this->tiempoInhabilitado--;
}

void Registro::cambiarEstado(EstadoRegistro estado){
    this->estado = estado;
}

Jugador *Registro::obtenerJugador(){
    return this->jugador;
}

void Registro::definirJugador(Jugador *jugador){
    if(!jugador){
        throw "El jugador no puede ser nulo";
    }
    
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

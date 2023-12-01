#include "Registro.h"

static const int ID_JUGADOR_NULO = 0;
static const int ID_TESORO_NULO = 0;
static const int MIN_TIEMPO_INHABILITADO = 0;

Registro::Registro(unsigned int x, unsigned int y, unsigned z)
{
    if(x <= 0 || y <= 0 || z <= 0){
        throw std::string("La posición del registro debe ser válida");
    }

    this->x = x;
    this->y = y;
    this->z = z;
    this->estado = LIBRE;
    this->jugadorId = ID_JUGADOR_NULO;
    this->tesoroId = ID_TESORO_NULO;
    this->tiempoInhabilitado = MIN_TIEMPO_INHABILITADO;
}

Registro::~Registro()
{
}

EstadoRegistro Registro::obtenerEstado()
{
    return this->estado;
}

bool Registro::estaLibre()
{
    if(this->estado != LIBRE){
        std::cout << "Ese casillero está ocupado. Intente nuevamente" << std::endl;
    }

    return (this->estado == LIBRE);
}

bool Registro::estaInhabilitado()
{
    if(this->estado == NO_DISPONIBLE){
        if(this->tiempoInhabilitado > MIN_TIEMPO_INHABILITADO){
            contarTiempoInhabilitado();
        }
        else
        {
            this->estado = LIBRE;
        }
    }

    return (this->estado == NO_DISPONIBLE);
}

void Registro::inhabilitarRegistro(int tiempoInhabilitado)
{
    if(tiempoInhabilitado <= MIN_TIEMPO_INHABILITADO){
        throw std::string("El tiempo que el resgistro está inhabilitado debe ser mayor a 0");
    }
    
    this->estado = NO_DISPONIBLE;
    this->tiempoInhabilitado = tiempoInhabilitado;
    this->jugadorId = ID_JUGADOR_NULO;
    this->tesoroId = ID_TESORO_NULO;

}

void Registro::contarTiempoInhabilitado()
{
        this->tiempoInhabilitado--;
}

void Registro::cambiarEstado(EstadoRegistro estado)
{
    if(estado == LIBRE){
        this->jugadorId = ID_JUGADOR_NULO;
        this->tesoroId = ID_TESORO_NULO;
    }
    
    this->estado = estado;
}

int Registro::obtenerJugadorId()
{
    return this->jugadorId;
}

void Registro::definirJugadorId(int id)
{
    if(id <= 0){
        throw std::string("El id del jugador tiene que ser mayor a 0");
    }
    
    this->jugadorId = id;
}

int Registro::obtenerTesoroId()
{
    return this->tesoroId;
}

void Registro::definirTesoroId(int id)
{
    if(id <= 0){
        throw std::string("El id debe ser positivo.");
    }

    this->tesoroId = id;
}

unsigned int Registro::getX()
{
    return this->x;
}

unsigned int Registro::getY()
{
    return this->y;
}

unsigned int Registro::getz()
{
    return this->z;
}

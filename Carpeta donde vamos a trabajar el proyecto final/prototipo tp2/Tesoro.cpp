#include "Tesoro.h"

Tesoro::Tesoro(int id){
        if(id <= 0){
                throw "El id debe ser mayor a 0";
        }

        this->id = id;
        this->estado = NEUTRO;
        this->fila = 0;
        this->columna = 0;
        this->altura = 0;
}

void Tesoro::definirPosicion(unsigned int fila, unsigned int columna, unsigned int altura)
{
        //validar?
        this->fila = fila;
        this->columna = columna;
        this->altura = altura;
}

void Tesoro::cambiarEstado(EstadoTesoro estado)
{
        this->estado = estado;
}

EstadoTesoro Tesoro::obtenerEstado()
{
        return this->estado;
}

Tesoro::~Tesoro()
{
}

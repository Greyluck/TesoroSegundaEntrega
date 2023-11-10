#include "Tesoro.h"

Tesoro::Tesoro(int id){
        if(id <= 0){
                throw "El id debe ser mayor a 0";
        }

        this->id = id;
        this->estado = NEUTRO;
        this->tiempoBlindado = 0;
        this->fila = 0;
        this->columna = 0;
        this->altura = 0;
}

void Tesoro::definirPosicion(unsigned int fila, unsigned int columna, unsigned int altura)
{
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

unsigned int Tesoro::getColumna()
{
        return this->columna;
}

unsigned int Tesoro::getAltura()
{
        return this->altura;
}

unsigned int Tesoro::getFila()
{
        return this->fila;
}

int Tesoro::getCantidadTurnosBlindado(){
        return this->tiempoBlindado;
}

void Tesoro::setCantidadTurnosBlinadado(int cantidadTurnos){
        if(cantidadTurnos < 0){
                throw "La cantidad de turnos debe ser > a 0";
        }
        this->tiempoBlindado = cantidadTurnos;
}

void Tesoro::disminuirCantidadTurnosBlindado(){
        this->tiempoBlindado--;
}

Tesoro::~Tesoro()
{
}

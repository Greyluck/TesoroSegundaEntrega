/*
 * Tablero.h
 *
 *  Created on: 05/10/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Lista.h"
#include "Registro.h"

class Tablero {
private:
	Lista<Lista<Lista<Registro*>*>*> *registros;
	unsigned int ancho;
	unsigned int alto;
	unsigned int distancia;
public:
	/**
	 * pre: ancho, alto y distancia deben ser positivos.
	 * post: Crea un tablero tridimensional de ancho*alto*profundidad
	 */
	Tablero(unsigned int ancho, unsigned int alto, unsigned int distancia);

	/**
	 * pre: -
	 * post: Libera la memoria reservada por el tablero
	 */
	virtual ~Tablero();

	/**
	 * pre: -
	 * post: Devuelve el alto del tablero
	 */
	unsigned int getAlto();

	/**
	 * pre: -
	 * post: Devuelve el ancho del tablero
	 */
	unsigned int getAncho();

	/**
	 * pre: -
	 * post: Devuelve la distancia del tablero
	 */
	unsigned int getDistancia();

    /**
	 * pre: x, y, z deben ser positivos y estar dentro del rango del tamaño del tablero.
	 * post: Devuelve el registro que se encuentra la posición recibida por parámetro.
	 */
	Registro* getCasillero(unsigned int x, unsigned int y, unsigned int z);
};

#endif /* TABLERO_H_ */

#ifndef REGISTRO_H_
#define REGISTRO_H_

#include <iostream>
#include "Jugador.h"

enum EstadoRegistro{
    OCUPADA,
	TESORO,
	ESPIA,
	NO_DISPONIBLE,
	LIBRE,
    MINA
};

class Registro{
private:
    EstadoRegistro estado;
    unsigned int x;
    unsigned int y;
    unsigned int z;
    //std::string jugador; //determinar si conviene tener el nombre del jugador o un puntero hacia el jugador
    Jugador *jugador;
    int tesoroId;
    int tiempoInhabilitado;

    /**
    * Pre: -
    * Post: Reduce en uno el tiempo que el registro est� inhabilitado si el registro esta inhabilitado.
    **/
    void contarTiempoInhabilitado();

public:
    /**
    * Pre: x, y, z deben ser positivos
    * Post: Inicializa el registro como libre.
    **/
    Registro(unsigned int x, unsigned int y, unsigned z);

    /**
    * Pre: -
    * Post: -
    **/
    virtual ~Registro();

    /**
    * Pre: -
    * Post: Devuelve true si el registro est� libre; false sino.
    **/
    bool estaLibre();

    /**
    * Pre: -
    * Post: Devuelve true si el registro esta inhabilitado; false sino.
    **/
    bool estaInhabilitado();

    /**
    * Pre: -
    * Post: Inhabilita el registro la cantidad de turnos indicada.
    **/
    void inhabilitarRegistro(int tiempoInhabilitado);

    /**
    * Pre: -
    * Post: Devuelve el estado del registro
    **/
    EstadoRegistro obtenerEstado();

    /**
    * Pre: estado debe ser OCUPADA,	TESORO, ESPIA, NO_DISPONIBLE o LIBRE
    * Post: Cambia el estado del registro.
    **/
    void cambiarEstado(EstadoRegistro estado);

    /**
    * Pre: -
    * Post: Devuelve el nombre del jugador que est� usando el registro.
    **/
    Jugador *obtenerJugador();

    /**
    * Pre: jugador no puede ser nulo.
    * Post: Define al jugador que est� usando el registro.
    **/
    void definirJugador(Jugador *jugador);

    /**
    * Pre: -
    * Post: Devuelve el id del tesoro que tiene el registro.
    *       En caso que el registro no tenga un tesoro devuelve 0;
    **/
    int obtenerTesoroId();

    /**
    * Pre: id deber positivo.
    * Post: Define el id del tesoro que tiene el registro.
    **/
    void definirTesoroId(int id);

    /**
	 * pre:
	 * post:
	 */
	unsigned int getX();

	/**
	 * pre:
	 * post:
	 */
	unsigned int getY();

	/**
    * Pre: -
    * Post:
    **/
	unsigned int getz();
};

#endif // REGISTRO_H_

#ifndef REGISTRO_H_
#define REGISTRO_H_

#include "Bibliotecas.h"

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
    // std::string jugador; //determinar si conviene tener el nombre del jugador o un puntero hacia el jugador
    int jugadorId;
    int tesoroId;
    int tiempoInhabilitado;

    /**
    * Pre: -
    * Post: Reduce en uno el tiempo que el registro está inhabilitado si el registro esta inhabilitado.
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
    * Post: Devuelve true si el registro está libre; false sino.
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
    * Pre: estado debe ser OCUPADA,	TESORO, ESPIA, NO_DISPONIBLE, LIBRE ó MINA
    * Post: Cambia el estado del registro.
    *       Si estado es igual a LIBRE setea el id del jugador y el tesoro que
    *       tiene el registro en ID_JUGADOR_NULO Y ID_TESORO_NULO respectivamente.
    **/
    void cambiarEstado(EstadoRegistro estado);

    /**
    * Pre: -
    * Post: Devuelve el id del jugador que está usando el registro.
    **/
    int obtenerJugadorId();

    /**
    * Pre: id debe ser mayor a 0.
    * Post: Define el id del jugador que está usando el registro.
    **/
    void definirJugadorId(int id);

    /**
    * Pre: -
    * Post: Devuelve el id del tesoro que tiene el registro.
    *       En caso que el registro no tenga un tesoro devuelve 0;
    **/
    int obtenerTesoroId();

    /**
    * Pre: id debe ser mayor a 0.
    * Post: Define el id del tesoro que tiene el registro.
    **/
    void definirTesoroId(int id);

    /**
	 * pre: -
	 * post: delvuelve la coordenada X del registro.
	 */
	unsigned int getX();

	/**
	 * pre: -
	 * post: devuelve la coordenada Y del registro
	 */
	unsigned int getY();

	/**
    * Pre: -
    * Post: devuelve la coordenada Z del registro
    **/
	unsigned int getz();
};

#endif // REGISTRO_H_

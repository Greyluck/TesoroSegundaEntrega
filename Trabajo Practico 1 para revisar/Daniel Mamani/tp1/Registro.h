#ifndef REGISTRO_H_
#define REGISTRO_H_

#include <iostream>

enum EstadoDeRegistro{
	OCUPADA,
	TESORO,
	ESPIA,
	NO_DISPONIBLE,
	LIBRE
};

typedef struct {
	bool ocupada;
    EstadoDeRegistro estado;
    std::string jugador;
    int tesoroId;
} Registro;

/**
* Inicializa todos los campos del puntero registro recibido por parámetro.
**/
void inicializarRegistro(Registro *registro);


#endif //REGISTRO_H_

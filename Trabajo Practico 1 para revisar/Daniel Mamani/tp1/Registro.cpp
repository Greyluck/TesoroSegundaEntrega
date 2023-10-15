#include "Registro.h"
#include <iostream>

static const std::string NOMBRE_VACIO = " ";
static const int ID_TESORO_NULO = 0;

void inicializarRegistro(Registro *registro) {
	registro->ocupada = false;
	registro->estado = LIBRE;
	registro->jugador = NOMBRE_VACIO;
	registro->tesoroId = ID_TESORO_NULO;
}

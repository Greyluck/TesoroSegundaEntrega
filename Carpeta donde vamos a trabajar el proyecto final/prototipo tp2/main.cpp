// #include "TesoroBinario.h"
#include "Tablero.h"
#include <iostream>

int main() {
	
	//prueba del juego
	// TesoroBinario *tesoroBinario = new TesoroBinario();
	// tesoroBinario->inciarJuego(2);
	// //se genera un segmetation fall luego de esconder tomar la pocision del
	// //primer tesoro del primer jugador
	// delete tesoroBinario;

	// return 0;

	//caso de tablero tridimensional con listas
	Tablero *tablero = new Tablero(1, 1, 1);
	for(unsigned int i = 1; i <= tablero->getAncho(); i++){
	for(unsigned int j = 1; j <= tablero->getAlto(); j++){
	for(unsigned int k = 1; k <= tablero->getLargo(); k++){
		tablero->getCasillero(i, j, k)->cambiarEstado(LIBRE);
	}
	}
	}

	tablero->getCasillero(1, 1, 1)->cambiarEstado(NO_DISPONIBLE);
	//tablero->getCasillero(1, 1, 1)->cambiarEstado(TESORO);

	int contador = 0;
	while(contador < 2){
	for( unsigned int i = 1; i<= tablero->getAncho(); i++) {
	std::cout << tablero->getCasillero(i, 0, 0)->obtenerEstado() << std::endl;
		for( unsigned int j = 1; j<= tablero->getAlto(); j++) {
	for(unsigned int k = 1; k <= tablero->getLargo(); k++){
		std::cout << tablero->getCasillero(i, j, k)->obtenerEstado();
	}
	std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	contador++;
	}


	delete tablero;
}

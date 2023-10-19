#include "Tablero.h"
#include <iostream>

int main() {
    /*
	{ //Caso de tablero con listas
		Tablero * tablero = new Tablero(3,3);
		for(unsigned int i = 1; i <= tablero->getAncho(); i++){
            for(unsigned int j = 1; j <= tablero->getAlto(); j++){
                tablero->getCasillero(i, j)->setFicha('0');
            }
		}

		tablero->getCasillero(2, 2)->setFicha('A');

		for( unsigned int i = 1; i<= tablero->getAncho(); i++) {
			for( unsigned int j = 1; j<= tablero->getAlto(); j++) {
				std::cout << tablero->getCasillero(i, j)->getFicha();
			}
			std::cout << std::endl;
		}

		delete tablero;
        */

		//caso de tablero tridimensional con listas
		Tablero *tablero = new Tablero(1, 2, 2);
		for(unsigned int i = 1; i <= tablero->getAncho(); i++){
            for(unsigned int j = 1; j <= tablero->getAlto(); j++){
                for(unsigned int k = 1; k <= tablero->getDistancia(); k++){
                    tablero->getCasillero(i, j, k)->cambiarEstado(LIBRE);
                }
            }
		}

		tablero->getCasillero(1, 1, 1)->cambiarEstado(NO_DISPONIBLE);
		//tablero->getCasillero(1, 1, 1)->cambiarEstado(TESORO);

		int contador = 0;
		while(contador < 10){
                for( unsigned int i = 1; i<= tablero->getAncho(); i++) {
                std::cout << tablero->getCasillero(i, 0, 0)->obtenerEstado() << std::endl;
			for( unsigned int j = 1; j<= tablero->getAlto(); j++) {
                for(unsigned int k = 1; k <= tablero->getDistancia(); k++){
                    std::cout << tablero->getCasillero(i, j, k)->obtenerEstado();
                }
                std::cout << std::endl;
			}
			std::cout << std::endl;
		}
            contador++;
		}


		delete tablero;

	//Terminar el TDA Tablero, Casillero y main
	//Hacerlo para 3 dimensiones
}

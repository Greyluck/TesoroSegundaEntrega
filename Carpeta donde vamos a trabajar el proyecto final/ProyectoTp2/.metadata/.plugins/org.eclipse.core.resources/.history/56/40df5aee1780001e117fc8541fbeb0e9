#include "TesoroBinario.h"
#include "Bibliotecas.h"
int main() {
	//agrego esto, que lo necesito para generar las cartas aleatorias
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	//prueba del juego
	TesoroBinario *tesoroBinario = new TesoroBinario();
	tesoroBinario->inciarJuego();
	tesoroBinario->jugarJuego();
	tesoroBinario->finalizarJuego();
	delete tesoroBinario;

	return 0;


	// // prueba de mazo para resover pérdida de memoria
	// std::cout << "Se crea un mazo pra 2 jugadores (tiene 6 cartas)" << std::endl;
	// Mazo *mazo = new Mazo(2);
	// std::cout << "Cada jugador toma una carta" << std::endl;
	// Carta *miCarta1 = mazo->desapilarCarta();
	// Carta *miCarta2 = mazo->desapilarCarta();

	// std::cout << "Se usan las cartas" << std::endl;
	// std::cout << "Carta 1: " << miCarta1->getNombreCarta() << std::endl;
	// std::cout << "Carta 2: " << miCarta2->getNombreCarta() << std::endl;

	// std::cout << "Se eliminan las cartas de los jugadores" << std:: endl;
	// delete miCarta1;
	// delete miCarta2;

	// std::cout << "Se elimina el mazo y no queda memoria colgada" << std::endl;
	// delete mazo;


	// //prueba de la pila para arreglar perdida de memoria
	// Pila<int*> *ptrosInt = new Pila<int*>();
	// //se agregan 5 elementos a la pila.
	// std::cout << "Se agrega 1 a la pila" << std::endl;
	// ptrosInt->apilar((int*)1);
	// std::cout << "Se agrega 2 a la pila" << std::endl;
	// ptrosInt->apilar((int*)2);
	// std::cout << "Se agrega 3 a la pila" << std::endl;
	// ptrosInt->apilar((int*)3);
	// std::cout << "Se agrega 4 a la pila" << std::endl;
	// ptrosInt->apilar((int*)4);
	// std::cout << "Se agrega 5 a la pila" << std::endl;
	// ptrosInt->apilar((int*)5);

	// //se remueven 2 enlementos de la pila
	// std::cout << "Se desapila el elemento " << ptrosInt->desapilar() << std::endl;
	// std::cout << "Se desapila el elemento " << ptrosInt->desapilar() << std::endl;

	// //se muestran todos lo elementos de la pila y luego se desapilan.
	// while(!ptrosInt->estaVacia()){
	// 	std::cout << "Elemento "<< ": " << ptrosInt->verTope() << std::endl;
	// 	std::cout << "Se desapila el elemento " << ptrosInt->desapilar() << std::endl;
	// }

	// //se elimina la pila y no debe quedar memoria colgada.
	// delete ptrosInt;


	//caso de tablero tridimensional con listas
	// Tablero *tablero = new Tablero(1, 1, 1);
	// for(unsigned int i = 1; i <= tablero->getAncho(); i++){
	// for(unsigned int j = 1; j <= tablero->getAlto(); j++){
	// for(unsigned int k = 1; k <= tablero->getLargo(); k++){
	// 	tablero->getCasillero(i, j, k)->cambiarEstado(LIBRE);
	// }
	// }
	// }

	// tablero->getCasillero(1, 1, 1)->cambiarEstado(NO_DISPONIBLE);
	// //tablero->getCasillero(1, 1, 1)->cambiarEstado(TESORO);

	// int contador = 0;
	// while(contador < 2){
	// for( unsigned int i = 1; i<= tablero->getAncho(); i++) {
	// std::cout << tablero->getCasillero(i, 0, 0)->obtenerEstado() << std::endl;
	// 	for( unsigned int j = 1; j<= tablero->getAlto(); j++) {
	// for(unsigned int k = 1; k <= tablero->getLargo(); k++){
	// 	std::cout << tablero->getCasillero(i, j, k)->obtenerEstado();
	// }
	// std::cout << std::endl;
	// 	}
	// 	std::cout << std::endl;
	// }
	// contador++;
	// }


	// delete tablero;
}

#include "TesoroBinario.h"

const std::string NOMBRE_JUEGO = "TESORO BINARIO";

TesoroBinario::TesoroBinario(Tablero *tablero, 
                             unsigned int cantidadDeJugadores){
        if(!tablero){
                throw "El tablero no puede ser nulo";
        }
        if(cantidadDeJugadores <= 1){
                throw "Se necesitan 2 o más jugadores para jugar";
        }
        
        this->tablero = tablero;

        this->jugadores = new Jugador * [cantidadDeJugadores];
        for(int i = 0; i < cantidadDeJugadores; i++){
                this->jugadores[i] = new Jugador();
        }

        this->cantidadDeJugadores = cantidadDeJugadores; 
}

/*
* pre: jugadores no puede ser nulo.
* post: Presenta el juego y define la cantidad tanto de jugadores como tesoros tendrá el juego.
*/
//nose si esta función conviete tenerla como método de esta clase o que esté en un archivo a parte
void mensajeBienvenida(int cantidadDeTesoros, int cantidadDeJugadores, Jugador **jugadores) {
        if(!jugadores){
                throw "Necesito el vector con los jugadores";
        }

	std::cout << "BIENVENIDOS A " << NOMBRE_JUEGO << std::endl << std::endl;
        std::cout << "¿Cuantas personas jugarán? (ingrese un número mayor a 2)" << std::endl;
        std::cin >> cantidadDeJugadores;
        std::cout << "¿Cuantos tesoros tendrá cada jugador? (ingrese un número mayor a 0)" << std::endl;
        std::cin >> cantidadDeTesoros;

        std::cout << "Ingrese el nombre de cada jugador (ingreselos separados por un enter)" << std::endl;
        for(int i = 0; i < cantidadDeJugadores; i++){
                std::cout << "Ingrese el nombre del jugador " << i+1 << std::endl;
                //tiene que haber una manera más prolija
                std::string nombre;
                std::cin >> nombre;
                jugadores[i]->setNombre(nombre);
        }

	std::cout << "Reglas del juego: " << std::endl <<
			"En primer lugar, cada jugador esconderá sus " << cantidadDeTesoros << " tesoros." << std::endl <<
			"Luego, jugarán por turnos, intentando hallar los otros tesoros a través de sus espías." << std::endl <<
			"La cantidad de jugadores permitida es " << cantidadDeJugadores << "." << std::endl <<
                        "Ahora sí, ¡BUENA SUERTE!" << std::endl << std::endl;
                        //agregar una breve presentación de las cartas
}

bool pedirTesoro(Tablero *tablero, int idTesoro, int fila, int columna, int altura){
        std::cout << "Tesoro " << idTesoro << std::endl;
         
}

void TesoroBinario::inciarJuego(){

        int cantidadDeJugadores, cantidadDeTesoros;
        bool casilleroOcupado = true;
        int fila, columna, altura;

        mensajeBienvenida(cantidadDeTesoros, cantidadDeJugadores, this->jugadores);

        for(int numeroJugador = 0; numeroJugador < this->cantidadDeJugadores; numeroJugador++){
                std::cout << this->jugadores[numeroJugador]->getNombre() << ": ingresá las posiciones de tus " << cantidadDeTesoros << " tesoros." << std::endl;
                for(int numeroTesoro = 0; numeroTesoro < cantidadDeTesoros; numeroTesoro++) {
			while(casilleroOcupado) {
				//casilleroOcupado = pedirTesoro(this->tablero, numeroTesoro + 1, fila, columna, altura);
			}

			this->jugadores[numeroJugador]->setCantidadDeTesoros(cantidadDeTesoros);
                        //modificarJugador(*jugador, jugador->cantidadEspias, jugador->cantidadTesoros + 1, imprimir);

		}
        }


}

TesoroBinario::~TesoroBinario(){
        for(int i = 0; i < this->cantidadDeJugadores; i++){
                delete this->jugadores[i];
        }
        delete [] this->jugadores;
}
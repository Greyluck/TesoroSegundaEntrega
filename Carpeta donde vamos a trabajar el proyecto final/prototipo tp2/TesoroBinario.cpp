#include "TesoroBinario.h"

const std::string NOMBRE_JUEGO = "TESORO BINARIO"; 

void TesoroBinario::pedirDatosParaJugar(int &cantidadDeJugadores, int &cantidadDeTesoros, int &anchoTablero, int &altoTablero, int &largoTablero)
{
        std::cout << "¿Cuantas personas jugarán? (ingrese un número mayor a 2)" << std::endl;
        std::cin >> cantidadDeJugadores;
        std::cout << "¿Cuantos tesoros tendrá cada jugador? (ingrese un número mayor a 0)" << std::endl;
        std::cin >> cantidadDeTesoros;
        std::cout << "¿Cuál será el ancho, el alto y el largo del tablero?" << std::endl;
        std::cout << "Ingrese el numero de cada uno por separado (el numero debe ser mayor que 0)" << std::endl;
        while(anchoTablero <= 0 && altoTablero <= 0 && largoTablero <= 0){
                std::cin >> anchoTablero >> altoTablero >> largoTablero; 
        }
}

void TesoroBinario::definirEstadoCasillero(int fila, int columna, int altura, EstadoRegistro estado, Jugador *jugador, int idTesoro)
{
        this->tablero->getCasillero(fila, columna, altura)->cambiarEstado(estado);
        this->tablero->getCasillero(fila, columna, altura)->definirTesoroId(idTesoro);
        this->tablero->getCasillero(fila, columna, altura)->definirJugadorId(jugador->getId());
        jugador->escoderTesoro(idTesoro, fila, columna, altura);
}

void TesoroBinario::exportarEstadoTablero(Jugador *jugador, std::string estadoTablero)
{
}

TesoroBinario::TesoroBinario()
{
        int anchoTablero = 0, altoTablero = 0, largoTablero = 0;
        int cantidadDeJugadores, cantidadDeTesoros;
        std::string nombreJugador;

        pedirDatosParaJugar(cantidadDeJugadores, cantidadDeTesoros, 
                            anchoTablero, altoTablero, largoTablero);
        
        //crea el tablero con las dimensiones indicadas
        this->tablero = new Tablero(anchoTablero, altoTablero, largoTablero);
        //Al crearse el teblero los registros se inicializan en LIBRE
        
        //pide los nombre de cada jugador
        std::cout << "Ingrese el nombre de cada jugador" << std::endl;
        std::cout << "(ingreselos uno por uno, no todos juntos o separados con espacios)" << std::endl;
        this->jugadores = new Jugador * [cantidadDeJugadores]();
        for(int i = 0; i < cantidadDeJugadores; i++){
                std::cout << "Ingrese el nombre del jugador " << i+1 << std::endl;
                std::cin >> nombreJugador;
                this->jugadores[i] = new Jugador(i+1, nombreJugador, cantidadDeTesoros);
        }

        this->cantidadDeJugadores = cantidadDeJugadores;
        this->cantidadDeTesoros = cantidadDeTesoros;
        this->mazo = new Mazo(this->cantidadDeJugadores);
}

/*
* pre: -
* post: Presenta el juego
*/
//nose si esta función conviete tenerla como método de esta clase o que esté en un archivo a parte
void mensajeBienvenida(int cantidadDeTesoros, int cantidadDeJugadores) {
	std::cout << "BIENVENIDOS A " << NOMBRE_JUEGO << std::endl << std::endl;
	std::cout << "Reglas del juego: " << std::endl <<
			"En primer lugar, cada jugador esconderá sus " << cantidadDeTesoros << " tesoros." << std::endl <<
			"Luego, jugarán por turnos, intentando hallar los otros tesoros a través de sus espías." << std::endl <<
			"La cantidad de jugadores permitida es " << cantidadDeJugadores << "." << std::endl <<
                        "Ahora sí, ¡BUENA SUERTE!" << std::endl << std::endl;
                        //agregar una breve presentación de las cartas
}

void TesoroBinario::inciarJuego(){

        int fila, columna, altura;

        //presenta el juego a los jugadores
        mensajeBienvenida(this->cantidadDeTesoros, this->cantidadDeJugadores);

        for(unsigned int numeroJugador = 0; numeroJugador < this->cantidadDeJugadores; numeroJugador++){
                std::cout << this->jugadores[numeroJugador]->getNombre() << ": ingresá las posiciones de tus " << this->cantidadDeTesoros << " tesoros." << std::endl;
                //esconde los tesoros de cada jugador en el tablero
                for(unsigned int numeroTesoro = 0; numeroTesoro < this->cantidadDeTesoros; numeroTesoro++) {
                        std::cin >> fila >> columna >> altura;
			while(this->tablero->getCasillero(fila, columna, altura)->estaLibre()){
                                definirEstadoCasillero(fila, columna, altura,
                                                       TESORO, this->jugadores[numeroJugador],
                                                       numeroTesoro+1);
                        }
		}
                //se exporta el estado del tablero al archivo del jugador
                exportarEstadoTablero(jugadores[numeroJugador], jugadores[numeroJugador]->getEstadoTablero());
        }
}

TesoroBinario::~TesoroBinario(){
        for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                delete this->jugadores[i];
        }
        delete [] this->jugadores;

        delete this->mazo;
        
        delete this->tablero;
}
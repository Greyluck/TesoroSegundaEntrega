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
                std::cout << "Ingrese el ancho: " << std::endl;
                std::cin >> anchoTablero;
                std::cout << "Ingrese el alto: " << std::endl;
                std::cin >> altoTablero;
                std::cout << "Ingrese el largo: " << std::endl;
                std::cin >> largoTablero;
        }
}

void TesoroBinario::exportarEstadoTablero(Jugador *jugador, std::string estadoTablero)
{
}

void TesoroBinario::destruirTesoro(int idTesoroVictima, int idVictima)
{
        Jugador *victima = this->jugadores[idVictima-1];
        std::cout << "El tesoro " << idTesoroVictima << " de " << victima->getNombre() << " ha sido destruido" << std::endl;
        victima->descartarTesoro(idTesoroVictima);
}

void TesoroBinario::jugarTurno(Jugador * jugador)
{
        int idTesoroVictima = 0, idVictima = 0;

        std::cout << "\nTe toca jugar " << jugador->getNombre() << std::endl;
        jugador->sacarCartaDelMazo(this->mazo, this->tablero);
        jugador->atacarCasillero(this->tablero, idTesoroVictima, idVictima);
        if(idTesoroVictima > 0 && idVictima > 0){
                destruirTesoro(idTesoroVictima, idVictima);
        }
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
                                this->jugadores[numeroJugador]->escoderTesoro(numeroTesoro+1, fila,
                                                                              columna, altura, this->tablero);
                        }
		}
                //se exporta el estado del tablero al archivo del jugador
                exportarEstadoTablero(jugadores[numeroJugador], jugadores[numeroJugador]->getEstadoTablero());
        }
}

int TesoroBinario::jugarJuego()
{
        int idJugadorGanador = 0;

        while(idJugadorGanador == 0){
                for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                        jugarTurno(this->jugadores[i]);
                }

                idJugadorGanador = 1;
        }

        return 0;
}

TesoroBinario::~TesoroBinario(){
        for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                delete this->jugadores[i];
        }
        delete [] this->jugadores;

        delete this->mazo;
        
        delete this->tablero;
}
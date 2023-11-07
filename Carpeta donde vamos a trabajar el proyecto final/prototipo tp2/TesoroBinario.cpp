#include "TesoroBinario.h"
#include <fstream>

static const std::string CELDA_LIBRE = " ";
static const std::string CELDA_TESORO = "T";
static const std::string CELDA_ESPIA = "E";
static const std::string CELDA_NO_DISPONIBLE = "X";
static const std::string CELDA_OCUPADA = "O";
static const std::string CELDA_MINA = "M";

const std::string NOMBRE_JUEGO = "TESORO BINARIO"; 

void TesoroBinario::pedirDatosParaJugar(int &cantidadDeJugadores, int &cantidadDeTesoros, int &anchoTablero, int &altoTablero, int &largoTablero)
{
        std::cout << "¿Cuantas personas jugarán? (ingrese un número mayor a 2)" << std::endl;
        std::cin >> cantidadDeJugadores;
        std::cout << "¿Cuantos tesoros tendrá cada jugador? (ingrese un número mayor a 0)" << std::endl;
        std::cin >> cantidadDeTesoros;
        std::cout << "¿Cuál será el ancho, el alto y el largo del tablero?" << std::endl;
        std::cout << "Ingrese el numero de cada uno por separado (el numero debe ser mayor que 0)" << std::endl;
        while(anchoTablero <= 0 || altoTablero <= 0 || largoTablero <= 0){
                std::cout << "Ingrese el ancho: ";
                std::cin >> anchoTablero;
                std::cout << "Ingrese el alto: ";
                std::cin >> altoTablero;
                std::cout << "Ingrese el largo: ";
                std::cin >> largoTablero;
        }
}

std::string TesoroBinario::definirEstadoCasillero(EstadoRegistro estado)
{
        switch(estado){
                case LIBRE:
                        return CELDA_LIBRE;
                        break;
                case TESORO:
                        return CELDA_TESORO;
                        break;
                case ESPIA:
                        return CELDA_ESPIA;
                        break;
                case NO_DISPONIBLE:
                        return CELDA_NO_DISPONIBLE;
                        break;
                case OCUPADA:
                        return CELDA_OCUPADA;
                        break;
                case MINA:
                        return CELDA_MINA;
                        break;
                default:
                        return CELDA_LIBRE;
                        break;
        }
}

void TesoroBinario::exportarEstadoTablero(Jugador *jugador, std::string estadoTablero)
{
        std::ofstream estado;
        estado.open(estadoTablero.c_str());

        //posible forma de imprimir el tablero con strings. Se debe imprimir como bitmap
        //ua idea para hacerlo es sustituir los strings de los mini tableros con colores
        for(unsigned int i = 1; i <= this->tablero->getAncho(); i++){
                std::cout<<"Fila "<<i<<":"<<std::endl;
                for(unsigned int j = 1; j <= this->tablero->getAlto(); j++){
                        for(unsigned int k = 1; k <= this->tablero->getLargo(); k++){
                                if(this->tablero->getCasillero(i, j, k)->obtenerJugadorId() == jugador->getId() ||
                                   this->tablero->getCasillero(i, j, k)->obtenerJugadorId() == 0){
                                        std::cout<<"|"<<definirEstadoCasillero(this->tablero->getCasillero(i, j, k)->obtenerEstado())<<"|";
                                }else
                                {
                                        std::cout<<"|"<<CELDA_LIBRE<<"|";
                                }
                        }
                        std::cout<<std::endl;
                }
                
        }

        estado.close();
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

        if(jugador->getEstado() == JUGANDO){
                std::cout << "\nTe toca jugar " << jugador->getNombre() << std::endl;
                jugador->sacarCartaDelMazo(this->mazo, this->tablero);
                jugador->atacarCasillero(this->tablero, idTesoroVictima, idVictima);
                if(idTesoroVictima > 0 && idVictima > 0){
                        destruirTesoro(idTesoroVictima, idVictima);
                }
                jugador->ponerEspia(this->tablero, idTesoroVictima, idVictima);
                if(idTesoroVictima > 0 && idVictima > 0){
                        destruirTesoro(idTesoroVictima, idVictima);
                }
                jugador->moverTesoro(this->tablero, idTesoroVictima, idVictima);

                exportarEstadoTablero(jugador, jugador->getEstadoTablero());
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
        this->cantidadDeJugadoresJugando = cantidadDeJugadores;
        this->cantidadDeTesoros = cantidadDeTesoros;
        this->mazo = new Mazo(this->cantidadDeJugadores);
        this->estado = JUGABLE;
        this->idGanador = 0;
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
        
        while(getEstado() == JUGABLE){
                for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                        jugarTurno(this->jugadores[i]);
                }

                revisarJuego();
        }

        return this->idGanador;
}

EstadoJuego TesoroBinario::getEstado(){
        return this->estado;
}

void TesoroBinario::setEstado(EstadoJuego estado){
        this->estado = estado;
}

void TesoroBinario::revisarJuego(){
        // verifica si hay jugadores eliminados y los descuentan de la cantidad que está jugando
        for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                if(this->jugadores[i]->getEstado() == ELIMINADO){
                        this->cantidadDeJugadoresJugando--;
                }
        }

        if(this->cantidadDeJugadoresJugando == 1){
                // Busca al jugador que todavía está jugando.
                for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                        if(this->jugadores[i]->getEstado() != ELIMINADO){
                                this->idGanador = this->jugadores[i]->getId();
                        }
                }
                setEstado(FINALIZADO);
        }
}

void TesoroBinario::finalizarJuego(){
        if(this->idGanador > 0){
                std::cout << "¡FELICITACIONES " << this->jugadores[idGanador-1]->getNombre() << "!" << std::endl;
                std::cout << "Ganaste el juego " << NOMBRE_JUEGO << std::endl;
                std::cout << "El juego ha finalizado con éxito" << std::endl;
        }else
        {
                // definir si agregar esto en caso de que haya ocurrrido en error durante la ejecución del programa
                std::cout << "El juego se cortó de manera inesperada" << std::endl;
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
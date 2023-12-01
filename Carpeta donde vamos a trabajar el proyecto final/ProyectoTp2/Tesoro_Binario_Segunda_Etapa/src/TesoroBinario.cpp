#include "TesoroBinario.h"
#include "Bibliotecas.h"

static const std::string CELDA_LIBRE = "-";
static const std::string BITMAP_CELDA_LIBRE = "EasyBMP/bitmaps/celda_libre2.bmp";
static const std::string CELDA_TESORO = "T";
static const std::string BITMAP_CELDA_TESORO = "EasyBMP/bitmaps/cofre2.bmp";
static const std::string CELDA_ESPIA = "E";
static const std::string BITMAP_CELDA_ESPIA = "EasyBMP/bitmaps/espia2.bmp";
static const std::string CELDA_NO_DISPONIBLE = "X";
static const std::string BITMAP_CELDA_NO_DISPONIBLE = "EasyBMP/bitmaps/celda_no_disponible2.bmp";
static const std::string CELDA_OCUPADA = "O";
static const std::string BITMAP_CELDA_OCUPADA = "EasyBMP/bitmaps/celda_ocupada.bmp";
static const std::string CELDA_MINA = "M";
static const std::string BITMAP_CELDA_MINA = "EasyBMP/bitmaps/mina2.bmp";

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

std::string TesoroBinario::definirBitmapACopiar(EstadoRegistro estado)
{
        switch(estado){
                case LIBRE:
                        return BITMAP_CELDA_LIBRE;
                        break;
                case TESORO:
                        return BITMAP_CELDA_TESORO;
                        break;
                case ESPIA:
                        return BITMAP_CELDA_ESPIA;
                        break;
                case NO_DISPONIBLE:
                        return BITMAP_CELDA_NO_DISPONIBLE;
                        break;
                case OCUPADA:
                        return BITMAP_CELDA_OCUPADA;
                        break;
                case MINA:
                        return BITMAP_CELDA_MINA;
                        break;
                default:
                        return BITMAP_CELDA_LIBRE;
                        break;
        }
}

void TesoroBinario::mostrarTablero()
{
        std::cout << "TABLERO GENERAL" << std::endl;
        for(unsigned int i = 1; i <= this->tablero->getAncho(); i++){
                std::cout<<std::endl;
                std::cout<<"Fila "<<i<<":"<<std::endl;
                for(unsigned int j = 1; j <= this->tablero->getAlto(); j++){
                        for(unsigned int k = 1; k <= this->tablero->getLargo(); k++){
                                std::cout<<definirEstadoCasillero(this->tablero->getCasillero(i, j, k)->obtenerEstado());
                        }
                        std::cout<<std::endl;
                }
                
        }
}

void TesoroBinario::exportarEstadoTablero(Jugador *jugador, std::string estadoTablero)
{
        for(unsigned int i = 1; i <= this->tablero->getAncho(); i++){
                for(unsigned int j = 1; j <= this->tablero->getAlto(); j++){
                        for(unsigned int k = 1; k <= this->tablero->getLargo(); k++){
                                unsigned int x = k;
                                unsigned int y = j;

                                // indica que la imagen debe imprimirse debajo de la anterior.
                                if(j > 1){
                                        y = 20 * (j-1);
                                }

                                // indica que la imagen debe imprimirse a la derecha de la anterior.
                                if(k > 1){
                                        x = 20 * (k-1);
                                }
                                
                                // indica que el subtablero debe imprimirse abajo del subtablero anterior.
                                // al tener más de 2 subtableros se genera un 
                                // error que superpone los tabaleros siguientes con el segundo impreso
                                if(i > 1){
                                        y = ((20 * this->tablero->getLargo()) + i) + (20*(j-1));
                                }

                                if(this->tablero->getCasillero(i, j, k)->obtenerJugadorId() == jugador->getId() ||
                                   this->tablero->getCasillero(i, j, k)->obtenerJugadorId() == 0){
                                        std::string rutaImagenACopiar = definirBitmapACopiar(this->tablero->getCasillero(i, j, k)->obtenerEstado());
                                        this->imagen->copiarImagen(rutaImagenACopiar, x, y, estadoTablero);
                                }else
                                {
                                        this->imagen->copiarImagen(BITMAP_CELDA_LIBRE, x, y, estadoTablero);
                                }
                        }
                }
                
        }
}

void TesoroBinario::jugarTurno(Jugador * jugador)
{
        int idTesoroVictima = 0, idVictima = 0;

        if(jugador->getEstado() != ELIMINADO && (!jugador->estaSuspendido())){
                std::cout << "\nTe toca jugar " << jugador->getNombre() << std::endl;
                jugador->sacarCartaDelMazo(this->mazo, this->tablero,
                                           this->jugadores, this->cantidadDeJugadores);

                // Dejar una MINA
                jugador->atacarCasillero(MINA, this->tablero, idTesoroVictima, idVictima);
                if(idTesoroVictima > 0 && idVictima > 0){
                	this->interfaz->destruirTesoro(this->jugadores[idVictima-1], idTesoroVictima);

                	if(!this->jugadores[idVictima-1]-> getCantidadTesoros()) {
                                    	this->jugadores[idVictima-1]->setEstado(ELIMINADO);
                	}
                	this->revisarJuego();
                	if(this->getEstado() == FINALIZADO) {
                		return;
                	}
                }

                //Dejar un ESPIA
                jugador->atacarCasillero(ESPIA, this->tablero, idTesoroVictima, idVictima);
                if(idTesoroVictima > 0 && idVictima > 0){
                	this->interfaz->destruirTesoro(this->jugadores[idVictima-1], idTesoroVictima);
                	if(!this->jugadores[idVictima-1]->getCantidadTesoros()) {
                		this->jugadores[idVictima-1]->setEstado(ELIMINADO);
                	}
                	this->revisarJuego();
                	if(this->getEstado() == FINALIZADO) {
                		return;
                	}
                }

                //Mover tesoro
                jugador->moverTesoro(this->tablero, idTesoroVictima, idVictima);
        }
}

TesoroBinario::TesoroBinario()
{
        int anchoTablero = 0, altoTablero = 0, largoTablero = 0;
        int cantidadDeJugadores = 0, cantidadDeTesoros = 0;

        this->interfaz = new Interfaz(cantidadDeJugadores, cantidadDeTesoros, 
                            anchoTablero, altoTablero, largoTablero);
        
        //crea el tablero con las dimensiones indicadas
        this->tablero = new Tablero(anchoTablero, altoTablero, largoTablero);
        //Al crearse el tablero los registros se inicializan en LIBRE
        
        this->jugadores = new Jugador * [cantidadDeJugadores]();
        this->cantidadDeJugadores = cantidadDeJugadores;
        this->cantidadDeJugadoresJugando = cantidadDeJugadores;
        this->cantidadDeTesoros = cantidadDeTesoros;
        //pide los nombres de cada jugador y lo crea
        this->interfaz->pedirJugadores(this->jugadores, 
                                       this->cantidadDeJugadores, this->cantidadDeTesoros);

        this->mazo = new Mazo(this->cantidadDeJugadores);
        this->estado = JUGABLE;
        this->idGanador = 0;
        this->imagen = new Imagen(((this->tablero->getAncho() * this->tablero->getAlto())+1) * 20, 
                                  (this->tablero->getLargo()+1) * 20);
}

void TesoroBinario::inciarJuego(){
        //presenta el juego a los jugadores
        this->interfaz->mensajeBienvenida(this->cantidadDeTesoros, this->cantidadDeJugadores);

        for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                this->interfaz->esconderTesorosInciales(this->jugadores[i],
                                                        this->cantidadDeTesoros,
                                                        this->tablero);
                
                mostrarTablero();
                exportarEstadoTablero(jugadores[i], jugadores[i]->getEstadoTablero());
        }
}



int TesoroBinario::jugarJuego()
{
        while(getEstado() == JUGABLE){
                for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                        jugarTurno(this->jugadores[i]);
                        exportarEstadoTablero(this->jugadores[i],
                                              this->jugadores[i]->getEstadoTablero());
                        jugadores[i]->aumentarTurnosBlindaje();
                        jugadores[i]->disminuirTurnoCongelado();
                }
                mostrarTablero();
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
        // verifica si hay algún casillero no disponible para disminuir su tiempo de bloqueo.
        for(unsigned int i = 1; i <= tablero->getAncho(); i++){
	        for(unsigned int j = 1; j <= tablero->getAlto(); j++){
	                for(unsigned int k = 1; k <= tablero->getLargo(); k++){
		                tablero->getCasillero(i, j, k)->estaInhabilitado();
	                }
	        }
	}
        
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
                this->interfaz->mensajeDeDespedida(this->jugadores[idGanador-1]);
        }
}

TesoroBinario::~TesoroBinario(){
        for(unsigned int i = 0; i < this->cantidadDeJugadores; i++){
                delete this->jugadores[i];
        }
        delete [] this->jugadores;

        delete this->mazo;
        delete this->tablero;
        delete this->interfaz;
        delete this->imagen;
}

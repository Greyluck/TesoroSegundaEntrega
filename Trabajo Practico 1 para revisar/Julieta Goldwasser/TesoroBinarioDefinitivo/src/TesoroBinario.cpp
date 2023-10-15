#include "TesoroBinario.h"

#include "Interacciones.h"
#include "Auxiliares.h"

using namespace std;


void inicializarJuego(TesoroBinario &juego) {
	juego.matriz = inicializarTablero();

	for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		inicializarJugador(juego.jugador[numeroJugador], numeroJugador);
	}

}


void iniciarJuego(TesoroBinario &juego) {

	mensajeBienvenida();

	unsigned int posicionFila;
	unsigned int posicionColumna;
	bool casillaOcupada;

	string imprimir;

	Casillero *casillero;
	Jugador *jugador;

	for(unsigned int numeroJugador= 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		cout << "Jugador " << numeroJugador+1 << ": ingrese las posiciones de sus " << CANTIDAD_TESOROS << " tesoros." << endl;
		for(unsigned int numeroTesoro = 0; numeroTesoro < CANTIDAD_TESOROS; numeroTesoro++) {
			casillaOcupada = true;
			while(casillaOcupada) {
				casillaOcupada = pedirTesoro(juego.matriz, numeroTesoro + 1, posicionFila, posicionColumna);
			}

			casillero = &(juego.matriz->casilla[posicionFila][posicionColumna]);
			jugador = &(casillero->jugador[numeroJugador]);
			imprimir = "T" + intToString(numeroJugador+1);

			modificarCasillero(*casillero, true, 0, numeroJugador+1, imprimir);
			modificarJugador(*jugador, jugador->cantidadEspias, jugador->cantidadTesoros + 1, imprimir);

		}

		limpiarPantalla();

	}

	generarArchivos(juego);

}


unsigned int jugarTesoroBinario(TesoroBinario &juego) {

	unsigned int posicionFila = 100; //fila que ingresará el jugador
	unsigned int posicionColumna = 100; //columna que ingresará el jugador

	unsigned int ganador = 0; //lo que devolverá la función

	Casillero *casillero;

	char caracter;

	bool seguir = seguirJugando(juego);

	while(seguir) {
		//jugar

		for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++){

			bool casillaOcupada = true;

			cout << "Es el turno del jugador " << numeroJugador+1 << ":" << endl;
			cout << "Por favor, ingrese la ubicación de un espía." << endl;

			while(casillaOcupada) {
				ingresarTesoroOEspia(posicionFila, posicionColumna);

				casillero = &(juego.matriz->casilla[posicionFila][posicionColumna]);

				casillaOcupada = casillero->ocupado;

				if(casillaOcupada) {
					caracter = casillero->imprimir[0];

					if(caracter == 'E') { //se supone que un jugador no va a ingresar un espia donde ya tiene uno propio, ya que conoce sus posiciones
						eliminarEspias(juego, posicionFila, posicionColumna);
						casillaOcupada = false;

					} else if(caracter == 'T') { //se supone que un jugador no va a ingresar un espia donde tiene untesoro propio, ya que conoce sus posiciones
						tesoroEncontrado(juego, numeroJugador, posicionFila, posicionColumna);
						casillaOcupada = false;

					} else {
						cout << "Casilla inhabilitada. Intente nuevamente." << endl;

					}

				} else {

					juego.jugador[numeroJugador].mensajePrincipal = "Casillero libre. Se ingresa un espía.";

					string imprimir = "E" + intToString(numeroJugador+1);

					modificarCasillero(*casillero, true, 0, numeroJugador + 1, imprimir);
					modificarJugador(casillero->jugador[numeroJugador], 1, 0, imprimir);

				}
			}

			turnosInhabilitados(juego.matriz);

			seguir = seguirJugando(juego);
			if(!seguir) {
				generarArchivos(juego);
				ganador = numeroJugador+1;
				break;
			}

			moverTesoro(juego, numeroJugador);
			generarArchivos(juego);

			limpiarPantalla();

			mostrarEstadoTablero(juego);
		}
	}

	return ganador;

}


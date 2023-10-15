#include "Interacciones.h"
#include "Jugador.h"
#include "Auxiliares.h"

using namespace std;

void mensajeBienvenida() {
	cout << "BIENVENIDOS A " << NOMBRE_JUEGO << endl << endl;
	cout << "Reglas del juego: " << endl <<
			"En primer lugar, cada jugador esconderá sus " << CANTIDAD_TESOROS << " tesoros." << endl <<
			"Luego, jugarán por turnos, intentando hallar los otros tesoros a través de sus espías." << endl <<
			"La cantidad de jugadores permitida es " << CANTIDAD_JUGADORES << "." << endl <<
			"Ahora sí, ¡BUENA SUERTE!" << endl << endl;
}


void terminarJuego(TesoroBinario &juego, unsigned int ganador) {

	mostrarTablero(juego.matriz);

	cout << "Felicidades Jugador " << ganador << "!!! Has ganado el juego " << NOMBRE_JUEGO << ":)" << endl <<
			"F I N   D E L   J U E G O" << endl;

	eliminarTablero(juego.matriz);
}


void mostrarTablero(Tablero *tablero) {
	//Mostrar numero columna
	cout << "    ";
	for(unsigned int i = 1; i < 10; i++) {
		cout << i << "  ";
	}
	for(unsigned int i = 10; i <= tablero->alto; i++) {
		cout << i << " ";
	}


	cout << endl;

	for(unsigned int numeroFila = 0; numeroFila < tablero->ancho; numeroFila++) {
		//Mostrar numero fila
		if(numeroFila < 9) {
			cout << ' ' << numeroFila+1 << "  ";
		} else {
			cout << numeroFila+1 << "  ";
		}

		for(unsigned int numeroColumna = 0; numeroColumna < tablero->alto; numeroColumna++) {
			cout << tablero->casilla[numeroFila][numeroColumna].imprimir << " ";
		}
		cout << endl;
	}

	cout << endl;

}


void generarArchivos(TesoroBinario &juego) {

	for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		ofstream archivo;

		string nombre = juego.jugador[numeroJugador].imprimir + ".txt";
		unsigned int tamaño = nombre.length();

		char *nombreArchivo = new char[tamaño+1];

		nombreArchivo[tamaño] = '\0';
		for(unsigned int posicion = 0; posicion < tamaño; posicion++) {
			nombreArchivo[posicion] = nombre[posicion];
		}

		archivo.open(nombreArchivo, ios::out);

		if(archivo.fail()){
			cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
		} else {

			archivo << juego.jugador[numeroJugador].imprimir << endl << endl;


			//Mostrar numero columna
			archivo << "    ";
			for(unsigned int i = 1; i < 10; i++) {
				archivo << i << "  ";
			}
			for(unsigned int i = 10; i <=juego.matriz->alto; i++) {
				archivo << i << " ";
			}

			archivo << endl;

			for(unsigned int numeroFila = 0; numeroFila < juego.matriz->ancho; numeroFila++) {
				//Mostrar numero fila
				if(numeroFila < 9) {
					archivo << ' ' << numeroFila+1 << "  ";
				} else {
					archivo << numeroFila+1 << "  ";
				}
				//Imprimir tablero
				for(unsigned int numeroColumna = 0; numeroColumna < juego.matriz->alto; numeroColumna++) {
					archivo << juego.matriz->casilla[numeroFila][numeroColumna].jugador[numeroJugador].imprimir << " ";
				}
				archivo << endl;
			}

			archivo << endl << endl;
			archivo << "Mensaje 1: " << juego.jugador[numeroJugador].mensajePrincipal << endl;
			archivo << "Mensaje 2: " << juego.jugador[numeroJugador].mensajeSecundario << endl;
		}

		juego.jugador[numeroJugador].mensajePrincipal = "";
		juego.jugador[numeroJugador].mensajeSecundario = "";

		delete [] nombreArchivo;

	}

}


void ingresarTesoroOEspia(unsigned int &fila, unsigned int &columna) {
	cout << "Fila: ";
	cin >> fila;
	fila--;

	cout << "Columna: ";
	cin >> columna;
	columna--;

	cout << endl;
}


bool pedirTesoro(Tablero* tablero, unsigned int numeroTesoro, unsigned int &fila, unsigned int &columna) {
	cout << "Tesoro " << numeroTesoro << ": " << endl;
	ingresarTesoroOEspia(fila, columna);

	if(tablero->casilla[fila][columna].ocupado == true) {
		cout << "Esa casilla está ocupada. Intente nuevamente." << endl;
		return true;
	}

	return false;
}


void eliminarEspias(TesoroBinario &juego, unsigned int fila, unsigned int columna) {

	Casillero *casillero = &(juego.matriz->casilla[fila][columna]);
	string imprimir = "- ";

	modificarCasillero(*casillero, false, 0, 0, imprimir);
	for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		modificarJugador(casillero->jugador[numeroJugador], 0, 0, imprimir);

		juego.jugador[numeroJugador].mensajePrincipal = "Se ha hallado un espía en la fila " + intToString(fila+1) + " y columna " + intToString(columna+1) + ". Ambos son eliminados.";

	}

}


void tesoroEncontrado(TesoroBinario &juego, unsigned int numeroJugador, int fila, int columna) {

	unsigned int numeroJugadorSinTesoro = juego.matriz->casilla[fila][columna].jugadorActual;

	juego.jugador[numeroJugador].mensajePrincipal = "Felicidades! Has hallado un tesoro del jugador " + intToString(numeroJugadorSinTesoro) + ". La casilla queda inahbilitada durante 5 turnos.";
	juego.jugador[numeroJugadorSinTesoro-1].mensajePrincipal = "Un tesoro tuyo ha sido encontrado :(";

	Jugador *jugadorSinTesoro = &(juego.jugador[numeroJugadorSinTesoro-1]);
	modificarJugador(*jugadorSinTesoro, jugadorSinTesoro->cantidadEspias, jugadorSinTesoro->cantidadTesoros - 1, jugadorSinTesoro->imprimir);

	inhabilitarCasilla(juego.matriz->casilla[fila][columna]);

}


void moverTesoro(TesoroBinario &juego, unsigned int numeroJugador) {
	cout << "¿Desea mover un tesoro?" << endl <<
			"Si la respuesta es NO, ingrese un 0. De lo contrario, toque cualquier tecla" << endl;

	char tecla;
	cin >> tecla;

	if(tecla == '0') {
		cout << endl;
		return;
	}

	cout << "Muy bien. Ingrese las coordenadas del tesoro que quiere mover." << endl; //se supone que el jugador conoce la posición de sus tesoros

	unsigned int filaActual;
	unsigned int columnaActual;
	ingresarTesoroOEspia(filaActual, columnaActual);

	cout << "¿A dónde quiere moverlo?" << endl;

	unsigned int filaNueva;
	unsigned int columnaNueva;

	bool condicion = true;
	while(condicion) {
		ingresarTesoroOEspia(filaNueva, columnaNueva);

		condicion = (filaNueva != filaActual) && (columnaNueva != columnaActual) && ((filaNueva - filaActual) != (columnaNueva - columnaActual));
		if(condicion) {
			cout << "Recuerde: solo puede mover su tesoro vertical, horizontal o diagonalmente. Por favor, intente de nuevo." << endl;
			continue;
		}

		char impresion = juego.matriz->casilla[filaNueva][columnaNueva].imprimir[0];

		if(impresion == 'X') {
			cout << "Casilla inhabilitada: tesoro en proceso de recuperación. Por favor, intente de nuevo." << endl;
			condicion = true;
			continue;
		}
		if(impresion == 'E') {
			juego.jugador[numeroJugador].mensajeSecundario = "El movimiento no fue posible dado a la existencia de un espía en dicha ubicación";
			return;
		}
		if(impresion == 'T') { //se supone que no va a intercambiar un tesoro con otro propio
			juego.jugador[numeroJugador].mensajeSecundario = "Shhh. ¡Has hallado un tesoro! No te olvides de esta posición ;) \nP.D.: no se pudo mover tu tesoro...";
			return;
		}
	}


	intercambiarCasilleros(juego.matriz->casilla[filaActual][columnaActual], juego.matriz->casilla[filaNueva][columnaNueva]);
	juego.jugador[numeroJugador].mensajeSecundario = "Tu tesoro fue movido.";

	limpiarPantalla();


}


void mostrarEstadoTablero(TesoroBinario &juego) {
	for(unsigned int numeroJugador = 0; numeroJugador < CANTIDAD_JUGADORES; numeroJugador++) {
		cout << "Jugador " << intToString(numeroJugador+1) << ": te quedan " << juego.jugador[numeroJugador].cantidadTesoros << " tesoros." << endl;
	}

	cout << endl;

}


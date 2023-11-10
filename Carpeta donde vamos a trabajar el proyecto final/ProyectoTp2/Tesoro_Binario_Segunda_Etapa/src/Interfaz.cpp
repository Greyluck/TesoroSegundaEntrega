#include "Interfaz.h"

Interfaz::Interfaz(int &cantidadDeJugadores, int &cantidadDeTesoros, 
       		int &anchoTablero, int &altoTablero, int &largoTablero)
{
        cout << "BIENVENIDOS A " << NOMBRE_JUEGO << endl << endl;
        cout << "¿Cuantas personas jugarán? (ingrese un número mayor o igual a 2)" << endl;
        cin >> cantidadDeJugadores;
        cout << "¿Cuantos tesoros tendrá cada jugador? (ingrese un número mayor a 0)" << endl;
        cin >> cantidadDeTesoros;
        cout << "¿Cuál será el ancho, el alto y el largo del tablero?" << endl;
        cout << "Ingrese el numero de cada uno por separado (el numero debe ser mayor que 0)" << endl;
        while(anchoTablero <= 0 || altoTablero <= 0 || largoTablero <= 0){
                cout << "Ingrese el ancho: ";
                cin >> anchoTablero;
                cout << "Ingrese el alto: ";
                cin >> altoTablero;
                cout << "Ingrese el largo: ";
                cin >> largoTablero;
        }
}

Interfaz::~Interfaz()
{
	//destructor de la interfaz.
}

void Interfaz::pedirJugadores(Jugador **jugadores, int cantidadDeJugadores,
                              int cantidadDeTesoros)
{
	string nombreJugador;
		
        cout << "Ingrese el nombre de cada jugador" << endl;
        cout << "(ingreselos uno por uno, no todos juntos o separados con espacios)" << endl;
        for(int i = 0; i < cantidadDeJugadores; i++){
                cout << "Ingrese el nombre del jugador " << i+1 << endl;
                cin >> nombreJugador;
                jugadores[i] = new Jugador(i+1, nombreJugador, cantidadDeTesoros);
        }
}

void Interfaz::mensajeBienvenida(int cantidadDeTesoros, int cantidadDeJugadores) {
        cout << "Reglas del juego: " << endl <<
                        "En primer lugar, cada jugador esconderá sus " << cantidadDeTesoros << " tesoros." << endl <<
                        "Luego, jugarán por turnos, intentando hallar los otros tesoros a través de sus espías." << endl <<
                        "La cantidad de jugadores permitida es " << cantidadDeJugadores << "." << endl <<
                        "Ahora sí, ¡BUENA SUERTE!" << endl << endl;
}

void Interfaz::esconderTesorosInciales(Jugador *jugador, 
				     int cantidadDeTesoros, Tablero *tablero){
        if(!jugador){
                throw string("El jugador no puede ser nulo");
        }
        if(cantidadDeTesoros <= 0){
                throw string("La cantidad de tesoros debe ser mayor a 0");
        }

        int x, y, z;

        cout << jugador->getNombre() << ": ingresá las posiciones de tus " << cantidadDeTesoros << " tesoros." << endl;
        for(int i = 0; i < cantidadDeTesoros; i++){
                cout << "\nTesoro " << i+1 << ": " << endl;
                cin >> x >> y >> z;
                while(!tablero->esPosicionValida(x, y, z)){
                        cout << "Esa posición no es válida, pruebe con otra" << endl;
                        cout << "x: ";
                        cin >> x;
                        cout << "y: ";
                        cin >> y;
                        cout << "z: ";
                        cin >> z;

                }
                while(tablero->getCasillero(x, y, z)->estaLibre()){
                        jugador->escoderTesoro(i+1, x, y, z, tablero);
                }
        }
}

void Interfaz::mensajeDeDespedida(Jugador *ganador){
        cout << "¡FELICITACIONES " << ganador->getNombre() << "!" << endl;
        cout << "Ganaste el juego " << NOMBRE_JUEGO << endl;
        cout << "El juego ha finalizado con éxito" << endl;
}

void Interfaz::destruirTesoro(Jugador *victima, int idTesoroVictima)
{
        cout << "El tesoro " << idTesoroVictima << " de " << victima->getNombre() << " fue destruido" << endl;
        victima->descartarTesoro(idTesoroVictima);
}

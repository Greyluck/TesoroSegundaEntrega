#include "Tablero.h"

Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	if(ancho <= 0 && alto <= 0 && largo <= 0){
        throw "La posici�n del tablero no puede ser negativa";
    }

	this->registros = new Lista<Lista<Lista<Registro*>*>*>();
	this->alto = alto;
	this->ancho = ancho;
	this->largo = largo;
	for(unsigned int k = 1; k <= ancho; k++){
        Lista<Lista<Registro*>*> *algo = new Lista<Lista<Registro*>*>();
        for(unsigned int i=1; i <= alto; i++) {
            Lista<Registro*> * fila = new Lista<Registro*>();
            for(unsigned int j=1; j <= largo; j++) {
                fila->agregar(new Registro(k, i, j));
            }
            algo->agregar(fila);
        }
        this->registros->agregar(algo);
	}
}

Tablero::~Tablero() {
    this->registros->iniciarCursor();
    while(this->registros->avanzarCursor()){
        Lista<Lista<Registro*>*> *algo = this->registros->obtenerCursor();
        algo->iniciarCursor();
        while(algo->avanzarCursor()){
            Lista<Registro*> *fila = algo->obtenerCursor();
            fila->iniciarCursor();
            while(fila->avanzarCursor()){
                delete fila->obtenerCursor();
            }
            delete fila;
        }
        delete algo;
    }
    delete this->registros;
}

Registro* Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z) {
	if(x < 0 && y < 0 && z < 0){
        throw "La posici�n del tablero no puede ser negativa";
    }
    if(x > this->ancho && y > this->alto && z > this->largo){
        throw "La posici�n debe estar dentro del tablero";
    }

	return this->registros->obtener(x)->obtener(y)->obtener(z);
}

unsigned int Tablero::getAncho(){
	return this->ancho;
}

unsigned int Tablero::getAlto(){
	return this->alto;
}

unsigned int Tablero::getLargo(){
    return this->largo;
}

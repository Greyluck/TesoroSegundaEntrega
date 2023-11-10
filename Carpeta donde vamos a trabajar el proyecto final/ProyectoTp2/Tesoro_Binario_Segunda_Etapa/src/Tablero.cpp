#include "Tablero.h"

Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	if(ancho <= 0 && alto <= 0 && largo <= 0){
        throw std::runtime_error("El tamaño del tablero no puede ser negativo");
    }

	this->registros = new Lista<Lista<Lista<Registro*>*>*>();
	this->alto = alto;
	this->ancho = ancho;
	this->largo = largo;
	for(unsigned int k = 1; k <= ancho; k++){
        Lista<Lista<Registro*>*> *fila = new Lista<Lista<Registro*>*>();
        for(unsigned int i=1; i <= alto; i++) {
            Lista<Registro*> * columna = new Lista<Registro*>();
            for(unsigned int j=1; j <= largo; j++) {
                columna->agregar(new Registro(k, i, j));
            }
            fila->agregar(columna);
        }
        this->registros->agregar(fila);
	}
}

Tablero::~Tablero() {
    this->registros->iniciarCursor();
    while(this->registros->avanzarCursor()){
        Lista<Lista<Registro*>*> *fila = this->registros->obtenerCursor();
        fila->iniciarCursor();
        while(fila->avanzarCursor()){
            Lista<Registro*> *columna = fila->obtenerCursor();
            columna->iniciarCursor();
            while(columna->avanzarCursor()){
                delete columna->obtenerCursor();
            }
            delete columna;
        }
        delete fila;
    }
    delete this->registros;
}

Registro* Tablero::getCasillero(unsigned int x, unsigned int y, unsigned int z) {
	if(x < 0 && y < 0 && z < 0){
        throw "La posición del tablero no puede ser negativa";
    }
    if(x > this->ancho && y > this->alto && z > this->largo){
        throw "La posición debe estar dentro del tablero";
    }

	return this->registros->obtener(x)->obtener(y)->obtener(z);
}

bool Tablero::esPosicionValida(unsigned int x, unsigned int y, unsigned int z)
{
    if(x > 0 && y > 0 && z > 0 && x <= this->ancho && y <= this->alto && z <= this->largo){
        return true;
    }

    std::cout << "Posición inválida. Intente nuevamente." << std::endl;
    return false;
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

#ifndef TRABAJO_PRACTICO_2_PILA_H
#define TRABAJO_PRACTICO_2_PILA_H
#include "Nodo.h"
#include <stdexcept>
template <class T> class Pila {
private:
    Nodo<T> *tope;
    unsigned int tamanio;
public:
    /*
    * pre: -
    * post: Crea una instancia de la clase Pila, cuando se crea esta vacia
    */
    Pila(){
        this->tope = NULL;
    };

    /*
    * pre: -
    * post: Apila un dato a la pila
    */
    void apilar(T nuevoDato){
        Nodo<T> *nuevoNodo = new Nodo<T>(nuevoDato);
        nuevoNodo->cambiarSiguiente(this->tope);
        this->tope = nuevoNodo;
    };

    /*
    * pre: NO debe estar vacia
    * post: Devuelve el dato de lo ultimo apilado, y lo saca de la pila
    */
    T desapilar(){
        if (this->estaVacia()){
            throw std::runtime_error("La pila esta vacia...");
        }
        T dato = this->tope->obtenerDato();
        Nodo<T> *nodoAEliminar = this->tope;
        this->tope = this->tope->obtenerSiguiente();
        delete nodoAEliminar;
        return dato;
    };

    /*
    * pre: -
    * post: Devuelve si esta vacia true -> vacia, false -> no vacia
    */
    bool estaVacia(){
        return this->tope == NULL;
    };

    /*
    * pre: No debe estar vacia
    * post: Devuelve el dato del tope pero no lo desapila de la pila
    */
    T verTope(){
        if (this->estaVacia()){
            throw std::runtime_error("La pila no puede estar vacia...");
        }
        return this->tope->obtenerDato();
    };

    /*
    * pre: -
    * post: Destruye una instancia de la clase Pila
    */
    ~Pila(){
        while(!this->estaVacia()){
            this->desapilar();
        }
    };
};


#endif //TRABAJO_PRACTICO_2_PILA_H

#include <iostream>
#include "Coordinate.h"
using namespace std;

// TODO: Verificar si es posible evitar pasar coordenadas y que las tome directo del board
void Coordinate::askForCoordinate(int maxColums,int maxRows){
    int acceptedCoordinate = false;
    while (!acceptedCoordinate) {
        int inputV, inputH;
        // Ingresa la coordenada vertical
        std::cout << "   - Ingrese la coordenada vertical: ";
        std::cin >> inputV;
        // Si la vertical esta bien, pide la horizontal
        if (inputV >= 0 && inputV < maxColums) {
            std::cout << "   - Ingrese la coordenada horizontal: ";
            std::cin >> inputH;
            // Si la horizontal tambeinte esta bien, las asigna y acepta la coordenada
            if (inputH >= 0 && inputH < maxRows) {
                horizontal = inputH;
                vertical = inputV;
                acceptedCoordinate = true;
                std::cout << "     (Cordenada valida)" << endl;
            } else {
                std::cout << "  - Fila fuera del tablero, intente de nuevo \n";
            }
        } else {
            std::cout << "  - Columna fuera del tablero, intente de nuevo \n";
        }
    }
}

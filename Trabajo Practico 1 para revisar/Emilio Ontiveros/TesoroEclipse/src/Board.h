#ifndef TESORO_BOARD_H
#define TESORO_BOARD_H
#include <iostream>

class Board {
    // Metodos
public:

    /** Setea los valores iniciales del juego*/
    void setInitialValues(int columns, int rows, int chestQuantity);

    /** Crea un tablero (board) que sera usado para el juego.*/
    void createMatrix();

    /** Solicita al jugador ingresar una celda para colocar un unico tesoro*/
    void placeChest();
    void placeChest(bool replacing, int column, int row);

    /** Solicita al jugador ingresar todos los tesoros iniciales*/
    void placeInitialChests();

    /** Imprime el tablero por pantalla*/
    void printBoard();

    /** Exporta el tablero hacia un documento*/
    void exportBoard();

    /** Devuelve la condicion de victoria (True cuando gano alguien)*/
    bool returnVictoryStatus();

    /** Intercambia el jugador actual*/
    void swapCurentPlayer();

    /** Juega un turno*/
    void playTheTurn();

    /** Consulta al jugador donde colocar su espia y lo coloca si los datos son correctos*/
    void placeTheSpy();

    /** Elimina un cofre de una posicion y le indica al jugador que ingrese una nueva*/
    void moveChest(int column, int row);

    /** Elimina un cofre de una posicion*/
    void removeChest(int column, int row);

    /** Cambia el valor de un casillero para empezar a cavar*/
    void digForTreasure (int column, int row);

    /** Actualiza el tablero y lo exporta*/
    void updateBoard();

    //TODO: Revisar si se requiere crear mas metodos para liberar memoria
    /** Borra el la matriz para liberar memoria*/
    void deleteMatrix(Board board);




#endif //TESORO_BOARD_H
};

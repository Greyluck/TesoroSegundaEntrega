
#include "actividad.h"
#include "mensajes.h"



void actividad(int **matriz, int fila, int columna){
	
	int codigo;
	
	if(matriz[fila][columna] == 5){
		
		matriz[fila][columna] = 4;
		
		codigo = 5;
		mensajes(codigo);
	}
	
	
	
	
	
	else if(matriz[fila][columna] == 4){
		
		matriz[fila][columna] = 3;
		
		codigo = 4;
		mensajes(codigo);
	}
	
	
	
	else if(matriz[fila][columna] == 3){
		
		matriz[fila][columna] = 2;
		
		codigo = 3;
		mensajes(codigo);
	}
	
	
	
	else if(matriz[fila][columna] == 2){
		
		matriz[fila][columna] = 1;
		
		codigo = 1;
		mensajes(codigo);
	}
	
	
	
	
	
	else{
		
		
		matriz[fila][columna] = 0;
		
		codigo = 0;
		mensajes(codigo);
		
	}
	
}

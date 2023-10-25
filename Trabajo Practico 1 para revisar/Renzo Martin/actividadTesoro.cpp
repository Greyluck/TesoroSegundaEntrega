


#include "actividadTesoro.h"
#include "posicionar.h"
#include "mensajes.h"






//************************************************************************************************************************************************************************************************************


void actividadTesoro(int **matriz, int &jugadorUno, int &jugadorDos, int fila, int columna, int turno){
	
	
	int codigo;
	
	
 	if(turno == 1){
 		
 	
 		if(matriz[fila][columna] == 8){
 			
 			matriz[fila][columna] = 88;
 			jugadorUno++;
 			codigo = 88;
 			mensajes(codigo);
 			
 			
		}
		 
		else if(matriz[fila][columna] == 88){
			
			matriz[fila][columna] = 888;
			jugadorUno++;
			codigo = 888;
			mensajes(codigo);
		}
		
		
		
		else if(matriz[fila][columna] == 888){
			
			matriz[fila][columna] = 8888;
			jugadorUno++;
			codigo = 8888;
			mensajes(codigo);
		}
		
		
		
		
		
		else if(matriz[fila][columna] == 9){
			
			matriz[fila][columna] = 98;
			jugadorUno++;
			codigo = 98;
			mensajes(codigo);
		 
		 	
		}
		
		else{
			
			codigo = 8989;
			mensajes(codigo);
			posicionar();
		}
 	
 	}
 	
 	
 	
 	
 	
 	if(turno == 2){
 		
 		
 	
 		if(matriz[fila][columna] == 9){
 			
 			matriz[fila][columna] = 99;
 			jugadorDos++;
 			codigo = 99;
 			mensajes(codigo);
		}
		
		
		 
		else if(matriz[fila][columna] == 99){
			
			matriz[fila][columna] = 999;
			jugadorDos++;
			codigo = 999;
			mensajes(codigo);	
		}
		
		
		
		else if(matriz[fila][columna] == 999){
			
			matriz[fila][columna] = 9999;
			jugadorDos++;
			codigo = 9999;
			mensajes(codigo);
			
		}
		
		
		
		
		else if(matriz[fila][columna] == 8){
			
			matriz[fila][columna] = 89;
			jugadorDos++;
			codigo = 89;
			mensajes(codigo);
		}
		
		
		
		
		else{
			
			codigo = 8989;
			mensajes(codigo);
			posicionar();
		}
 	
 	}

}







//***********************************************************************************************************************************************************************************************************




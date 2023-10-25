





#include <iostream>

#include "posicionar.h"
#include "actividadTesoro.h"
#include  "actividad.h"
#include "mensajes.h"


//**********************************************************************************************************************************************************************************************************




void posicionarEspia(int **matriz, int &jugadorUno, int &jugadorDos, int fila, int columna, int turno){
	
	
	
	if(turno == 1){
		
		
		
		if(matriz[fila][columna] == 8 || matriz[fila][columna] == 88 || matriz[fila][columna] == 888  || matriz[fila][columna] == 8888 ){
			
			std::cout<< "Tiene un tesoro en esta posicion, pierde el turno"<<"\n\n\n";
		}
		
		
		else if(matriz[fila][columna]  == 9 || matriz[fila][columna] == 99 || matriz[fila][columna] == 999 || matriz[fila][columna] == 9999 ){
			
			
			if(matriz[fila][columna] == 9){
				jugadorDos--;
			}
			
			
			
			else if(matriz[fila][columna] == 99){
				jugadorDos--;
				jugadorDos--;	
			}
			
			
			
			
			else if(matriz[fila][columna] == 999){
				jugadorDos--;
				jugadorDos--;
				jugadorDos--;
			}
			
			
			
			else{
				
				jugadorDos = 0;
				matriz[fila][columna] = 5;
			}
		}
	}
	
	
	
	
	
	
	if(turno == 2){
		
		
		if(matriz[fila][columna] == 9 || matriz[fila][columna] == 99 || matriz[fila][columna] == 999 || matriz[fila][columna] == 9999 ){
			
			std::cout<< "Tiene un tesoro en esta posicion, pierde el turno"<<"\n\n\n";
		}
		
		
		else if(matriz[fila][columna]  == 8 || matriz[fila][columna] == 88 || matriz[fila][columna] == 888 ||matriz[fila][columna] == 8888 ){
			
			
			if(matriz[fila][columna] == 8){
				jugadorUno--;
			}
			
			else if(matriz[fila][columna] == 88){
				jugadorUno--;
				jugadorUno--;	
			}
			
			else if(matriz[fila][columna] == 888){
				jugadorUno--;
				jugadorUno--;
				jugadorUno--;
			}
			
			else{
				jugadorUno = 0;
				matriz[fila][columna] = 5;
	
			}
			
		}
	}
	
	actividad(matriz, fila, columna);
	
}






//***********************************************************************************************************************************************************************************************************



void posicionarTesoro(int **matriz, int &jugadorUno, int &jugadorDos, int fila, int columna, int turno){
	
	
	
	
	int codigo;

	
	if(turno == 1){
		
		
		if(matriz[fila][columna] == 0){
			
			matriz[fila][columna] = 8;
			
			jugadorUno++;
			
			codigo = 8;
			mensajes(codigo);
			
		}
		else{
			actividadTesoro(matriz, jugadorUno, jugadorDos, fila, columna, turno);
		}		
	}
	
	
	
	
	if(turno == 2){
		
		
		if(matriz[fila][columna] == 0){
			
			matriz[fila][columna] = 9;
			
			jugadorDos++;
			
			codigo = 9;
			mensajes(codigo);
			
		}
		else{
			actividadTesoro(matriz, jugadorUno, jugadorDos, fila, columna, turno);
		}
	}
	
		

}





//**********************************************************************************************************************************************************************************************************



int* posicionar(){
	
	int fila = 40, columna = 40;
	char fil, colum;
	
	int vector[2];


	while(fila == 40 || columna == 40){
		
		
		
		std::cout<<"Elija fila desde A hasta T: ";
		std::cin>>fil;
		
		std::cout<<"Elija una columna desde A hasta T: ";
		std::cin>>colum;
		
		std::cout<< "\n\n";
		
		
		
		
		switch(fil){
			
			case 'A': fila = 0;break;
			case 'B': fila = 1;break;
			case 'C': fila = 2;break;
			case 'D': fila = 3;break;
			case 'E': fila = 4;break;
			case 'F': fila = 5;break;
			case 'G': fila = 6;break;
			case 'H': fila = 7;break;
			case 'I': fila = 8;break;
			case 'J': fila = 9;break;
			case 'K': fila = 10;break;
			case 'L': fila = 11;break;
			case 'M': fila = 12;break;
			case 'N': fila = 13;break;
			case 'O': fila = 14;break;
			case 'P': fila = 15;break;
			case 'Q': fila = 16;break;
			case 'R': fila = 17;break;
			case 'S': fila = 18;break;
			case 'T': fila = 19;break;
			default:std::cout<<">>>Fila fuera de rango, elija nuevamente"<< "\n\n";fila=40;
			
		}
		
		
		
		switch(colum){
			
			case 'A': columna = 0;break;
			case 'B': columna = 1;break;
			case 'C': columna = 2;break;
			case 'D': columna = 3;break;
			case 'E': columna = 4;break;
			case 'F': columna = 5;break;
			case 'G': columna = 6;break;
			case 'H': columna = 7;break;
			case 'I': columna = 8;break;
			case 'J': columna = 9;break;
			case 'K': columna = 10;break;
			case 'L': columna = 11;break;
			case 'M': columna = 12;break;
			case 'N': columna = 13;break;
			case 'O': columna = 14;break;
			case 'P': columna = 15;break;
			case 'Q': columna = 16;break;
			case 'R': columna = 17;break;
			case 'S': columna = 18;break;
			case 'T': columna = 19;break;
			default:std::cout<<">>>Columna fuera de rango, elija nuevamente"<< "\n\n";columna=40;
			
		}				
	}	
	
	vector[0] = fila;
	vector[1] = columna;
	
	return vector;
}


//************************************************************************************************************************************************************************************************************

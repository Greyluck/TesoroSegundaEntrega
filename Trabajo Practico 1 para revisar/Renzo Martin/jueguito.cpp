
#include <iostream>

#include "jueguito.h"
#include "posicionar.h"



//***********************************************************************************************************************************************************************************************************

void juego(int **matriz){

	std::cout<<"Comienza el juego !! colocaran 4 tesoros por jugador en turnos intercalados"<<"\n\n\n";
	
	int jugadorUno = 0, jugadorDos = 0, maximo = 8, contador = 0, turno = 1;
	int *posiciones;

	while(contador < maximo){
		
		if(turno == 1){
			
			std::cout<<"Turno del jugador 1"<< "\n\n";
			posiciones = posicionar();
			posicionarTesoro(matriz, jugadorUno, jugadorDos, posiciones[0], posiciones[1], turno);
			std::cout<< "Tesoro del jugador "<< turno <<" colocado >>>"<<" Fila: "<< posiciones[0] << " >>> " << "Columna: "<< posiciones[1] << "\n\n";
			
			turno = 2;
		}
		
		else{
			
			std::cout<<"Turno del jugador 2"<< "\n\n";
			posiciones = posicionar();
			posicionarTesoro(matriz, jugadorUno, jugadorDos, posiciones[0], posiciones[1], turno);
			std::cout<< "Tesoro del jugador "<< turno <<" colocado >>>"<<" Fila: "<< posiciones[0] << " >>> " << "Columna: "<< posiciones[1] << "\n\n";
			turno = 1;
		}
		
		contador++;
		
		std::cout << "Jugador 1: " << jugadorUno <<",  jugador 2: "<< jugadorDos<<"\n\n\n";
	}
	
	
	
	
	std::cout<<"Preparese para colocar espias !!!"<<"\n\n\n";
	
	
	
	
	while(jugadorUno > 0 && jugadorDos > 0){
		
		if(turno == 1){
			
			std::cout<<"Turno del jugador 1"<<"\n\n\n";
			posiciones = posicionar();
			posicionarEspia(matriz, jugadorUno, jugadorDos, posiciones[0], posiciones[1], turno);
			
			turno = 2;	
		}
		
		
		
		
		else{
			
			std::cout<<"Turno del jugador 2"<<"\n\n\n";
			posiciones = posicionar();
			posicionarEspia(matriz, jugadorUno, jugadorDos, posiciones[0], posiciones[1], turno);
			
			turno = 1;
			
		}
		
	}
	
	
	
	
	if(jugadorUno > jugadorDos){
		
		std::cout<<"GANADOR JUGADOR 1   $ FELICIDADES $"<<"\n\n";
		std::cout<<"Jugador 1: " << jugadorUno<< ", "<<"Jugador dos: "<<jugadorDos << "\n\n";	
	}
	else{
		std::cout<<"GANADOR JUGADOR 2   $ FELICIDADES $"<<"\n\n";
		std::cout<<"Jugador 1: " << jugadorUno<< ", "<<"Jugador dos: "<<jugadorDos << "\n\n";
	}
	
}


//***********************************************************************************************************************************************************************************************************

void mostrarTitulo(){
	
	std::cout<<std::endl;
	
	std::string titulo= "Tesoro Binario";
	
	std::cout<< "$  -------------------  $  " << titulo << "  $  ------------------  $"<<"\n\n\n\n";
}


//***********************************************************************************************************************************************************************************************************


int** inicializarMatriz(int **matriz){
	
	matriz = new int*[20];
	
	for(int i=0; i<20; i++){
		
		matriz[i] = new int[20];
		
		for(int j=0; j<20; j++){
			
			matriz[i][j] = 0;		
		}
	}
	
	return matriz;	
}


//************************************************************************************************************************************************************************************************************


void mostrarMatriz(int **matriz){
	
	char letras[20] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
	
	std::cout<<"            A B C D E F G H I J K L M N O P Q R S T " << "\n\n";
	
	for(int i=0; i<20; i++){
		
		std::cout<< "        " <<letras[i] << "   ";
		for(int j=0; j<20; j++){
			
			std::cout<<matriz[i][j]<< ' ';
		}
		
		std::cout<<std::endl;
	}
	
	std::cout<< "\n\n\n";
}

//************************************************************************************************************************************************************************************************************

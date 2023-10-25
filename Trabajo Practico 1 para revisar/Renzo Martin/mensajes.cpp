
#include <iostream>
#include "mensajes.h"


void mensajes(int codigo){
	
	
	
	if(codigo == 8){
		
		std::cout << "Tesoro jugador 1 colocado"<< "\n\n";
	}
	
	
	
	
	else if(codigo == 88){
		
		std::cout<< "Tesoro del jugador 1 colocado, tiene 2 tesoros en esta posicion"<<"\n\n";
		
	}
	
	
	
	
	else if(codigo == 888){
		std::cout<< "Tesoro del jugador 1 colocado, tiene 3 tesoros en esta posicion"<< "\n\n";
	}
	
	
	
	
	else if(codigo == 8888){
		
		std::cout<< "Tesoro del jugador 1 colocado, tiene 4 tesoros en esta posicion"<<"\n\n";	
	}
	
	
	
	
	else if(codigo == 9){
		std::cout<<"Tesoro del jugador 2 colocado"<< "\n\n";
	}
	
	
	
	
	else if(codigo == 99){
		std::cout<<  "Tesoro del jugador 2 colocado, tiene 2 tesoros en esta posicion"<< " \n\n";
	}
	
	
	
	
	
	else if(codigo == 999){
		std::cout<<"Tesoro del jugador 2 colocado tiene 3 tesoros en esta posicion"<< "\n\n";	
	}
	
	
	
	
	else if (codigo == 9999){
		std::cout<<"Tesoro del jugador 2, tiene 4 tesoros en esta posicion "<< "\n\n";
	}
	
	else if(codigo == 98){
		std::cout<<"Tesoro del jugador" << 1 << " colocado, llame un espia, tambien hay un tesoro enemigo en la posicion"<<"\n\n\n";
	}
	
	
	
	else if(codigo == 89){
		std::cout<<"Tesoro del jugador" << 2 << " colocado, llame un espia, tambien hay un tesoro enemigo en la posicion"<<"\n\n\n";
	}
	
	
	
	else if(codigo==8989){
		
		std::cout<<"Ya tiene un tesoro suyo junto con uno enemigo, Sllame a un espia antes de que lo mueva de posicion! ! !.  Ah ! tambien vuelva a elegir la posicion"<<"\n\n\n";
	}
	
	
	
	
	else if(codigo == 5){
		
		std::cout<< "Encontro un tesoro !!! Celda inativa por 5 turnos ..."<<"\n\n\n";
	}
	
	
	
	else if(codigo == 4){
		
		std::cout<<"Celda inactiva por 4 turnos ..."<< "\n\n\n";
	}
	
	
	
	
	else if(codigo == 3){
		std::cout<<"Celda inativa por 3 turnos ..."<<"\n\n\n";
	}
	
	
	
	else if(codigo == 2){
		std::cout<<"Celda inactiva por 2 turnos ..."<<"\n\n\n";
	}
	
	
	
	else if(codigo == 1){
		
		std::cout<<"Celda inactiva por 1 turno ..."<<"\n\n\n";
	}
	
	else{
		std::cout<<"Se activo una celda ..."<<"\n\n\n";
	}
	
	
}

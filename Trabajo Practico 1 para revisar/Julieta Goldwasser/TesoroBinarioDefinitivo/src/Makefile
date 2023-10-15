CXXFLAGS = -Wall -pedantic -std=c++98 -g
CXX = g++

OBJECTS = main.o Auxiliares.o Casillero.o Interacciones.o Jugador.o Tablero.o TesoroBinario.o

all: programa

programa: $(OBJECTS)
	$(CXX) -g $(OBJECTS) -o programa 

main.o: main.cpp Bibliotecas.h TesoroBinario.h Interacciones.h
	$(CXX) $(CXXFLAGS) main.cpp -c main.o
	
Auxiliares.o: Auxiliares.cpp Auxiliares.h Constantes.h
	$(CXX) $(CXXFLAGS) Auxiliares.cpp -c Auxiliares.o

Casillero.o: Casillero.cpp Casillero.h
	$(CXX) $(CXXFLAGS) Casillero.cpp -c Casillero.o
	
Interacciones.o: Interacciones.cpp Interacciones.h Auxiliares.h
	$(CXX) $(CXXFLAGS) Interacciones.cpp -c Interacciones.o

Jugador.o: Jugador.cpp Jugador.h Auxiliares.h
	$(CXX) $(CXXFLAGS) Jugador.cpp -c Jugador.o

Tablero.o: Tablero.cpp Tablero.h Constantes.h
	$(CXX) $(CXXFLAGS) Tablero.cpp -c Tablero.o

TesoroBinario.o: TesoroBinario.cpp TesoroBinario.h Interacciones.h Auxiliares.h
	$(CXX) $(CXXFLAGS) TesoroBinario.cpp -c TesoroBinario.o
	


clean:
	rm *.o programa 
	
cleanTXT:
	rm *.txt


#valgrind --leak.check=yes ./programa

#ver por qué no se van las cruces luego de los 4 turnos inhabilitados


CXXFLAGS = -Wall -pedantic -std=c++98 -g
CXX = g++

OBJECTS = main.o Carta.o Jugador.o Mazo.o Registro.o Tablero.o Tesoro.o TesoroBinario.o Interfaz.o prueba.o EasyBMP.o

all: programa

programa: $(OBJECTS)
	$(CXX) -g $(OBJECTS) -o programa 

main.o: main.cpp TesoroBinario.h
	$(CXX) $(CXXFLAGS) main.cpp -c
	
Carta.o: Carta.cpp Carta.h
	$(CXX) $(CXXFLAGS) Carta.cpp -c

Jugador.o: Jugador.cpp Jugador.h TesoroBinario.h
	$(CXX) $(CXXFLAGS) Jugador.cpp -c
	
Mazo.o: Mazo.cpp Mazo.h 
	$(CXX) $(CXXFLAGS) Mazo.cpp -c
	
Registro.o: Registro.cpp Registro.h
	$(CXX) $(CXXFLAGS) Registro.cpp -c

Tablero.o: Tablero.cpp Tablero.h
	$(CXX) $(CXXFLAGS) Tablero.cpp -c

Tesoro.o: Tesoro.cpp Tesoro.h
	$(CXX) $(CXXFLAGS) Tesoro.cpp -c

TesoroBinario.o: TesoroBinario.cpp TesoroBinario.h
	$(CXX) $(CXXFLAGS) TesoroBinario.cpp -c

Iterfaz.o: Interfaz.cpp Interfaz.h
	$(CXX) $(CXXFLAGS) Iterfaz.cpp -c
	
prueba.o: EasyBMP/prueba.cpp
	$(CXX) $(CXXFLAGS) EasyBMP/prueba.cpp -c

EasyBMP.o: EasyBMP/EasyBMP.cpp EasyBMP/EasyBMP.h
	$(CXX) $(CXXFLAGS) EasyBMP/EasyBMP.cpp -c


clean:
	rm *.o programa 
	
cleanTXT:
	#rm *.txt


#valgrind --leak-check=yes ./programa

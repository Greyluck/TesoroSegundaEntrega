CXXFLAGS = -Wall -pedantic -std=c++98 -g
CXX = g++

OBJECTS = Tesoro_Binario_Segunda_Etapa.o Carta.o Jugador.o Mazo.o Registro.o Tablero.o Tesoro.o TesoroBinario.o Interfaz.o prueba.o EasyBMP.o Imagen.o

all: programa

programa: $(OBJECTS)
	$(CXX) -g $(OBJECTS) -o programa 

Tesoro_Binario_Segunda_Etapa.o: Tesoro_Binario_Segunda_Etapa.cpp TesoroBinario.h
	$(CXX) $(CXXFLAGS) Tesoro_Binario_Segunda_Etapa.cpp -c
	
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

Imagen.o : Imagen.h Imagen.cpp
	$(CXX) $(CXXFLAGS) Imagen.cpp -c

clean:
	rm *.o programa 
	
cleanTXT:
	#rm *.txt


#valgrind --leak-check=yes ./programa

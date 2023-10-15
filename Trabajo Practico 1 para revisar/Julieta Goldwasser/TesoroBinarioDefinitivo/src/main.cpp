#include "Bibliotecas.h"
#include "TesoroBinario.h"
#include "Interacciones.h"

int main() {
	TesoroBinario juego;
	inicializarJuego(juego);
	iniciarJuego(juego);
	unsigned int ganador = jugarTesoroBinario(juego);
	terminarJuego(juego, ganador);

	return 0;
}



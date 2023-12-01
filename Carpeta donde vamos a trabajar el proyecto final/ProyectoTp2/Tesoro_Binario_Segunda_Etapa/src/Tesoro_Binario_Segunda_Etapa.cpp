#include "TesoroBinario.h"
#include "Bibliotecas.h"
int main() {
	//agrego esto, que lo necesito para generar las cartas aleatorias
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	//prueba del juego
	TesoroBinario *tesoroBinario = new TesoroBinario();
	tesoroBinario->inciarJuego();
	tesoroBinario->jugarJuego();
	tesoroBinario->finalizarJuego();
	delete tesoroBinario;

	return 0;
}

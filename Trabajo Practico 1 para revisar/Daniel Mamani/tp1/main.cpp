#include "TesoroBinario.h"

int main(){

    std::string jugador1;
    std::string jugador2;

    TesoroBinario *tesoroBinario = inicializarTesoroBinario(jugador1, jugador2);
	iniciarJuego(tesoroBinario);
	jugar(tesoroBinario);
	finalizarJuego(tesoroBinario);

    return 0;
}

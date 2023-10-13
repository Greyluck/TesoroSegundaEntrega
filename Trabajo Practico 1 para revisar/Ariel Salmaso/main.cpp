#include "TesoroBinario.h"

int main(){
    TesoroBinario *juego  = iniciarJuego();
    jugar(juego);
    return 0;
}

//cuando un espia toca a otro espia se tienen que eliminar.

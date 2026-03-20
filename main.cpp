#include "Juego.hpp" // Incluye el "cerebro" previamnete programado 

int main() {
    // Creamos el objeto 'partida' basado en la clase Juego
    Juego partida;

    // Llamamos al método que muestra el menú y controla todo
    partida.iniciarMenu();

    return 0;
}
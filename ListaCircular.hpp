#ifndef LISTA_CIRCULAR_HPP
#define LISTA_CIRCULAR_HPP
#include <iostream>
#include "Oleada.hpp"

using namespace std;

struct NodoOleada {
    Oleada dato;
    NodoOleada* siguiente;
    NodoOleada(Oleada o) : dato(o), siguiente(nullptr) {}
};

class ListaCircular {
private:
    NodoOleada* ultimo; // En listas circulares, con apuntar al último es suficiente
    NodoOleada* oleadaActual; 

public:
    ListaCircular() { ultimo = nullptr; oleadaActual = nullptr; }

    // TODO: Integrante 4 - Programar la lógica de estos métodos asegurando la circularidad
    void registrarOleada(Oleada o) {
        cout << "[Oleadas] Falta programar: Registrar oleada (Insertar)\n";
    }

    void mostrarOleadas() {
        cout << "[Oleadas] Falta programar: Mostrar el ciclo de oleadas\n";
    }

    void avanzarSiguienteOleada() {
        cout << "[Oleadas] Falta programar: Mover puntero a la siguiente oleada\n";
    }
};
#endif
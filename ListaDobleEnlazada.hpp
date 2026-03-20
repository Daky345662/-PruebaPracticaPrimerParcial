#ifndef LISTA_DOBLE_ENLAZADA_HPP
#define LISTA_DOBLE_ENLAZADA_HPP
#include <iostream>
#include "Enemigo.hpp"

using namespace std;

struct NodoEnemigo {
    Enemigo dato;
    NodoEnemigo* siguiente;
    NodoEnemigo* anterior;
    NodoEnemigo(Enemigo e) : dato(e), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDobleEnlazada {
private:
    NodoEnemigo* primero;
    NodoEnemigo* ultimo;

public:
    ListaDobleEnlazada() { primero = nullptr; ultimo = nullptr; }

    // TODO: Integrante 3 - Programar la lógica de estos métodos
    void insertarFinal(Enemigo e) {
        cout << "[Enemigos] Falta programar: Insertar al final\n";
    }

    void eliminarDestruido(int id) {
        cout << "[Enemigos] Falta programar: Eliminar por ID\n";
    }

    void mostrarAdelante() {
        cout << "[Enemigos] Falta programar: Recorrer hacia adelante\n";
    }

    void mostrarAtras() {
        cout << "[Enemigos] Falta programar: Recorrer hacia atrás\n";
    }

    // TODO: Integrante 3 - Sumar la velocidad a la posición de cada enemigo
    void actualizarPosiciones() {
        cout << "[Enemigos] Falta programar: Actualizar posiciones\n";
    }
};
#endif
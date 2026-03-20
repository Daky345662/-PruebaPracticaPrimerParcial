#ifndef LISTA_SECUENCIAL_HPP
#define LISTA_SECUENCIAL_HPP
#include <iostream>
#include "Torre.hpp"

using namespace std;

class ListaSecuencial {
private:
    Torre arreglo[100]; // Arreglo estático como pide la restricción sin std::vector
    int cantidad;

public:
    ListaSecuencial() { cantidad = 0; }

    // TODO: Integrante 2 - Programar la lógica de estos métodos
    bool insertarTorre(Torre t) {
        cout << "[Torres] Falta programar: Insertar\n";
        return false;
    }

    bool eliminarTorrePorId(int id) {
        cout << "[Torres] Falta programar: Eliminar por ID\n";
        return false;
    }

    Torre* buscarTorrePorId(int id) {
        cout << "[Torres] Falta programar: Buscar por ID\n";
        return nullptr;
    }

    void mostrarTorres() {
        cout << "[Torres] Falta programar: Mostrar todas\n";
    }

    int contarTorres() {
        return cantidad;
    }
    
    // Método útil para el integrador
    Torre* obtenerTorrePorIndice(int index) {
        if(index >= 0 && index < cantidad) return &arreglo[index];
        return nullptr;
    }
};
#endif
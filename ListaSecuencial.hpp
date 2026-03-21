#ifndef LISTA_SECUENCIAL_HPP
#define LISTA_SECUENCIAL_HPP

#include "Torre.hpp"
#include <iostream>
using namespace std;

const int MAX_TORRES = 100;

class ListaSecuencial {
private:
    Torre torres[MAX_TORRES];
    int cantidad;
    
public:
    ListaSecuencial() : cantidad(0) {}
    
    bool insertar(Torre torre) {
        if(cantidad >= MAX_TORRES) {
            cout << "Error: No se pueden agregar más torres" << endl;
            return false;
        }
        torres[cantidad] = torre;
        cantidad++;
        return true;
    }
    
    bool eliminar(int id) {
        for(int i = 0; i < cantidad; i++) {
            if(torres[i].id == id) {
                for(int j = i; j < cantidad - 1; j++) {
                    torres[j] = torres[j + 1];
                }
                cantidad--;
                return true;
            }
        }
        return false;
    }
    
    Torre* buscar(int id) {
        for(int i = 0; i < cantidad; i++) {
            if(torres[i].id == id) {
                return &torres[i];
            }
        }
        return nullptr;
    }
    
    void mostrar() {
        if(cantidad == 0) {
            cout << "No hay torres registradas" << endl;
            return;
        }
        cout << "\n=== TORRES DEFENSIVAS ===" << endl;
        for(int i = 0; i < cantidad; i++) {
            torres[i].mostrar();
        }
        cout << "Total: " << cantidad << " torres" << endl;
    }
    
    int contarActivas() {
        int activas = 0;
        for(int i = 0; i < cantidad; i++) {
            if(torres[i].activa) activas++;
        }
        return activas;
    }
    
    int getCantidad() { return cantidad; }
    Torre* getTorres() { return torres; }
};

#endif

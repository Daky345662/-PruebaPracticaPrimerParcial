#ifndef LISTA_CIRCULAR_HPP
#define LISTA_CIRCULAR_HPP

#include "Oleada.hpp"
#include <iostream>
using namespace std;

struct NodoOleada {
    Oleada oleada;
    NodoOleada* siguiente;
    
    NodoOleada(Oleada o) : oleada(o), siguiente(nullptr) {}
};

class ListaCircular {
private:
    NodoOleada* ultimo;
    NodoOleada* actual;
    int cantidad;
    
public:
    ListaCircular() : ultimo(nullptr), actual(nullptr), cantidad(0) {}
    
    ~ListaCircular() {
        if(ultimo == nullptr) return;
        
        NodoOleada* inicio = ultimo->siguiente;
        NodoOleada* temp;
        
        while(inicio != ultimo) {
            temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
        }
        delete ultimo;
    }
    
    void insertar(Oleada oleada) {
        NodoOleada* nuevo = new NodoOleada(oleada);
        
        if(ultimo == nullptr) {
            ultimo = nuevo;
            ultimo->siguiente = ultimo;
        } else {
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
        cantidad++;
        
        if(actual == nullptr) {
            actual = ultimo->siguiente;
        }
    }
    
    void mostrar() {
        if(ultimo == nullptr) {
            cout << "No hay oleadas registradas" << endl;
            return;
        }
        
        cout << "\n=== OLEADAS ===" << endl;
        NodoOleada* temp = ultimo->siguiente;
        int i = 1;
        do {
            temp->oleada.mostrar();
            temp = temp->siguiente;
            i++;
        } while(temp != ultimo->siguiente);
        cout << "Total: " << cantidad << " oleadas" << endl;
    }
    
    Oleada* avanzar() {
        if(actual == nullptr) return nullptr;
        
        actual = actual->siguiente;
        return &(actual->oleada);
    }
    
    Oleada* getOleadaActual() {
        if(actual == nullptr) return nullptr;
        return &(actual->oleada);
    }
    
    void reiniciar() {
        if(ultimo != nullptr) {
            actual = ultimo->siguiente;
        }
    }
    
    int getCantidad() { return cantidad; }
    bool estaVacio() { return ultimo == nullptr; }
};

#endif
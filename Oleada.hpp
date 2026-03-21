#ifndef LISTA_CIRCULAR_HPP
#define LISTA_CIRCULAR_HPP

#include "Oleada.hpp"
#include <iostream>

using namespace std;

// Estructura que representa un nodo individual de la lista
struct NodoOleada {
    Oleada oleada;          
    NodoOleada* siguiente;   // Puntero al próximo nodo en el ciclo
    
    // Constructor del nodo
    NodoOleada(Oleada o) : oleada(o), siguiente(nullptr) {}
};

class ListaCircular {
private:
    NodoOleada* ultimo;  // Puntero al último nodo 
    NodoOleada* actual;  // Puntero auxiliar para navegar o iterar por la lista
    int cantidad;        
    
public:
    // Constructor: Inicializa una lista vacía
    ListaCircular() : ultimo(nullptr), actual(nullptr), cantidad(0) {}
    
    // Destructor: Se encarga de liberar la memoria dinámica al destruir la lista
    ~ListaCircular() {
        if(ultimo == nullptr) return; 
        
        NodoOleada* inicio = ultimo->siguiente; 
        NodoOleada* temp;
        
        // Recorre la lista borrando cada nodo hasta llegar de nuevo al último
        while(inicio != ultimo) {
            temp = inicio;
            inicio = inicio->siguiente;
            delete temp;
        }
        delete ultimo; 
    }
    
    // Inserta una nueva oleada al final de la lista
    void insertar(Oleada oleada) {
        NodoOleada* nuevo = new NodoOleada(oleada);
        
        if(ultimo == nullptr) {
            //El nodo se apunta a sí mismo para ser circular
            ultimo = nuevo;
            ultimo->siguiente = ultimo;
        } else {
            //El nuevo apunta al inicio y el último al nuevo
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
            ultimo = nuevo; 
        }
        
        cantidad++;
        
        if(actual == nullptr) {
            actual = ultimo->siguiente;
        }
    }
    
    // Imprime todas las oleadas registradas
    void mostrar() {
        if(ultimo == nullptr) {
            cout << "No hay oleadas registradas" << endl;
            return;
        }
        
        cout << "\n=== OLEADAS ===" << endl;
        NodoOleada* temp = ultimo->siguiente; 

        do {
            temp->oleada.mostrar(); // Llama al método mostrar de la clase Oleada
            temp = temp->siguiente;
        } while(temp != ultimo->siguiente);
        
        cout << "Total: " << cantidad << " oleadas" << endl;
    }
    
    // Mueve el puntero 'actual' al siguiente y devuelve la oleada 
    Oleada* avanzar() {
        if(actual == nullptr) return nullptr;
        
        actual = actual->siguiente;
        return &(actual->oleada);
    }
    
    // Devuelve la oleada donde está el cursor 'actual' sin moverlo
    Oleada* getOleadaActual() {
        if(actual == nullptr) return nullptr;
        return &(actual->oleada);
    }
    
    // Regresa el cursor 'actual' al principio de la lista
    void reiniciar() {
        if(ultimo != nullptr) {
            actual = ultimo->siguiente;
        }
    }
    
    int getCantidad() { return cantidad; }
    bool estaVacio() { return ultimo == nullptr; }
};

#endif
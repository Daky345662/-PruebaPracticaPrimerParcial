#include <iostream>
using namespace std;
#ifndef LISTA_DOBLE_ENLAZADA_HPP
#define LISTA_DOBLE_ENLAZADA_HPP

#include "Enemigo.hpp"


struct NodoEnemigo {
    Enemigo enemigo;
    NodoEnemigo* siguiente;
    NodoEnemigo* anterior;
    
    NodoEnemigo(Enemigo e) : enemigo(e), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDobleEnlazada {
private:
    NodoEnemigo* primero;
    NodoEnemigo* ultimo;
    int cantidad;
    
public:
    ListaDobleEnlazada() : primero(nullptr), ultimo(nullptr), cantidad(0) {}
    
    ~ListaDobleEnlazada() {
        while(primero != nullptr) {
            NodoEnemigo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
    }
    
    void insertarFinal(Enemigo enemigo) {
        NodoEnemigo* nuevo = new NodoEnemigo(enemigo);
        
        if(primero == nullptr) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        }
        cantidad++;
    }
    
    bool eliminar(int id) {
        NodoEnemigo* actual = primero;
        
        while(actual != nullptr) {
            if(actual->enemigo.id == id) {
                if(actual->anterior != nullptr) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    primero = actual->siguiente;
                }
                
                if(actual->siguiente != nullptr) {
                    actual->siguiente->anterior = actual->anterior;
                } else {
                    ultimo = actual->anterior;
                }
                
                delete actual;
                cantidad--;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }
    
    Enemigo* buscar(int id) {
        NodoEnemigo* actual = primero;
        while(actual != nullptr) {
            if(actual->enemigo.id == id) {
                return &(actual->enemigo);
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }
    
    void recorrerAdelante() {
        if(primero == nullptr) {
            cout << "No hay enemigos activos" << endl;
            return;
        }
        
        cout << "\n=== ENEMIGOS ACTIVOS (Inicio a Fin) ===" << endl;
        NodoEnemigo* actual = primero;
        while(actual != nullptr) {
            actual->enemigo.mostrar();
            actual = actual->siguiente;
        }
        cout << "Total: " << cantidad << " enemigos" << endl;
    }
    
    void recorrerAtras() {
        if(ultimo == nullptr) {
            cout << "No hay enemigos activos" << endl;
            return;
        }
        
        cout << "\n=== ENEMIGOS ACTIVOS (Fin a Inicio) ===" << endl;
        NodoEnemigo* actual = ultimo;
        while(actual != nullptr) {
            actual->enemigo.mostrar();
            actual = actual->anterior;
        }
        cout << "Total: " << cantidad << " enemigos" << endl;
    }
    
    void moverTodos() {
        NodoEnemigo* actual = primero;
        while(actual != nullptr) {
            actual->enemigo.mover();
            actual = actual->siguiente;
        }
    }
    
    NodoEnemigo* getPrimero() { return primero; }
    int getCantidad() { return cantidad; }
    bool estaVacio() { return primero == nullptr; }
};

#endif
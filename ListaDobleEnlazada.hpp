#ifndef LISTA_DOBLE_ENLAZADA_HPP
#define LISTA_DOBLE_ENLAZADA_HPP

#include "Enemigo.hpp"
#include <iostream>
using namespace std;

// Nodo
struct NodoEnemigo {
    Enemigo enemigo;
    NodoEnemigo* siguiente;
    NodoEnemigo* anterior;

    NodoEnemigo(Enemigo e) : enemigo(e), siguiente(NULL), anterior(NULL) {}
};

class ListaDobleEnlazada {
private:
    NodoEnemigo* primero;
    NodoEnemigo* ultimo;
    int cantidad;

public:
    ListaDobleEnlazada() : primero(NULL), ultimo(NULL), cantidad(0) {}

    // Destructor
    ~ListaDobleEnlazada() {
        while (primero != NULL) {
            NodoEnemigo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
    }

    // Insertar al final
    void insertarFinal(Enemigo enemigo) {
        NodoEnemigo* nuevo = new NodoEnemigo(enemigo);

        if (primero == NULL) {
            primero = nuevo;
            ultimo = nuevo;
        } else {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        }
        cantidad++;
    }

    // Eliminar por ID
    bool eliminar(int id) {
        NodoEnemigo* actual = primero;

        while (actual != NULL) {
            if (actual->enemigo.id == id) {

                if (actual->anterior != NULL)
                    actual->anterior->siguiente = actual->siguiente;
                else
                    primero = actual->siguiente;

                if (actual->siguiente != NULL)
                    actual->siguiente->anterior = actual->anterior;
                else
                    ultimo = actual->anterior;

                delete actual;
                cantidad--;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    // Buscar
    Enemigo* buscar(int id) {
        NodoEnemigo* actual = primero;

        while (actual != NULL) {
            if (actual->enemigo.id == id)
                return &(actual->enemigo);

            actual = actual->siguiente;
        }
        return NULL;
    }

    // Recorrer adelante
    void recorrerAdelante() {
        NodoEnemigo* actual = primero;

        if (actual == NULL) {
            cout << "No hay enemigos activos" << endl;
            return;
        }

        cout << "\n=== ENEMIGOS (Inicio -> Fin) ===" << endl;
        while (actual != NULL) {
            actual->enemigo.mostrar();
            actual = actual->siguiente;
        }
        cout << "Total: " << cantidad << endl;
    }

    // Recorrer atrás
    void recorrerAtras() {
        NodoEnemigo* actual = ultimo;

        if (actual == NULL) {
            cout << "No hay enemigos activos" << endl;
            return;
        }

        cout << "\n=== ENEMIGOS (Fin -> Inicio) ===" << endl;
        while (actual != NULL) {
            actual->enemigo.mostrar();
            actual = actual->anterior;
        }
        cout << "Total: " << cantidad << endl;
    }

    // Mover todos
    void moverTodos() {
        NodoEnemigo* actual = primero;

        while (actual != NULL) {
            actual->enemigo.mover();
            actual = actual->siguiente;
        }
    }

    // Getters
    NodoEnemigo* getPrimero() { return primero; }
    int getCantidad() { return cantidad; }
    bool estaVacio() { return primero == NULL; }
};

#endif
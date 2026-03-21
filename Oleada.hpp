#ifndef OLEADA_HPP
#define OLEADA_HPP

#include <string>
using namespace std;

struct Oleada {
    int idOleada;
    int cantidadEnemigos;
    string tipoEnemigo;
    int vidaBase;
    int velocidadBase;
    
    Oleada() : idOleada(0), cantidadEnemigos(0), tipoEnemigo(""), vidaBase(0), velocidadBase(0) {}
    
    Oleada(int id, int cant, string tipo, int vida, int vel)
        : idOleada(id), cantidadEnemigos(cant), tipoEnemigo(tipo), vidaBase(vida), velocidadBase(vel) {}
    
    void mostrar() {
        cout << "Oleada " << idOleada << ": " << cantidadEnemigos << " enemigos tipo '" 
             << tipoEnemigo << "' (Vida: " << vidaBase << ", Velocidad: " << velocidadBase << ")" << endl;
    }
};

#endif
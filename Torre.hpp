#ifndef TORRE_HPP
#define TORRE_HPP

#include <iostream>  // Línea 4
#include <string>
using namespace std;

struct Torre {
    int id;
    string nombre;
    string tipo;
    int posicion;
    int danio;
    int rango;
    int costo;
    bool activa;
    
    Torre() : id(0), nombre(""), tipo(""), posicion(0), danio(0), rango(0), costo(0), activa(true) {}
    
    Torre(int i, string nom, string tip, int pos, int dan, int ran, int cost) 
        : id(i), nombre(nom), tipo(tip), posicion(pos), danio(dan), rango(ran), costo(cost), activa(true) {}
    
    void mostrar() {
        cout << "ID: " << id << " | Nombre: " << nombre << " | Tipo: " << tipo
             << " | Pos: " << posicion << " | Danio: " << danio << " | Rango: " << rango
             << " | Costo: " << costo << " | Estado: " << (activa ? "Activa" : "Inactiva") << endl;
    }
};

#endif
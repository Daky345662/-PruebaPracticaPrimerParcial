#ifndef ENEMIGO_HPP
#define ENEMIGO_HPP

#include <string>
using namespace std;

struct Enemigo {
    int id;
    string tipo;
    int vida;
    int velocidad;
    int posicion;
    int recompensa;
    
    Enemigo() : id(0), tipo(""), vida(0), velocidad(0), posicion(0), recompensa(0) {}
    
    Enemigo(int i, string tip, int vid, int vel, int pos, int rec)
        : id(i), tipo(tip), vida(vid), velocidad(vel), posicion(pos), recompensa(rec) {}
    
    void mostrar() {
        cout << "ID: " << id << " | Tipo: " << tipo << " | Vida: " << vida 
             << " | Velocidad: " << velocidad << " | Pos: " << posicion 
             << " | Recompensa: " << recompensa << endl;
    }
    
    void mover() {
        posicion += velocidad;
    }
    
    bool estaVivo() {
        return vida > 0;
    }
    
    void recibirDanio(int danio) {
        vida -= danio;
        if(vida < 0) vida = 0;
    }
};

#endif
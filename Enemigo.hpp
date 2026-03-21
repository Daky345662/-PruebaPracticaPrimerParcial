#ifndef ENEMIGO_HPP
#define ENEMIGO_HPP

#include <iostream>
#include <string>
using namespace std;

struct Enemigo {
    int id;
    string tipo;
    int vida;
    int velocidad;
    int posicion;
    int recompensa;

    // Constructor por defecto
    Enemigo() : id(0), tipo(""), vida(0), velocidad(0), posicion(0), recompensa(0) {}

    // Constructor con parámetros
    Enemigo(int i, string tip, int vid, int vel, int pos, int rec)
        : id(i), tipo(tip), vida(vid), velocidad(vel), posicion(pos), recompensa(rec) {}

    // Mostrar datos
    void mostrar() {
        cout << "ID: " << id
             << " | Tipo: " << tipo
             << " | Vida: " << vida
             << " | Velocidad: " << velocidad
             << " | Pos: " << posicion
             << " | Recompensa: " << recompensa << endl;
    }

    // Mover enemigo
    void mover() {
        posicion += velocidad;
    }

    // Verificar si sigue vivo
    bool estaVivo() {
        return vida > 0;
    }

    // Recibir daño
    void recibirDanio(int danio) {
        vida -= danio;
        if (vida < 0) vida = 0;
    }
};

#endif
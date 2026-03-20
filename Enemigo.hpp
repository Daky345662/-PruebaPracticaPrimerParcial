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
};
#endif
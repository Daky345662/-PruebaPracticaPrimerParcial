#ifndef JUEGO_HPP
#define JUEGO_HPP

#include <iostream>
#include "ListaSecuencial.hpp"
#include "ListaDobleEnlazada.hpp"
#include "ListaCircular.hpp"

using namespace std;

class Juego {
private:
    ListaSecuencial torres;
    ListaDobleEnlazada enemigos;
    ListaCircular oleadas;
    int vidas;
    int turnoActual;
    const int LIMITE_RUTA = 20;

public:
    // Constructor
    Juego() {
        vidas = 3;
        turnoActual = 0;
    }

    // Método del Menú
    void iniciarMenu() {
        int opcion;
        do {
            cout << "\n=== TOWER DEFENSE - MENU PRINCIPAL ===\n";
            cout << "Vidas: " << vidas << " | Turno: " << turnoActual << "\n";
            cout << "1. Registrar torre defensiva\n";
            cout << "2. Mostrar torres registradas\n";
            cout << "7. Avanzar turno\n";
            cout << "10. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1: cout << "Llamando a insertar torre...\n"; break; // Conectarás esto luego
                case 2: cout << "Llamando a mostrar torres...\n"; break;
                case 7: avanzarTurno(); break;
                case 10: cout << "Saliendo...\n"; break;
                default: cout << "Opcion no valida.\n";
            }
        } while(opcion != 10 && vidas > 0);
    }

    // Método del Motor del Juego
    void avanzarTurno() {
        turnoActual++;
        cout << "\n--- RESOLVIENDO TURNO " << turnoActual << " ---\n";
        cout << "Movimiendo enemigos y calculando ataques...\n";
        // Aquí llamarás a las funciones de tus compañeros cuando las terminen
    }
};

#endif
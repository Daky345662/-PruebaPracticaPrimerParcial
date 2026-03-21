#include "Juego.hpp"
#include <iostream>
#include <limits>
using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "         TOWER DEFENSE GAME" << endl;
    cout << "========================================" << endl;
    cout << "1. Registrar torre defensiva" << endl;
    cout << "2. Mostrar torres registradas" << endl;
    cout << "3. Eliminar torre" << endl;
    cout << "4. Registrar oleada" << endl;
    cout << "5. Mostrar oleadas" << endl;
    cout << "6. Iniciar siguiente oleada" << endl;
    cout << "7. Avanzar turno" << endl;
    cout << "8. Mostrar enemigos activos" << endl;
    cout << "9. Mostrar estado general del juego" << endl;
    cout << "10. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Opcion: ";
}

int main() {
    Juego juego;
    int opcion;
    bool salir = false;
    
    cout << "=== BIENVENIDO A TOWER DEFENSE ===" << endl;
    cout << "Longitud del camino: 20 posiciones" << endl;
    cout << "Vidas iniciales: 3" << endl;
    
    while(!salir && !juego.isJuegoTerminado()) {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                juego.registrarTorre();
                break;
            case 2:
                juego.mostrarTorres();
                break;
            case 3:
                juego.eliminarTorre();
                break;
            case 4:
                juego.registrarOleada();
                break;
            case 5:
                juego.mostrarOleadas();
                break;
            case 6:
                juego.iniciarSiguienteOleada();
                break;
            case 7:
                juego.avanzarTurno();
                break;
            case 8:
                juego.mostrarEnemigosActivos();
                break;
            case 9:
                juego.mostrarEstadoGeneral();
                break;
            case 10:
                cout << "Gracias por jugar!" << endl;
                salir = true;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                limpiarBuffer();
        }
        
        if(juego.isJuegoTerminado()) {
            cout << "\nEl juego ha terminado. Presiona Enter para salir" << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }
    
    return 0;
}
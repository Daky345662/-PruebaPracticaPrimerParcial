
    #ifndef JUEGO_HPP
#define JUEGO_HPP

#include <iostream>
#include <cmath> // Para usar abs() y calcular distancias
#include "ListaSecuencial.hpp"
#include "ListaDobleEnlazada.hpp"
#include "ListaCircular.hpp"

using namespace std;

class Juego {
private:
    // --- ATRIBUTOS PRIVADOS (Encapsulamiento) ---
    ListaSecuencial torres;      // Maneja el arreglo de estructuras defensivas
    ListaDobleEnlazada enemigos; // Maneja los enemigos activos (nodos dobles)
    ListaCircular oleadas;       // Maneja el ciclo infinito de oleadas
    
    int vidas;                   // Salud del jugador (inicia en 3)
    int turnoActual;             // Contador de turnos transcurridos
    const int LIMITE_RUTA = 20;  // Longitud máxima del camino (0 a 20)

public:
    // Constructor: Define el estado inicial de la partida
    Juego() {
        vidas = 3;
        turnoActual = 0;
    }

    // Método que gestiona la interacción con el usuario
    void iniciarMenu() {
        int opcion;
        do {
            cout << "\n=== TOWER DEFENSE - MENU PRINCIPAL ===\n";
            cout << "Vidas: " << vidas << " | Turno: " << turnoActual << "\n";
            cout << "1. Registrar torre defensiva\n";
            cout << "2. Mostrar torres registradas\n";
            cout << "3. Eliminar torre\n";
            cout << "4. Registrar oleada\n";
            cout << "5. Mostrar oleadas\n";
            cout << "6. Iniciar siguiente oleada\n";
            cout << "7. Avanzar turno\n";
            cout << "8. Mostrar enemigos activos\n";
            cout << "9. Mostrar estado general del juego\n";
            cout << "10. Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            switch(opcion) {
                case 1: {
                    // Captura de datos para crear una nueva torre
                    Torre t;
                    cout << "ID: "; cin >> t.id;
                    cout << "Nombre: "; cin >> t.nombre;
                    cout << "Tipo: "; cin >> t.tipo;
                    cout << "Posicion (0-20): "; cin >> t.posicion;
                    cout << "Danio: "; cin >> t.danio;
                    cout << "Rango: "; cin >> t.rango;
                    cout << "Costo: "; cin >> t.costo;
                    // Se envía la estructura a la lista secuencial
                    torres.insertarTorre(t); 
                    break;
                }
                case 2: 
                    torres.mostrarTorres(); 
                    break;
                case 3: 
                    int idEliminar;
                    cout << "ID de torre a eliminar: "; cin >> idEliminar;
                    torres.eliminarTorrePorId(idEliminar);
                    break;
                case 4: {
                    // Captura de datos para una nueva oleada
                    Oleada o;
                    cout << "ID Oleada: "; cin >> o.idOleada;
                    cout << "Cantidad enemigos: "; cin >> o.cantidadEnemigos;
                    // Se envía a la lista circular
                    oleadas.registrarOleada(o); 
                    break;
                }
                case 5: 
                    oleadas.mostrarOleadas(); 
                    break;
                case 6: 
                    // Cambia el puntero de la oleada actual a la siguiente en el círculo
                    oleadas.avanzarSiguienteOleada(); 
                    break;
                case 7: 
                    // Ejecuta la lógica de combate y movimiento
                    avanzarTurno(); 
                    break;
                case 8: 
                    // Recorre la lista doblemente enlazada de enemigos
                    enemigos.mostrarAdelante(); 
                    break;
                case 9: 
                    cout << "=== ESTADO DEL JUGADOR ===\n";
                    cout << "Vidas restantes: " << vidas << "\n";
                    cout << "Turnos completados: " << turnoActual << "\n";
                    cout << "Torres activas: " << torres.contarTorres() << "\n";
                    break;
                case 10: 
                    cout << "Saliendo del juego...\n"; 
                    break;
                default: 
                    cout << "Opcion no valida. Intente de nuevo.\n";
            }
        } while(opcion != 10 && vidas > 0);

        // Mensaje de derrota si las vidas llegan a cero
        if (vidas <= 0) cout << "\n¡GAME OVER! Los enemigos han conquistado tu base.\n";
    }

    // --- LÓGICA DEL MOTOR DE JUEGO (Turnos) ---
    void avanzarTurno() {
        if (vidas <= 0) return;

        turnoActual++;
        cout << "\n--- PROCESANDO TURNO " << turnoActual << " ---\n";
        
        // MOVIMIENTO:Cada enemigo avanza según su propia velocidad
        // Delegamos esto a la lista doble de enemigos
        enemigos.actualizarPosiciones();
        
        // ATAQUE: Recorremos todas las torres registradas en el arreglo (lista secuencial)
        int numTorres = torres.contarTorres();
        for (int i = 0; i < numTorres; i++) {
            // Obtenemos un puntero a la torre actual
            Torre* t = torres.obtenerTorrePorIndice(i);
            
            if (t != nullptr) {
                // Informamos qué torre está disparando
                cout << "Torre " << t->nombre << " atacando en rango " << t->rango << "...\n";
                
                // El Manager de enemigos busca qué nodos están cerca de la torre y les resta vida
                enemigos.recibirAtaque(t->posicion, t->rango, t->danio);
            }
        }

        // VALIDACIÓN DE DAÑO A LA BASE:
        // Si algún enemigo superó la posición 20, se descuentan vidas del jugador
        enemigos.verificarLlegadaAlFinal(LIMITE_RUTA, vidas);
        
        // LIMPIEZA: Eliminamos de la lista doble a los enemigos con vida <= 0
        enemigos.eliminarMuertos();
        
        cout << "Turno " << turnoActual << " completado con exito.\n";
    }
};

#endif
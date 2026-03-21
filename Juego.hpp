#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "ListaSecuencial.hpp"
#include <vector>    // Línea 5
#include "ListaDobleEnlazada.hpp"
#include "ListaCircular.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

const int LONGITUD_CAMINO = 20;
const int VIDAS_INICIALES = 3;

class Juego {
private:
    ListaSecuencial torres;
    ListaDobleEnlazada enemigosActivos;
    ListaCircular oleadas;
    int vidas;
    int puntuacion;
    int oleadaActual;
    int contadorEnemigos;
    bool juegoTerminado;
    
public:
    Juego() : vidas(VIDAS_INICIALES), puntuacion(0), oleadaActual(0), contadorEnemigos(1), juegoTerminado(false) {}
    
    // Registro de torres
    void registrarTorre() {
        Torre torre;
        cout << "\n=== REGISTRAR TORRE ===" << endl;
        cout << "ID: ";
        cin >> torre.id;
        
        if(torres.buscar(torre.id) != nullptr) {
            cout << "Error: Ya existe una torre con ese ID" << endl;
            return;
        }
        
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, torre.nombre);
        cout << "Tipo: ";
        getline(cin, torre.tipo);
        cout << "Posición (0-" << LONGITUD_CAMINO << "): ";
        cin >> torre.posicion;
        cout << "Daño: ";
        cin >> torre.danio;
        cout << "Rango: ";
        cin >> torre.rango;
        cout << "Costo: ";
        cin >> torre.costo;
        
        torre.activa = true;
        
        if(torres.insertar(torre)) {
            cout << "Torre registrada exitosamente!" << endl;
        }
    }
    
    void mostrarTorres() {
        torres.mostrar();
    }
    
    void eliminarTorre() {
        int id;
        cout << "ID de la torre a eliminar: ";
        cin >> id;
        
        if(torres.eliminar(id)) {
            cout << "Torre eliminada exitosamente!" << endl;
        } else {
            cout << "No se encontró torre con ID " << id << endl;
        }
    }
    
    // Registro de oleadas
    void registrarOleada() {
        Oleada oleada;
        cout << "\n=== REGISTRAR OLEADA ===" << endl;
        cout << "ID de oleada: ";
        cin >> oleada.idOleada;
        cout << "Cantidad de enemigos: ";
        cin >> oleada.cantidadEnemigos;
        cout << "Tipo de enemigo: ";
        cin.ignore();
        getline(cin, oleada.tipoEnemigo);
        cout << "Vida base: ";
        cin >> oleada.vidaBase;
        cout << "Velocidad base: ";
        cin >> oleada.velocidadBase;
        
        oleadas.insertar(oleada);
        cout << "Oleada registrada exitosamente!" << endl;
    }
    
    void mostrarOleadas() {
        oleadas.mostrar();
    }
    
    // Iniciar siguiente oleada
    void iniciarSiguienteOleada() {
        if(juegoTerminado) {
            cout << "El juego ya terminó. Reinicia el juego para comenzar de nuevo." << endl;
            return;
        }
        
        if(!enemigosActivos.estaVacio()) {
            cout << "Primero debes eliminar a los enemigos activos antes de iniciar una nueva oleada." << endl;
            return;
        }
        
        Oleada* oleada = oleadas.getOleadaActual();
        if(oleada == nullptr) {
            if(oleadas.getCantidad() > 0) {
                oleadas.reiniciar();
                oleada = oleadas.getOleadaActual();
            } else {
                cout << "No hay oleadas registradas. Registra al menos una oleada." << endl;
                return;
            }
        }
        
        cout << "\n=== INICIANDO OLEADA " << oleada->idOleada << " ===" << endl;
        
        for(int i = 0; i < oleada->cantidadEnemigos; i++) {
            Enemigo enemigo(
                contadorEnemigos++,
                oleada->tipoEnemigo,
                oleada->vidaBase,
                oleada->velocidadBase,
                0, // posición inicial
                10 // recompensa base
            );
            enemigosActivos.insertarFinal(enemigo);
        }
        
        cout << "Se han generado " << oleada->cantidadEnemigos << " enemigos!" << endl;
        
        // Avanzar a la siguiente oleada
        oleadas.avanzar();
    }
    
    // Avanzar turno
    void avanzarTurno() {
        if(juegoTerminado) {
            cout << "El juego ha terminado. Reinicia el programa para jugar de nuevo." << endl;
            return;
        }
        
        if(enemigosActivos.estaVacio()) {
            cout << "No hay enemigos activos. Inicia una oleada primero." << endl;
            return;
        }
        
        cout << "\n=== TURNO " << (oleadaActual + 1) << " ===" << endl;
        
        // 1. Mover enemigos
        enemigosActivos.moverTodos();
        
        // 2. Torres atacan
        atacarEnemigos();
        
        // 3. Verificar enemigos destruidos y llegar al final
        verificarEnemigos();
        
        // 4. Verificar fin del juego
        if(vidas <= 0) {
            juegoTerminado = true;
            cout << "\n!!! GAME OVER !!! Has perdido todas tus vidas." << endl;
        } else if(enemigosActivos.estaVacio() && !hayMasOleadas()) {
            juegoTerminado = true;
            cout << "\n!!! VICTORIA !!! Has completado todas las oleadas!" << endl;
        } else {
            mostrarEstadoGeneral();
        }
        
        oleadaActual++;
    }
    
    void atacarEnemigos() {
        cout << "\n--- ATAQUES DE TORRES ---" << endl;
        
        for(int i = 0; i < torres.getCantidad(); i++) {
            Torre* torre = &(torres.getTorres()[i]);
            if(!torre->activa) continue;
            
            NodoEnemigo* nodo = enemigosActivos.getPrimero();
            bool ataco = false;
            
            while(nodo != nullptr) {
                int distancia = abs(nodo->enemigo.posicion - torre->posicion);
                
                if(distancia <= torre->rango) {
                    cout << "Torre '" << torre->nombre << "' ataca a enemigo " 
                         << nodo->enemigo.id << " causando " << torre->danio << " de daño!" << endl;
                    nodo->enemigo.recibirDanio(torre->danio);
                    ataco = true;
                }
                nodo = nodo->siguiente;
            }
            
            if(!ataco) {
                cout << "Torre '" << torre->nombre << "' no tiene enemigos en su rango." << endl;
            }
        }
    }
    
    void verificarEnemigos() {
        NodoEnemigo* nodo = enemigosActivos.getPrimero();
        vector<int> idsEliminar;
        vector<int> idsLlegaron;
        
        while(nodo != nullptr) {
            if(!nodo->enemigo.estaVivo()) {
                idsEliminar.push_back(nodo->enemigo.id);
                puntuacion += nodo->enemigo.recompensa;
                cout << "Enemigo " << nodo->enemigo.id << " eliminado! +" 
                     << nodo->enemigo.recompensa << " puntos." << endl;
            } else if(nodo->enemigo.posicion >= LONGITUD_CAMINO) {
                idsLlegaron.push_back(nodo->enemigo.id);
            }
            nodo = nodo->siguiente;
        }
        
        // Eliminar enemigos muertos
        for(int id : idsEliminar) {
            enemigosActivos.eliminar(id);
        }
        
        // Descontar vidas por enemigos que llegaron al final
        for(int id : idsLlegaron) {
            enemigosActivos.eliminar(id);
            vidas--;
            cout << "Enemigo " << id << " llego al final! Pierdes 1 vida. Vidas restantes: " << vidas << endl;
        }
        
        if(!idsLlegaron.empty()) {
            cout << "Total de vidas perdidas: " << idsLlegaron.size() << endl;
        }
    }
    
    bool hayMasOleadas() {
        // Verificar si hay más oleadas (si el actual no es el último)
        // Esto es simplificado - en una implementación real se necesitaría más lógica
        return oleadas.getCantidad() > 0;
    }
    
    void mostrarEnemigosActivos() {
        enemigosActivos.recorrerAdelante();
    }
    
    void mostrarEstadoGeneral() {
        cout << "\n=== ESTADO GENERAL DEL JUEGO ===" << endl;
        cout << "Vidas restantes: " << vidas << endl;
        cout << "Puntuacion total: " << puntuacion << endl;
        cout << "Torres activas: " << torres.contarActivas() << " de " << torres.getCantidad() << endl;
        cout << "Enemigos activos: " << enemigosActivos.getCantidad() << endl;
        cout << "Estado: " << (juegoTerminado ? "TERMINADO" : "EN CURSO") << endl;
        
        if(!juegoTerminado) {
            Oleada* oleada = oleadas.getOleadaActual();
            if(oleada != nullptr) {
                cout << "Proxima oleada: " << oleada->idOleada << " (" 
                     << oleada->cantidadEnemigos << " enemigos)" << endl;
            } else {
                cout << "Todas las oleadas completadas!" << endl;
            }
        }
    }
    
    bool isJuegoTerminado() { return juegoTerminado; }
};

#endif
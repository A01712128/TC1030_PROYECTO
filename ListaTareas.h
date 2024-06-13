/*
 *
 * Proyecto Gestor de tareas clase ListaTareas
 * Liliana Valdovinos Catarino
 * A01712128
 * 10/06/2024
 *
 * Esta clase define un objeto de tipo ListaTareas que contiene todas las 
 * operaciones para manejar una lista de tareas. Permite agregar
 * y mostrar tareas. Esta clase es utilizada por la clase Usuario para gestionar 
 * las tareas de un usuario.
 */

#ifndef LISTATAREAS_H // Si LISTATAREAS_H no ha sido definido,
#define LISTATAREAS_H

#include "TareaBase.h"
#include "TareaProgramada.h" 
#include <vector>
#include <iostream>
using namespace std;

class ListaTareas {
private:
    vector<TareaBase*> tareas; // Vector de punteros a TareaBase

public:
    // Agrega una tarea a la lista 
    void agregarTarea(TareaBase* tarea) {
        tareas.push_back(tarea);
    }

    // Elimina una tarea de la lista
    void eliminarTarea(TareaBase* tarea) {
        for (auto it = tareas.begin(); it != tareas.end(); ++it) {
            if (*it == tarea) {
                tareas.erase(it);
                break;
            }
        }
    }

    // Muestra todas las tareas en la lista
// Const al final de la función, asegura que esta función no altere el objeto lista, ni sus miembros.
    void mostrarTareas() const {
        for (size_t i = 0; i < tareas.size(); ++i) {
            cout << "[" << i + 1 << "] ";
            cout << (dynamic_cast<TareaProgramada*>(tareas[i]) ? "Tarea Programada: " : "Tarea Simple: ");
            cout << "Descripcion: " << tareas[i]->getDescripcion() << "\n";
            cout << "Completada: " << (tareas[i]->estaCompletada() ? "Si" : "No") << "\n";
            cout << "-------------------\n";
        }
    }

    // Retorna la lista de tareas
    vector<TareaBase*>& getTareas() {
        return tareas;
    }

    // Destructor que libera la memoria de las tareas
    ~ListaTareas() {
        for (auto& tarea : tareas) {
            delete tarea;
        }
    }
};

#endif // LISTATAREAS_H

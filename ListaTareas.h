#include <iostream>
#include <string>
#include <vector>
#include "TareaBase.h"
using namespace std;

// Clase para gestionar una lista de tareas
class ListaTareas {
private:
    vector<TareaBase*> tareas; // Vector de punteros a tareas

public:
    // Método para agregar una tarea a la lista
    void agregarTarea(TareaBase* tarea) {
        tareas.push_back(tarea);
    }

    // Método para eliminar una tarea de la lista
    void eliminarTarea(TareaBase* tarea) {
        // Elimina la tarea sin usar la librería <algorithm>
        for (auto it = tareas.begin(); it != tareas.end(); ++it) {
            if (*it == tarea) {
                tareas.erase(it);
                break;
            }
        }
    }

    // Método para mostrar todas las tareas en la lista
    void mostrarTareas() const {
        for (const auto& tarea : tareas) {
            cout << "Descripcion: " << tarea->getDescripcion() << "\n";
            cout << "Completada: " << (tarea->estaCompletada() ? "Si" : "No") << "\n";
            cout << "-------------------\n";
        }
    }

    // Destructor para liberar la memoria de las tareas
    ~ListaTareas() {
        for (auto& tarea : tareas) {
            delete tarea;
        }
    }
};
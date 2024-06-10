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
#include <vector>

class ListaTareas {
private:
    vector<TareaBase*> tareas; // Vector de punteros a TareaBase

public:
    void agregarTarea(TareaBase* tarea); // Método para agregar una tarea a la lista.
    void mostrarTareas() const; // Método para mostrar todas las tareas de la lista.
    vector<TareaBase*>& getTareas() { return tareas; } // Método para obtener todas las tareas de la lista.
    ~ListaTareas(); // Destructor de la lista de tareas.
};

#endif // LISTATAREAS_H

/*
 *
 * Proyecto Gestor de tareas clase TareaBase
 * Liliana Valdovinos Catarino
 * A01712128
 * 10/06/2024
 *
 * Esta clase define un objeto abstracto de tipo TareaBase que sirve como base 
 * para las tareas. Contiene operaciones comunes para las tareas, como marcar 
 * una tarea como completada o incompleta, y verificar su estado. Esta clase 
 * es utilizada como base para las clases TareaSimple y TareaProgramada.
 */

#ifndef TAREABASE_H // Si TAREABASE_H no ha sido definido,
#define TAREABASE_H

#include <string>
using namespace std;

class TareaBase {
protected:
    string descripcion; // Descripción de la tarea.
    bool completada; // Estado de la tarea.

public:
    TareaBase(const string& desc); // Constructor que inicia la descripción y el estado de la tarea.

    virtual void marcarCompletada(); // Método virtual para marcar la tarea como completada.
    virtual void marcarIncompleta(); // Método virtual para marcar la tarea como incompleta.
    virtual string getDescripcion() const = 0; // Método virtual puro para obtener la descripción de la tarea.
    virtual bool estaCompletada() const; // Método virtual para verificar si la tarea está completada.
    virtual ~TareaBase() = 0; // Destructor virtual puro.
};

#endif // TAREABASE_H

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

#ifndef TAREABASE_H
#define TAREABASE_H

#include <string>
using namespace std;

class TareaBase {
protected:
    string descripcion; // Descripción de la tarea
    bool completada; // Estado de completitud de la tarea

public:
/**
 * Constructor de TareaBase.
 *
 * @param desc Descripción de la tarea.
 */
    TareaBase(const string& desc) : descripcion(desc), completada(false) {}
/**
 * Marca la tarea como completada.
 *
 * @param 
 * @return 
 */
    virtual void marcarCompletada() {
        completada = true;
    }

/**
 * Marca la tarea como incompleta.
 *
 * @param 
 * @return 
 */
    virtual void marcarIncompleta() {
        completada = false;
    }
/**
 * Retorna la descripción de la tarea.
 *
 * @param 
 * @return La descripción de la tarea.

Const al final de la declaración de la función virtual, indica que la función no modificará el estado del objeto.
 */
    virtual string getDescripcion() const = 0;

/**
 * Retorna si la tarea está completada.
 *
 * @param 
 * @return true si la tarea está completada, false de lo contrario.
 */
    virtual bool estaCompletada() const {
        return completada;
    }
/**
 * Destructor virtual.

Destructor virtual (se utiliza para permitir la eliminación de objetos derivados))
 */
    virtual ~TareaBase() {}
};

#endif // TAREABASE_H

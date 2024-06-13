/*
 *
 * Proyecto Gestor de tareas clase TareaSimple
 * Liliana Valdovinos Catarino
 * A01712128
 * 10/06/2024
 *
 * Esta clase define un objeto de tipo TareaSimple que hereda de TareaBase.
 * Representa una tarea sencilla sin fecha de vencimiento. Contiene métodos 
 * específicos para manejar la descripción de la tarea. Esta clase es utilizada 
 * para crear tareas simples sin una fecha límite.
 */

#ifndef TAREASIMPLE_H
#define TAREASIMPLE_H

#include "TareaBase.h"

class TareaSimple : public TareaBase {
public:
// Constructor: recibe un string desc y lo pasa al constructor de TareaBase.
// El const antes de string& desc indica que desc no se modificará dentro del constructor.
    TareaSimple(const string& desc) : TareaBase(desc) {}

// Método getDescripcion: devuelve la descripción de la tarea.
// El const override asegura que no altere el estado del objeto y sobrescribe correctamente la función virtual de la clase base.
    string getDescripcion() const override {
        return descripcion;
    }
};

#endif // TAREASIMPLE_H

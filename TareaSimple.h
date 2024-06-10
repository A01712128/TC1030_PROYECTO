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

#ifndef TAREASIMPLE_H // Si TAREASIMPLE_H no ha sido definido,
#define TAREASIMPLE_H

#include "TareaBase.h"

class TareaSimple : public TareaBase {
public:
    TareaSimple(const string& desc); // Constructor que inicia la descripción de la tarea simple.
    string getDescripcion() const override; // Método para obtener la descripción de la tarea simple.
};

#endif // TAREASIMPLE_H

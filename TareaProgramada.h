/*
 *
 * Proyecto Gestor de tareas clase TareaProgramada
 * Liliana Valdovinos Catarino
 * A01712128
 * 10/06/2024
 *
 * Esta clase define un objeto de tipo TareaProgramada que hereda de TareaBase.
 * Representa una tarea que tiene una fecha de vencimiento. Contiene métodos 
 * específicos para manejar la fecha de vencimiento de la tarea. 
 * Esta clase es utilizada para crear tareas con una fecha límite.
 */

#ifndef TAREAPROGRAMADA_H // Si TAREAPROGRAMADA_H no ha sido definido,
#define TAREAPROGRAMADA_H

#include "TareaBase.h"
#include <ctime>

class TareaProgramada : public TareaBase {
private:
    time_t fechaVencimiento; // Fecha de vencimiento de la tarea.

public:
    TareaProgramada(const string& desc, time_t fecha); // Constructor que inicia la descripción y la fecha de vencimiento de la tarea.
    void setFechaVencimiento(time_t fecha); // Método para establecer la fecha de vencimiento de la tarea.
    time_t getFechaVencimiento() const; // Método para obtener la fecha de vencimiento de la tarea.
    string getDescripcion() const override; // Método para obtener la descripción de la tarea, incluyendo la fecha de vencimiento.
};

#endif // TAREAPROGRAMADA_H

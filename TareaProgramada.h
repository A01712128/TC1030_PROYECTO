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

#ifndef TAREAPROGRAMADA_H
#define TAREAPROGRAMADA_H

#include "TareaBase.h"
#include <ctime>
#include <string>

class TareaProgramada : public TareaBase {
private:
    time_t fechaVencimiento; // Fecha de vencimiento de la tarea

public:
    // Constructor
// El const significa que dentro del cuerpo del constructor, no se puede modificar el string al que desc hace referencia.
    TareaProgramada(const string& desc, time_t fecha) : TareaBase(desc), fechaVencimiento(fecha) {}

    // Establece la fecha de vencimiento
    void setFechaVencimiento(time_t fecha) {
        fechaVencimiento = fecha;
    }

    // Retorna la fecha de vencimiento
    time_t getFechaVencimiento() const {
        return fechaVencimiento;
    }

    // Retorna la descripción de la tarea, incluyendo la fecha de vencimiento
// En la función getDescripcion de la clase TareaProgramada, el const al final indica que la función no modificará ningún miembro de datos de la clase. Se utiliza strftime para formatear la fecha de vencimiento y almacenarla en un buffer de caracteres. Esta fecha formateada se concatena con la descripción de la tarea y se devuelve como resultado de la función. El buffer es un área de almacenamiento temporal para el resultado formateado de la fecha. El uso de const es importante para garantizar que la función no altere el estado del objeto y mantenga la integridad de los datos.
    string getDescripcion() const override {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&fechaVencimiento));
        return descripcion + " (vencimiento: " + buffer + ")";
    }
};

#endif // TAREAPROGRAMADA_H

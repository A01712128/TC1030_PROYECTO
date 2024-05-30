#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "TareaBase.h"
using namespace std;

// Clase derivada para tareas programadas
class TareaProgramada : public TareaBase {
private:
    time_t fechaVencimiento; // Fecha de vencimiento de la tarea

public:
    // Constructor que llama al constructor de la clase base y establece la fecha de vencimiento
    TareaProgramada(const string& desc, time_t fecha)
        : TareaBase(desc), fechaVencimiento(fecha) {}

    // Método para establecer la fecha de vencimiento
    void setFechaVencimiento(time_t fecha) {
        fechaVencimiento = fecha;
    }

    // Método para obtener la fecha de vencimiento
    time_t getFechaVencimiento() const {
        return fechaVencimiento;
    }

    // Sobrescritura del método getDescripcion para incluir la fecha de vencimiento
    string getDescripcion() const override {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&fechaVencimiento));
        return TareaBase::getDescripcion() + " (vencimiento: " + buffer + ")";
    }
};
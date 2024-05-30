#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include "ListaTareas.h"
#include "Usuario.h"
using namespace std;

// Clase base para las tareas
class TareaBase {
protected:
    string descripcion; // Descripción de la tarea
    bool completada;    // Estado de la tarea, si está completada o no

public:
    // Constructor de la clase base
    TareaBase(const string& desc) : descripcion(desc), completada(false) {}

    // Método para marcar una tarea como completada
    virtual void marcarCompletada() {
        completada = true;
    }

    // Método para marcar una tarea como incompleta
    virtual void marcarIncompleta() {
        completada = false;
    }

    // Método para obtener la descripción de la tarea
    virtual string getDescripcion() const {
        return descripcion;
    }

    // Método para comprobar si la tarea está completada
    virtual bool estaCompletada() const {
        return completada;
    }

    // Destructor virtual para permitir la eliminación adecuada de objetos derivados
    virtual ~TareaBase() {}
};

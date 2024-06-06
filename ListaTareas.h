#ifndef LISTATAREAS_H
#define LISTATAREAS_H

#include "TareaBase.h"
#include <vector>

class ListaTareas {
private:
    vector<TareaBase*> tareas;

public:
    void agregarTarea(TareaBase* tarea);
    void eliminarTarea(TareaBase* tarea);
    void mostrarTareas() const;
    vector<TareaBase*>& getTareas() { return tareas; } // Implementación en línea de getTareas()
    ~ListaTareas();
};

#endif // LISTATAREAS_H

#include <iostream>  
#include <vector>    
#include <string>    

using namespace std; 

// Clase TareaBase
class TareaBase {
protected:
    string descripcion; 
    bool completada;    

public:
    // Constructor que inicia la tarea con una descripcion y la marca como no completada
    TareaBase(const string& desc) : descripcion(desc), completada(false) {}

    // Marca la tarea como completada
    void marcarCompletada() {
        completada = true;
    }

    // Marca la tarea como incompleta
    void marcarIncompleta() {
        completada = false;
    }

    // Devuelve la descripcion de la tarea
    string getDescripcion() const {
        return descripcion;
    }

    // Checa si la tarea esta completada
    bool estaCompletada() const {
        return completada;
    }

};

// Clase TareaSimple que hereda de TareaBase
class TareaSimple : public TareaBase {
public:
    // Constructor que inicia TareaSimple usando el constructor de TareaBase
    TareaSimple(const string& desc) : TareaBase(desc) {}
    // No se agregan nuevos metodos o atributos, usa los heredados de TareaBase
};

// Clase TareaProgramada que hereda de TareaBase
class TareaProgramada : public TareaBase {
private:
    string fechaVencimiento; // Fecha de vencimiento de la tarea

public:
    // Constructor que inicia TareaProgramada con una descripcion y una fecha de vencimiento
    TareaProgramada(const string& desc, const string& fecha) 
        : TareaBase(desc), fechaVencimiento(fecha) {}

    // Pone la fecha de vencimiento de la tarea
    void setFechaVencimiento(const string& fecha) {
        fechaVencimiento = fecha;
    }

    // Devuelve la fecha de vencimiento de la tarea
    string getFechaVencimiento() const {
        return fechaVencimiento;
    }

    // Sobrescribe el metodo getDescripcion para incluir la fecha de vencimiento en la descripcin
    string getDescripcion() const override {
        return descripcion + " (Vence el: " + fechaVencimiento + ")";
    }
};

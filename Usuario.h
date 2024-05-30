#include <iostream>
#include <string>
#include "ListaTareas.h"
using namespace std;

// Clase para representar a un usuario
class Usuario {
private:
    string nombre; // Nombre del usuario
    string correo; // Correo del usuario
    ListaTareas listaTareas; // Lista de tareas del usuario

public:
    // Método para establecer el nombre del usuario
    void setNombre(const string& nom) {
        nombre = nom;
    }

    // Método para establecer el correo del usuario
    void setCorreo(const string& mail) {
        correo = mail;
    }

    // Método para obtener el nombre del usuario
    string getNombre() const {
        return nombre;
    }

    // Método para obtener el correo del usuario
    string getCorreo() const {
        return correo;
    }

    // Método para obtener la lista de tareas del usuario
    ListaTareas& getListaTareas() {
        return listaTareas;
    }
};
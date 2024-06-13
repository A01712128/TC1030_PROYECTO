/*
 *
 * Proyecto Gestor de tareas clase Usuario
 * Liliana Valdovinos Catarino
 * A01712128
 * 10/06/2024
 *
 * Esta clase define un objeto de tipo Usuario que contiene el nombre, correo,
 * y lista de tareas de un usuario. Permite establecer y obtener los datos del 
 * usuario, así como acceder a la lista de tareas del usuario. Esta clase es 
 * utilizada por la función principal del programa para gestionar los datos 
 * del usuario y sus tareas.
 */

#ifndef USUARIO_H
#define USUARIO_H

#include "ListaTareas.h"
#include <string>
using namespace std;

class Usuario {
private:
    string nombre; // Nombre del usuario
    string correo; // Correo del usuario
    ListaTareas listaTareas; // Lista de tareas del usuario

public:
    // Establece el nombre del usuario
    void setNombre(string& nom) {
        nombre = nom;
    }

    // Establece el correo del usuario
    void setCorreo(string& mail) {
        correo = mail;
    }

    // Retorna el nombre del usuario
    string getNombre() {
        return nombre;
    }

    // Retorna el correo del usuario
    string getCorreo() {
        return correo;
    }

    // Retorna la lista de tareas del usuario
    ListaTareas& getListaTareas() {
        return listaTareas;
    }
};

#endif // USUARIO_H

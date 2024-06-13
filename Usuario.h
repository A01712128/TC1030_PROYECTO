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
    /**
     * Establece el nombre del usuario.
     *
     * @param nombre Nombre del usuario.
     */
    void setNombre(string& nombre) {
        this->nombre = nombre;
    }

    /**
     * Retorna el nombre del usuario.
     *
     * @param 
     * @return El nombre del usuario.
     */
    string getNombre() {
        return nombre;
    }

    /**
     * Establece el correo del usuario.
     *
     * @param correo Correo del usuario.
     */
    void setCorreo(string& correo) {
        this->correo = correo;
    }

    /**
     * Retorna el correo del usuario.
     *
     * @param 
     * @return El correo del usuario.
     */
    string getCorreo() {
        return correo;
    }

    /**
     * Retorna la lista de tareas del usuario.
     *
     * @param 
     * @return La lista de tareas del usuario.
     */
    ListaTareas& getListaTareas() {
        return listaTareas;
    }
};

#endif // USUARIO_H

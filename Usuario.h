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

#ifndef USUARIO_H // Si USUARIO_H no ha sido definido,
#define USUARIO_H

#include "ListaTareas.h"
#include <string>
using namespace std;

class Usuario {
private:
    string nombre; // Nombre del usuario.
    string correo; // Correo del usuario.
    ListaTareas listaTareas; // Lista de tareas.

public:
    void setNombre(const string& nom); // Método para establecer el nombre del usuario.
    void setCorreo(const string& mail); // Método para establecer el correo del usuario.
    string getNombre() const; // Método para obtener el nombre del usuario.
    string getCorreo() const; // Método para obtener el correo del usuario.
    ListaTareas& getListaTareas(); // Método para obtener la lista de tareas del usuario.
};

#endif // USUARIO_H

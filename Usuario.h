#ifndef USUARIO_H
#define USUARIO_H

#include "ListaTareas.h"
#include <string>
using namespace std;

class Usuario {
private:
    string nombre;
    string correo;
    ListaTareas listaTareas;

public:
    void setNombre(const string& nom);
    void setCorreo(const string& mail);
    string getNombre() const;
    string getCorreo() const;
    ListaTareas& getListaTareas();
};

#endif // USUARIO_H

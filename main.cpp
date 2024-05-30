#include <iostream>
#include <string>
#include "Usuario.h"        // Incluir el archivo de encabezado de Usuario
#include "TareaSimple.h"    // Incluir el archivo de encabezado de TareaSimple
#include "TareaProgramada.h"// Incluir el archivo de encabezado de TareaProgramada
#include "ListaTareas.h"    // Incluir el archivo de encabezado de ListaTareas
using namespace std;

// Función para convertir una cadena de texto en un objeto time_t
time_t stringToTimeT(const string& fechaStr) {
    tm tm = {};
    sscanf(fechaStr.c_str(), "%Y-%m-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    return mktime(&tm);

int main() {
    Usuario usuario;
    string nombre, correo;

    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    usuario.setNombre(nombre);

    cout << "Ingrese su correo: ";
    getline(cin, correo);
    usuario.setCorreo(correo);

    bool continuar = true;
    while (continuar) {
        int opcion;
        cout << "\nMenu:\n";
        cout << "1. Agregar tarea simple\n";
        cout << "2. Agregar tarea programada\n";
        cout << "3. Mostrar tareas\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1: {
                string descripcion;
                cout << "Ingrese la descripcion de la tarea simple: ";
                getline(cin, descripcion);
                TareaSimple* tarea = new TareaSimple(descripcion);
                usuario.getListaTareas().agregarTarea(tarea);
                break;
            }
            case 2: {
                string descripcion, fechaStr;
                cout << "Ingrese la descripcion de la tarea programada: ";
                getline(cin, descripcion);
                cout << "Ingrese la fecha de vencimiento (YYYY-MM-DD): ";
                getline(cin, fechaStr);
                time_t fechaVencimiento = stringToTimeT(fechaStr);
                TareaProgramada* tarea = new TareaProgramada(descripcion, fechaVencimiento);
                usuario.getListaTareas().agregarTarea(tarea);
                break;
            }
            case 3: {
                usuario.getListaTareas().mostrarTareas();
                break;
            }
            case 4: {
                continuar = false;
                break;
            }
            default: {
                cout << "Opcion no valida, intente de nuevo.\n";
                break;
            }
        }
    }

    return 0;
}
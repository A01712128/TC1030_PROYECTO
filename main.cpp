/*
 * Proyecto Gestor de Tareas
 * Liliana Valdovinos Catarino
 * A01712128
 * 10/06/2024
 *
 * Este es un proyecto para la clase TC1030.304 Programación Orientado a
 * Objetos. Es un programa que permite gestionar tareas simples las cuales serían como 
 * (sacar al perro, comprar leche) ya que no ocupan una fecha límite y 
 * tareas programadas que si ocupan fecha límite para un usuario. 
 * Los usuarios pueden agregar tareas, ver la lista de tareas, 
 * y marcar tareas como completadas.
 */

#include "Usuario.h"
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include <iostream>
#include <ctime>

using namespace std;
/**
 * Esta función la utilizo para convertir una cadena de fecha en el formato "YYYY-MM-DD" (time_t).
 *
 * @param fechaStr La fecha en formato de cadena "YYYY-MM-DD".
 * @return El objeto time_t correspondiente a la fecha, o -1 si la conversión falla.
 */

time_t stringToTimeT(const string& fechaStr) {
    tm tm = {};
    if (sscanf(fechaStr.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) == 3) {
        tm.tm_year -= 1900; // Ajuste año
        tm.tm_mon -= 1; // Ajuste mes
        return mktime(&tm); // Convierte la fecha en formato de texto
    }
    return -1; // Retorna -1 si la conversión falla (Si el usuario introduce mal la fecha, el programa detecta este valor y muestra un mensaje de error).
}

/**
 * Función principal que ejecuta el programa.
 *
 * Crea un objeto Usuario y permite al usuario interactuar con el sistema
 * de gestión de tareas a través de un menú.
 *
 * @return 0 al finalizar el programa.
 */
int main() {
    Usuario usuario; // Crea el objeto usuario
    string nombre, correo; 

    // Solicita al usuario su nombre
    cout << "Ingrese su nombre: ";
    getline(cin, nombre); // Utiliza getline para leer una línea completa (Es útil para leer entradas de usuario que pueden contener espacios, como nombres completos)
    usuario.setNombre(nombre);

    // Solicita al usuario su correo
    cout << "Ingrese su correo: ";
    getline(cin, correo); // Utiliza getline para leer una línea completa
    usuario.setCorreo(correo);

    bool continuar = true;
    while (continuar) {
        int opcion;
        // Muestra las opciones del menú
        cout << "\nMenu:\n";
        cout << "1. Agregar tarea simple\n";
        cout << "2. Agregar tarea programada\n";
        cout << "3. Mostrar tareas\n";
        cout << "4. Marcar tarea como completada\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpia el buffer de entrada después de leer una entrada cin. (Asegura que la siguiente llamada a getline lea la entrada del usuario correctamente)

        switch (opcion) {
            case 1: {
                string descripcion;
                // Solicita y agrega una tarea simple
                cout << "Ingrese la descripcion de la tarea simple: ";
                getline(cin, descripcion);
                TareaSimple* tarea = new TareaSimple(descripcion);
                usuario.getListaTareas().agregarTarea(tarea);
                break;
            }
            case 2: {
                string descripcion, fechaStr;
                // Solicita y agrega una tarea programada
                cout << "Ingrese la descripcion de la tarea programada: ";
                getline(cin, descripcion);
                cout << "Ingrese la fecha de vencimiento (YYYY-MM-DD): ";
                getline(cin, fechaStr);
                time_t fechaVencimiento = stringToTimeT(fechaStr);
                if (fechaVencimiento != -1) {
                    TareaProgramada* tarea = new TareaProgramada(descripcion, fechaVencimiento);
                    usuario.getListaTareas().agregarTarea(tarea);
                } else {
                    cout << "Fecha inválida.\n";
                }
                break;
            }
            case 3: {
                // Muestra todas las tareas
                usuario.getListaTareas().mostrarTareas();
                break;
            }
            case 4: {
                int indice;
                // Marca una tarea como completada
                cout << "Ingrese el número de índice de la tarea a marcar como completada: ";
                cin >> indice;
                cin.ignore();

                if (indice > 0 && indice <= usuario.getListaTareas().getTareas().size()) {
                    TareaBase* tarea = usuario.getListaTareas().getTareas()[indice - 1];
                    tarea->marcarCompletada();
                    cout << "Tarea marcada como completada.\n";
                } else {
                    cout << "Índice no encontrado. Intente de nuevo.\n";
                }
                break;
            }
            case 5: {
                // Sale del programa
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

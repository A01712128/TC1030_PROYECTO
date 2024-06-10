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

#include "Usuario.h" // Incluye la clase Usuario.
#include "TareaSimple.h" // Incluye la clase TareaSimple.
#include "TareaProgramada.h" // Incluye la clase TareaProgramada.
#include <iostream> // Biblioteca para manejo de entrada y salida.
#include <ctime> // Biblioteca para fechas.

using namespace std;

// Esta función la utilizo para convertir una cadena de fecha en el formato "YYYY-MM-DD".
time_t stringToTimeT(const string& fechaStr) {
    tm tm = {};
    // sscan f la utilizo para dividir la fecha en año, mes y día
    if (sscanf(fechaStr.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) == 3) {
        tm.tm_year -= 2000; //Ajuste año
        tm.tm_mon -= 1; // Ajuste mes
        return mktime(&tm); // Convierte la fecha en formato de texto
    }
    return -1;
}

// Implementaciones de TareaBase
TareaBase::TareaBase(const string& desc) : descripcion(desc), completada(false) {}

// MArca la tarea como completada
void TareaBase::marcarCompletada() {
    completada = true;
}

// Marca la tarea como incompleta
void TareaBase::marcarIncompleta() {
    completada = false;
}

// Esto verifica si la tarea está completada
bool TareaBase::estaCompletada() const {
    return completada;
}

TareaBase::~TareaBase() {}

// Implementaciones de TareaSimple
TareaSimple::TareaSimple(const string& desc) : TareaBase(desc) {}

// Devuelve la descripcion de la tarea
string TareaSimple::getDescripcion() const {
    return descripcion;
}

// Implementaciones de TareaProgramada
TareaProgramada::TareaProgramada(const string& desc, time_t fecha)
    : TareaBase(desc), fechaVencimiento(fecha) {}

// Establece la fecha de vencimiento de la tarea
void TareaProgramada::setFechaVencimiento(time_t fecha) {
    fechaVencimiento = fecha;
}

// Devuelve la fecha de vencimiento
time_t TareaProgramada::getFechaVencimiento() const {
    return fechaVencimiento;
}

// Devuelve la descripcion de la tarea con la fecha de vencimiento
// El buffer lo utilizo para guardar la fecha de vencimineto en un formato legible
string TareaProgramada::getDescripcion() const {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&fechaVencimiento));
    return descripcion + " (vencimiento: " + buffer + ")";
}

// Implementaciones de ListaTareas
// Agrega una tarea a la lista
void ListaTareas::agregarTarea(TareaBase* tarea) {
    tareas.push_back(tarea);
}

// Muestra todas la tareas de la lista
void ListaTareas::mostrarTareas() const {
    for (const auto& tarea : tareas) {
        cout << (dynamic_cast<TareaProgramada*>(tarea) ? "Tarea Programada: " : "Tarea Simple: ");
        cout << "Descripcion: " << tarea->getDescripcion() << "\n";
        cout << "Completada: " << (tarea->estaCompletada() ? "Si" : "No") << "\n";
        cout << "-------------------\n";
    }
}

// Destructor de la lista de tareas para liberar memoria
ListaTareas::~ListaTareas() {
    for (auto& tarea : tareas) {
        delete tarea;
    }
}

// Implementaciones de Usuario
// Se asigna el nombre del usuario
void Usuario::setNombre(const string& nom) {
    nombre = nom;
}

// Se asigna el correo del usuario
void Usuario::setCorreo(const string& mail) {
    correo = mail;
}

// Devuelve el nombre del usuario
string Usuario::getNombre() const {
    return nombre;
}

// Devuelve el correo del usuario
string Usuario::getCorreo() const {
    return correo;
}

// Devuelve la lista de tareas del usuario
ListaTareas& Usuario::getListaTareas() {
    return listaTareas;
}

// Función principal
int main() {
    Usuario usuario; // Crea el objeto usuario
    string nombre, correo;
    // Solicita al usuario su nombre
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    usuario.setNombre(nombre);
    // Solicita al usuario su correo
    cout << "Ingrese su correo: ";
    getline(cin, correo);
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
        cin.ignore();

        switch (opcion) {
            case 1: {
                // Se agrega una tarea simple
                string descripcion;
                cout << "Ingrese la descripcion de la tarea simple: ";
                getline(cin, descripcion);
                TareaSimple* tarea = new TareaSimple(descripcion);
                usuario.getListaTareas().agregarTarea(tarea);
                break;
            }
            case 2: {
                // Se agrega una tarea programada
                string descripcion, fechaStr;
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
                // Marca tarea como completada
                string descripcion;
                cout << "Ingrese la descripcion de la tarea a marcar como completada: ";
                getline(cin, descripcion);
                for (TareaBase* tarea : usuario.getListaTareas().getTareas()) {
                    if (tarea->getDescripcion() == descripcion) {
                        tarea->marcarCompletada();
                        break;
                    }
                }
                break;
            }
            case 5: {
                // Se sale del programa
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

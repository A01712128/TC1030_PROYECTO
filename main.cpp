#include "Usuario.h"
#include "TareaSimple.h"
#include "TareaProgramada.h"
#include <iostream>
#include <ctime>

using namespace std;

time_t stringToTimeT(const string& fechaStr) {
    tm tm = {};
    if (sscanf(fechaStr.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) == 3) {
        tm.tm_year -= 1900;
        tm.tm_mon -= 1;
        return mktime(&tm);
    }
    return -1;
}

// Implementaciones de TareaBase
TareaBase::TareaBase(const string& desc) : descripcion(desc), completada(false) {}

void TareaBase::marcarCompletada() {
    completada = true;
}

void TareaBase::marcarIncompleta() {
    completada = false;
}

bool TareaBase::estaCompletada() const {
    return completada;
}

TareaBase::~TareaBase() {}

// Implementaciones de TareaSimple
TareaSimple::TareaSimple(const string& desc) : TareaBase(desc) {}

string TareaSimple::getDescripcion() const {
    return descripcion;
}

// Implementaciones de TareaProgramada
TareaProgramada::TareaProgramada(const string& desc, time_t fecha)
    : TareaBase(desc), fechaVencimiento(fecha) {}

void TareaProgramada::setFechaVencimiento(time_t fecha) {
    fechaVencimiento = fecha;
}

time_t TareaProgramada::getFechaVencimiento() const {
    return fechaVencimiento;
}

string TareaProgramada::getDescripcion() const {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&fechaVencimiento));
    return descripcion + " (vencimiento: " + buffer + ")";
}

// Implementaciones de ListaTareas
void ListaTareas::agregarTarea(TareaBase* tarea) {
    tareas.push_back(tarea);
}

void ListaTareas::eliminarTarea(TareaBase* tarea) {
    for (auto it = tareas.begin(); it != tareas.end(); ++it) {
        if (*it == tarea) {
            tareas.erase(it);
            break;
        }
    }
}

void ListaTareas::mostrarTareas() const {
    for (const auto& tarea : tareas) {
        cout << (dynamic_cast<TareaProgramada*>(tarea) ? "Tarea Programada: " : "Tarea Simple: ");
        cout << "Descripcion: " << tarea->getDescripcion() << "\n";
        cout << "Completada: " << (tarea->estaCompletada() ? "Si" : "No") << "\n";
        cout << "-------------------\n";
    }
}

ListaTareas::~ListaTareas() {
    for (auto& tarea : tareas) {
        delete tarea;
    }
}

// Implementaciones de Usuario
void Usuario::setNombre(const string& nom) {
    nombre = nom;
}

void Usuario::setCorreo(const string& mail) {
    correo = mail;
}

string Usuario::getNombre() const {
    return nombre;
}

string Usuario::getCorreo() const {
    return correo;
}

ListaTareas& Usuario::getListaTareas() {
    return listaTareas;
}

// Función principal
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
        cout << "4. Marcar tarea como completada\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

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
                if (fechaVencimiento != -1) {
                    TareaProgramada* tarea = new TareaProgramada(descripcion, fechaVencimiento);
                    usuario.getListaTareas().agregarTarea(tarea);
                } else {
                    cout << "Fecha inválida.\n";
                }
                break;
            }
            case 3: {
                usuario.getListaTareas().mostrarTareas();
                break;
            }
            case 4: {
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

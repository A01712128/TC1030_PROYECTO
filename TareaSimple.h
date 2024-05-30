#include <iostream>
#include <string>
#include "TareaBase.h"
using namespace std;

// Clase derivada para tareas simples
class TareaSimple : public TareaBase {
public:
    // Constructor que llama al constructor de la clase base
    TareaSimple(const string& desc) : TareaBase(desc) {}
};
#ifndef TAREABASE_H
#define TAREABASE_H

#include <string>
using namespace std;

class TareaBase {
protected:
    string descripcion;
    bool completada;

public:
    TareaBase(const string& desc);

    virtual void marcarCompletada();
    virtual void marcarIncompleta();
    virtual string getDescripcion() const = 0;
    virtual bool estaCompletada() const;
    virtual ~TareaBase() = 0;
};

#endif // TAREABASE_H

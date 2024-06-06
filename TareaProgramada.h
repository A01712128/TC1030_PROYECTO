#ifndef TAREAPROGRAMADA_H
#define TAREAPROGRAMADA_H

#include "TareaBase.h"
#include <ctime>

class TareaProgramada : public TareaBase {
private:
    time_t fechaVencimiento;

public:
    TareaProgramada(const string& desc, time_t fecha);
    void setFechaVencimiento(time_t fecha);
    time_t getFechaVencimiento() const;
    string getDescripcion() const override;
};

#endif // TAREAPROGRAMADA_H

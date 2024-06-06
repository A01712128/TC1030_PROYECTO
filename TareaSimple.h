#ifndef TAREASIMPLE_H
#define TAREASIMPLE_H

#include "TareaBase.h"

class TareaSimple : public TareaBase {
public:
    TareaSimple(const string& desc);
    string getDescripcion() const override;
};

#endif // TAREASIMPLE_H

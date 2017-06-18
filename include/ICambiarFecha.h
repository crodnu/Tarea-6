#ifndef ICAMBIARFECHA_H_INCLUDED
#define ICAMBIARFECHA_H_INCLUDED

#include "Fecha.h"

class ICambiarFecha {
public:
    virtual Fecha getFechaActual() = 0;
    virtual void setFechaActual(Fecha fecha) = 0;
};

#endif // ICAMBIARFECHA_H_INCLUDED

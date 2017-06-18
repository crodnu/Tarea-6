#ifndef CONTROLADORFECHA_H
#define CONTROLADORFECHA_H

#include "Fecha.h"
#include "ICambiarFecha.h"

class ControladorFecha: public ICambiarFecha {
public:
    static ControladorFecha* getInstance();
    virtual Fecha getFechaActual();
    virtual void setFechaActual(Fecha fecha);

private:
    ControladorFecha();
    static ControladorFecha* instancia;
    Fecha fechaActual;
};

#endif // CONTROLADORFECHA_H

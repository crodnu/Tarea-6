#ifndef CONTROLADORFECHA_H
#define CONTROLADORFECHA_H

#include "Fecha.h"

class ControladorFecha {
public:
    static ControladorFecha* getInstance();
    Fecha getFechaActual();
    void setFechaActual(Fecha fecha);

private:
    ControladorFecha();
    static ControladorFecha* instancia;
    Fecha fechaActual;
};

#endif // CONTROLADORFECHA_H

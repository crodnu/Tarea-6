#ifndef CONTROLADORFACTORY_H
#define CONTROLADORFACTORY_H

#include "ICambiarFecha.h"

class ControladorFactory {
public:
    static ICambiarFecha* getICambiarFecha();
};

#endif // CONTROLADORFACTORY_H

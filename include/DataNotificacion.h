#ifndef DATANOTIFICACION_H
#define DATANOTIFICACION_H

#include <string>

#include "DataContacto.h"
#include "Fecha.h"

class DataNotificacion {
public:
    DataNotificacion(DataContacto contacto, std::string tipo, Fecha fecha);
    DataContacto getContacto();
    std::string getTipo();
    Fecha getFecha();

private:
    Fecha fecha;
    DataContacto contacto;
    std::string tipo;
};

#endif // DATANOTIFICACION_H

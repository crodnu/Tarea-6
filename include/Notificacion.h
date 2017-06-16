#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include <string>

#include "DataContacto.h"
#include "DataNotificacion.h"
#include "Fecha.h"
#include "Usuario.h"

class Usuario;

class Notificacion {
public:
    Notificacion(std::string tipo);
    DataNotificacion getDataNotificacion();

private:
    Fecha fecha;
    Usuario* contacto;
    std::string tipo;
};

#endif // NOTIFICACION_H

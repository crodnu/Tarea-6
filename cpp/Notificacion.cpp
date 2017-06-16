#include "ControladorFecha.h"
#include "ControladorUsuarios.h"
#include "Notificacion.h"

Notificacion::Notificacion(std::string tipo){
    this->fecha = ControladorFecha::getInstance()->getFechaActual();
    this->contacto = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    this->tipo = tipo;
}

DataNotificacion Notificacion::getDataNotificacion() {
    return DataNotificacion(contacto->getDataContacto(), tipo, fecha);
}

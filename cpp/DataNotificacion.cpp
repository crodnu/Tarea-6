#include "../include/DataNotificacion.h"

using namespace std;

DataNotificacion::DataNotificacion(DataContacto contacto, string tipo, Fecha fecha):
    fecha(fecha), contacto(contacto) {
    this->tipo = tipo;
}

DataContacto DataNotificacion::getContacto() {
    return this->contacto;
}

string DataNotificacion::getTipo() {
    return this->tipo;
}

Fecha DataNotificacion::getFecha() {
    return this->fecha;
}

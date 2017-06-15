#include "../include/DataReceptor.h"

DataReceptor::DataReceptor(const Fecha& fechaRecibido, const DataContacto& contacto):
    contacto(contacto), fechaRecibido(fechaRecibido) { }

DataReceptor::DataReceptor(const DataReceptor& orig):
    contacto(orig.contacto), fechaRecibido(orig.fechaRecibido) { }

DataContacto DataReceptor::getContacto() {
    return this->contacto;
}

Fecha DataReceptor::getFechaRecibido() {
    return this->fechaRecibido;
}

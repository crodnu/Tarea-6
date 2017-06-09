#include "../include/DataReceptor.h"

DataReceptor::DataReceptor(const Fecha& fechaRecibido, const DataContacto& contacto) {
    this->contacto = contacto;
    this->fechaRecibido = fechaRecibido;
}

DataReceptor::DataReceptor(const DataReceptor& orig) {
    this->contacto = orig.contacto;
    this->fechaRecibido = orig.fechaRecibido;
}

DataContacto DataReceptor::getContacto() {
    return this->contacto;
}

Fecha DataReceptor::getFechaRecibido() {
    return this->fechaRecibido;
}

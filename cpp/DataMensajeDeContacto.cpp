#include "../include/DataMensajeDeContacto.h"

DataMensajeDeContacto::DataMensajeDeContacto(Fecha fechaDeEnviado,
    DataContacto contacto): DataMensaje(fechaDeEnviado) {
    this->contacto = contacto;
}

DataContacto DataMensajeDeContacto::getContacto() {
    return this->contacto;
}

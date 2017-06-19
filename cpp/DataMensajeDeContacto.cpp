#include "../include/DataMensajeDeContacto.h"

DataMensajeDeContacto::DataMensajeDeContacto(IdMensaje id, Fecha fechaDeEnviado,
    DataContacto contacto): DataMensaje(id, fechaDeEnviado), contacto(contacto) { }

DataContacto DataMensajeDeContacto::getContacto() {
    return this->contacto;
}

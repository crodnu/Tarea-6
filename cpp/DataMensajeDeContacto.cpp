#include "../include/DataMensajeDeContacto.h"

DataMensajeDeContacto::DataMensajeDeContacto(Fecha fechaDeEnviado,
    DataContacto contacto): DataMensaje(fechaDeEnviado), contacto(contacto) { }

DataContacto DataMensajeDeContacto::getContacto() {
    return this->contacto;
}

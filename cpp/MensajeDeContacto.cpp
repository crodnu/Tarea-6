#include "../include/MensajeDeContacto.h"

MensajeDeContacto::MensajeDeContacto(Usuario* contacto): contacto(contacto){ }

DataMensaje* MensajeDeContacto::getDataMensaje() {
    this->setLeidoPorUsuarioActual();
    return new DataMensajeDeContacto(this->getFechaEnviado(), this->contacto->getDataContacto());
}

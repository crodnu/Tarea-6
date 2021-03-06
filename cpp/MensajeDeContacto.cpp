#include "../include/MensajeDeContacto.h"

MensajeDeContacto::~MensajeDeContacto() {}

MensajeDeContacto::MensajeDeContacto(Usuario* contacto): contacto(contacto){ }

DataMensaje* MensajeDeContacto::getDataMensaje() {
    this->setLeidoPorUsuarioActual();
    return new DataMensajeDeContacto(this->getId(), this->getFechaEnviado(), this->contacto->getDataContacto());
}

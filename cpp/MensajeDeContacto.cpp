#include "../include/MensajeDeContacto.h"

MensajeDeContacto::MensajeDeContacto(Usuario* contacto) {
    this->contacto = cotacto;
}

DataMensaje* MensajeDeContacto::getDataMensaje() {
    return new DataMensajeDeContacto(this->getFechaEnviado(), this->contacto->getDataContacto());
}

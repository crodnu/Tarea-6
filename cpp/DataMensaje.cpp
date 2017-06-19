#include "../include/DataMensaje.h"

DataMensaje::DataMensaje(IdMensaje id, Fecha fechaDeEnviado): fechaDeEnviado(fechaDeEnviado) {
    this->id = id;
}

IdMensaje DataMensaje::getId() {
    return this->id;
}

Fecha DataMensaje::getFechaDeEnviado() {
    return this->fechaDeEnviado;
}

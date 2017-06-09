#include "../include/DataMensaje.h"

DataMensaje::DataMensaje(Fecha fechaDeEnviado) {
    this->fechaDeEnviado = fechaDeEnviado;
}

Fecha DataMensaje::getFechaDeEnviado() {
    return this->fechaDeEnviado;
}

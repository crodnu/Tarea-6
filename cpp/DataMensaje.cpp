#include "../include/DataMensaje.h"

DataMensaje::DataMensaje(Fecha fechaDeEnviado): fechaDeEnviado(fechaDeEnviado) { }

Fecha DataMensaje::getFechaDeEnviado() {
    return this->fechaDeEnviado;
}

#include "../include/ControladorFecha.h"

ControladorFecha::ControladorFecha() {
    this->fechaActual = Fecha(1, 1, 2000);
}

static ControladorFecha* ControladorFecha::getInstance() {
    if(ControladorFecha->instancia == NULL)
        ControladorFecha->instancia = new ControladorFecha();

    return ControladorFecha->instancia;
}

Fecha ControladorFecha::getFechaActual() {
    return this->fechaActual;
}

void ControladorFecha::setFechaActual(Fecha fecha) {
    this->fechaActual = fecha;
}

#include "../include/Fecha.h"

Fecha::Fecha(unsigned dia, unsigned mes, unsigned anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha(const Fecha &unaFecha) {
    this->dia = unaFecha.dia;
    this->mes = unaFecha.mes;
    this->anio = unaFecha.anio;
}

unsigned Fecha::getDia() {
    return dia;
}

unsigned Fecha::getMes() {
    return mes;
}

unsigned Fecha::getAnio() {
    return anio;
}

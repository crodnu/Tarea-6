#include <iostream>

#include "../include/DataMensaje.h"

using namespace std;

DataMensaje::~DataMensaje() {}

DataMensaje::DataMensaje(IdMensaje id, Fecha fechaDeEnviado): fechaDeEnviado(fechaDeEnviado) {
    this->id = id;
}

IdMensaje DataMensaje::getId() {
    return this->id;
}

Fecha DataMensaje::getFechaDeEnviado() {
    return this->fechaDeEnviado;
}

void DataMensaje::print() {
    cout << "ID: " << this->id << endl << "Fecha de enviado: ";
    this->fechaDeEnviado.print();
    cout << endl;
}

#include <iostream>

#include "../include/DataMensajeDeContacto.h"

using namespace std;

DataMensajeDeContacto::DataMensajeDeContacto(IdMensaje id, Fecha fechaDeEnviado,
    DataContacto contacto): DataMensaje(id, fechaDeEnviado), contacto(contacto) { }

DataContacto DataMensajeDeContacto::getContacto() {
    return this->contacto;
}

void DataMensajeDeContacto::print() {
    DataMensaje::print();
    cout << "Contacto " << endl
        << "\t-Nombre: " << this->contacto.getNombre() << endl
        << "\t-Telefono: " << this->contacto.getTelefono() << endl
        << "\t-Descripcion: " << this->contacto.getDescripcion() << endl
        << "\t-Avatar: " << this->contacto.getUrlImagen() << endl;
}

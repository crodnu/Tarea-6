#include <iostream>

#include "../include/DataConversacionSimple.h"

using namespace std;

DataConversacionSimple::~DataConversacionSimple() {}

DataConversacionSimple::DataConversacionSimple(IdConversacion id, bool archivada,
    list<DataMensaje*> mensajes, DataContacto contacto):
    DataConversacion(id, archivada, mensajes), contacto(contacto) { }

DataContacto DataConversacionSimple::getContacto() {
    return this->contacto;
}

void DataConversacionSimple::print() {
    DataConversacion::print();
    cout << "Nombre del grupo: " << this->contacto.getNombre() << endl;
}

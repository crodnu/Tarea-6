#include <iostream>

#include "../include/DataConversacionGrupo.h"

using namespace std;

DataConversacionGrupo::~DataConversacionGrupo() {}

DataConversacionGrupo::DataConversacionGrupo(IdConversacion id, bool archivada, list<DataMensaje*> mensajes,
    string nombreGrupo): DataConversacion(id, archivada, mensajes) {
    this->nombreGrupo = nombreGrupo;
}

string DataConversacionGrupo::getNombreGrupo() {
    return this->nombreGrupo;
}

void DataConversacionGrupo::print() {
    DataConversacion::print();
    cout << "Nombre del grupo: " << this->nombreGrupo << endl;
}

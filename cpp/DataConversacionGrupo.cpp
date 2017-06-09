#include "../include/DataConversacionGrupo.h"

using namespace std;

DataConversacionGrupo::DataConversacionGrupo(bool archivada, list<DataMensaje*> mensajes,
    string nombreGrupo): DataConversacion(archivada, mensajes) {
    this->nombreGrupo = nombreGrupo;
}

string DataConversacionGrupo::getNombreGrupo() {
    return this->nombreGrupo;
}

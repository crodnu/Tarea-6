#include "../include/DataConversacion.h"

using namespace std;

DataConversacion::DataConversacion(IdConversacion id, bool archivada, list<DataMensaje*> mensajes) {
    this->archivada = archivada;
    this->mensajes = mensajes;
    this->id = id;
}

bool DataConversacion::getArchivada() {
    return this->archivada;
}

IdConversacion DataConversacion::getId() {
    return this->id;
}

list<DataMensaje*> DataConversacion::getMensajes() {
    return this->mensajes;
}

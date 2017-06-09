#include "../include/DataConversacion.h"

using namespace std;

DataConversacion::DataConversacion(bool archivada, list<DataMensaje*> mensajes) {
    this->archivada = archivada;
    this->mensajes = mensajes;
}

bool DataConversacion::getArchivada() {
    return this->archivada;
}

list<DataMensaje*> DataConversacion::getMensajes() {
    return this->mensajes;
}
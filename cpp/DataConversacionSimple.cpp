#include "../include/DataConversacionSimple.h"

using namespace std;

DataConversacionSimple::DataConversacionSimple(bool archivada,
    list<DataMensaje*> mensajes, DataContacto contacto): DataConversacion(archivada, mensajes) {
    this->contacto = contacto;
}

DataContacto DataConversacionSimple::getContacto() {
    return this->contacto;
}

#include "../include/DataConversacionSimple.h"

using namespace std;

DataConversacionSimple::DataConversacionSimple(bool archivada,
    list<DataMensaje*> mensajes, DataContacto contacto):
    DataConversacion(archivada, mensajes), contacto(contacto) { }

DataContacto DataConversacionSimple::getContacto() {
    return this->contacto;
}

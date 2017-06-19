#include "../include/DataConversacionSimple.h"

using namespace std;

DataConversacionSimple::DataConversacionSimple(IdConversacion id, bool archivada,
    list<DataMensaje*> mensajes, DataContacto contacto):
    DataConversacion(id, archivada, mensajes), contacto(contacto) { }

DataContacto DataConversacionSimple::getContacto() {
    return this->contacto;
}

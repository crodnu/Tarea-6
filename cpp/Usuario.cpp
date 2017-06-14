#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(TelefonoUsuario telefono, string nombre, string descripcion, string urlAvatar) {
    this->telefono = telefono;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->urlAvatar = urlAvatar;
    this->fechaDeRegistro = ControladorFecha::getInstance()->getFechaActual();
    this->ultimaConexion = ControladorFecha::getInstance()->getFechaActual();
}

list<DataContacto> Usuario::getContactos() {
    list<DataContacto> contactosList;

    for(const auto& par : this->contactos) {
        Usuario* contacto = par.second;
        contactosList.push_front(contacto->getDataContacto());
    }

    return contactosList;
}

DataContacto Usuario::getDataContacto() {
    return DataContacto(this->nombre, this->descripcion, this->urlAvatar);
}

void Usuario::agregarContacto(Usuario* contacto) {
    this->contactos[contacto->telefono] = contacto;
}

list<DataConversacion> Usuario::getSetDataConversacion() {
    list<DataContacto> conversaciones;

    for(const auto& par : this->conversacionesArchivadas) {
        Conversacion* conversacion = par.second;
        conversaciones.push_front(conversacion->getDataConversacion());
    }

    for(const auto& par : this->conversacionesIntegradas) {
        Conversacion* conversacion = par.second;
        conversaciones.push_front(conversacion->getDataConversacion());
    }

    return conversaciones;
}

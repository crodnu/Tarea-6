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

    for(map<TelefonoUsuario, Usuario*>::iterator it = this->contactos.begin(); it != this->contactos.end(); it++) {
        Usuario* contacto = it->second;
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

list<DataConversacion*> Usuario::getSetDataConversacion() {
    list<DataConversacion*> conversaciones;

    for(map<IdConversacion, Conversacion*>::iterator it = this->conversacionesArchivadas.begin();
            it != this->conversacionesArchivadas.end(); it++) {
        Conversacion* conversacion = it->second;
        conversaciones.push_front(conversacion->getDataConversacion());
    }

    for(map<IdConversacion, Conversacion*>::iterator it = this->conversacionesIntegradas.begin();
            it != this->conversacionesIntegradas.end(); it++) {
        Conversacion* conversacion = it->second;
        conversaciones.push_front(conversacion->getDataConversacion());
    }

    return conversaciones;
}

void Usuario::suscribirse(Usuario* user) {
    user->suscriptores[this->telefono] = this;
}

list<DataNotificacion> Usuario::getNotificaciones() {
    list<DataNotificacion> result;

    for(list<Notificacion*>::iterator it = this->notificacionesRecibidas.begin();
        it != this->notificacionesRecibidas.end(); it++) {
        result.push_front((*it)->getDataNotificacion());
        delete *it;
    }

    this->notificacionesRecibidas.clear();
    return result;
}

void Usuario::notificarSuscriptores(Notificacion notificacion) {

}

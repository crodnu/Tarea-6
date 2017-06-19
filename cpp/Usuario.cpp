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

TelefonoUsuario Usuario::getTelefono() {
    return this->telefono;
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
    return DataContacto(this->telefono, this->nombre, this->descripcion, this->urlAvatar);
}

void Usuario::agregarContacto(Usuario* contacto) {
    this->contactos[contacto->telefono] = contacto;
}

list<DataConversacion*> Usuario::getSetDataConversacion() {
    list<DataConversacion*> conversaciones = this->getSetDataConversacionesActivas();
    list<DataConversacion*> conversaciones2 = this->getSetDataConversacionesArchivadas();
    conversaciones.splice(conversaciones.begin(), conversaciones2);
    return conversaciones;
}

list<DataConversacion*> Usuario::getSetDataConversacionesArchivadas(){
    list<DataConversacion*> conversaciones;

    for(map<IdConversacion, Conversacion*>::iterator it = this->conversacionesArchivadas.begin();
            it != this->conversacionesArchivadas.end(); it++) {
        Conversacion* conversacion = it->second;
        conversaciones.push_front(conversacion->getDataConversacionSimple(true));
    }
    for(map<NombreGrupo, Grupo*>::iterator it = this->gruposIntegradosConversacionesArchivadas.begin();
            it != this->gruposIntegradosConversacionesArchivadas.end(); it++) {
        Grupo * actual = it->second;
        conversaciones.push_front(actual->getDataConversacion(true));
    }
    return conversaciones;
}

list<DataConversacion*> Usuario::getSetDataConversacionesActivas(){
    list<DataConversacion*> conversaciones;

    for(map<IdConversacion, Conversacion*>::iterator it = this->conversacionesIntegradas.begin();
            it != this->conversacionesIntegradas.end(); it++) {
        Conversacion* conversacion = it->second;
        conversaciones.push_front(conversacion->getDataConversacionSimple(false));
    }
    for(map<NombreGrupo, Grupo*>::iterator it = this->gruposIntegradosConversacionesActivas.begin();
            it != this->gruposIntegradosConversacionesActivas.end(); it++) {
        Grupo * actual = it->second;
        conversaciones.push_front(actual->getDataConversacion(false));
    }
    return conversaciones;
}

void Usuario::suscribirse(Usuario* user) {
    user->suscriptores[this->telefono] = this;
}

list<DataNotificacion> Usuario::getNotificaciones() {
    list<DataNotificacion> result = this->notificacionesRecibidas;
    this->notificacionesRecibidas.clear();
    return result;
}

void Usuario::notificarSuscriptores(DataNotificacion notificacion) {
  for(map<TelefonoUsuario, Usuario*>::iterator it = this->suscriptores.begin();
        it != this->suscriptores.end(); it++) {
        Usuario * suscriptor = it->second;
        suscriptor->notificacionesRecibidas.push_front(notificacion);
    }

}

DataNotificacion Usuario::crearDataNotificacion(string tipo) {
    DataContacto userData = this->getDataContacto();
    Fecha hoy = ControladorFecha::getInstance()->getFechaActual();
    return DataNotificacion(userData, tipo, hoy);
}

void Usuario::actualizarNombre(string nombre){
    DataNotificacion nueva = this->crearDataNotificacion("Nombre");
    this->notificarSuscriptores(nueva);
    this->nombre = nombre;
}

void Usuario::actualizarImagen(string urlImagen){
    DataNotificacion nueva = this->crearDataNotificacion("Avatar");
    this->notificarSuscriptores(nueva);
    this->urlAvatar = urlImagen;
}

void Usuario::actualizarDescripcion(string descripcion){
    DataNotificacion nueva = this->crearDataNotificacion("Descripcion");
    this->notificarSuscriptores(nueva);
    this->descripcion = descripcion;
}

void Usuario::actualizarFechaUltimaConexion() {
    this->ultimaConexion = ControladorFecha::getInstance()->getFechaActual();
}

void Usuario::agregarConversacionActiva(Conversacion* conv) {
    this->conversacionesIntegradas[conv->getId()] = conv;
    conv->addParticipante(this);
}

void Usuario::archivarConversacion(IdConversacion id) {
    if(this->conversacionesIntegradas[id]) {
        this->conversacionesArchivadas[id] = this->conversacionesIntegradas[id];
        this->conversacionesIntegradas.erase(id);
    }

    else {
        for(map<NombreGrupo, Grupo*>::iterator it = this->gruposIntegradosConversacionesActivas.begin();
            it != this->gruposIntegradosConversacionesActivas.end(); it++) {
            Grupo* grupo = it->second;
            NombreGrupo nombre = it->first;
            if(grupo->getIdConversacion() == id) {
                this->gruposIntegradosConversacionesArchivadas[nombre] = grupo;
                this->gruposIntegradosConversacionesActivas.erase(nombre);
                return;
            }
        }
    }
}

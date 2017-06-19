#include "../include/ControladorUsuarios.h"
#include "../include/Conversacion.h"

IdConversacion Conversacion::idActual = 0;

Conversacion::Conversacion() {
    Conversacion::idActual++;
    this->id = Conversacion::idActual;
}

map<IdMensaje, Mensaje*> Conversacion::getSetMensajes() {
    map<IdMensaje, Mensaje*> copia = this->mensajes;
    return copia;
}

Mensaje* Conversacion::getMensaje(IdMensaje identificador) {
    if(this->mensajes.count(identificador) == 0) // Si no existe el mensaje.
        return NULL; // Excepcion?
    return this->mensajes[identificador];
}

DataConversacionSimple* Conversacion::getDataConversacionSimple(bool archivada) {
    Usuario* user = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    for(std::map<TelefonoUsuario, Usuario*>::iterator it = this->participantes.begin();
        it != this->participantes.end(); it++) {
        Usuario* otro = it->second;
        if(otro != user) {
            list<DataMensaje*> mensajes;
            for(map<IdMensaje, Mensaje*>::iterator it = this->mensajes.begin();
                it != this->mensajes.end(); it++) {
                Mensaje* msj = it->second;
                mensajes.push_front(msj->getDataMensaje());
            }
            return new DataConversacionSimple(this->id, archivada, mensajes, otro->getDataContacto());
        }
    }
    return NULL;
}

DataConversacionGrupo* Conversacion::getDataConversacionGrupo(bool archivada, std::string nombre) {
    list<DataMensaje*> mensajes;
    for(map<IdMensaje, Mensaje*>::iterator it = this->mensajes.begin();
        it != this->mensajes.end(); it++) {
        Mensaje* msj = it->second;
        mensajes.push_front(msj->getDataMensaje());
    }
    return new DataConversacionGrupo(this->id, archivada, mensajes, nombre);
}

map<IdMensaje, Mensaje*> Conversacion::obtenerMensajes(Usuario* user) {
    map<IdMensaje, Mensaje*> setMensajes;

    for(map<IdMensaje, Mensaje*>::iterator it = setMensajes.begin(); it != setMensajes.end(); it++) {
        IdMensaje idMensaje = it->first;
        Mensaje* mensaje = it->second;

        if(mensaje->esReceptor(user))
            setMensajes[idMensaje] = mensaje;
    }

    return setMensajes;
}

void Conversacion::enviar(Mensaje* mensaje) {
    for(std::map<TelefonoUsuario, Usuario*>::iterator it = this->participantes.begin();
        it != this->participantes.end(); it++)
        mensaje->addReceptor(it->second);

    this->mensajes[mensaje->getId()] = mensaje;
}

IdConversacion Conversacion::getId(){
    return this->id;
}

void Conversacion::addParticipante(Usuario* participante) {
    this->participantes[participante->getTelefono()] = participante;
}

void Conversacion::borrarMensaje(Mensaje* msj) {
    this->mensajes.erase(msj->getId());
    delete msj;
}

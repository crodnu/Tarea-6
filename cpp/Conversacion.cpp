#include "../include/ControladorUsuarios.h"
#include "../include/Conversacion.h"

IdConversacion Conversacion::idActual = 0;

Conversacion::Conversacion() {
    Conversacion::idActual++;
    this->id = Conversacion::idActual;
    Usuario* usuarioActual = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    this->participantes[usuarioActual->getTelefono()] = usuarioActual;
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

DataConversacion* Conversacion::getDataConversacion() {

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

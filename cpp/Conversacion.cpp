#include "../include/Conversacion.h"

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

DataConversacion* getDataConversacion() {

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

IdConversacion Conversacion::getId(){
    return this->id;
}

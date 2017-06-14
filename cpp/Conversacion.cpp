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

map<IdMensaje, Mensaje*> obtenerMensajes(Usuario* user) {
    map<IdMensaje, Mensaje*> setMensajes;

    for(const auto& par : this->mensajes) {
        IdMensaje idMensaje = par.first;
        Mensaje* mensaje = par.second;

        if(mensaje->esReceptor(user))
            setMensajes[idMensaje] = mensaje;
    }

    return setMensajes;
}

#include "../include/Mensaje.h"

Mensaje::Mensaje() {
    Mensaje::codigoActual++;
    this->codigo = Mensaje::codigoActual;
    this->visto = false;
    this->fechaDeEnviado = ControladorFecha::getInstance()->getFechaActual();
    this->emisor = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
}

bool Mensaje::esReceptor(Usuario* user) {
    for(map<TelefonoUsuario, Usuario*>::iterator it = this->receptores.begin(); it != this->receptores.end(); it++) {
        Usuario* usuario = it->second;
        if(usuario == user) return true;
    }

    return false;
}

Fecha Mensaje::getFechaEnviado() {
    return this->fechaDeEnviado;
}

IdMensaje Mensaje::getId() {
    return this->codigo;
}

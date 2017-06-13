#include "../include/Mensaje.h"

Mensaje::Mensaje() {
    Mensaje::codigoActual++;
    this->codigo = Mensaje::codigoActual
    this->leido = false;
    this->fechaDeEnviado = ControladorFecha::getInstance()->getFechaActual();
    this->emisor = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
}

bool Mensaje::esReceptor(Usuario* user) {
    for(const auto& par : this->receptores) {
        Usuario* usuario = par.second;
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

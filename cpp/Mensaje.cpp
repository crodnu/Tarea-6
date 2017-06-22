#include "../include/Mensaje.h"

IdMensaje Mensaje::codigoActual = 0;

Mensaje::~Mensaje() {}

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

bool Mensaje::esEmisor(Usuario* user) {
    return user == this->emisor;
}

std::list<DataReceptor> Mensaje::getDataReceptor() {
    std::list<DataReceptor> result;

    for(std::map<TelefonoUsuario, std::pair<Usuario*, Fecha> >::iterator it = this->leidoPor.begin();
        it != this->leidoPor.end(); it++) {
        DataReceptor dataReceptor(it->second.second, it->second.first->getDataContacto());
        result.push_front(dataReceptor);
    }

    return result;
}

Fecha Mensaje::getFechaEnviado() {
    return this->fechaDeEnviado;
}

IdMensaje Mensaje::getId() {
    return this->codigo;
}

void Mensaje::addReceptor(Usuario* receptor) {
    if(this->emisor != receptor)
        this->receptores[receptor->getTelefono()] = receptor;
}

void Mensaje::quitarReceptor(Usuario* receptor) {
    this->receptores.erase(receptor->getTelefono());
}

void Mensaje::setLeidoPorUsuarioActual() {
    Usuario* usuarioActual = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    if(this->leidoPor.count(usuarioActual->getTelefono()) == 0) {
        Fecha fechaActual = ControladorFecha::getInstance()->getFechaActual();
        this->leidoPor[usuarioActual->getTelefono()] = make_pair(usuarioActual, fechaActual);
    }
}

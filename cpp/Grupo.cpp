#include "../include/ControladorUsuarios.h"
#include "../include/Grupo.h"

using namespace std;

Grupo::Grupo(NombreGrupo nombre, string urlImagen, Fecha fechaDeCreacion): fechaDeCreacion(fechaDeCreacion) {
    this->nombre = nombre;
    this->urlImagen = urlImagen;
    Usuario* fundador = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    this->administradores[fundador->getTelefono()] = fundador;
    this->integrantes[fundador->getTelefono()] = fundador;
    this->conversacion = new Conversacion();
}

Conversacion * Grupo::getConversacion(){
  return this->conversacion;
}

DataConversacionGrupo* Grupo::getDataConversacion(bool archivada) {
    return this->conversacion->getDataConversacionGrupo(archivada, this->nombre);
}

IdConversacion Grupo::getIdConversacion() {
    return this->conversacion->getId();
}

NombreGrupo Grupo::getNombre() {
    return this->nombre;
}

void Grupo::hacerAdministrador(Usuario* user) {
    this->administradores[user->getTelefono()] = user;
    this->hacerIntegrante(user);
}

void Grupo::hacerIntegrante(Usuario* user) {
    this->integrantes[user->getTelefono()] = user;
    this->conversacion->addParticipante(user);
}

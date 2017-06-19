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

#include "../include/ControladorMensajes.h"

ControladorMensajes::ControladorMensajes() {
}

void ControladorMensajes::enviarMensaje(Mensaje mensaje, ControladorUsuarios contUsuarios){
  Usuario actual = contUsuarios->getUsuarioSesionActual();
  (this->conversacionSeleccionada)->enviar(Mensaje mensaje, Usuario actual);
}

void ControladorMensajes::seleccionarConversacion(IdConversacion identificador){
  this->conversacionSeleccionada = this->conversacionesDelSistema[identificador];
}

ControladorMensajes ControladorMensajes::getControladorMensajes(){
  if (this->instancia == NULL)
    this->instancia = new ControladorMensajes();

  return this->instancia;
}

void ControladorMensajes::crearConversacionSimple(TelefonoUsuario telefonoContacto, ControladorUsuarios contUsuarios){
  Usuario * iniciante = contUsuarios->getUsuarioSesionActual();
  Usuario * receptor = contUsuarios->getUsuario(telefonoContacto);
  Conversacion * nuevaConversacion = new Conversacion(iniciante, receptor);
  this->conversacionesDelSistema[nuevaConversacion->getId()] = nuevaConversacion;
}

set<DataConversacion> ControladorMensajes::darConversaciones(){
  set<DataConversacion> retorno;
  //iteracion sobre las conversaciones agregando los DataConversacion a retorno
  return retorno;
}

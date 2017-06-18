#include "../include/ControladorMensajes.h"

ControladorMensajes::ControladorMensajes() {
}

void ControladorMensajes::enviarMensaje(Mensaje * mensaje){
  this->conversacionSeleccionada->enviar(mensaje);
}

void ControladorMensajes::seleccionarConversacion(IdConversacion identificador){
  this->conversacionSeleccionada = ControladorMensajes::instancia->conversacionesDelSistema[identificador];
}

ControladorMensajes* ControladorMensajes::getControladorMensajes(){
  if (ControladorMensajes::instancia == NULL)
    ControladorMensajes::instancia = new ControladorMensajes();

  return ControladorMensajes::instancia;
}

void ControladorMensajes::crearConversacionSimple(TelefonoUsuario telefonoContacto){
  Conversacion * nuevaConversacion = new Conversacion();
  this->conversacionesDelSistema[nuevaConversacion->getId()] = nuevaConversacion;
}

list<DataConversacion*> ControladorMensajes::darConversaciones(){
  Usuario * unUser = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
  return unUser->getSetDataConversacion();
}

list<DataConversacion*> ControladorMensajes::darConversacionesActivas(){
  Usuario * unUser = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
  return unUser->getSetDataConversacionesActivas();
}

list<DataConversacion*> ControladorMensajes::darConversacionesArchivadas(){
  Usuario * unUser = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
  return unUser->getSetDataConversacionesArchivadas();
}

void ControladorMensajes::enviarMensajeContacto(TelefonoUsuario numeroContacto){
  Usuario* contacto = ControladorUsuarios::getControladorUsuarios()->getUsuario(numeroContacto);
  MensajeDeContacto* mensaje = new MensajeDeContacto(contacto);
  this->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio){
  MensajeConImagen * mensaje = new MensajeConImagen(formato, texto, urlImagen, tamanio);
  this->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeSimple(string texto){
  MensajeSimple * mensaje = new MensajeSimple(texto);
  this->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeVideo(string urmVideo, int duracion){
  MensajeConVideo * mensaje = new MensajeConVideo(urmVideo, duracion);
  this->enviarMensaje(mensaje);
}

list<DataContacto> ControladorMensajes::listarContactos(){
  return ControladorUsuarios::getControladorUsuarios()->listarContactos();
}

list<DataMensaje*> ControladorMensajes::obtenerMensajesDeConversacion(){
  DataConversacion* seleccionada = this->conversacionSeleccionada->getDataConversacion();
  return seleccionada->getMensajes();
}

void ControladorMensajes::seleccionarConversacionActiva(IdConversacion identificador){
  this->conversacionSeleccionada = this->conversacionesDelSistema[identificador];
}

void ControladorMensajes::seleccionarConversacionArchivada(IdConversacion identificador){
  this->conversacionSeleccionada = this->conversacionesDelSistema[identificador];
}

list<DataReceptor> ControladorMensajes::obtenerInformacionAdicional(IdMensaje identificador){
  list<DataReceptor> retorno;
  Conversacion* conv = this->conversacionSeleccionada;
  return conv->getMensaje(identificador)->getDataReceptor();
}

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

set<DataConversacion*> ControladorMensajes::darConversaciones(){
  std::set<DataConversacion*> retorno;
  std::map<IdConversacion, Conversacion*>::iterator it;
  for(it=conversacionesDelSistema.begin(); it!= conversacionesDelSistema.end(); it++){
    Conversacion* actual = it->second;
    retorno.insert(actual->getDataConversacion());
  }
  return retorno;
}

set<DataConversacion*> ControladorMensajes::darConversacionesActivas(){
//Pasar Usuario *?
}
set<DataConversacion*> ControladorMensajes::darConversacionesArchivadas(){
  //idem que conversaciones activas
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

set<DataReceptor> obtenerInformacionAdicional(int identificador);

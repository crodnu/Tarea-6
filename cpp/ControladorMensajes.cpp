#include "../include/ControladorMensajes.h"

ControladorMensajes::ControladorMensajes() {
}

void ControladorMensajes::enviarMensaje(Mensaje mensaje,Usuario * actual){
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
  std::set<DataConversacion> retorno;
  std::map<idConversacion, Conversacion *>::iterator it;
  for(it=conversacionesDelSistema.begin(); it!= conversacionesDelSistema.end(); it++){
    Conversacion * actual = it->second;
    retorno.insert(actual.getDataConversacion());
  }
  return retorno;
}

set<DataConversacion> ControladorMensajes::darConversacionesActivas(){
//Pasar Usuario *?
}
set<DataConversacion> ControladorMensajes::darConversacionesArchivadas(){
  //idem que conversaciones activas
}
void ControladorMensajes::enviarMensajeContacto(TelefonoUsuario numeroContacto, ControladorUsuarios contUsuarios){
  Usuario* contacto = contUsuarios->usuariosDelSistema[numeroContacto];
  Usuario * actual = contUsuarios->getUsuarioSesionActual();
  MensajeDeContacto mensaje = new MensajeDeContacto(contacto);
  this->enviarMensaje(mensaje, actual);
}

void ControladorMensajes::enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio, ControladorUsuarios contUsuarios){
  Usuario* contacto = contUsuarios->usuariosDelSistema[numeroContacto];
  Usuario * actual = contUsuarios->getUsuarioSesionActual();
  MensajeConImagen mensaje = new MensajeConImagen(formato, texto, urlImagen, tamanio);
  this->enviarMensaje(mensaje, actual);
}

void ControladorMensajes::enviarMensajeSimple(string texto, ControladorUsuarios contUsuarios){
  Usuario* contacto = contUsuarios->usuariosDelSistema[numeroContacto];
  Usuario * actual = contUsuarios->getUsuarioSesionActual();
  MensajeSimple mensaje = new MensajeSimple(texto);
  this->enviarMensaje(mensaje, actual);
}

void ControladorMensajes::enviarMensajeVideo(string urmVideo, int duracion, ControladorUsuarios contUsuarios){
  Usuario* contacto = contUsuarios->usuariosDelSistema[numeroContacto];
  Usuario * actual = contUsuarios->getUsuarioSesionActual();
  MensajeConVideo mensaje = new MensajeConVideo(urmVideo, duracion);
  this->enviarMensaje(mensaje, actual);
}

set<DataContacto> ControladorMensajes::listarContactos(){

}

set<DataMensaje> obtenerMensajesDeConversacion();

void ControladorMensajes::seleccionarConversacionActiva(IdConversacion identificador){
  this->conversacionSeleccionada = this->conversacionesDelSistema[identificador];
}

void ControladorMensajes::seleccionarConversacionArchivada(IdConversacion identificador){
  this->conversacionSeleccionada = this->conversacionesDelSistema[identificador];
}

set<DataReceptor> obtenerInformacionAdicional(int identificador);

#include "../include/ControladorMensajes.h"

ControladorMensajes::ControladorMensajes() {
}

void ControladorMensajes::enviarMensaje(Mensaje * mensaje){
  (ControladorMensajes::instancia->conversacionSeleccionada)->enviar(mensaje);
}

void ControladorMensajes::seleccionarConversacion(IdConversacion identificador){
  ControladorMensajes::instancia->conversacionSeleccionada = ControladorMensajes::instancia->conversacionesDelSistema[identificador];
}

ControladorMensajes ControladorMensajes::getControladorMensajes(){
  if (ControladorMensajes::instancia == NULL)
    ControladorMensajes::instancia = new ControladorMensajes();

  return ControladorMensajes::instancia;
}

void ControladorMensajes::crearConversacionSimple(TelefonoUsuario telefonoContacto){
  Conversacion * nuevaConversacion = new Conversacion();
  ControladorMensajes::instancia->conversacionesDelSistema[nuevaConversacion->getId()] = nuevaConversacion;
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
void ControladorMensajes::enviarMensajeContacto(TelefonoUsuario numeroContacto){
  Usuario* contacto = ControladorUsuarios::instancia->usuariosDelSistema[numeroContacto];
  MensajeDeContacto * mensaje = new MensajeDeContacto(contacto);
  ControladorMensajes::instancia->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio){
  MensajeConImagen * mensaje = new MensajeConImagen(formato, texto, urlImagen, tamanio);
  ControladorMensajes::instancia->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeSimple(string texto){
  MensajeSimple * mensaje = new MensajeSimple(texto);
  ControladorMensajes::instancia->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeVideo(string urmVideo, int duracion){
  MensajeConVideo * mensaje = new MensajeConVideo(urmVideo, duracion);
  ControladorMensajes::instancia->enviarMensaje(mensaje);
}

set<DataContacto> ControladorMensajes::listarContactos(){

}

set<DataMensaje> obtenerMensajesDeConversacion();

void ControladorMensajes::seleccionarConversacionActiva(IdConversacion identificador){
  ControladorMensajes::instancia->conversacionSeleccionada = ControladorMensajes::instancia->conversacionesDelSistema[identificador];
}

void ControladorMensajes::seleccionarConversacionArchivada(IdConversacion identificador){
  ControladorMensajes::instancia->conversacionSeleccionada = ControladorMensajes::instancia->conversacionesDelSistema[identificador];
}

set<DataReceptor> obtenerInformacionAdicional(int identificador);

#include "../include/ControladorMensajes.h"
#include "../include/ControladorUsuarios.h"

#include <iostream>
#include <stdexcept>

ControladorMensajes* ControladorMensajes::instancia = NULL;

ControladorMensajes::ControladorMensajes() {
}

void ControladorMensajes::enviarMensaje(Mensaje * mensaje){
  this->conversacionSeleccionada->enviar(mensaje);
}

void ControladorMensajes::seleccionarConversacion(IdConversacion identificador){
  this->conversacionSeleccionada = ControladorUsuarios::getControladorUsuarios()
    ->getUsuarioSesionActual()->getConversacion(identificador);
}

ControladorMensajes* ControladorMensajes::getControladorMensajes(){
  if (ControladorMensajes::instancia == NULL)
    ControladorMensajes::instancia = new ControladorMensajes();

  return ControladorMensajes::instancia;
}

void ControladorMensajes::crearConversacionSimple(TelefonoUsuario telefonoContacto){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->tieneContactoConTelefono(telefonoContacto))
        throw invalid_argument("El usuario seleccionado no existe o no es su contacto.");

    Conversacion * nuevaConversacion = new Conversacion();
    this->conversacionesDelSistema[nuevaConversacion->getId()] = nuevaConversacion;
    ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->agregarConversacionActiva(nuevaConversacion);
    ControladorUsuarios::getControladorUsuarios()->getUsuario(telefonoContacto)->agregarConversacionActiva(nuevaConversacion);
    this->conversacionSeleccionada = nuevaConversacion;
}

list<DataConversacion*> ControladorMensajes::darConversaciones(){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    Usuario * unUser = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    return unUser->getSetDataConversacion();
}

list<DataConversacion*> ControladorMensajes::darConversacionesActivas(){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

  Usuario * unUser = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
  return unUser->getSetDataConversacionesActivas();
}

list<DataConversacion*> ControladorMensajes::darConversacionesArchivadas(){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

  Usuario * unUser = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
  return unUser->getSetDataConversacionesArchivadas();
}

void ControladorMensajes::enviarMensajeContacto(TelefonoUsuario numeroContacto){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->tieneContactoConTelefono(numeroContacto))
        throw invalid_argument("El usuario seleccionado no existe o no es su contacto.");

    Usuario* contacto = ControladorUsuarios::getControladorUsuarios()->getUsuario(numeroContacto);
    MensajeDeContacto* mensaje = new MensajeDeContacto(contacto);
    this->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    MensajeConImagen * mensaje = new MensajeConImagen(formato, texto, urlImagen, tamanio);
    this->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeSimple(string texto){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    MensajeSimple * mensaje = new MensajeSimple(texto);
    this->enviarMensaje(mensaje);
}

void ControladorMensajes::enviarMensajeVideo(string urmVideo, int duracion){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    MensajeConVideo * mensaje = new MensajeConVideo(urmVideo, duracion);
    this->enviarMensaje(mensaje);
}

list<DataContacto> ControladorMensajes::listarContactos(){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    return ControladorUsuarios::getControladorUsuarios()->listarContactos();
}

list<DataMensaje*> ControladorMensajes::obtenerMensajesDeConversacion(){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    map<IdMensaje, Mensaje*> mensajes = this->conversacionSeleccionada->getSetMensajes();
    list<DataMensaje*> dataMensajes;
    Usuario* usr = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    for(map<IdMensaje, Mensaje*>::iterator it = mensajes.begin(); it != mensajes.end(); it++) {
    Mensaje* msj = it->second;
    if(msj->esEmisor(usr) || msj->esReceptor(usr))
        dataMensajes.push_front(msj->getDataMensaje());
    }
    return dataMensajes;
}

void ControladorMensajes::seleccionarConversacionActiva(IdConversacion identificador){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->tieneConversacionActiva(identificador))
        throw invalid_argument("La conversacion seleccionada no existe, no pertenece a ella, o ya fue archivada.");

    this->conversacionSeleccionada = ControladorUsuarios::getControladorUsuarios()
    ->getUsuarioSesionActual()->getConversacion(identificador);
}

void ControladorMensajes::seleccionarConversacionArchivada(IdConversacion identificador){
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->tieneConversacionArchivada(identificador))
        throw invalid_argument("La conversacion seleccionada no existe, no pertenece a ella, o no fue archivada.");

  this->conversacionSeleccionada = ControladorUsuarios::getControladorUsuarios()
    ->getUsuarioSesionActual()->getConversacion(identificador);
}

list<DataReceptor> ControladorMensajes::obtenerInformacionAdicional(IdMensaje identificador){
    Usuario* user = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();
    if(user == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!this->conversacionSeleccionada->tieneMensaje(identificador) ||
       (!this->conversacionSeleccionada->getMensaje(identificador)->esEmisor(user) &&
        !this->conversacionSeleccionada->getMensaje(identificador)->esReceptor(user)))
        throw invalid_argument("El mensaje no existe en la conversacion, o no tiene permisos para verlo.");

    list<DataReceptor> retorno;
    Conversacion* conv = this->conversacionSeleccionada;
    return conv->getMensaje(identificador)->getDataReceptor();
}

void ControladorMensajes::eliminarMensaje(IdMensaje id) {
    Usuario* user = ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual();

    if(user == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!this->conversacionSeleccionada->tieneMensaje(id) ||
       (!this->conversacionSeleccionada->getMensaje(id)->esEmisor(user) &&
        !this->conversacionSeleccionada->getMensaje(id)->esReceptor(user)))
        throw invalid_argument("El mensaje no existe en la conversacion, o no tiene permisos para verlo.");

    Mensaje* msj = this->conversacionSeleccionada->getMensaje(id);

    if(msj->esReceptor(user)) {
        msj->quitarReceptor(user);
    }
    else if(msj->esEmisor(user)) {
        this->conversacionSeleccionada->borrarMensaje(msj);
    }
}

void ControladorMensajes::archivarConversacion(IdConversacion id) {
    if(ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual() == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->tieneConversacionActiva(id))
        throw invalid_argument("La conversacion seleccionada no existe, no pertenece a ella, o ya fue archivada.");

    ControladorUsuarios::getControladorUsuarios()->getUsuarioSesionActual()->archivarConversacion(id);
}

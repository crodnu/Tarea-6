#include "../include/ControladorMensajes.h"

ControladorMensajes::ControladorMensajes() {
<<<<<<< HEAD
  this->instancia = new ControladorMensajes();
  return this->instancia;
=======
  //this.instancia = new ControladorMensajes();
  //return this.instancia;
>>>>>>> 788e4cb5bf2d2844ee65ad08bdd0c9e312ef7ec9
}

void ControladorMensajes::enviarMensaje(Mensaje mensaje){
//ver si pasamos el controlador o el usuario
}

void ControladorMensajes::seleccionarConversacion(int identificador){
  this->conversacionSeleccionada = this->conversacionesDelSistema[identificador];
}

ControladorMensajes ControladorMensajes::getControladorMensajes(){
  if (this->instancia == NULL)
    this->instancia = ControladorMensajes();

  return this->instancia;
}

void ControladorMensajes::crearConversacionSimple(string telefonoContacto){
//ver si pasamos el controlador o el usuario
}

set<DataConversacion> ControladorMensajes::darConversaciones(){
  set<DataConversacion> retorno;
  //iteracion sobre las conversaciones agregando los DataConversacion a retorno
  return retorno;
}

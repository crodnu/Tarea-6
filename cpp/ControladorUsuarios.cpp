#include "../include/ControladorUsuarios.h"

ControladorUsuarios ControladorUsuarios::ControladorUsuarios(){
    this.instancia = new ControladorUsuarios();
    return this.instancia;
}

ControladorUsuarios * ControladorUsuarios::getControladorUsuarios(){
    if(this.instancia == NULL)
            this.instancia = ControladorUsuarios();
    return this.instancia;
}

void ControladorUsuarios::agregarContacto(string cel){
    this.usuarioIniciado.agregarContacto(this.usuariosDelSistema[cel]);
}

Usuario ControladorUsuarios::getUsuario(string cel){
    return this.usuariosDelSistema[cel];
}

Usuario ControladorUsuarios::getUsuarioSesionActual(){
    return this.usuarioIniciado;
}

DataContacto ControladorUsuarios::getDatos(string cel){
    return this.usuarioIniciado.getDataContacto();
}

void ControladorUsuarios::darseDeAlta(string nombre, string cel, string urlImagen, string descripcion){
    Usuario uno = new Usuario();
    uno.nombre = nombre;
    uno.telefono = cel;
    uno.urlAvatar = urlImagen;
    uno.descripcion = descripcion;
    this.usuariosDelSistema[cel] = uno;
}

enumIniciarSesion ControladorUsuarios::iniciarSesion(string cel){
    return SESION_INICIADA_CORRECTAMENTE;
}

set<dataContacto> ControladorUsuarios::listarContactos(){
    return this.usuarioIniciado.getContactos();
}

void ControladorUsuarios::archivarConversacion(int identificadorConv){
    this.usuarioIniciado.archivarConversacion(identificadorConv);
}


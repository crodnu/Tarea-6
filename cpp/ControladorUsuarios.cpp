#include "../include/ControladorUsuarios.h"

ControladorUsuarios ControladorUsuarios::ControladorUsuarios(){
    this->instancia = new ControladorUsuarios();
    return this->instancia;
}

enumIniciarSesion ControladorUsuarios::iniciarSesionUsuario(){
    return SESION_INICIADA_CORRECTAMENTE;
}

ControladorUsuarios * ControladorUsuarios::getControladorUsuarios(){
    if(this->instancia == NULL)
            this->instancia = ControladorUsuarios();
    return this->instancia;
}

void ControladorUsuarios::agregarContacto(string cel){
    Usuario iniciado = this->getUsuarioSesionActual();
    Usuario contacto = this->usuariosDelSistema[cel];
    if(iniciado != NULL && contacto != NULL)
        iniciado.agregarContacto(contacto);
}

Usuario ControladorUsuarios::getUsuario(string cel){
    return this->usuariosDelSistema[cel];
}

Usuario ControladorUsuarios::getUsuarioSesionActual(){
    return this->usuarioIniciado;
}

DataContacto ControladorUsuarios::getDatos(string cel){
    Usuario iniciado = this->usuarioIniciado;
    return iniciado.getDataContacto();
}

void ControladorUsuarios::darseDeAlta(string nombre, string cel, string urlImagen, string descripcion){
    Usuario uno = new Usuario();
    uno.nombre = nombre;
    uno.telefono = cel;
    uno.urlAvatar = urlImagen;
    uno.descripcion = descripcion;
    this->usuariosDelSistema[cel] = uno;
}

enumIniciarSesion ControladorUsuarios::iniciarSesion(string cel){
    Usuario entrante = usuariosDelSistema[cel];
    Usuario enSesion = this->getUsuarioSesionActual();
    if(entrante == NULL){
        return NUMERO_NO_EXISTE;
    }else if(entrante == enSesion && entrante =! NULL){
        return SESION_YA_INICIADA_MISMO_NUMERO;
    }else if(entrante != enSesion && entrante != NULL && enSesion != NULL){
        return SESION_YA_INICIADA_OTRO_NUMERO;
    }else{
        this->usuarioIniciado = entrante;
        this->iniciarSesionUsuario();
    }
}

set<dataContacto> ControladorUsuarios::listarContactos(){
    Usuario iniciado = this->usuarioIniciado;
    return iniciado.getContactos();
}

void ControladorUsuarios::archivarConversacion(int identificadorConv){
    Usuario iniciado = this->usuarioIniciado;
    iniciado.archivarConversacion(identificadorConv);
}


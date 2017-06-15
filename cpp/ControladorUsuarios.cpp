#include "../include/ControladorUsuarios.h"

ControladorUsuarios::ControladorUsuarios(){
}

void ControladorUsuarios::iniciarSesionUsuario(Usuario * entrante){
    ControladorUsuarios::instancia->usuarioIniciado = entrante;
    return SESION_INICIADA_CORRECTAMENTE;
}

ControladorUsuarios* ControladorUsuarios::getControladorUsuarios(){
    if(ControladorUsuarios::instancia == NULL)
        ControladorUsuarios::instancia = new ControladorUsuarios();

    return ControladorUsuarios::instancia;
}

void ControladorUsuarios::agregarContacto(TelefonoUsuario cel){
    Usuario* iniciado = ControladorUsuarios::instancia->getUsuarioSesionActual();
    Usuario* contacto = ControladorUsuarios::instancia->usuariosDelSistema[cel];
    if(iniciado != NULL && contacto != NULL)
        iniciado->agregarContacto(contacto);
}

Usuario* ControladorUsuarios::getUsuario(TelefonoUsuario cel){
    return ControladorUsuarios::instancia->usuariosDelSistema[cel];
}

Usuario* ControladorUsuarios::getUsuarioSesionActual(){
    return ControladorUsuarios::instancia->usuarioIniciado;
}

DataContacto ControladorUsuarios::getDatos(TelefonoUsuario cel){
    Usuario* iniciado = ControladorUsuarios::instancia->usuarioIniciado;
    return iniciado->getDataContacto();
}

void ControladorUsuarios::darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion){
    Usuario* uno = new Usuario(cel, nombre, descripcion, urlImagen);
    ControladorUsuarios::instancia->usuariosDelSistema[cel] = uno;
}

enumIniciarSesion ControladorUsuarios::iniciarSesion(TelefonoUsuario cel){
    Usuario* entrante = usuariosDelSistema[cel];
    Usuario* enSesion = ControladorUsuarios::instancia->getUsuarioSesionActual();

    if(entrante == NULL) {
        return NUMERO_NO_EXISTE;
    }

    else if(entrante == enSesion && entrante != NULL) {
        return SESION_YA_INICIADA_MISMO_NUMERO;
    }

    else if(entrante != enSesion && entrante != NULL && enSesion != NULL) {
        return SESION_YA_INICIADA_OTRO_NUMERO;
    }

    else {
        return ControladorUsuarios::instancia->iniciarSesionUsuario(entrante);
    }
}

list<DataContacto> ControladorUsuarios::listarContactos(){
    Usuario* iniciado = ControladorUsuarios::instancia->getUsuarioSesionActual;
    return iniciado->getContactos();
}

void ControladorUsuarios::archivarConversacion(IdConversacion identificadorConv){
    Usuario* iniciado = ControladorUsuarios::instancia->usuarioIniciado;
    iniciado->archivarConversacion(identificadorConv);
}

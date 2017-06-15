#include "../include/ControladorUsuarios.h"
#include "../include/ControladorUsuarios.h"

ControladorUsuarios::ControladorUsuarios(){
}

ControladorUsuarios* ControladorUsuarios::getControladorUsuarios(){
    if(ControladorUsuarios::instancia == NULL)
        ControladorUsuarios::instancia = new ControladorUsuarios();

    return ControladorUsuarios::instancia;
}

void ControladorUsuarios::agregarContacto(TelefonoUsuario cel){
    Usuario* iniciado = this->getUsuarioSesionActual();
    Usuario* contacto = this->usuariosDelSistema[cel];
    if(iniciado != NULL && contacto != NULL)
        iniciado->agregarContacto(contacto);
}

Usuario* ControladorUsuarios::getUsuario(TelefonoUsuario cel){
    return this->usuariosDelSistema[cel];
}

Usuario* ControladorUsuarios::getUsuarioSesionActual(){
    return this->usuarioIniciado;
}

DataContacto ControladorUsuarios::getDatos(TelefonoUsuario cel){
    Usuario* iniciado = this->usuarioIniciado;
    return iniciado->getDataContacto();
}

void ControladorUsuarios::darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion){
    Usuario* uno = new Usuario(cel, nombre, descripcion, urlImagen);
    this->usuariosDelSistema[cel] = uno;
}

enumIniciarSesion ControladorUsuarios::iniciarSesion(TelefonoUsuario cel){
    Usuario* entrante = usuariosDelSistema[cel];
    Usuario* enSesion = this->getUsuarioSesionActual();

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
        this->usuarioIniciado = entrante;
        return SESION_INICIADA_CORRECTAMENTE;
    }
}

list<DataContacto> ControladorUsuarios::listarContactos(){
<<<<<<< HEAD
    Usuario* iniciado = ControladorUsuarios::instancia->getUsuarioSesionActual;
=======
    Usuario* iniciado = this->usuarioIniciado;
>>>>>>> f973b184afab18ea865de7a8bb0e45216ff77330
    return iniciado->getContactos();
}

void ControladorUsuarios::archivarConversacion(IdConversacion identificadorConv){
    Usuario* iniciado = this->usuarioIniciado;
    Conversacion* = iniciado->
    iniciado->archivarConversacion(identificadorConv);
}

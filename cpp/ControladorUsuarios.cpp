#include "../include/ControladorUsuarios.h"
#include "../include/ControladorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::instancia = NULL;

ControladorUsuarios::ControladorUsuarios() {
    this->usuarioIniciado = NULL;
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

void ControladorUsuarios::cerrarSesion() {
    this->usuarioIniciado = NULL;
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
    this->usuarioIniciado = uno;
    this->usuariosDelSistema[cel] = uno;
}

enumIniciarSesion ControladorUsuarios::iniciarSesion(TelefonoUsuario cel){
    Usuario* entrante = this->usuariosDelSistema[cel];
    Usuario* enSesion = this->getUsuarioSesionActual();

    if(entrante == enSesion && enSesion != NULL) {
        return SESION_YA_INICIADA_MISMO_NUMERO;
    }

    if(entrante != enSesion && enSesion != NULL) {
        return SESION_YA_INICIADA_OTRO_NUMERO;
    }

    if(entrante == NULL) {
        return NUMERO_NO_EXISTE;
    }

    else {
        this->usuarioIniciado = entrante;
        entrante->actualizarFechaUltimaConexion();
        return SESION_INICIADA_CORRECTAMENTE;
    }
}

list<DataContacto> ControladorUsuarios::listarContactos(){
    Usuario* iniciado = ControladorUsuarios::instancia->getUsuarioSesionActual();
    return iniciado->getContactos();
}

void ControladorUsuarios::archivarConversacion(IdConversacion identificadorConv){
    Usuario* iniciado = this->usuarioIniciado;
    iniciado->archivarConversacion(identificadorConv);
}

void ControladorUsuarios::actualizarNombreUsuario(string nombre){
    Usuario * iniciado = this->usuarioIniciado;
    iniciado->actualizarNombre(nombre);
}
void ControladorUsuarios::actualizarImagenUsuario(string urlImagen){
    Usuario * iniciado = this->usuarioIniciado;
    iniciado->actualizarImagen(urlImagen);
}
void ControladorUsuarios::actualizarDescripcionUsuario(string descripcion){
    Usuario * iniciado = this->usuarioIniciado;
    iniciado->actualizarDescripcion(descripcion);
}

list<DataNotificacion> ControladorUsuarios::getNotificaciones() {
    return this->usuarioIniciado->getNotificaciones();
}

void ControladorUsuarios::suscribirse(TelefonoUsuario telefono) {
    this->usuarioIniciado->suscribirse(this->usuariosDelSistema[telefono]);
}

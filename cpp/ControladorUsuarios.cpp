#include "../include/ControladorUsuarios.h"

#include <iostream>
#include <stdexcept>

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
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    this->usuarioIniciado = NULL;
}

Usuario* ControladorUsuarios::getUsuario(TelefonoUsuario cel){
    return this->usuariosDelSistema[cel];
}

Usuario* ControladorUsuarios::getUsuarioSesionActual(){
    return this->usuarioIniciado;
}

DataContacto ControladorUsuarios::getDatos(TelefonoUsuario cel){
    Usuario* user = this->usuariosDelSistema[cel];
    return user->getDataContacto();
}

void ControladorUsuarios::darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion){
    if(this->usuariosDelSistema.count(cel) == 1)
        throw invalid_argument("El numero ingresado ya existe en el sistema.");

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
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    Usuario* iniciado = ControladorUsuarios::instancia->getUsuarioSesionActual();
    return iniciado->getContactos();
}

void ControladorUsuarios::archivarConversacion(IdConversacion identificadorConv){
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(!this->usuarioIniciado->tieneConversacionActiva(identificadorConv))
        throw invalid_argument("La conversacion seleccionada no existe, no pertenece a ella, o ya fue archivada.");

    Usuario* iniciado = this->usuarioIniciado;
    iniciado->archivarConversacion(identificadorConv);
}

void ControladorUsuarios::actualizarNombreUsuario(string nombre){
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    Usuario * iniciado = this->usuarioIniciado;
    iniciado->actualizarNombre(nombre);
}
void ControladorUsuarios::actualizarImagenUsuario(string urlImagen){
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    Usuario * iniciado = this->usuarioIniciado;
    iniciado->actualizarImagen(urlImagen);
}
void ControladorUsuarios::actualizarDescripcionUsuario(string descripcion){
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    Usuario * iniciado = this->usuarioIniciado;
    iniciado->actualizarDescripcion(descripcion);
}

list<DataNotificacion> ControladorUsuarios::getNotificaciones() {
    return this->usuarioIniciado->getNotificaciones();
}

void ControladorUsuarios::suscribirse(TelefonoUsuario telefono) {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(this->usuariosDelSistema.count(telefono) == 0 || !this->usuarioIniciado->tieneContactoConTelefono(telefono))
        throw invalid_argument("El usuario seleccionado no existe o no es su contacto.");

    this->usuarioIniciado->suscribirse(this->usuariosDelSistema[telefono]);
}

void ControladorUsuarios::resetSets() {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    this->usuariosPorAgregar = ControladorUsuarios::getControladorUsuarios()
        ->getUsuarioSesionActual()->getMapContactos();
    this->usuariosAgregados.clear();
}

list<DataContacto> ControladorUsuarios::listarParticipantes() {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    list<DataContacto> participantes;

    for(map<TelefonoUsuario, Usuario*>::iterator it = this->usuariosAgregados.begin();
        it != this->usuariosAgregados.end(); it++) {
        Usuario* contacto = it->second;
        participantes.push_front(contacto->getDataContacto());
    }

    return participantes;
}

list<DataContacto> ControladorUsuarios::listarContactosRestantes() {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    list<DataContacto> contactos;

    for(map<TelefonoUsuario, Usuario*>::iterator it = this->usuariosPorAgregar.begin();
        it != this->usuariosPorAgregar.end(); it++) {
        Usuario* contacto = it->second;
        contactos.push_front(contacto->getDataContacto());
    }

    return contactos;
}

void ControladorUsuarios::agregarPaticipante(TelefonoUsuario cel) {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(this->usuariosDelSistema.count(cel) == 0 || !this->usuarioIniciado->tieneContactoConTelefono(cel))
        throw invalid_argument("El usuario seleccionado no existe o no es su contacto.");

    this->usuariosAgregados[cel] = this->usuariosPorAgregar[cel];
    this->usuariosPorAgregar.erase(cel);
}

void ControladorUsuarios::removerParticipante(TelefonoUsuario cel) {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(this->usuariosAgregados.count(cel) == 0)
        throw invalid_argument("El usuario seleccionado no fue agregado al set de participantes.");

    this->usuariosPorAgregar[cel] = this->usuariosAgregados[cel];
    this->usuariosAgregados.erase(cel);
}

void ControladorUsuarios::crearGrupo(NombreGrupo nombre, string urlImagen) {
    if(this->usuarioIniciado == NULL)
        throw invalid_argument("La sesion no fue iniciada.");

    if(this->usuariosAgregados.size() == 0)
        throw invalid_argument("No se selecciono ningun participante para el grupo.");

    if(this->gruposDelSistema.count(nombre) == 1)
        throw invalid_argument("Ya existe un grupo en el sistema con ese nombre.");

    Grupo* grupo = new Grupo(nombre, urlImagen, ControladorFecha::getInstance()->getFechaActual());
    this->usuarioIniciado->administrar(grupo);
    this->gruposDelSistema[nombre] = grupo;

    for(map<TelefonoUsuario, Usuario*>::iterator it = this->usuariosAgregados.begin();
        it != this->usuariosAgregados.end(); it++) {
        Usuario* contacto = it->second;
        contacto->integrar(grupo);
    }
}

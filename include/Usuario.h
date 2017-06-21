#ifndef USUARIO_H
#define	USUARIO_H

#include <list>
#include <map>
#include <string>

#include "ControladorFecha.h"
#include "Conversacion.h"
#include "DataContacto.h"
#include "DataConversacion.h"
#include "DataNotificacion.h"
#include "Fecha.h"
#include "Grupo.h"
#include "typedefs.h"

class Conversacion;
class Grupo;
class Mensaje;
class Notificacion;

class Usuario {
public:
    Usuario(TelefonoUsuario telefono, std::string nombre, std::string descripcion, std::string urlAvatar);
    TelefonoUsuario getTelefono();
    DataContacto getDataContacto();
    std::list<DataContacto> getContactos();
    void agregarContacto(Usuario* contacto);
    std::list<DataConversacion*> getSetDataConversacion();
    void suscribirse(Usuario* user);
    std::list<DataNotificacion> getNotificaciones();
    std::list<DataConversacion*> getSetDataConversacionesArchivadas();
    std::list<DataConversacion*> getSetDataConversacionesActivas();
    void actualizarNombre(std::string nombre);
    void actualizarImagen(std::string urlImagen);
    void actualizarDescripcion(std::string descripcion);
    void actualizarFechaUltimaConexion();
    void agregarConversacionActiva(Conversacion* conv);
    void archivarConversacion(IdConversacion id);
    std::map<TelefonoUsuario, Usuario*> getMapContactos();
    void administrar(Grupo* grupo);
    void integrar(Grupo* grupo);
    Conversacion* getConversacion(IdConversacion identificador);
    bool tieneContactoConTelefono(TelefonoUsuario telefono);
    bool tieneConversacionActiva(IdConversacion id);
    bool tieneConversacionArchivada(IdConversacion id);

private:
    TelefonoUsuario telefono;
    std::string nombre;
    std::string urlAvatar;
    std::string descripcion;
    Fecha fechaDeRegistro;
    Fecha ultimaConexion;
    std::map<TelefonoUsuario, Usuario*> contactos;
    std::map<TelefonoUsuario, Usuario*> suscriptores;
    std::list<DataNotificacion> notificacionesRecibidas;
    std::map<IdConversacion, Conversacion*> conversacionesIntegradas;
    std::map<IdConversacion, Conversacion*> conversacionesArchivadas;
    void notificarSuscriptores(DataNotificacion notificacion);
    std::map<NombreGrupo, Grupo*> gruposIntegradosConversacionesActivas;
    std::map<NombreGrupo, Grupo*> gruposIntegradosConversacionesArchivadas;
    std::map<NombreGrupo, Grupo*> gruposAdministrados;
    DataNotificacion crearDataNotificacion(std::string tipo);
};

#endif	/* USUARIO_H */

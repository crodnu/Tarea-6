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
#include "Notificacion.h"
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
    void actualizarNombre(string nombre);
    void actualizarImagen(string urlImagen);
    void actualizarDescripcion(string descripcion);
    void actualizarFechaUltimaConexion();

private:
    TelefonoUsuario telefono;
    std::string nombre;
    std::string urlAvatar;
    std::string descripcion;
    Fecha fechaDeRegistro;
    Fecha ultimaConexion;
    std::map<TelefonoUsuario, Usuario*> contactos;
    std::map<TelefonoUsuario, Usuario*> suscriptores;
    std::list<Notificacion*> notificacionesRecibidas;
    std::map<IdConversacion, Conversacion*> conversacionesIntegradas;
    std::map<IdConversacion, Conversacion*> conversacionesArchivadas;
    void notificarSuscriptores(Notificacion notificacion);
    std::map<NombreGrupo, Grupo*> gruposIntegrados;
    std::map<NombreGrupo, Grupo*> gruposAdministrados;
};

#endif	/* USUARIO_H */

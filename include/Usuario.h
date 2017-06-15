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
#include "Notificacion.h"
#include "typedefs.h"

class Conversacion;
class Mensaje;
class Notificacion;

class Usuario {
public:
    Usuario(TelefonoUsuario telefono, std::string nombre, std::string descripcion, std::string urlAvatar);
    DataContacto getDataContacto();
    std::list<DataContacto> getContactos();
    void agregarContacto(Usuario* contacto);
    std::list<DataConversacion*> getSetDataConversacion();
    void suscribirse(Usuario* user);
    std::list<DataNotificacion> getNotificaciones();

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
};

#endif	/* USUARIO_H */

#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include <string>

#include <map>
#include <list>

#include "DataContacto.h"
#include "DataNotificacion.h"
#include "enumIniciarSesion.h"
#include "Mensaje.h"
#include "typedefs.h"
#include "Usuario.h"

// Interfaces
#include "IAbrirGuassapFing.h"
#include "IAgregarContactos.h"
#include "IAltaGrupo.h"
#include "IArchivarConversaciones.h"
#include "ICambiarFecha.h"
#include "ICerrarGuassapFing.h"
#include "IEliminarMensajes.h"
#include "IEnviarMensaje.h"
#include "IModificarUsuario.h"
#include "ISuscribirse.h"
#include "IVerMensajes.h"

using namespace std;

class Usuario;

class ControladorUsuarios: public IAbrirGuassapFing, public ICerrarGuassapFing, public IAgregarContactos {
private:
    static ControladorUsuarios* instancia;
    Usuario* usuarioIniciado;
    std::map<TelefonoUsuario, Usuario*> usuariosDelSistema;
    ControladorUsuarios();

public:
    static ControladorUsuarios* getControladorUsuarios();
    virtual void agregarContacto(TelefonoUsuario cel);
    virtual void cerrarSesion();
    virtual Usuario* getUsuario(TelefonoUsuario cel);
    Usuario* getUsuarioSesionActual();
    virtual DataContacto getDatos(TelefonoUsuario cel);
    virtual void darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion);
    virtual enumIniciarSesion iniciarSesion(TelefonoUsuario cel);
    virtual std::list<DataContacto> listarContactos();
    virtual void archivarConversacion(int identificadorConv);
    virtual void actualizarNombreUsuario(string nombre);
    virtual void actualizarImagenUsuario(string urlImagen);
    virtual void actualizarDescripcionUsuario(string descripcion);
    virtual std::list<DataNotificacion> getNotificaciones();
};

#endif  /* CONTROLADORUSUARIOS_H */

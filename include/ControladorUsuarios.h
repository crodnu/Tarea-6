#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include <string>

#include <map>
#include <list>

#include "DataContacto.h"
#include "enumIniciarSesion.h"
#include "Mensaje.h"
#include "typedefs.h"
#include "Usuario.h"

using namespace std;

class Usuario;

class ControladorUsuarios {
private:
    static ControladorUsuarios* instancia;
    Usuario* usuarioIniciado;
    enumIniciarSesion enumerado; // Necesario?
    std::map<TelefonoUsuario, Usuario*> usuariosDelSistema;
    ControladorUsuarios();

public:
    static ControladorUsuarios* getControladorUsuarios();
    void agregarContacto(TelefonoUsuario cel);
    Usuario* getUsuario(TelefonoUsuario cel);
    Usuario* getUsuarioSesionActual();
    DataContacto getDatos(TelefonoUsuario cel);
    void darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion);
    enumIniciarSesion iniciarSesion(TelefonoUsuario cel);
    std::list<DataContacto> listarContactos();
    void archivarConversacion(int identificadorConv);
    void actualizarNombreUsuario(string nombre);
    void actualizarImagenUsuario(string urlImagen);
    void actualizarDescripcionUsuario(string descripcion);
};

#endif  /* CONTROLADORUSUARIOS_H */

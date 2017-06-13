#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include <string>

#include <map>

#include "Usuario.h"
#include "DataContacto.h"
#include "enumIniciarSesion.h"

using namespace std;

class ControladorUsuarios {
private:
    static ControladorUsuarios * instancia = NULL;
    Usuario * usuarioIniciado = NULL;
    enumIniciarSesion enumerado;
    std::map<TelefonoUsuario, Usuario*> usuariosDelSistema;
    ControladorUsuarios();
    enumIniciarSesion iniciarSesionUsuario();

public:
    ControladorUsuarios getControladorUsuarios();
    void agregarContacto(TelefonoUsuario cel);
    Usuario getUsuario(TelefonoUsuario cel);
    Usuario getUsuarioSesionActual();
    DataContacto getDatos(TelefonoUsuario cel);
    void darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion);
    enumIniciarSesion iniciarSesion(TelefonoUsuario cel);
    set<dataContacto> listarContactos();
    void archivarConversacion(int identificadorConv);
};

#endif  /* CONTROLADORUSUARIOS_H */

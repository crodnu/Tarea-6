#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H
#include <string>
using namespace std;
#include "Usuario.h"
#include "DataContacto.h"
#include "enumIniciarSesion.h"
#include <map>

class ControladorUsuarios {
private:
    static ControladorUsuarios * instancia = NULL;
    Usuario * usuarioIniciado = NULL;
    enumIniciarSesion enumerado;
    ControladorUsuarios();
    map<string,Usuario *> usuariosDelSistema;
    void iniciarSesionUsuario();/*no tengo idea que se supone que haga*/
public:
    ControladorUsuarios getControladorUsuarios();
    void agregarContacto(string cel);
    Usuario getUsuario(string cel);
    Usuario getUsuarioSesionActual();
    DataContacto getDatos(string cel);
    void darseDeAlta(string nombre, string cel, string urlImagen, string descripcion);
    enumIniciarSesion iniciarSesion(string cel);
    set<dataContacto> listarContactos();
    void archivarConversacion(int identificadorConv);
};

#endif  /* CONTROLADORUSUARIOS_H */

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

class ControladorUsuarios {
private:
    static ControladorUsuarios* instancia;
    Usuario * usuarioIniciado = NULL;
    std::map<TelefonoUsuario, Usuario*> usuariosDelSistema;
    ControladorUsuarios();

public:
    ControladorUsuarios* getControladorUsuarios();
    void agregarContacto(TelefonoUsuario cel);
    Usuario* getUsuario(TelefonoUsuario cel);
    Usuario* getUsuarioSesionActual();
    DataContacto getDatos(TelefonoUsuario cel);
    void darseDeAlta(string nombre, TelefonoUsuario cel, string urlImagen, string descripcion);
    enumIniciarSesion iniciarSesion(TelefonoUsuario cel);
    std::list<DataContacto> listarContactos();
    void archivarConversacion(int identificadorConv);
};

#endif  /* CONTROLADORUSUARIOS_H */

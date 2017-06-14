#ifndef USUARIO_H
#define	USUARIO_H

#include <list>
#include <map>
#include <string>

#include "ControladorFecha.h"
#include "Conversacion.h"
#include "DataContacto.h"
#include "DataConversacion.h"
#include "Fecha.h"
#include "NodoJerarquia.h"
#include "typedefs.h"

class Conversacion;
class Mensaje;
class NodoJerarquia;

class Usuario {
public:
    Usuario(TelefonoUsuario telefono, std::string nombre, std::string descripcion, std::string urlAvatar);
    DataContacto getDataContacto();
    std::list<DataContacto> getContactos();
    void agregarContacto(Usuario* contacto);
    std::list<DataConversacion> getSetDataConversacion();

private:
    TelefonoUsuario telefono;
    std::string nombre;
    std::string urlAvatar;
    std::string descripcion;
    Fecha fechaDeRegistro;
    Fecha ultimaConexion;
    std::map<TelefonoUsuario, Usuario*> contactos;
    std::map<IdConversacion, Conversacion*> conversacionesIntegradas;
    std::map<IdConversacion, Conversacion*> conversacionesArchivadas;
    std::map<IdJerarquia, NodoJerarquia*> jerarquias;
};

#endif	/* USUARIO_H */

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

typedef std::string TelefonoUsuario;

class Usuario {
public:
    Usuario(TelefonoUsuario telefono, std::string nombre, std::string descripcion, std::string urlAvatar);
    DataContacto getDataContacto();
    list<DataContacto> getContactos();
    void agregarContacto(Usuario* contacto);
    list<DataConversacion> getSetDataConversacion();

private:
    TelefonoUsuario telefono;
    std::string nombre;
    std::string urlAvatar;
    std::string descripcion;
    Fecha fechaDeRegistro;
    Fecha ultimaConexion;
    map<TelefonoUsuario, Usuario*> contactos;
    map<IdConversacion, Conversacion*> conversacionesIntegradas;
    map<IdConversacion, Conversacion*> conversacionesArchivadas;
    map<???, NodoJerarquia*> jerarquias;
};

#endif	/* USUARIO_H */

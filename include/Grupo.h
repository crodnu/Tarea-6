#ifndef GRUPO_H
#define	GRUPO_H

#include <map>
#include <string>

#include "Conversacion.h"
#include "DataConversacionGrupo.h"
#include "Fecha.h"
#include "typedefs.h"
#include "Usuario.h"

class Conversacion;
class Usuario;

class Grupo {
public:
    Grupo(NombreGrupo nombre, std::string urlImagen, Fecha fechaDeCreacion);
    Conversacion * getConversacion();
    DataConversacionGrupo* getDataConversacion(bool archivada);
    IdConversacion getIdConversacion();

private:
    NombreGrupo nombre;
    std::string urlImagen;
    Fecha fechaDeCreacion;
    std::map<TelefonoUsuario, Usuario*> integrantes;
    std::map<TelefonoUsuario, Usuario*> administradores;
    Conversacion* conversacion;
};

#endif	/* GRUPO_H */

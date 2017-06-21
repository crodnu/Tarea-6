#ifndef CONVERSACION_H
#define	CONVERSACION_H

#include <map>
#include <string>

#include "DataConversacionSimple.h"
#include "DataConversacionGrupo.h"
#include "Mensaje.h"
#include "typedefs.h"
#include "Usuario.h"

class Mensaje;
class Usuario;

class Conversacion {
public:
    Conversacion();
    std::map<IdMensaje, Mensaje*> getSetMensajes();
    Mensaje* getMensaje(IdMensaje identificador);
    DataConversacionSimple* getDataConversacionSimple(bool archivada);
    DataConversacionGrupo* getDataConversacionGrupo(bool archivada, std::string nombre);
    std::map<IdMensaje, Mensaje*> obtenerMensajes(Usuario* user);
    void enviar(Mensaje* mensaje);
    IdConversacion getId();
    void addParticipante(Usuario* participante);
    void borrarMensaje(Mensaje* msj);
    bool tieneMensaje(IdMensaje id);

private:
    IdConversacion id;
    static IdConversacion idActual;
    std::map<IdMensaje, Mensaje*> mensajes;
    std::map<TelefonoUsuario, Usuario*> participantes;
};

#endif	/* CONVERSACION_H */

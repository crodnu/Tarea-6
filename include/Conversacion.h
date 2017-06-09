#ifndef CONVERSACION_H
#define	CONVERSACION_H

#include <map>

#include "DataConversacion.h"
#include "Mensaje.h"
#include "Usuario.h"

typedef int IdConversacion;

class Conversacion {
public:
    Conversacion();
    map<IdMensaje, Mensaje*> getSetMensajes();
    Mensaje* getMensaje(IdMensaje identificador);
    DataConversacion* getDataConversacion();
    map<IdMensaje, Mensaje*> obtenerMensajes(Usuario* user);

private:
    IdConversacion id;
    std::map<IdMensaje, Mensaje*> mensajes;
    void enviar(Mensaje* mensaje);
};

#endif	/* CONVERSACION_H */

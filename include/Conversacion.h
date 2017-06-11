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
    void enviar(Mensaje* mensaje);

private:
    IdConversacion id;
    static IdConversacion idActual;
    std::map<IdMensaje, Mensaje*> mensajes;
};

#endif	/* CONVERSACION_H */

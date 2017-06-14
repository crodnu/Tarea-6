#ifndef CONVERSACION_H
#define	CONVERSACION_H

#include <map>

#include "DataConversacion.h"
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
    DataConversacion* getDataConversacion();
    std::map<IdMensaje, Mensaje*> obtenerMensajes(Usuario* user);
    void enviar(Mensaje* mensaje);

private:
    IdConversacion id;
    static IdConversacion idActual;
    std::map<IdMensaje, Mensaje*> mensajes;
};

#endif	/* CONVERSACION_H */

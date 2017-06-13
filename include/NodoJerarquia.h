#ifndef NODOJERARQUIA_H
#define	NODOJERARQUIA_H

#include <list>
#include <map>

#include "DataMensaje.h"
#include "Mensaje.h"
#include "typedefs.h"
#include "Usuario.h"

class Mensaje;
class Usuario;

class NodoJerarquia {
public:
    NodoJerarquia();
    void enviar(Mensaje* mensaje);
    virtual std::list<DataMensaje*> obtenerMensajes();
    IdJerarquia getId();

private:
    static IdJerarquia idActual;
    IdJerarquia id;
    std::map<IdMensaje, Mensaje*> mensajes;
};


#endif	/* NODOJERARQUIA_H */

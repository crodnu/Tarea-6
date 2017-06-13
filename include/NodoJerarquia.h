#ifndef NODOJERARQUIA_H
#define	NODOJERARQUIA_H

#include <list>
#include <map>

#include "DataMensaje.h"
#include "Mensaje.h"
#include "NodoCompuesto.h"
#include "Usuario.h"

typedef int IdJerarquia;

class NodoJerarquia {
public:
    NodoJerarquia(NodoCompuesto* padre);
    void enviar(Mensaje* mensaje);
    virtual std::list<DataMensaje*> obtenerMensajes();
    IdJerarquia getId();

private:
    static idJerarquia idActual = 0;
    IdJerarquia id;
    std::map<IdMensaje, Mensaje*> mensajes;
};

#endif	/* NODOJERARQUIA_H */

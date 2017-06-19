#ifndef IELIMINARMENSAJES_H_INCLUDED
#define IELIMINARMENSAJES_H_INCLUDED

#include <list>

#include "DataConversacion.h"

class IEliminarMensajes {
public:
    virtual std::list<DataConversacion*> darConversaciones() = 0;
    virtual std::list<DataConversacion*> darConversacionesArchivadas() = 0;
    virtual void seleccionarConversacionActiva(int id) = 0;
    virtual void seleccionarConversacionArchivada(int id) = 0;
    virtual void eliminarMensaje(int id) = 0;
};

#endif // IELIMINARMENSAJES_H_INCLUDED

#ifndef IVERMENSAJES_H_INCLUDED
#define IVERMENSAJES_H_INCLUDED

#include <list>

#include <DataConversacion.h>
#include <DataMensaje.h>
#include <DataReceptor.h>

class IVerMensajes {
public:
    virtual std::list<DataConversacion*> darConversaciones() = 0;
    virtual std::list<DataConversacion*> darConversacionesArchivadas() = 0;
    virtual void seleccionarConversacionActiva(int identificador) = 0;
    virtual void seleccionarConversacionArchivada(int identificador) = 0;
    virtual std::list<DataMensaje*> obtenerMensajesDeConversacion() = 0;
    virtual std::list<DataReceptor> obtenerInformacionAdicional(int identificador) = 0;
};

#endif // IVERMENSAJES_H_INCLUDED

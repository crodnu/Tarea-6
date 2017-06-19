#ifndef DATACONVERSACION_H
#define	DATACONVERSACION_H

#include <list>

#include "DataMensaje.h"
#include "typedefs.h"

class DataConversacion {
public:
    DataConversacion(IdConversacion id, bool archivada, std::list<DataMensaje*> mensajes);

    bool getArchivada();

    // Ta bien esto?
    std::list<DataMensaje*> getMensajes();
    IdConversacion getId();

private:
    bool archivada;
    IdConversacion id;
    std::list<DataMensaje*> mensajes;
};

#endif	/* DATACONVERSACION_H */

#ifndef DATACONVERSACION_H
#define	DATACONVERSACION_H

#include <list>

#include "DataMensaje.h"

class DataConversacion {
public:
    DataConversacion(bool archivada, std::list<DataMensaje*> mensajes);

    bool getArchivada();
    
    // Ta bien esto?
    std::list<DataMensaje*> getMensajes();

private:
    bool archivada;
    std::list<DataMensaje*> mensajes;
};

#endif	/* DATACONVERSACION_H */

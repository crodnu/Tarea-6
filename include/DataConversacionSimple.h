#ifndef DATACONVERSACIONSIMPLE_H
#define	DATACONVERSACIONSIMPLE_H

#include "DataContacto.h"
#include "DataConversacion.h"

class DataConversacionSimple: public DataConversacion {
public:
    DataConversacionSimple(bool archivada, std::list<DataMensaje*> mensajes, DataContacto contacto);

    DataContacto getContacto();

private:
    DataContacto contacto;
};

#endif	/* DATACONVERSACIONSIMPLE_H */

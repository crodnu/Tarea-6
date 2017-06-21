#ifndef DATACONVERSACIONSIMPLE_H
#define	DATACONVERSACIONSIMPLE_H

#include "DataContacto.h"
#include "DataConversacion.h"

class DataConversacionSimple: public DataConversacion {
public:
    DataConversacionSimple(IdConversacion id, bool archivada, std::list<DataMensaje*> mensajes, DataContacto contacto);

    DataContacto getContacto();
    virtual void print();

private:
    DataContacto contacto;
};

#endif	/* DATACONVERSACIONSIMPLE_H */

#ifndef DATAMENSAJEDECONTACTO_H
#define	DATAMENSAJEDECONTACTO_H

#include "DataContacto.h"
#include "DataMensaje.h"

class DataMensajeDeContacto: public DataMensaje {
public:
    DataMensajeDeContacto(IdMensaje id, Fecha fechaDeEnviado, DataContacto contacto);

    DataContacto getContacto();
    virtual void print();

private:
    DataContacto contacto;
};

#endif	/* DATAMENSAJEDECONTACTO_H */

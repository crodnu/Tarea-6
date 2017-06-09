#ifndef DATAMENSAJEDECONTACTO_H
#define	DATAMENSAJEDECONTACTO_H

#include "DataContacto.h"
#include "DataMensaje.h"

class DataMensajeDeContacto: DataMensaje {
public:
    DataMensajeDeContacto(Fecha fechaDeEnviado, DataContacto contacto);

    DataContacto getContacto();

private:
    DataContacto contacto;
};

#endif	/* DATAMENSAJEDECONTACTO_H */

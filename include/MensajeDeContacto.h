#ifndef MENSAJEDECONTACTO_H
#define	MENSAJEDECONTACTO_H

#include "DataContacto.h" // Necesario?
#include "DataMensajeDeContacto.h"
#include "Mensaje.h"
#include "Usuario.h"

class MensajeDeContacto: public Mensaje {
public:
    MensajeDeContacto(Usuario* contacto);
    virtual DataMensaje* getDataMensaje();
    virtual ~MensajeDeContacto();

private:
    Usuario* contacto;
};

#endif	/* MENSAJEDECONTACTO_H */

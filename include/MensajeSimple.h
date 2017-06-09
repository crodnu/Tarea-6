#ifndef MENSAJESIMPLE_H
#define	MENSAJESIMPLE_H

#include <string>

#include "DataMensajeSimple.h"
#include "Mensaje.h"

class MensajeSimple: Mensaje {
public:
    MensajeSimple(std::string texto);
    virtual DataMensaje* getDataMensaje();

private:
    std::string texto;
};

#endif	/* MENSAJESIMPLE_H */

#ifndef MENSAJECONIMAGEN_H
#define	MENSAJECONIMAGEN_H

#include <string>

#include "Mensaje.h"
#include "DataMensajeConImagen.h"

class MensajeConImagen: Mensaje {
public:
    MensajeConImagen(std::string formato, std::string
        texto, std::string urlImagen, unsigned tamanio);
    virtual DataMensaje* getDataMensaje();

private:
    std::string formato;
    std::string texto;
    std::string urlImagen;
    unsigned tamanio;
};

#endif	/* MENSAJECONIMAGEN_H */

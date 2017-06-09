#ifndef DATAMENSAJECONIMAGEN_H
#define	DATAMENSAJECONIMAGEN_H

#include <string>

#include "DataMensaje.h"

class DataMensajeConImagen:  DataMensaje {
public:
    DataMensajeConImagen(Fecha fechaDeEnviado, std::string formato, std::string
        texto, std::string urlImagen, unsigned tamanio);

    std::string getFormato();
    std::string getTexto();
    std::string getUrlImagen();
    unsigned getTamanio();

private:
    std::string formato;
    std::string texto;
    std::string urlImagen;
    unsigned tamanio;
};

#endif	/* DATAMENSAJECONIMAGEN_H */

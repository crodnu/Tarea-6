#ifndef DATAMENSAJECONIMAGEN_H
#define	DATAMENSAJECONIMAGEN_H

#include <string>

#include "DataMensaje.h"

class DataMensajeConImagen: public DataMensaje {
public:
    DataMensajeConImagen(IdMensaje id, Fecha fechaDeEnviado, std::string formato, std::string
        texto, std::string urlImagen, unsigned tamanio);

    std::string getFormato();
    std::string getTexto();
    std::string getUrlImagen();
    unsigned getTamanio();
    virtual void print();

private:
    std::string formato;
    std::string texto;
    std::string urlImagen;
    unsigned tamanio;
};

#endif	/* DATAMENSAJECONIMAGEN_H */

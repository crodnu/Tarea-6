#ifndef DATAMENSAJESIMPLE_H
#define	DATAMENSAJESIMPLE_H

#include <string>

#include "DataMensaje.h"

class DataMensajeSimple: public DataMensaje {
public:
    DataMensajeSimple(IdMensaje id, Fecha fechaDeEnviado, std::string texto);

    std::string getTexto();
    virtual void print();
    virtual ~DataMensajeSimple();

private:
    std::string texto;
};

#endif	/* DATAMENSAJESIMPLE_H */

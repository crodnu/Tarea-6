#ifndef DATAMENSAJESIMPLE_H
#define	DATAMENSAJESIMPLE_H

#include <string>

#include "DataMensaje.h"

class DataMensajeSimple: DataMensaje {
public:
    DataMensajeSimple(Fecha fechaDeEnviado, std::string texto);

    std::string getTexto();

private:
    std::string texto;
};

#endif	/* DATAMENSAJESIMPLE_H */

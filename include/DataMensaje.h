#ifndef DATAMENSAJE_H
#define	DATAMENSAJE_H

#include "Fecha.h"

class DataMensaje {
public:
    DataMensaje(Fecha fechaDeEnviado);

    Fecha getFechaDeEnviado();

private:
    Fecha fechaDeEnviado;
};

#endif	/* DATAMENSAJE_H */

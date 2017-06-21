#ifndef DATAMENSAJE_H
#define	DATAMENSAJE_H

#include "Fecha.h"
#include "typedefs.h"

class DataMensaje {
public:
    DataMensaje(IdMensaje id, Fecha fechaDeEnviado);

    Fecha getFechaDeEnviado();
    IdMensaje getId();
    virtual void print();

private:
    Fecha fechaDeEnviado;
    IdMensaje id;
};

#endif	/* DATAMENSAJE_H */

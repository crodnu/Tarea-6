#ifndef DATARECEPTOR_H
#define	DATARECEPTOR_H

#include "Fecha.h"
#include "DataContacto.h"

class DataReceptor {
public:
    DataReceptor(const Fecha& fechaRecibido, const DataContacto& contacto);
    DataReceptor(const DataReceptor& orig);

    DataContacto getContacto();
    Fecha getFechaRecibido();

private:
    Fecha fechaRecibido;
    DataContacto contacto;
};

#endif	/* DATARECEPTOR_H */

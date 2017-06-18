#ifndef ISUSCRIBIRSE_H_INCLUDED
#define ISUSCRIBIRSE_H_INCLUDED

#include <list>
#include <string>

#include <DataContacto.h>

class ISuscribirse {
public:
    virtual std::list<DataContacto> listarContactos() = 0;
    virtual void suscribirse(std::string telefono) = 0;
};

#endif // ISUSCRIBIRSE_H_INCLUDED

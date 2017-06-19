#ifndef IAGREGARCONTACTOS_H_INCLUDED
#define IAGREGARCONTACTOS_H_INCLUDED

#include <list>
#include <string>

#include <DataContacto.h>

class IAgregarContactos {
public:
    virtual std::list<DataContacto> listarContactos() = 0;
    virtual DataContacto getDatos(std::string cel) = 0;
    virtual void agregarContacto(std::string cel) = 0;
};

#endif // IAGREGARCONTACTOS_H_INCLUDED

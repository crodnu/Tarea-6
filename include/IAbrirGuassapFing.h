#ifndef IABRIRGUASSAPFING_H_INCLUDED
#define IABRIRGUASSAPFING_H_INCLUDED

#include <string>

#include "enumIniciarSesion.h"
#include "ICerrarGuassapFing.h"

class IAbrirGuassapFing {
public:
    virtual enumIniciarSesion iniciarSesion(std::string cel) = 0;
    virtual void darseDeAlta(std::string nombre, std::string cel, std::string urlImagen, std::string descripcion) = 0;
    virtual void cerrarSesion() = 0;
};

#endif // IABRIRGUASSAPFING_H_INCLUDED

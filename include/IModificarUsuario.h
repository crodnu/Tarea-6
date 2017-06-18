#ifndef IMODIFICARUSUARIO_H_INCLUDED
#define IMODIFICARUSUARIO_H_INCLUDED

#include <string>

class IModificarUsuario {
public:
    virtual void actualizarNombreUsuario(std::string nombre) = 0;
    virtual void actualizarImagenUsuario(std::string urlImagen) = 0;
    virtual void actualizarDescripcionUsuario(std::string descripcion) = 0;
};

#endif // IMODIFICARUSUARIO_H_INCLUDED

#ifndef DATACONTACTO_H
#define	DATACONTACTO_H

#include <string>

#include "typedefs.h"

class DataContacto {
public:
    DataContacto(TelefonoUsuario telefono, std::string nombre, std::string descripcion, std::string urlImagen);
    DataContacto(const DataContacto& orig);

    std::string getNombre();
    std::string getDescripcion();
    std::string getUrlImagen();
    TelefonoUsuario getTelefono();

private:
    std::string nombre;
    std::string descripcion;
    std::string urlImagen;
    TelefonoUsuario telefono;
};

#endif	/* DATACONTACTO_H */

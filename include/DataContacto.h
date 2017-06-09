#ifndef DATACONTACTO_H
#define	DATACONTACTO_H

#include <string>

class DataContacto {
public:
    DataContacto(std::string nombre, std::string descripcion, std::string urlImagen);
    DataContacto(const DataContacto& orig);

    std::string getNombre();
    std::string getDescripcion();
    std::string getUrlImagen();

private:
    std::string nombre;
    std::string descripcion;
    std::string urlImagen;
};

#endif	/* DATACONTACTO_H */

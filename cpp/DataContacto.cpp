#include "../include/DataContacto.h"

using namespace std;

DataContacto::DataContacto(string nombre, string descripcion, string urlImagen) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->urlImagen = urlImagen;
}

DataContacto::DataContacto(const DataContacto& orig) {
    this->nombre = orig.nombre;
    this->descripcion = orig.descripcion;
    this->urlImagen = orig.urlImagen;
}

string DataContacto::getNombre() {
    return this->nombre;
}

string DataContacto::getDescripcion() {
    return this->descripcion;
}

string DataContacto::getUrlImagen() {
    return this->urlImagen;
}

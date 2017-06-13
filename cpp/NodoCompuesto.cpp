#include "../include/NodoCompuesto.h"

using namespace std;

NodoCompuesto::NodoCompuesto(NodoCompuesto* padre): NodoJerarquia(padre) {}

list<DataMensaje*> NodoCompuesto::obtenerMensajes() {
    list<DataMensaje*> result = NodoJerarquia::obtenerMensajes();

    for(const auto& par : this->hijos) {
        NodoJerarquia* hijo = par.second;
        result.splice(result.begin(), hijo->obtenerMensajes());
    }

    return result;
}

void NodoCompuesto::agregarHijo(NodoJerarquia* hijo) {
    this->hijos[hijo->getId()] = hijo;
}

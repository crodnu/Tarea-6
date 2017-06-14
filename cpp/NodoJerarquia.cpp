#include "../include/NodoJerarquia.h"

using namespace std;

NodoJerarquia::NodoJerarquia() {
    NodoJerarquia::idActual++;
    this->id = NodoJerarquia::idActual;
}

void NodoJerarquia::enviar(Mensaje* mensaje) {
    this->mensajes[mensaje->getId()] = mensaje;
}

list<DataMensaje*> NodoJerarquia::obtenerMensajes() {
    list<DataMensaje*> result;

    for(const auto& par: this->mensajes) {
        Mensaje* mensaje = par.second;
        DataMensaje* dataMensaje = mensaje->getDataMensaje();
        result.push_front(dataMensaje);
    }

    return result;
}

IdJerarquia NodoJerarquia::getId() {
    return this->id;
}

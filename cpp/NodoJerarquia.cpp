#include "../include/NodoJerarquia.h"

using namespace std;

NodoJerarquia::NodoJerarquia(NodoCompuesto* padre) {
    NodoJerarquia::idActual++;
    this->id = NodoJerarquia::idActual;

    if(padre != NULL) // Overloading?
        padre->agregarHijo(this);
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

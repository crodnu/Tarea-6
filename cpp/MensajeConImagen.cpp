#include "../include/MensajeConImagen.h"

using namespace std;

MensajeConImagen::MensajeConImagen(string formato, string texto,
                            string urlImagen, unsigned tamanio) {
    this->formato = formato;
    this->texto = texto;
    this->urlImagen = urlImagen;
    this->tamanio = tamanio;
}

DataMensaje* MensajeConImagen::getDataMensaje() {
    this->setLeidoPorUsuarioActual();
    return new DataMensajeConImagen(this->getFechaEnviado(),
        this->formato, this->texto, this->urlImagen, this->tamanio);
}

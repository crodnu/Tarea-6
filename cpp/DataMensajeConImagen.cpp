#include "../include/DataMensajeConImagen.h"

using namespace std;

DataMensajeConImagen::DataMensajeConImagen(Fecha fechaDeEnviado, string formato,
    string texto, string urlImagen, unsigned tamanio):
    DataMensaje(fechaDeEnviado) {
    this->formato = formato;
    this->tamanio = tamanio;
    this ->texto = texto;
    this->urlImagen = urlImagen;
}

string DataMensajeConImagen::getFormato() {
    return this->formato;
}

string DataMensajeConImagen::getTexto() {
    return this->texto;
}

string DataMensajeConImagen::getUrlImagen() {
    return this->urlImagen;
}

unsigned DataMensajeConImagen::getTamanio() {
    return this->tamanio;
}

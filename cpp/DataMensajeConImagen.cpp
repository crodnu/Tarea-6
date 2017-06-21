#include <iostream>

#include "../include/DataMensajeConImagen.h"

using namespace std;

DataMensajeConImagen::DataMensajeConImagen(IdMensaje id, Fecha fechaDeEnviado, string formato,
    string texto, string urlImagen, unsigned tamanio):
    DataMensaje(id, fechaDeEnviado) {
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

void DataMensajeConImagen::print() {
    DataMensaje::print();
    cout << "Imagen: " << this->urlImagen << endl
        << "Formato: " << this->formato << endl
        << "Tamanio: " << this->tamanio << endl;
    if(this->texto != "")
        cout << "Texto: " << this->texto << endl;
}

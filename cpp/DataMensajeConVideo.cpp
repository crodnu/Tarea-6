#include <iostream>

#include "../include/DataMensajeConVideo.h"

using namespace std;

DataMensajeConVideo::DataMensajeConVideo(IdMensaje id, Fecha fechaDeEnviado, string urlVideo, unsigned duracion):
    DataMensaje(id, fechaDeEnviado) {
    this->duracion = duracion;
    this->urlVideo = urlVideo;
}

string DataMensajeConVideo::getUrlVideo() {
    return this->urlVideo;
}

unsigned DataMensajeConVideo::getDuracion() {
    return this->duracion;
}

void DataMensajeConVideo::print() {
    DataMensaje::print();
    cout << "Video: " << this->urlVideo << endl
        << "Duracion: " << this->duracion << endl;
}

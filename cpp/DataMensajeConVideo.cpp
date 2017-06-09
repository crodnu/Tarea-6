#include "../include/DataMensajeConVideo.h"

using namespace std;

DataMensajeConVideo::DataMensajeConVideo(Fecha fechaDeEnviado, string urlVideo, unsigned duracion):
    DataMensaje(fechaDeEnviado) {
    this->duracion = duracion;
    this->urlVideo = urlVideo;
}

string DataMensajeConVideo::getUrlVideo() {
    return this->urlVideo;
}

unsigned DataMensajeConVideo::getDuracion() {
    return this->duracion;
}

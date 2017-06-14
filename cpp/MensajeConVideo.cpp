#include "../include/MensajeConVideo.h"

using namespace std;

MensajeConVideo::MensajeConVideo(std::string urlVideo, unsigned duracion) {
    this->urlVideo = urlVideo;
    this->duracion = duracion;
}

DataMensaje* MensajeConVideo::getDataMensaje() {
    return new DataMensajeConVideo(this->getFechaEnviado(), this->urlVideo, this->duracion);
}

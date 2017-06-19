#include "../include/MensajeConVideo.h"

using namespace std;

MensajeConVideo::MensajeConVideo(std::string urlVideo, unsigned duracion) {
    this->urlVideo = urlVideo;
    this->duracion = duracion;
}

DataMensaje* MensajeConVideo::getDataMensaje() {
    this->setLeidoPorUsuarioActual();
    return new DataMensajeConVideo(this->getId(), this->getFechaEnviado(), this->urlVideo, this->duracion);
}

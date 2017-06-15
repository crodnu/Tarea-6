#ifndef MENSAJECONVIDEO_H
#define	MENSAJECONVIDEO_H

#include <string>

#include <DataMensajeConVideo.h>
#include "Mensaje.h"

class MensajeConVideo: public Mensaje {
public:
    MensajeConVideo(std::string urlVideo, unsigned duracion);
    virtual DataMensaje* getDataMensaje();

private:
    std::string urlVideo;
    unsigned duracion;
};

#endif	/* MENSAJECONVIDEO_H */

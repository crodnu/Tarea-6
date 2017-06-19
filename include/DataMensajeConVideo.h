#ifndef DATAMENSAJECONVIDEO_H
#define	DATAMENSAJECONVIDEO_H

#include <string>

#include "DataMensaje.h"

class DataMensajeConVideo: public DataMensaje {
public:
    DataMensajeConVideo(IdMensaje id, Fecha fechaDeEnviado, std::string urlVideo, unsigned duracion);

    std::string getUrlVideo();
    unsigned getDuracion();

private:
    std::string urlVideo;
    unsigned duracion;
};

#endif	/* DATAMENSAJECONVIDEO_H */

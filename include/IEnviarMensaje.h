#ifndef IENVIARMENSAJE_H_INCLUDED
#define IENVIARMENSAJE_H_INCLUDED

#include <list>
#include <string>

#include "DataContacto.h"
#include "DataConversacion.h"

class IEnviarMensaje {
public:
    virtual void seleccionarConversacionActiva(int identificador) = 0;
    virtual void seleccionarConversacionArchivada(int identificador) = 0;
    virtual std::list<DataConversacion*> darConversaciones() = 0;
    virtual std::list<DataConversacion*> darConversacionesArchivadas() = 0;
    virtual void crearConversacionSimple(std::string telefonoContacto) = 0;
    virtual std::list<DataContacto> listarContactos() = 0;
    virtual void enviarMensajeContacto(std::string numeroContacto) = 0;
    virtual void enviarMensajeImagen(std::string urlImagen, std::string formato, std::string texto, int tamanio) = 0;
    virtual void enviarMensajeSimple(std::string texto) = 0;
    virtual void enviarMensajeVideo(std::string urlVideo, int duracion) = 0;
};

#endif // IENVIARMENSAJE_H_INCLUDED

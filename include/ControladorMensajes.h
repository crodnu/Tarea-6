#ifndef CONTROLADORMENSAJES_H
#define	CONTROLADORMENSAJES_H

#include <map>
#include <string>
#include <set>
#include <list>

#include "Conversacion.h"
#include "Mensaje.h"
#include "MensajeConImagen.h"
#include "MensajeConVideo.h"
#include "MensajeDeContacto.h"
#include "MensajeSimple.h"
#include "DataConversacion.h"
#include "DataMensaje.h"
#include "DataContacto.h"
#include "DataReceptor.h"
#include "typedefs.h"

using namespace std;

class ControladorMensajes {
private:
    static ControladorMensajes* instancia;
    Conversacion* conversacionSeleccionada;
    std::map<IdConversacion, Conversacion*> conversacionesDelSistema;
    ControladorMensajes();
    void enviarMensaje(Mensaje* mensaje);
    void seleccionarConversacion(IdConversacion identificador);

public:
    static ControladorMensajes* getControladorMensajes();
    void crearConversacionSimple(TelefonoUsuario telefonoContacto);
    std::list<DataConversacion*> darConversaciones();
    std::list<DataConversacion*> darConversacionesActivas();
    std::list<DataConversacion*> darConversacionesArchivadas();
    void enviarMensajeContacto(TelefonoUsuario numeroContacto);
    void enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio);
    void enviarMensajeSimple(string texto);
    void enviarMensajeVideo(string urmVideo, int duracion);
    std::list<DataContacto> listarContactos();
    std::list<DataMensaje*> obtenerMensajesDeConversacion();
    void seleccionarConversacionActiva(IdConversacion identificador);
    void seleccionarConversacionArchivada(IdConversacion identificador);
    set<DataReceptor> obtenerInformacionAdicional(int identificador);
};

#endif	/* CONTROLADORMENSAJES_H */

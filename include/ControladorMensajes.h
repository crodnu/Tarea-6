#ifndef CONTROLADORMENSAJES_H
#define	CONTROLADORMENSAJES_H

#include <map>
#include <string>
<<<<<<< HEAD
#include map;
#include list;
=======
#include <set>

>>>>>>> f973b184afab18ea865de7a8bb0e45216ff77330
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
    Conversacion* conversacionSeleccionada = NULL;
    std::map<IdConversacion, Conversacion*> conversacionesDelSistema;
    ControladorMensajes();
    void enviarMensaje(Mensaje* mensaje);
    void seleccionarConversacion(IdConversacion identificador);

public:
    static ControladorMensajes* getControladorMensajes();
    void crearConversacionSimple(TelefonoUsuario telefonoContacto);
    set<DataConversacion*> darConversaciones();
    set<DataConversacion*> darConversacionesActivas();
    set<DataConversacion*> darConversacionesArchivadas();
    void enviarMensajeContacto(TelefonoUsuario numeroContacto);
    void enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio);
    void enviarMensajeSimple(string texto);
    void enviarMensajeVideo(string urmVideo, int duracion);
<<<<<<< HEAD
    std::list<DataContacto> listarContactos();
    std::list<DataMensaje> obtenerMensajesDeConversacion();
=======
    set<DataContacto> listarContactos();
    set<DataMensaje*> obtenerMensajesDeConversacion();
>>>>>>> f973b184afab18ea865de7a8bb0e45216ff77330
    void seleccionarConversacionActiva(IdConversacion identificador);
    void seleccionarConversacionArchivada(IdConversacion identificador);
    set<DataReceptor> obtenerInformacionAdicional(int identificador);
};

#endif	/* CONTROLADORMENSAJES_H */

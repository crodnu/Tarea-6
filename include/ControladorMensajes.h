#ifndef CONTROLADORMENSAJES_H
#define	CONTROLADORMENSAJES_H

#include <map>
#include <string>
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

// Interfaces
#include "IAbrirGuassapFing.h"
#include "IAgregarContactos.h"
#include "IAltaGrupo.h"
#include "IArchivarConversaciones.h"
#include "ICambiarFecha.h"
#include "ICerrarGuassapFing.h"
#include "IEliminarMensajes.h"
#include "IEnviarMensaje.h"
#include "IModificarUsuario.h"
#include "ISuscribirse.h"
#include "IVerMensajes.h"

using namespace std;

class ControladorMensajes: public IEliminarMensaje, public IArchivarConversaciones, public IEnviarMensaje {
private:
    static ControladorMensajes* instancia;
    Conversacion* conversacionSeleccionada;
    std::map<IdConversacion, Conversacion*> conversacionesDelSistema;
    ControladorMensajes();
    void enviarMensaje(Mensaje* mensaje);
    void seleccionarConversacion(IdConversacion identificador);

public:
    static ControladorMensajes* getControladorMensajes();
    virtual void crearConversacionSimple(TelefonoUsuario telefonoContacto);
    virtual std::list<DataConversacion*> darConversaciones();
    virtual std::list<DataConversacion*> darConversacionesActivas();
    virtual std::list<DataConversacion*> darConversacionesArchivadas();
    virtual void enviarMensajeContacto(TelefonoUsuario numeroContacto);
    virtual void enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio);
    virtual void enviarMensajeSimple(string texto);
    virtual void enviarMensajeVideo(string urmVideo, int duracion);
    virtual std::list<DataContacto> listarContactos();
    virtual std::list<DataMensaje*> obtenerMensajesDeConversacion();
    virtual void seleccionarConversacionActiva(IdConversacion identificador);
    virtual void seleccionarConversacionArchivada(IdConversacion identificador);
    virtual std::list<DataReceptor> obtenerInformacionAdicional(int identificador);
    virtual void eliminarMensaje(IdMensaje id);
    virtual void archivarConversacion(IdConversacion id);
};

#endif	/* CONTROLADORMENSAJES_H */

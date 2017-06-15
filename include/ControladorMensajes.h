#ifndef CONTROLADORMENSAJES_H
#define	CONTROLADORMENSAJES_H

#include <string>
#include "Conversacion.h"
#include "Mensaje.h"
#include "DataConversacion.h"
#include "DataMensaje.h"
#include "DataContacto.h"
#include "DataReceptor.h"

using namespace std;

class ControladorMensajes {
private:
    static ControladorMensajes* instancia;
    Conversacion* conversacionSeleccionada = NULL;
    std::map<idConversacion, Conversacion *> conversacionesDelSistema;
    ControladorMensajes();
    void enviarMensaje(Mensaje mensaje, Usuario * actual);
    void seleccionarConversacion(IdConversacion identificador);

public:
    static ControladorMensajes getControladorMensajes();
    void crearConversacionSimple(TelefonoUsuario telefonoContacto);
    set<DataConversacion> darConversaciones();
    set<DataConversacion> darConversacionesActivas();
    set<DataConversacion> darConversacionesArchivadas();
    void enviarMensajeContacto(TelefonoUsuario numeroContacto, ControladorUsuarios contUsuarios);
    void enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio, ControladorUsuarios contUsuarios);
    void enviarMensajeSimple(string texto, ControladorUsuarios contUsuarios);
    void enviarMensajeVideo(string urmVideo, int duracion, ControladorUsuarios contUsuarios);
    set<DataContacto> listarContactos();
    set<DataMensaje> obtenerMensajesDeConversacion();
    void seleccionarConversacionActiva(IdConversacion identificador);
    void seleccionarConversacionArchivada(IdConversacion identificador);
    set<DataReceptor> obtenerInformacionAdicional(int identificador);
};

#endif	/* CONTROLADORMENSAJES_H */

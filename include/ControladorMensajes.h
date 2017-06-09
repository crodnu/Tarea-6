#ifndef CONTROLADORMENSAJES_H
#define	CONTROLADORMENSAJES_H

#include <string>
using namespace std;
class ControladorMensajes {
private:
    ControladorMensajes instancia;
    Conversacion * conversacionSeleccionada;
    set<Conversacion> conversacionesDelSistema;
    ControladorMensajes();
    void enviarMensaje(Mensaje mensaje);
    void seleccionarConversacion(int identificador);
public:
    static ControladorMensajes getControladorMensajes();
    void crearConversacionSimple(string telefonoContacto);
    set<DataConversacion> darConversaciones();
    set<DataConversacion> darConversacionesActivas();
    set<DataConversacion> darConversacionesArchivadas();
    void enviarMensajeContacto(string numeroContacto);
    void enviarMensajeImagen(string urlImagen, string formato, string texto, int tamanio);
    void enviarMensajeSimple(string texto);
    void enviarMensajeVideo(string urmVideo, int duracion);
    set<DataContacto> listarContactos();
    set<DataMensaje> obtenerMensajesDeConversacion();
    void seleccionarConversacionActiva(int identificador);
    void seleccionarConversacionArchivada(int identificador);
    set<DataReceptor> obtenerInformacionAdicional(int identificador);
};

#endif	/* CONTROLADORMENSAJES_H */

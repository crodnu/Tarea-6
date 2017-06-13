#ifndef MENSAJE_H
#define	MENSAJE_H

#include <map>
#include <list>

#include "ControladorFecha.h"
#include "ControladorUsuarios.h"
#include "DataMensaje.h"
#include "DataReceptor.h"
#include "Fecha.h"
#include "Usuario.h"

typedef int IdMensaje;

class Mensaje {
public:
    Mensaje();
    virtual DataMensaje* getDataMensaje();
    bool esReceptor(Usuario* user);
    list<DataReceptor> getDataReceptor();
    Fecha getFechaEnviado();

private:
    idMensaje codigo;
    static idMensaje codigoActual;
    bool visto;
    Fecha fechaDeEnviado;
    Usuario* emisor;
    map<TelefonoUsuario, Usuario*> receptores;
    map<TelefonoUsuario, Usuario*> leidoPor;
};

#endif	/* MENSAJE_H */

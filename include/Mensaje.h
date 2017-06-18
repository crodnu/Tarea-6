#ifndef MENSAJE_H
#define	MENSAJE_H

#include <map>
#include <list>
#include <utility>

#include "ControladorFecha.h"
#include "ControladorUsuarios.h"
#include "DataMensaje.h"
#include "DataReceptor.h"
#include "Fecha.h"
#include "typedefs.h"
#include "Usuario.h"

class Usuario;

class Mensaje {
public:
    Mensaje();
    virtual DataMensaje* getDataMensaje();
    bool esReceptor(Usuario* user);
    std::list<DataReceptor> getDataReceptor();
    Fecha getFechaEnviado();
    IdMensaje getId();
    void addReceptor(Usuario* receptor);

protected:
    void setLeidoPorUsuarioActual();

private:
    IdMensaje codigo;
    static IdMensaje codigoActual;
    bool visto;
    Fecha fechaDeEnviado;
    Usuario* emisor;
    std::map<TelefonoUsuario, Usuario*> receptores;
    std::map<TelefonoUsuario, std::pair<Usuario*, Fecha> > leidoPor;
};

#endif	/* MENSAJE_H */

#ifndef CONTROLADORFACTORY_H
#define CONTROLADORFACTORY_H

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

class ControladorFactory {
public:
    static IAbrirGuassapFing* getIAbrirGuassapFing();
    static IAgregarContactos* getIAgregarContactos();
    static IAltaGrupo* getIAltaGrupo();
    static IArchivarConversaciones* getIArchivarConversaciones();
    static ICambiarFecha* getICambiarFecha();
    static ICerrarGuassapFing* getICerrarGuassapFing();
    static IEliminarMensajes* getIEliminarMensajes();
    static IEnviarMensaje* getIEnviarMensaje();
    static IModificarUsuario* getIModificarUsuario();
    static ISuscribirse* getISuscribirse();
    static IVerMensajes* getIVerMensajes();
};

#endif // CONTROLADORFACTORY_H

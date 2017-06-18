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
    static ICambiarFecha* getICambiarFecha();
};

#endif // CONTROLADORFACTORY_H

#include "../include/ControladorFactory.h"
#include "../include/ControladorFecha.h"
#include "../include/ControladorMensajes.h"
#include "../include/ControladorUsuarios.h"

IAbrirGuassapFing* ControladorFactory::getIAbrirGuassapFing() {
    return ControladorUsuarios::getControladorUsuarios();
}

IAgregarContactos* ControladorFactory::getIAgregarContactos() {
    return ControladorUsuarios::getControladorUsuarios();
}

IAltaGrupo* ControladorFactory::getIAltaGrupo() {
    return ControladorUsuarios::getControladorUsuarios();
}

IArchivarConversaciones* ControladorFactory::getIArchivarConversaciones() {
    return ControladorMensajes::getControladorMensajes();
}

ICambiarFecha* ControladorFactory::getICambiarFecha() {
    return ControladorFecha::getInstance();
}

ICerrarGuassapFing* ControladorFactory::getICerrarGuassapFing() {
    return ControladorUsuarios::getControladorUsuarios();
}

IEliminarMensajes* ControladorFactory::getIEliminarMensajes() {
    return ControladorMensajes::getControladorMensajes();
}

IEnviarMensaje* ControladorFactory::getIEnviarMensaje() {
    return ControladorMensajes::getControladorMensajes();
}

IModificarUsuario* ControladorFactory::getIModificarUsuario() {
    return ControladorUsuarios::getControladorUsuarios();
}

ISuscribirse* ControladorFactory::getISuscribirse() {
    return ControladorUsuarios::getControladorUsuarios();
}

IVerMensajes* ControladorFactory::getIVerMensajes() {
    return ControladorMensajes::getControladorMensajes();
}

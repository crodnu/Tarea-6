#include "../include/ControladorFactory.h"
#include "../include/ControladorFecha.h"
#include "../include/ControladorMensajes.h"
#include "../include/ControladorUsuarios.h"

ICambiarFecha* ControladorFactory::getICambiarFecha() {
    return ControladorFecha::getInstance();
}

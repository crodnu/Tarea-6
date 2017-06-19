#include "../include/MensajeSimple.h"

using namespace std;

MensajeSimple::MensajeSimple(string texto) {
    this->texto = texto;
}

DataMensaje* MensajeSimple::getDataMensaje() {
    this->setLeidoPorUsuarioActual();
    return new DataMensajeSimple(this->getId(), this->getFechaEnviado(), this->texto);
}

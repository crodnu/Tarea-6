#include "../include/MensajeSimple.h"

using namespace std;

MensajeSimple::MensajeSimple(string texto) {
    this->texto = texto;
}

DataMensaje* MensajeSimple::getDataMensaje() {
    return DataMensajeSimple(this->getFechaEnviado(), this->texto);
}

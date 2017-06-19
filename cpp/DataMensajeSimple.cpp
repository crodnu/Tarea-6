#include "../include/DataMensajeSimple.h"

using namespace std;

DataMensajeSimple::DataMensajeSimple(IdMensaje id, Fecha fechaDeEnviado, string texto):
    DataMensaje(id, fechaDeEnviado) {
    this->texto = texto;
}

string DataMensajeSimple::getTexto() {
    return this->texto;
}

#include "../include/DataMensajeSimple.h"

using namespace std;

DataMensajeSimple::DataMensajeSimple(Fecha fechaDeEnviado, string texto):
    DataMensaje(fechaDeEnviado) {
    this->texto = texto;
}

string DataMensajeSimple::getTexto() {
    return this->texto;
}

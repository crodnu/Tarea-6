#include <cstddef>
#include <iostream>
#include <string>

#include "../include/ControladorFactory.h"
#include "../include/Fecha.h"
#include "../include/UI.h"

#include "../include/IAbrirGuassapFing.h"
#include "../include/IAgregarContactos.h"
#include "../include/IAltaGrupo.h"
#include "../include/IArchivarConversaciones.h"
#include "../include/ICambiarFecha.h"
#include "../include/ICerrarGuassapFing.h"
#include "../include/IEliminarMensajes.h"
#include "../include/IEnviarMensaje.h"
#include "../include/IModificarUsuario.h"
#include "../include/ISuscribirse.h"
#include "../include/IVerMensajes.h"

using namespace std;

UI* UI::instance = NULL;

UI::UI() { }

UI* UI::getInstance() {
    if(UI::instance == NULL)
        UI::instance = new UI();

    return UI::instance;
}

unsigned UI::seleccionarOpcionMenuPrincipal() {
    cout << "Seleccione una de las siguientes opciones: \n ";
    cout << "0. Salir \n 1. Abrir GuasapFING  \n 2. Cerrar GuasapFING \n 3. Agregar contactos  \n 4. Alta grupo  \n 5. Enviar mensajes  \n ";
    cout << "6. Ver mensajes  \n 7. Archivar conversaciones   \n 8. Modificar usuario  \n 9. Eliminar mensajes   \n 10. Suscripción para recibir los cambios en la información personal de un contacto\n;";
    unsigned opcionSeleccionada;
    cin >> opcionSeleccionada;
    return opcionSeleccionada;
}

void UI::abrirGuassapFing() {
    string tel;

    cout << "Ingrese TEL\n";
    cin >> tel;
    //iniciarSesion(tel);
    //darseDeAlta(cel,url,descripcion)
    cout << "Sesion iniciada." << endl;
}

void UI::cerrarGuassapFing() {

}

void UI::agregarContactos() {
    string tel;

    cout << "Ingrese tel del socio\n";
    cin >> tel;

    //agregarContacto(tel);
    cout << "Contacto agregado." << endl;
}

void UI::altaGrupo() {

}

void UI::enviarMensaje() {
    string msj;

    cout << "Ingrese el mensaje." << endl;
    cin >> msj;
    //enviarMensaje(msj);
    cout << "Mensaje enviado." << endl;
}

void UI::verMensajes() {

}

void UI::archivarConversaciones() {
    int id;
    cout << "Ingrese el id." << endl;
    cin >> id;
    //archivarConversacion(id);
}

void UI::modificarUsuario() {

}

void UI::eliminarMensajes() {

}

void UI::suscribirse() {

}

void UI::cambiarFecha() {
    ICambiarFecha* iCambiarFecha = ControladorFactory::getICambiarFecha();

    Fecha fechaActual = iCambiarFecha->getFechaActual();
    cout << "La fecha actual es: " << fechaActual.getDia() << "/" <<
        fechaActual.getMes()<< "/" << fechaActual.getAnio() << endl;

    unsigned dia, mes, anio;
    cout << "Inserte el dia nuevo." << endl;
    cin >> dia;
    cout << "Inserte el mes nuevo." << endl;
    cin >> mes;
    cout << "Inserte el anio nuevo." << endl;
    cin >> anio;

    fechaActual = Fecha(dia, mes, anio);
    iCambiarFecha->setFechaActual(fechaActual);
    cout << "Fecha cambiada correctamente!" << endl;
}

void UI::opcionNoValida() {
    cout << "Opcion no valida." <<endl;
}

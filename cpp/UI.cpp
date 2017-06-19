#include <cstddef>
#include <iostream>
#include <list>
#include <string>

#include "../include/DataContacto.h"
#include "../include/DataConversacion.h"
#include "../include/DataMensaje.h"
#include "../include/DataNotificacion.h"
#include "../include/DataReceptor.h"
#include "../include/ControladorFactory.h"
#include "../include/enumIniciarSesion.h"
#include "../include/Fecha.h"
#include "../include/UI.h"

// Interfaces al sistema.
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

bool yesOrNo() {
    string opcion;
    cin >> opcion;
    if(opcion == "y") return true;
    if(opcion == "n") return false;
    return false; // raise?
}

string getString() {
    string result;
    cin >> result;
    return result;
}

unsigned UI::seleccionarOpcionMenuPrincipal() {
    cout << "Seleccione una de las siguientes opciones:" << endl;
    cout << "\t0. Salir \n \t1. Abrir GuasapFING  \n \t2. Cerrar GuasapFING \n \t3. Agregar contactos  \n \t4. Alta grupo  \n \t5. Enviar mensajes  \n ";
    cout << "\t6. Ver mensajes  \n \t7. Archivar conversaciones   \n \t8. Modificar usuario  \n \t9. Eliminar mensajes   \n \t10. Suscripción para recibir los cambios en la información personal de un contacto\n"
        << "\t11 Cambiar la fecha del sistema" << endl;
    unsigned opcionSeleccionada;
    cin >> opcionSeleccionada;
    cout << endl;
    return opcionSeleccionada;
}

void UI::abrirGuassapFing() {
    IAbrirGuassapFing* iAbrirGuassapFing = ControladorFactory::getIAbrirGuassapFing();
    while(true) {
        cout << "Ingrese su telefono o FIN para salir." << endl;
        string tel = getString();
        if(tel == "FIN") return;
        enumIniciarSesion resultado = iAbrirGuassapFing->iniciarSesion(tel);

        if(resultado == SESION_YA_INICIADA_OTRO_NUMERO) {
            cout << "Sesion ya iniciada con un numero distinto." << endl
                << "Desea cerrar la sesion?(y/n)" << endl;
            if(yesOrNo()) iAbrirGuassapFing->cerrarSesion();
            cout << "Sesion cerrada correctamente!" << endl;
        }

        if(resultado == NUMERO_NO_EXISTE) {
            cout << "El numero seleccionado no existe. Desea darlo de alta?(y/n)" << endl;
            if(yesOrNo()) {
                cout << "Ingrese su nombre." << endl;
                string nombre = getString();
                cout << "Ingrese su descripcion personal." << endl;
                string descripcion = getString();
                cout << "Ingrese la url de su avatar." << endl;
                string avatar = getString();
                iAbrirGuassapFing->darseDeAlta(nombre, tel, avatar, descripcion);
                cout << "Usuario dado de alta correctamente!" << endl;
                return;
            }
        }

        if(resultado == SESION_YA_INICIADA_MISMO_NUMERO) {
            cout << "Sesion ya iniciada con el numero ingresado. Saliendo." << endl;
            return;
        }

        if(resultado == SESION_INICIADA_CORRECTAMENTE) {
            list<DataNotificacion> notificaciones = iAbrirGuassapFing->getNotificaciones();
            cout << "Sesion abierta correctamente. Notificaciones desde su ultima visita:" << endl;
            for(list<DataNotificacion>::iterator it = notificaciones.begin(); it != notificaciones.end(); it++) {
                DataNotificacion notificacion = *it;
                cout << notificacion.getContacto().getNombre() << " modifico su " << notificacion.getTipo() <<
                    " el dia " << notificacion.getFecha().getDia() << "/" << notificacion.getFecha().getMes() <<
                    "/" << notificacion.getFecha().getAnio() << endl;
            }
        }
    }
}

void UI::cerrarGuassapFing() {
    ICerrarGuassapFing* iCerrarGuassapFing = ControladorFactory::getICerrarGuassapFing();
    iCerrarGuassapFing->cerrarSesion();
    cout << "Sesion cerrada correctamente!" << endl;
}

void UI::agregarContactos() {
    IAgregarContactos* iAgregarContactos = ControladorFactory::getIAgregarContactos();
    cout << "Sus contactos actuales son:" << endl;

    list<DataContacto> contactosActuales = iAgregarContactos->listarContactos();
    for(list<DataContacto>::iterator it = contactosActuales.begin();
        it != contactosActuales.end(); it++) {
        DataContacto contacto = *it;
        cout << "\t+" << contacto.getNombre() << ": " << contacto.getDescripcion() << endl;
    }

    cout << endl;

    string tel = "PLACEHOLDER_TEXT";
    while(true) {
        cout << "Ingrese telefonp del contacto, o FIN para salir." << endl;
        if(tel == "FIN") break; // Oh no Eduardo, nos vas a matar a TODOS! D:>
        DataContacto nuevo = iAgregarContactos->getDatos(tel);
        cout << "Informacion del contacto:" << endl
            << "\tNombre: " << nuevo.getNombre() << endl
            << "\tDescripcion: " << nuevo.getDescripcion() << endl
            << "\tNombre: " << nuevo.getUrlImagen() << " <- Imagine que eso es una imagen :)"<< endl
            << "Desea agregarlo?(y/n)" << endl;
        string opcion;
        cin >> opcion;
        if(opcion == "y") iAgregarContactos->agregarContacto(tel);
    }

    cout << "Contactos agregados exitosamente!." << endl;
}

void UI::altaGrupo() {
    IAltaGrupo* iAltaGrupo = ControladorFactory::getIAltaGrupo();
}

void UI::enviarMensaje() {
    IEnviarMensaje* iEnviarMensaje = ControladorFactory::getIEnviarMensaje();
    string msj;

    cout << "Ingrese el mensaje." << endl;
    cin >> msj;
    //enviarMensaje(msj);
    cout << "Mensaje enviado." << endl;
}

void UI::verMensajes() {
    IVerMensajes* iVerMensajes = ControladorFactory::getIVerMensajes();
}

void UI::archivarConversaciones() {
    IArchivarConversaciones* iArchivarConversaciones = ControladorFactory::getIArchivarConversaciones();

    cout << "Sus converaciones activas son:" << endl;
    list<DataConversacion*> conversaciones = iArchivarConversaciones->darConversacionesActivas();
    for(list<DataConversacion*>::iterator it = conversaciones.begin(); it != conversaciones.end(); it++) {
        DataConversacion* conversacion = *it;
        cout << conversacion->getId() << endl; //idfk
        delete conversacion;
    }

    while(true) {
        int id;
        cout << "Ingrese el id o 0 para salir." << endl;
        cin >> id;
        if(id == 0) break;
        iArchivarConversaciones->archivarConversacion(id);
    }

    cout << "Conversaciones seleccionadas archivadas correctamente." << endl;
}

void UI::modificarUsuario() {
    IModificarUsuario* iModificarUsuario = ControladorFactory::getIModificarUsuario();
    int opcion = 0;
    cout << "Que campo desea modificar?" << endl
        << "\t1) Nombre" << endl
        << "\t2) Descripcion" << endl
        << "\t3) Avatar (url)" << endl;
    cin >> opcion;

    switch(opcion) {
    case 1: {
        string nombreNuevo;
        cout << "Inserte un nombre nuevo." << endl;
        cin >> nombreNuevo;
        iModificarUsuario->actualizarNombreUsuario(nombreNuevo);
        cout << "Nombre actualizado correctamente!" << endl;
    }

    case 2: {
        string descripcionNueva;
        cout << "Inserte una descripcion nueva." << endl;
        cin >> descripcionNueva;
        iModificarUsuario->actualizarDescripcionUsuario(descripcionNueva);
        cout << "Descripcion actualizada correctamente!" << endl;
    }

    case 3: {
        string avatarNuevo;
        cout << "Inserte una url con un avatar nuevo." << endl;
        cin >> avatarNuevo;
        iModificarUsuario->actualizarImagenUsuario(avatarNuevo);
        cout << "Avatar actualizado correctamente!" << endl;
    }

    default: {
        cout << "Opcion no valida!" << endl;
    }
    }
}

void UI::eliminarMensajes() {
    IEliminarMensajes* iEliminarMensajes = ControladorFactory::getIEliminarMensajes();
}

void UI::suscribirse() {
    ISuscribirse* iSuscribirse = ControladorFactory::getISuscribirse();
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

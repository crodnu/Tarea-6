#include <cstddef>
#include <iostream>
#include <list>
#include <sstream>
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

string getString() {
    string result;
    getline(cin, result);
    return result;
}

unsigned getUnsigned() {
    unsigned result;
    string resultStr = getString();
    istringstream buffer(resultStr);
    buffer >> result;
    return result;
}

int getInt() {
    int result;
    string resultStr = getString();
    istringstream buffer(resultStr);
    buffer >> result;
    return result;
}

bool yesOrNo() {
    string opcion = getString();
    if(opcion == "y") return true;
    if(opcion == "n") return false;
    return false; // raise?
}

void listarConversaciones(list<DataConversacion*> conversaciones, bool listarArchivadas) {
    unsigned conversacionesArchivadas = 0;
    for(list<DataConversacion*>::iterator it = conversaciones.begin(); it != conversaciones.end(); it++) {
        DataConversacion* conversacion = *it;
        if(conversacion->getArchivada() == false or listarArchivadas) conversacion->print();
        else conversacionesArchivadas++;
        delete conversacion;
    }

    cout << endl;
    if(!listarArchivadas) cout << "Numero de conversaciones archivadas: " << conversacionesArchivadas << endl << endl;
}

void listarDataContactos(list<DataContacto> contactos) {
    for(list<DataContacto>::iterator it = contactos.begin(); it != contactos.end(); it++) {
        DataContacto contacto = *it;
        cout << "\t+" << contacto.getNombre() << "(" << contacto.getTelefono() << "): " << contacto.getDescripcion() << endl;
    }
    cout << endl;
}

unsigned UI::seleccionarOpcionMenuPrincipal() {
    cout << "Seleccione una de las siguientes opciones:" << endl;
    cout << "\t0. Salir \n \t1. Abrir GuasapFING  \n \t2. Cerrar GuasapFING \n \t3. Agregar contactos  \n \t4. Alta grupo  \n \t5. Enviar mensajes  \n ";
    cout << "\t6. Ver mensajes  \n \t7. Archivar conversaciones   \n \t8. Modificar usuario  \n \t9. Eliminar mensajes   \n \t10. Suscripción para recibir los cambios en la información personal de un contacto\n"
        << "\t11. Cambiar la fecha del sistema" << endl;
    unsigned opcionSeleccionada = getUnsigned();
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
            if(yesOrNo()) {
                iAbrirGuassapFing->cerrarSesion();
                cout << "Sesion cerrada correctamente!" << endl;
            }
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
                cout << notificacion.getContacto().getNombre() << " modifico su " << notificacion.getTipo() << " el dia ";
                notificacion.getFecha().print();
                cout << endl;
            }
            cout << endl;
            return;
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
    listarDataContactos(contactosActuales);

    while(true) {
        cout << "Ingrese telefono del contacto, o FIN para salir." << endl;
        string tel = getString();
        if(tel == "FIN") break; // Oh no Eduardo, nos vas a matar a TODOS! D:>
        DataContacto nuevo = iAgregarContactos->getDatos(tel);
        cout << "Informacion del contacto:" << endl
            << "\tNombre: " << nuevo.getNombre() << endl
            << "\tDescripcion: " << nuevo.getDescripcion() << endl
            << "\tNombre: " << nuevo.getUrlImagen() << " <- Imagine que eso es una imagen :)"<< endl
            << "Desea agregarlo?(y/n)" << endl;
        string opcion = getString();
        if(opcion == "y") iAgregarContactos->agregarContacto(tel);
    }

    cout << "Contactos agregados exitosamente!." << endl;
}

void UI::altaGrupo() {
    IAltaGrupo* iAltaGrupo = ControladorFactory::getIAltaGrupo();
    iAltaGrupo->resetSets();
    list<DataContacto> contactos;
    cout << "Iniciando creacion de grupo." << endl;

    bool fin = false;
    while(!fin) {
        cout << "Contactos agregados:" << endl;
        contactos = iAltaGrupo->listarParticipantes();
        listarDataContactos(contactos);
        cout << "Contactos no agregados:" << endl;
        contactos = iAltaGrupo->listarContactosRestantes();
        listarDataContactos(contactos);
        cout << "Seleccione una opcion:" << endl
            << "\t1) Agregar un contacto" << endl
            << "\t2) Remover un contacto" << endl
            << "\t3) Finalizar seleccion de participantes" << endl;
        int opcion = getInt();
        switch(opcion) {
            case 1: {
                cout << "Ingrese el telefono del contacto a agregar." << endl;
                string telefono = getString();
                iAltaGrupo->agregarPaticipante(telefono);
                break;
            }
            case 2: {
                cout << "Ingrese el telefono del contacto a remover." << endl;
                string telefono = getString();
                iAltaGrupo->removerParticipante(telefono);
                break;
            }
            case 3: {
                fin = true;
                break;
            }
            default: {
                cout << "Opcion no valida!" << endl;
                return;
            }
        }
    }

    if(iAltaGrupo->listarParticipantes().size() == 0) {
        cout << "Se debe selccionar al menos un contacto." << endl;
        return;
    }

    cout << "Ingrese el nombre del grupo." << endl;
    string nombre = getString();
    cout << "Ingrese la url con la imagen para el grupo." << endl;
    string url = getString();
    iAltaGrupo->crearGrupo(nombre, url);
    cout << "Grupo creado correctamente!" << endl;
}

void UI::enviarMensaje() {
    IEnviarMensaje* iEnviarMensaje = ControladorFactory::getIEnviarMensaje();
    list<DataConversacion*> conversaciones = iEnviarMensaje->darConversaciones();

    if(conversaciones.size() == 0) {
        cout << "No participa en ninguna conversacion." << endl;
        return;
    }

    cout << "Sus converaciones son:" << endl;
    listarConversaciones(conversaciones, false);

    cout << endl;
    cout << "Seleccione una opcion:" << endl
        << "\t1) Seleccionar una conversacion activa" << endl
        << "\t2) Seleccionar una conversacion archivada" << endl
        << "\t3) Crear una conversacion simple con un contacto" << endl;
    int opcion = getInt();

    switch(opcion) {
        case 1: {
            cout << "Ingrese el id de la conversacion activa." << endl;
            int id = getInt();
            iEnviarMensaje->seleccionarConversacionActiva(id);
            break;
        }
        case 2: {
            conversaciones = iEnviarMensaje->darConversacionesArchivadas();
            cout << "Sus conversaciones archivadas son:" << endl;
            listarConversaciones(conversaciones, true);
            cout << "Ingrese el id de la conversacion archivada." << endl;
            int id = getInt();
            iEnviarMensaje->seleccionarConversacionArchivada(id);
            break;
        }
        case 3: {
            list<DataContacto> contactos = iEnviarMensaje->listarContactos();
            cout << "Sus contactos actuales son:" << endl;
            listarDataContactos(contactos);
            cout << "Ingrese el telefono del usuario con el que desea crear la conversacion." << endl;
            string telefono = getString();
            iEnviarMensaje->crearConversacionSimple(telefono);
            cout << "Conversacion creada correctamente!" << endl;
            break;
        }
        default: {
            cout << "Opcion no valida!" << endl;
            return;
        }
    }

    cout << endl;
    cout << "Seleccione una opcion:" << endl
        << "\t1) Enviar un mensaje simple" << endl
        << "\t2) Enviar un mensaje multimedia con imagen" << endl
        << "\t3) Enviar un mensaje multimedia con video" << endl
        << "\t3) Enviar un con un numero de contacto" << endl;
    opcion = getInt();

    switch(opcion) {
        case 1: {
            cout << "Ingrese el texto del mensaje." << endl;
            string texto = getString();
            iEnviarMensaje->enviarMensajeSimple(texto);
            break;
        }
        case 2: {
            cout << "Ingrese el texto del mensaje." << endl;
            string texto = getString();
            cout << "Ingrese la url con la imagen." << endl;
            string url = getString();
            cout << "Ingrese el formato de la imagen." << endl;
            string formato = getString();
            cout << "Ingrese el tamanio de la imagen." << endl;
            int tamanio = getInt();
            iEnviarMensaje->enviarMensajeImagen(url, formato, texto, tamanio);
            break;
        }
        case 3: {
            cout << "Ingrese la url con el video." << endl;
            string url = getString();
            cout << "Ingrese la duracion del video." << endl;
            int duracion = getInt();
            iEnviarMensaje->enviarMensajeVideo(url, duracion);
            break;
        }
        case 4: {
            list<DataContacto> contactos = iEnviarMensaje->listarContactos();
            cout << "Sus contactos actuales son:" << endl;
            listarDataContactos(contactos);
            cout << "Ingrese el telefono del que quiere compartir." << endl;
            string telefono = getString();
            iEnviarMensaje->enviarMensajeContacto(telefono);
            break;
        }
        default: {
            cout << "Opcion no valida!" << endl;
        }
    }

    cout << "Mensaje enviado correctamente!" << endl;
}

void UI::verMensajes() {
    IVerMensajes* iVerMensajes = ControladorFactory::getIVerMensajes();
    list<DataConversacion*> conversaciones = iVerMensajes->darConversaciones();

    if(conversaciones.size() == 0) {
        cout << "No participa en ninguna conversacion." << endl;
        return;
    }

    cout << "Sus converaciones son:" << endl;
    listarConversaciones(conversaciones, false);

    cout << "Desea seleccionar una conversacion activa (A) or archivada (R)?" << endl;
    string opcion = getString();
    if(opcion == "A") {
        cout << "Ingrese el id de la conversacion." << endl;
        int id = getInt();
        iVerMensajes->seleccionarConversacionActiva(id);
    }
    else if(opcion == "R") {
        conversaciones = iVerMensajes->darConversacionesArchivadas();
        cout << "Sus conversaciones archivadas son:" << endl;
        listarConversaciones(conversaciones, true);
        cout << "Ingrese el id de la conversacion." << endl;
        int id = getInt();
        iVerMensajes->seleccionarConversacionArchivada(id);
    }
    else {
        cout << "Opcion no valida!" << endl;
        return;
    }

    cout << "Los mensajes en esta conversacion son:" << endl;
    list<DataMensaje*> mensajes = iVerMensajes->obtenerMensajesDeConversacion();
    for(list<DataMensaje*>::iterator it = mensajes.begin(); it != mensajes.end(); it++) {
        DataMensaje* mensaje = *it;
        mensaje->print();
        cout << endl;
        delete mensaje;
    }
    cout << endl;

    while(true) {
        cout << "ingrese el ID de un mensaje para obtener mas informacion, o 0 para salir." << endl;
        int id = getInt();
        if(id == 0) return;
        list<DataReceptor> receptores = iVerMensajes->obtenerInformacionAdicional(id);
        cout << "Los receptores de este mensaje son:" << endl;
        for(list<DataReceptor>::iterator it = receptores.begin(); it != receptores.end(); it++) {
            DataReceptor receptor = *it;
            Fecha fecha = receptor.getFechaRecibido();
            cout << "\t*" << receptor.getContacto().getNombre() << " vio el mensaje el dia: ";
            fecha.print();
            cout << endl;
        }

        cout << endl;
    }
}

void UI::archivarConversaciones() {
    IArchivarConversaciones* iArchivarConversaciones = ControladorFactory::getIArchivarConversaciones();

    list<DataConversacion*> conversaciones = iArchivarConversaciones->darConversacionesActivas();
    if(conversaciones.size() == 0) {
        cout << "No participa en ninguna conversacion." << endl;
        return;
    }

    cout << "Sus converaciones activas son:" << endl;
    listarConversaciones(conversaciones, true); // Solo deberian haber conversaciones activas.

    while(true) {
        cout << "Ingrese el id o 0 para salir." << endl;
        int id = getInt();
        if(id == 0) break;
        iArchivarConversaciones->archivarConversacion(id);
    }

    cout << "Conversaciones seleccionadas archivadas correctamente." << endl;
}

void UI::modificarUsuario() {
    IModificarUsuario* iModificarUsuario = ControladorFactory::getIModificarUsuario();
    cout << "Que campo desea modificar?" << endl
        << "\t1) Nombre" << endl
        << "\t2) Descripcion" << endl
        << "\t3) Avatar (url)" << endl;
    int opcion = getInt();

    switch(opcion) {
    case 1: {
        cout << "Inserte un nombre nuevo." << endl;
        string nombreNuevo = getString();
        iModificarUsuario->actualizarNombreUsuario(nombreNuevo);
        cout << "Nombre actualizado correctamente!" << endl;
        break;
    }

    case 2: {
        cout << "Inserte una descripcion nueva." << endl;
        string descripcionNueva = getString();
        iModificarUsuario->actualizarDescripcionUsuario(descripcionNueva);
        cout << "Descripcion actualizada correctamente!" << endl;
        break;
    }

    case 3: {
        cout << "Inserte una url con un avatar nuevo." << endl;
        string avatarNuevo = getString();
        iModificarUsuario->actualizarImagenUsuario(avatarNuevo);
        cout << "Avatar actualizado correctamente!" << endl;
        break;
    }

    default: {
        cout << "Opcion no valida!" << endl;
    }
    }
}

void UI::eliminarMensajes() {
    IEliminarMensajes* iEliminarMensajes = ControladorFactory::getIEliminarMensajes();
    list<DataConversacion*> conversaciones = iEliminarMensajes->darConversaciones();

    if(conversaciones.size() == 0) {
        cout << "No participa en ninguna conversacion." << endl;
        return;
    }

    cout << "Sus converaciones son:" << endl;
    listarConversaciones(conversaciones, false);

    cout << "Desea seleccionar una conversacion activa (A) or archivada (R)?" << endl;
    string opcion = getString();
    if(opcion == "A") {
        cout << "Ingrese el id de la conversacion." << endl;
        int id = getInt();
        iEliminarMensajes->seleccionarConversacionActiva(id);
    }
    else if(opcion == "R") {
        conversaciones = iEliminarMensajes->darConversacionesArchivadas();
        cout << "Sus conversaciones archivadas son:" << endl;
        listarConversaciones(conversaciones, true);
        cout << "Ingrese el id de la conversacion." << endl;
        int id = getInt();
        iEliminarMensajes->seleccionarConversacionArchivada(id);
    }
    else {
        cout << "Opcion no valida!" << endl;
        return;
    }

    cout << "Ingrese el id del mensaje que desea eliminar." << endl
        << "(Nota: puede ver el id de los mensajes al ver los mensajes.)" << endl;
    int idMensaje = getInt();
    iEliminarMensajes->eliminarMensaje(idMensaje);
}

void UI::suscribirse() {
    ISuscribirse* iSuscribirse = ControladorFactory::getISuscribirse();
    cout << "Sus contactos actuales son:" << endl;

    list<DataContacto> contactosActuales = iSuscribirse->listarContactos();
    listarDataContactos(contactosActuales);

    cout << endl;

    while(true) {
        cout << "Inserte un telefono al que suscribirse o FIN para salir." << endl;
        string telefono = getString();
        if(telefono == "FIN") break;
        iSuscribirse->suscribirse(telefono);
        cout << "Suscripcion completada." << endl;
    }

    cout << "Los usuarios seleccionados ahora le enviaran notificaciones!" << endl;
}

void UI::cambiarFecha() {
    ICambiarFecha* iCambiarFecha = ControladorFactory::getICambiarFecha();

    Fecha fechaActual = iCambiarFecha->getFechaActual();
    fechaActual.print();
    cout << endl;

    cout << "Inserte el dia nuevo." << endl;
    unsigned dia = getUnsigned();
    cout << "Inserte el mes nuevo." << endl;
    unsigned mes = getUnsigned();
    cout << "Inserte el anio nuevo." << endl;
    unsigned anio = getUnsigned();

    fechaActual = Fecha(dia, mes, anio);
    iCambiarFecha->setFechaActual(fechaActual);
    cout << "Fecha cambiada correctamente!" << endl;
}

void UI::opcionNoValida() {
    cout << "Opcion no valida." <<endl;
}

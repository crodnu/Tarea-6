#include <cstddef>
#include <iostream>
#include <string>

#include "../include/UI.h"

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

}

void UI::opcionNoValida() {
    cout << "Opcion no valida." <<endl;
}

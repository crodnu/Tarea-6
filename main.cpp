#include "ControladorFecha.h"
#include "ControladorMensajes.h"
#include "ControladorUsuarios.h"


#include <iostream>
#include <stdexcept>
#include <string>

#include "UI.h"

// Limites del sistema


// Opciones del menu
#define SALIR                   0
#define ABRIR_GUASAPFING        1
#define CERRAR_GUASSAPFING      2
#define AGREGAR_CONTACTOS       3
#define ALTA_GRUPO              4
#define ENVIAR_MENSAJE          5
#define VER_MENSAJES            6
#define ARCHIVAR_CONVERSACIONES 7
#define MODIFICAR_USUARIO       8
#define ELIMINAR_MENSAJES       9
#define SUSCRIBIRSE             10
#define CAMBIAR_FECHA_ACTUAL    11

using namespace std;

bool menu();

int main(){
    bool salir;
    do {
        try {
            salir = menu();
        }
        catch (exception& e) {
            cout << "ERROR: " << e.what() << endl << endl;
        }
    } while(!salir);
    return 1;
}

bool menu(){
    UI* userInterface = UI::getInstance();
    unsigned opcionSeleccionada = userInterface->seleccionarOpcionMenuPrincipal();

    switch (opcionSeleccionada){
        case SALIR: {
            return true;
        }

        case ABRIR_GUASAPFING : {
            userInterface->abrirGuassapFing();
            break;
        }

        case CERRAR_GUASSAPFING: {
            userInterface->cerrarGuassapFing();
            break;
        }

        case AGREGAR_CONTACTOS: {
            userInterface->agregarContactos();
            break;
        }

        case ALTA_GRUPO: {
            userInterface->altaGrupo();
            break;
        }

        case ENVIAR_MENSAJE: {
            userInterface->enviarMensaje();
            break;
        }

        case VER_MENSAJES: {
            userInterface->verMensajes();
            break;
        }

        case ARCHIVAR_CONVERSACIONES: {
            userInterface->archivarConversaciones();
            break;
        }

        case MODIFICAR_USUARIO: {
            userInterface->modificarUsuario();
            break;
        }

        case ELIMINAR_MENSAJES: {
            userInterface->eliminarMensajes();
            break;
        }

        case SUSCRIBIRSE: {
            userInterface->suscribirse();
            break;
        }

        case CAMBIAR_FECHA_ACTUAL: {
            userInterface->cambiarFecha();
            break;
        }

        default: {
            userInterface->opcionNoValida();
        }
    }

    return false;
}


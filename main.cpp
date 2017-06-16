#include "ControladorFecha.h"
#include "ControladorMensajes.h"
#include "ControladorUsuarios.h"


#include <iostream>
#include <stdexcept>
#include <string>

// Limites del sistema


// Opciones del menu
#define SALIR 0
#define ABRIR_GUASAPFING  1
#define Cerrar_GuasapFING  2
#define  Agregar_contactos  3
#define  Alta_grupo  4
#define  Enviar_mensajes  5
#define  Ver_mensajes   6
#define  Archivar_conversaciones  7
#define  Modificar_usuario   8
#define  Eliminar_mensajes    9
#define  Suscripcion   10

using namespace std;

bool menu();

int main(){
    bool salir;
    do {
        try {
            salir = menu();
        }
        catch (exception& e) {
            cout << "ERROR: " << e.what() << endl;
        }
    } while(!salir);
    return 1;
}

bool menu(){
    cout << "Seleccione una de las siguientes opciones: \n ";
    cout << "0. Salir \n 1. Abrir GuasapFING  \n 2. Cerrar GuasapFING \n 3. Agregar contactos  \n 4. Alta grupo  \n 5. Enviar mensajes  \n ";
    cout << "6. Ver mensajes  \n 7. Archivar conversaciones   \n 8. Modificar usuario  \n 9. Eliminar mensajes   \n 10. Suscripción para recibir los cambios en la información personal de un contacto\n;";
    unsigned opcionSeleccionada;
    cin >> opcionSeleccionada;

    switch (opcionSeleccionada){
        case SALIR: {
            return true;
        }

        case ABRIR_GUASAPFING : {

            string tel;

            cout << "Ingrese TEL\n";
            cin >> tel;
            iniciarSesion(tel);
            darseDeAlta(cel,url,descripcion)
            cout << "Sesion iniciada." << endl;
            break;
        }

        case CERRAR_GuasapFING: {



        }

        case Agregar_contactos: {

            string tel;

            cout << "Ingrese tel del socio\n";
            cin >> tel;

            agregarContacto(tel);
            cout << "Contacto agregado." << endl;
            break;
        }

        case Alta_grupo: {
         // Lo hace el usuario

            altaGrupo();


            break;
        }

        case Enviar_mensajes: {

            string msj;

            cout << "Ingrese el mensaje." << endl;
            cin >> msj;
            enviarMensaje(msj);
                cout << "Mensaje enviado." << endl;
            break;
        }

        case Ver_mensajes: {

            verMensajes();

            break;
        }

        case Archivar_conversaciones: {

            int id;
            cout << "Ingrese el id." << endl;
            cin >> id;
            archivarConversacion(id);

            break;
        }

        case Modificar_usuario: {

            modificarUsuario();

            break;
        }

        case Eliminar_mensajes: {

            eliminarMensajes();

            break;
        }

        case Suscripcion: {

            suscribirse();

            break;
        }

        default: {
            cout << "Opcion no valida." <<endl;
        }
    }

    return false;
}


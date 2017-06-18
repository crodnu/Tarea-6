#ifndef UI_H
#define UI_H

class UI {
public:
    static UI* getInstance();
    unsigned seleccionarOpcionMenuPrincipal();
    void abrirGuassapFing();
    void cerrarGuassapFing();
    void agregarContactos();
    void altaGrupo();
    void enviarMensaje();
    void verMensajes();
    void archivarConversaciones();
    void modificarUsuario();
    void eliminarMensajes();
    void suscribirse();
    void cambiarFecha();
    void opcionNoValida();

private:
    UI();
    static UI* instance;
};

#endif // UI_H

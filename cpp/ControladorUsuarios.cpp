#include "../include/ControladorUsuarios.h"

ControladorUsuarios ControladorUsuarios::ControladorUsuarios(){ 
    this.instancia = new ControladorUsuarios(); 
    //this.usuariosDelSistema = ; //como sea que se vaya a inicializar la coleccion     
    return this.instancia; 
} 

ControladorUsuarios * ControladorUsuarios::getControladorUsuarios(){ 
    if(this.instancia == NULL) 
            this.instancia = ControladorUsuarios(); 
    return this.instancia; 
}  

void ControladorUsuarios::agregarContacto(string cel){
    this.usuarioIniciado.agregarContacto((this.usuariosDelSistema).find(cel));
    /*Hacemos tambien el inverso?*/
}

Usuario ControladorUsuarios::getUsuario(string cel){
    return (this.usuarioDelSistema).find(cel);
}

Usuario ControladorUsuarios::getUsuarioSesionActual(){
    return this.usuarioIniciado;
}

DataContacto ControladorUsuarios::getDatos(string cel){
    return this.usuarioIniciado.getDataContacto();
}

void ControladorUsuarios::darseDeAlta(string cel, string urlImagen, string descripcion){
    Usuario uno = new Usuario();
    uno.telefono = cel;
    uno.urlAvatar = urlImagen;
    uno.descripcion = descripcion;
    //nos comimos el nombre
    this.usuariosDelSistema.add(uno);
}



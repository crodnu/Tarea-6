#ifndef NODOCOMPUESTO_H
#define	NODOCOMPUESTO_H

#include <map>

#include "NodoJerarquia.h"

class NodoCompuesto: NodoJerarquia {
public:
    NodoCompuesto(NodoCompuesto* padre);
    virtual std::list<DataMensaje*> obtenerMensajes();
    void agregarHijo(NodoJerarquia* hijo);

private:
    std::map<IdJerarquia, NodoJerarquia*> hijos;
};

#endif	/* NODOCOMPUESTO_H */

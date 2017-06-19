#ifndef IARCHIVARCONVERSACIONES_H_INCLUDED
#define IARCHIVARCONVERSACIONES_H_INCLUDED

#include <list>

#include "DataConversacion.h"

class IArchivarConversaciones {
public:
    virtual std::list<DataConversacion*> darConversacionesActivas() = 0;
    virtual void archivarConversacion(int id) = 0;
};

#endif // IARCHIVARCONVERSACIONES_H_INCLUDED

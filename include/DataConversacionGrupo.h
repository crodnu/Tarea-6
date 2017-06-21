#ifndef DATACONVERSACIONGRUPO_H
#define	DATACONVERSACIONGRUPO_H

#include <string>

#include "DataConversacion.h"

class DataConversacionGrupo: public DataConversacion {
public:
    DataConversacionGrupo(IdConversacion id, bool archivada, std::list<DataMensaje*> mensajes, std::string nombreGrupo);

    std::string getNombreGrupo();
    virtual void print();

private:
    std::string nombreGrupo;
};

#endif	/* DATACONVERSACIONGRUPO_H */

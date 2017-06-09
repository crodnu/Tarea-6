#ifndef DATACONVERSACIONGRUPO_H
#define	DATACONVERSACIONGRUPO_H

#include <string>

#include "DataConversacion.h"

class DataConversacionGrupo: DataConversacion {
public:
    DataConversacionGrupo(bool archivada, std::list<DataMensaje*> mensajes, std::string nombreGrupo);

    std::string getNombreGrupo();

private:
    std::string nombreGrupo;
};

#endif	/* DATACONVERSACIONGRUPO_H */

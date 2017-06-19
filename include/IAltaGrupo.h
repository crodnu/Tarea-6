#ifndef IALTAGRUPO_H_INCLUDED
#define IALTAGRUPO_H_INCLUDED

#include <list>
#include <string>

#include "DataContacto.h"

class IAltaGrupo {
public:
    virtual void resetSets() = 0;
    virtual std::list<DataContacto> listarParticipantes() = 0;
    virtual std::list<DataContacto> listarContactosRestantes() = 0;
    virtual void agregarPaticipante(std::string cel) = 0;
    virtual void removerParticipante(std::string cel) = 0;
    virtual void crearGrupo(std::string nombre, std::string urlImagen) = 0;
};

#endif // IALTAGRUPO_H_INCLUDED

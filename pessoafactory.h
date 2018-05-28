#ifndef PESSOAFACTORY_H
#define PESSOAFACTORY_H

#include "paciente.h"
#include "medico.h"

enum class tipoPessoa{
    medico,
    paciente
};

class pessoaFactory
{
public:
    // Fabrica de pessoas
    virtual Pessoa * createPessoa(tipoPessoa type)=0;
};

#endif // PESSOAFACTORY_H

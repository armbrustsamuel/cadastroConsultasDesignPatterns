#ifndef PESSOAFACTORY_H
#define PESSOAFACTORY_H

enum class tipoPessoa{
    medico,
    paciente
};

class pessoaFactory
{
public:
    pessoaFactory();

    // Fabrica de pessoas
    void createPessoa(tipoPessoa type);

};

#endif // PESSOAFACTORY_H

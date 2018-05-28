#include "consultorio.h"

Consultorio::Consultorio(string name, string address, string expertise)
{
    setEndereco(address);
    setEspecialidade(expertise);
    setNome(name);
}

string Consultorio::getEspecialidade() const
{
    return especialidade;
}

void Consultorio::setEspecialidade(const string &value)
{
    especialidade = value;
}

string Consultorio::getEndereco() const
{
    return endereco;
}

void Consultorio::setEndereco(const string &value)
{
    endereco = value;
}

string Consultorio::getNome() const
{
    return nome;
}

void Consultorio::setNome(const string &value)
{
    nome = value;
}

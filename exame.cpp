#include "exame.h"

string Exame::getData() const
{
    return data;
}

void Exame::setData(const string &value)
{
    data = value;
}

string Exame::getEspecialidade() const
{
    return especialidade;
}

void Exame::setEspecialidade(const string &value)
{
    especialidade = value;
}

string Exame::getEndereco() const
{
    return endereco;
}

void Exame::setEndereco(const string &value)
{
    endereco = value;
}

string Exame::getResultado() const
{
    return resultado;
}

void Exame::setResultado(const string &value)
{
    resultado = value;
}

Exame::Exame(string date, string expertise, string address)
{
    setData(date);
    setEndereco(address);
    setEspecialidade(expertise);
}

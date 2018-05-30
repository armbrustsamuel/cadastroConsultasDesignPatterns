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

string Exame::getMedico() const
{
    return medico;
}

void Exame::setMedico(const string &value)
{
    medico = value;
}

Exame::Exame(string date, string expertise, string address, string doctor)
{
    setData(date);
    setEndereco(address);
    setEspecialidade(expertise);
    setMedico(doctor);
}

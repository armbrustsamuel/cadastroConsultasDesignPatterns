#include "paciente.h"

Paciente::Paciente(string pain, string name, int age,
                   Genero gender, string address,
                   string phone, string mail):
    Pessoa(name, age, gender, address, phone, mail)
{
    setEnfermo(pain);
}

Paciente::Paciente(Pessoa*pessoa):
    Pessoa(pessoa)
{}

Historico *Paciente::getHistorico() const
{
    return historico;
}

void Paciente::setHistorico(Historico *value)
{
    historico = value;
}

Paciente::Paciente(string nome){
    setNome(nome);
}

void Paciente::setEnfermo(string pain){
    enfermo = pain;
}

string Paciente::getEnfermo(){
    return enfermo;
}



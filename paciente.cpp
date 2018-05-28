#include "paciente.h"

Historico *Paciente::getHistorico() const
{
    // getHistoricoFromDataBase
    return historico;
}

void Paciente::setHistorico(Historico *value)
{
    historico = value;
}

Paciente::Paciente(string pain, string name, int age,
                   Genero gender, string address,
                   string phone, string mail):
    Pessoa(name, age, gender, address, phone, mail)
{
    setEnfermo(pain);
}

Paciente::Paciente(Pessoa*pessoa):
    Pessoa(pessoa)
{
}

void Paciente::setEnfermo(string pain){
    enfermo = pain;
}

string Paciente::getEnfermo(){
    return enfermo;
}



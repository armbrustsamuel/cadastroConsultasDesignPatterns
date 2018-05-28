#include "medico.h"

string Medico::getPrescricao() const
{
    return prescricao;
}

void Medico::setPrescricao(const string &value)
{
    prescricao = value;
}

Medico::Medico(string pain, string name, int age,
               Genero gender, string address,
               string phone, string mail):
    Pessoa(name, age, gender, address, phone, mail)
{
    setEspecialidade(pain);
}

Medico::Medico(Pessoa *pessoa):
Pessoa(pessoa)
{}

string Medico::getEspecialidade(){
    return especialidade;
}

void Medico::setEspecialidade(string specialMed){
    especialidade = specialMed;
}

#include "medico.h"

Medico::Medico(string pain, string name, int age,
                   Genero gender, string address,
                   string phone, string mail):
    Pessoa(name, age, gender, address, phone, mail)
{
    setEspecialidade(pain);
}


string Medico::getEspecialidade(){
    return especialidade;
}

void Medico::setEspecialidade(string specialMed){
    especialidade = specialMed;
}

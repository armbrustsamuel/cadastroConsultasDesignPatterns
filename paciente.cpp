#include "paciente.h"

Paciente::Paciente(string pain, string name, int age,
                   Genero gender, string address,
                   string phone, string mail):
    Pessoa(name, age, gender, address, phone, mail)
{
    setEnfermo(pain);
}

void Paciente::setEnfermo(string pain){
    enfermo = pain;
}

string Paciente::getEnfermo(){
    return enfermo;
}



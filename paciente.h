#ifndef PACIENTE_H
#define PACIENTE_H

#include "pessoa.h"

class Paciente: public Pessoa
{
private:
    string enfermo;
public:
    Paciente(){};
    Paciente(string pain, string name, int age, Genero gender,
              string address, string phone, string mail);

    void setEnfermo(string pain);
    string getEnfermo();
};

#endif // PACIENTE_H

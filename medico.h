#ifndef MEDICO_H
#define MEDICO_H

#include "pessoa.h"

class Medico: public Pessoa
{
private:
    string especialidade;
public:
    Medico(){};
    Medico(string pain, string name, int age, Genero gender,
           string address, string phone, string mail);

    void setEspecialidade(string specialMed);
    string getEspecialidade();

};

#endif // MEDICO_H

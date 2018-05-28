#ifndef MEDICO_H
#define MEDICO_H

#include "pessoa.h"

class Medico: public Pessoa
{
private:
    string especialidade;
    string prescricao;
public:
    Medico(){};
    Medico(Pessoa*pessoa);
    Medico(string pain, string name, int age, Genero gender,
           string address, string phone, string mail);

    void setEspecialidade(string specialMed);
    string getEspecialidade();

    void atender(){std::cout << getPrescricao() << endl;}
    void descreverCaso(){};
    string getPrescricao() const;
    void setPrescricao(const string &value);
};

#endif // MEDICO_H

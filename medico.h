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
    string getPrescricao() const;
    void setPrescricao(const string &value);

    void atender(){std::cout << "Diagnóstico: " << getPrescricao() << endl;}
    void descreverCaso(){};
};

#endif // MEDICO_H

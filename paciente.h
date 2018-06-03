#ifndef PACIENTE_H
#define PACIENTE_H

#include "pessoa.h"
#include "historico.h"

class Paciente: public Pessoa
{
private:
    string enfermo;
    Historico * historico;
public:
    Paciente(){};
    Paciente(string nome);
    Paciente(Pessoa*pessoa);
    Paciente(string pain, string name, int age, Genero gender,
              string address, string phone, string mail);

    void setEnfermo(string pain);
    string getEnfermo();

    Historico *getHistorico() const;
    void setHistorico(Historico *value);

    void atender(){};
    void descreverCaso(){std::cout << "Sintoma: Eu estou com "<< enfermo << endl;}
};

#endif // PACIENTE_H

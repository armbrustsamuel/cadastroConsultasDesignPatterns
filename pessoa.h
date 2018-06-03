#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

// To mock history
#include "historico.h"

using namespace std;

enum class Genero {
    masculino,
    feminino
};

class Pessoa
{
private:
    double id;
    string nome;
    int idade;
    Genero genero;
    string endereco;
//    int telefone[9];
    string telefone;
    string email;
    Historico * historico;
    int index=0;
public:
    Pessoa(){};
    Pessoa(Pessoa*pessoa);
    Pessoa(string name, int age, Genero gender,
        string address, string phone, string mail);

    double getId() const;
    string getNome();
    int getIdade();
    Genero getGenero();
    string getEndereco();
    string getTelefone();
//    int * getTelefone();
    string getEmail();

    void setId(double value);
    void setNome(string name);
    void setIdade(int age);
    void setGenero(Genero gender);
    void setEndereco(string address);
//    void setTelefone(int *phone);
    void setTelefone(string phone);
    void setEmail(string mail);

    virtual void atender() = 0;
    virtual void descreverCaso() = 0;

    Historico * mockHistory();

//    Historico *getHistorico() const;
//    void setHistorico(Historico *value);
};

#endif // PESSOA_H

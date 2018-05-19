#ifndef PESSOA_H
#define PESSOA_H

#include <string>

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
public:
    Pessoa(){};
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

};

#endif // PESSOA_H

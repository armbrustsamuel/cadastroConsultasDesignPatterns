#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include <string>

using namespace std;

class Consultorio
{
private:
    string nome;
    string endereco;
    string especialidade;
public:
    Consultorio(){};
    Consultorio(string name, string address, string expertise);
    string getEspecialidade() const;
    void setEspecialidade(const string &value);
    string getEndereco() const;
    void setEndereco(const string &value);
    string getNome() const;
    void setNome(const string &value);
};

#endif // CONSULTORIO_H

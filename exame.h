#ifndef EXAME_H
#define EXAME_H

#include<string>

using namespace std;

class Exame
{
private:
    int id;
    string data;
    string medico;
    string paciente;
    string especialidade;
    string endereco;
    string resultado = "Pendente";

public:
    Exame(){};
    Exame(string date, string expertise, string address, string medico);
    Exame(string date, string expertise, string address, string medico, string paciente);
    string getData() const;
    void setData(const string &value);
    string getEspecialidade() const;
    void setEspecialidade(const string &value);
    string getEndereco() const;
    void setEndereco(const string &value);
    string getResultado() const;
    void setResultado(const string &value);
    string getMedico() const;
    void setMedico(const string &value);
    string getPaciente() const;
    void setPaciente(const string &value);
    int getId() const;
    void setId(int value);
};

#endif // EXAME_H

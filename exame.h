#ifndef EXAME_H
#define EXAME_H

#include<string>
#include <QList>

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
    vector < class ObserverExame * > views;
    int indexExame=0;


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

    void attach(ObserverExame *obs);
    void notify();

    QList<string> *log = new QList<string>();
    QList<string> *getLog() const;
    void setLog(QList<string> *value);
};

class ObserverExame {
    // 2. "dependent" functionality
    Exame *model;

public:
    ObserverExame(){};
    ObserverExame(Exame *mod);
    virtual string * update() = 0;

protected:
    Exame *getExame();
};

#endif // EXAME_H

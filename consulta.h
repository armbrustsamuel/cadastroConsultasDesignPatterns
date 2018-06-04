#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include "paciente.h"
#include "medico.h"

using namespace std;

class Consulta
{
private:
    static Consulta * instance;
    string consultorio;
    string exame;
    Paciente * paciente;
    Medico * medico;
    Consulta(){};
    QList<Exame> *list = new QList<Exame>();
    vector < class Observer * > views;
    int indexExame=0;
public:
//    Consulta(string place, string exam, Paciente *patient, Medico *doctor);

    void attach(Observer *obs);
    void notify();

    string getConsultorio() const;
    void setConsultorio(const string &value);
    string getExame() const;
    void setExame(const string &value);
    Paciente *getPaciente() const;
    void setPaciente(Paciente *value);
    Medico *getMedico() const;
    void setMedico(Medico *value);

    void addExame(Exame *exame);

    static Consulta * getInstance();
    QList<Exame> *getList() const;
    void setList(QList<Exame> *value);
};

class Observer {
    // 2. "dependent" functionality
    Consulta *model;

public:
    Observer(){};
    Observer(Consulta *mod);
    virtual void update() = 0;

protected:
    Consulta *getConsulta();
};


#endif // CONSULTA_H

#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include "paciente.h"
#include <medico.h>

using namespace std;

class Consulta
{
private:
    string consultorio;
    string exame;
    Paciente paciente;
    Medico medico;

public:
    Consulta(){};
    Consulta(string place, string exam, Paciente patient, Medico doctor);

    string getConsultorio() const;
    void setConsultorio(const string &value);
    string getExame() const;
    void setExame(const string &value);
    Paciente getPaciente() const;
    void setPaciente(const Paciente &value);
    Medico getMedico() const;
    void setMedico(const Medico &value);
};

#endif // CONSULTA_H

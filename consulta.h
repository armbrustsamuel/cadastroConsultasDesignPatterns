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

public:
//    Consulta(string place, string exam, Paciente *patient, Medico *doctor);

    string getConsultorio() const;
    void setConsultorio(const string &value);
    string getExame() const;
    void setExame(const string &value);
    Paciente *getPaciente() const;
    void setPaciente(Paciente *value);
    Medico *getMedico() const;
    void setMedico(Medico *value);

    static Consulta * getInstance();
};

#endif // CONSULTA_H

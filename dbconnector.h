#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include "medico.h"
#include "paciente.h"
#include "consulta.h"
#include "exame.h"
#include "consultorio.h"

class DBConnector
{
private:
    static DBConnector * instance;
    Paciente paciente;
    Medico medico;
    Exame exame;
    Consultorio consultorio;

public:
    DBConnector(){};

    DBConnector *getInstance();

    Consultorio getConsultorio() const;
    void setConsultorio(const Consultorio &value);
    Exame getExame() const;
    void setExame(const Exame &value);
    Medico getMedico() const;
    void setMedico(const Medico &value);
    Paciente getPaciente() const;
    void setPaciente(const Paciente &value);
};

#endif // DBCONNECTOR_H

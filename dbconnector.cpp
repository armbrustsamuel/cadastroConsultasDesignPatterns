#include "dbconnector.h"

DBConnector * DBConnector::instance = 0;

Consultorio DBConnector::getConsultorio() const
{
    return consultorio;
}

void DBConnector::setConsultorio(const Consultorio &value)
{
    consultorio = value;
}

Exame DBConnector::getExame() const
{
    return exame;
}

void DBConnector::setExame(const Exame &value)
{
    exame = value;
}

Medico DBConnector::getMedico() const
{
    return medico;
}

void DBConnector::setMedico(const Medico &value)
{
    medico = value;
}

Paciente DBConnector::getPaciente() const
{
    return paciente;
}

void DBConnector::setPaciente(const Paciente &value)
{
    paciente = value;
}

DBConnector *DBConnector::getInstance()
{
    if(instance == 0) {
        instance = new DBConnector();
        // get info by patient
    }
    return instance;
}

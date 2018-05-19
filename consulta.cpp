#include "consulta.h"

Consulta::Consulta(string place, string exam, Paciente patient, Medico doctor)
{
    setConsultorio(place);
    setExame(exam);
    setPaciente(patient);
    setMedico(doctor);
}

string Consulta::getConsultorio() const
{
    return consultorio;
}

void Consulta::setConsultorio(const string &value)
{
    consultorio = value;
}

string Consulta::getExame() const
{
    return exame;
}

void Consulta::setExame(const string &value)
{
    exame = value;
}

Paciente Consulta::getPaciente() const
{
    return paciente;
}

void Consulta::setPaciente(const Paciente &value)
{
    paciente = value;
}

Medico Consulta::getMedico() const
{
    return medico;
}

void Consulta::setMedico(const Medico &value)
{
    medico = value;
}

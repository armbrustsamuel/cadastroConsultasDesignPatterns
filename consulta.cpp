#include "consulta.h"

Consulta * Consulta::instance = 0;

Paciente *Consulta::getPaciente() const
{
    return paciente;
}

void Consulta::setPaciente(Paciente *value)
{
    paciente = value;
}

Medico *Consulta::getMedico() const
{
    return medico;
}

void Consulta::setMedico(Medico *value)
{
    medico = value;
}

Consulta *Consulta::getInstance()
{
    if(instance == 0) {
        instance = new Consulta();
        // get info by patient
    }
    return instance;
}

//Consulta::Consulta(string place, string exam, Paciente * patient, Medico * doctor)
//{
//    setConsultorio(place);
//    setExame(exam);
//    setPaciente(patient);
//    setMedico(doctor);
//}

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

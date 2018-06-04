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

void Consulta::addExame(Exame *exame)
{
    // Add new exame
    list->insert(indexExame, *exame);
    indexExame+=1;
    notify();
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

QList<Exame> *Consulta::getList() const
{
    return list;
}

void Consulta::setList(QList<Exame> *value)
{
    list = value;
}

QList<string> *Consulta::getLog() const
{
    return log;
}

void Consulta::setLog(QList<string> *value)
{
    log = value;
}

void Consulta::attach(Observer *obs)
{
    views.push_back(obs);
}

void Consulta::notify()
{
    // 5. Publisher broadcasts
    for (int i = 0; i < views.size(); i++){
        views[i]->update();
    }
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

Consulta *Observer::getConsulta() {
    return model;
}

Observer::Observer(Consulta *mod) {
    model = mod;
    // 4. Observers register themselves with the Subject
    model->attach(this);
}

#include "exame.h"

string Exame::getData() const
{
    return data;
}

void Exame::setData(const string &value)
{
    data = value;
}

string Exame::getEspecialidade() const
{
    return especialidade;
}

void Exame::setEspecialidade(const string &value)
{
    especialidade = value;
}

string Exame::getEndereco() const
{
    return endereco;
}

void Exame::setEndereco(const string &value)
{
    endereco = value;
}

string Exame::getResultado() const
{
    return resultado;
}

void Exame::setResultado(const string &value)
{
    resultado = value;
}

string Exame::getMedico() const
{
    return medico;
}

void Exame::setMedico(const string &value)
{
    medico = value;
}

string Exame::getPaciente() const
{
    return paciente;
}

void Exame::setPaciente(const string &value)
{
    paciente = value;
}

int Exame::getId() const
{
    return id;
}

void Exame::setId(int value)
{
    id = value;
    notify();
}

Exame::Exame(string date, string expertise, string address, string doctor)
{
    setData(date);
    setEndereco(address);
    setEspecialidade(expertise);
    setMedico(doctor);
}

Exame::Exame(string date, string expertise, string address, string doctor, string paciente)
{
    setData(date);
    setEndereco(address);
    setEspecialidade(expertise);
    setMedico(doctor);
    setPaciente(paciente);
}

Exame *ObserverExame::getExame()
{
    return model;
}

ObserverExame::ObserverExame(Exame *mod) {
    model = mod;
    // 4. Observers register themselves with the Subject
    model->attach(this);
}

void Exame::notify()
{
    string *t;
    // 5. Publisher broadcasts
    for (int i = 0; i < views.size(); i++){
//        if ( this->getData().substr(6,4) < "2010" ){
            t = views[i]->update();
//        }
        // Verificar uma forma de testar data muito antiga!
    }
    this->getLog()->insert(indexExame, *t);
}

QList<string> *Exame::getLog() const
{
    return log;
}

void Exame::setLog(QList<string> *value)
{
    log = value;
}

void Exame::attach(ObserverExame *obs)
{
    views.push_back(obs);
}

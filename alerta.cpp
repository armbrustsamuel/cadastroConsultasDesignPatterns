#include "alerta.h"

#include <iostream>

void Alerta::setPaciente(const string &value)
{
    paciente = value;
}

string Alerta::getPaciente() const
{
    return paciente;
}

string Alerta::getMedico() const
{
    return medico;
}

void Alerta::setMedico(const string &value)
{
    medico = value;
}

Alerta::Alerta(string paciente, string medico, string date, string mensagem, string emailDestino)
{
    setData(date);
    setPaciente(paciente);
    setMedico(medico);
    setEmailDestino(emailDestino);
    setMensagem(mensagem);
}

string Alerta::getData() const
{
    return data;
}

void Alerta::setData(const string &value)
{
    data = value;
}

string Alerta::getMensagem() const
{
    return message;
}

void Alerta::setMensagem(const string &value)
{
    message = value;
}

string Alerta::getEmailDestino() const
{
    return emailDestino;
}

void Alerta::setEmailDestino(const string &value)
{
    emailDestino = value;
}

void Alerta::display()
{
    cout << endl;
    cout << "Alerta" << endl;
    cout << "Destinatario: " << getEmailDestino() << endl;
    cout << "Mensagem: " << getMensagem() << endl;
    cout << "Paciente: " << getPaciente() << endl;
    cout << "Medico: " << getMedico() << endl;
    cout << "Data: " << getData() << endl;
    cout << endl;
}

#include "alerta.h"

Alerta::Alerta(Paciente paciente, Medico medico, string date, string mensagem, string emailDestino)
{
    setDate(date);
    setPaciente(paciente);
    setMedico(medico);
    setEmailDestino(emailDestino);
    setMensagem(mensagem);
}

Paciente Alerta::getPaciente() const
{
    return paciente;
}

void Alerta::setPaciente(const Paciente &value)
{
    paciente = value;
}

Medico Alerta::getMedico() const
{
    return medico;
}

void Alerta::setMedico(const Medico &value)
{
    medico = value;
}

string Alerta::getDate() const
{
    return date;
}

void Alerta::setDate(const string &value)
{
    date = value;
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

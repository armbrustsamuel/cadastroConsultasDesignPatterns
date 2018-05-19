#ifndef ALERTA_H
#define ALERTA_H

#include<string>
#include "paciente.h"
#include "medico.h"

// include date;


class Alerta
{
private:
    Paciente paciente;
    Medico medico;
    string date; //redo using date lib
    string message;
    string emailDestino;
public:
    Alerta(){};
    Alerta(Paciente paciente, Medico medico,
           string date, string mensagem, string emailDestino);
    Paciente getPaciente() const;
    void setPaciente(const Paciente &value);
    Medico getMedico() const;
    void setMedico(const Medico &value);
    string getDate() const;
    void setDate(const string &value);
    string getMensagem() const;
    void setMensagem(const string &value);
    string getEmailDestino() const;
    void setEmailDestino(const string &value);
};

#endif // ALERTA_H

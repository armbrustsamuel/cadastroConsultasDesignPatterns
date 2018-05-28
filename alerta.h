#ifndef ALERTA_H
#define ALERTA_H

#include<string>
#include "paciente.h"
#include "medico.h"

// include date;


class Alerta
{
private:
    string paciente;
    string medico;
    string data; //redo using date lib
    string message;
    string emailDestino;
public:
    Alerta(){};
    Alerta(string paciente, string medico,
           string date, string mensagem, string emailDestino);
    string getData() const;
    void setData(const string &value);
    string getMensagem() const;
    void setMensagem(const string &value);
    string getEmailDestino() const;
    void setEmailDestino(const string &value);
    string getPaciente() const;
    void setPaciente(const string &value);
    string getMedico() const;
    void setMedico(const string &value);

    virtual void display();
};

#endif // ALERTA_H

#ifndef EXAMEFACADE_H
#define EXAMEFACADE_H

#include "marcacaoexame.h"
#include <iostream>

using namespace std;

class ExameFacade
{
public:
    ExameFacade();
    void proximaEtapa();
    bool verificarEstado();
    int numeroAtividades();

private:
    enum States
    {
        Requisitado, Marcacao, Aprovado, Finalizado
    };
    int _contador;
    int _estado;
    MarcacaoExame _exame;
};

#endif // EXAMEFACADE_H

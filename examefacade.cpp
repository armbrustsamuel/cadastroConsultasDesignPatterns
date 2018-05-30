#include "examefacade.h"

ExameFacade::ExameFacade()
{
    _contador = 0;
}

void ExameFacade::proximaEtapa()
{
    _estado = 0;
}

bool ExameFacade::verificarEstado()
{
    _contador++;

    if (_estado == States::Requisitado) {
        // requisitado
        _estado++;

        _exame.requisitarExame();
        cout << "Exame requisitado" << endl;
    }

    else if (_estado == States::Marcacao) {
        if(_exame.verificarResultado())
        {
            _estado++;
            cout << "Exame finalizado" << endl;
        }
    }

    else if (_estado == States::Aprovado) {
        // aprovado
        _estado++;
        return true;
        cout << "Exame enviado" << endl;
    }

    return false;
}

int ExameFacade::numeroAtividades()
{
    return _contador;
}

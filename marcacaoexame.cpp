#include "marcacaoexame.h"

void MarcacaoExame::requisitarExame()
{
    _estado = 0;
}

bool MarcacaoExame::verificarResultado()
{
    _estado++;
    if (_estado == States::EmailEnviado)
      return true;
    return false;
}

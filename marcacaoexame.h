#ifndef MARCACAOEXAME_H
#define MARCACAOEXAME_H


class MarcacaoExame
{
public:
    MarcacaoExame(){};
    void requisitarExame();
    bool verificarResultado();
private:
    enum States
    {
        Requisitado, Marcado, Executado, Processado, Informado,
        EmailEnviado
    };
    int _estado;
};

#endif // MARCACAOEXAME_H

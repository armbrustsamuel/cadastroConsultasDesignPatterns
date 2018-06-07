#include "novoexameobserver.h"

NovoExameObserver::NovoExameObserver(Consulta *mod):
    Observer(mod)
{

}

string * NovoExameObserver::update()
{
//    cout << endl;
//    cout << "Novo Exame adicionado ao histórico" << endl;
//    cout << endl;

    string * t = new string("Novo Exame adicionado ao histórico");
    return t;

}


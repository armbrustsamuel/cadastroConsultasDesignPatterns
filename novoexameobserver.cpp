#include "novoexameobserver.h"

NovoExameObserver::NovoExameObserver(Historico *mod):
    Observer(mod)
{

}

void NovoExameObserver::update()
{
    //getHistorico()->getList();
    cout << endl;
    cout << "Novo Exame adicionado ao histórico" << endl;
    cout << endl;
}

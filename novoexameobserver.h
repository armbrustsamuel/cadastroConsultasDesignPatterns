#ifndef NOVOEXAMEOBSERVER_H
#define NOVOEXAMEOBSERVER_H

//#include "historico.h"
#include "consulta.h"

class NovoExameObserver: public Observer
{
public:
    NovoExameObserver(Consulta *mod);
    string *update();
};

#endif // NOVOEXAMEOBSERVER_H

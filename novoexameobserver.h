#ifndef NOVOEXAMEOBSERVER_H
#define NOVOEXAMEOBSERVER_H

#include "historico.h"
#include <iostream>

class NovoExameObserver: public Observer
{
public:
    NovoExameObserver(Historico *mod);
    void update();
};

#endif // NOVOEXAMEOBSERVER_H

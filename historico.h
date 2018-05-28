#ifndef HISTORICO_H
#define HISTORICO_H

#include "exame.h"
#include <QList>

class Historico
{
private:
    static Historico * instance;
    int index=0;
    QList<Exame> *list = new QList<Exame>();
public:
    Historico(){};

    static Historico *getInstance();
    QList<Exame> *getList() const;
    void setList(QList<Exame> *value);

    void adicionarExame(Exame *exam);
    void removerExame(Exame *exam);

    virtual void display();
};

#endif // HISTORICO_H

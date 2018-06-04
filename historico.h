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
//    vector < class Observer * > views;
public:
    Historico(){};

//    void attach(Observer *obs);

    // Removed from Singleton responsibility
//    static Historico *getInstance();
    QList<Exame> *getList() const;
    void setList(QList<Exame> *value);

    void adicionarExame(Exame *exam);
    void removerExame(Exame *exam);

    virtual void display();
//    void notify();
};

//class Observer {
//    // 2. "dependent" functionality
//    Historico *model;

//public:
//    Observer(){};
//    Observer(Historico *mod);
//    virtual void update() = 0;

//protected:
//    Historico *getHistorico();
//};


#endif // HISTORICO_H

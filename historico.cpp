#include "historico.h"

#include <iostream>

Historico * Historico::instance = 0;

QList<Exame> *Historico::getList() const
{
    return list;
}

void Historico::setList(QList<Exame> *value)
{
    list = value;
    notify();
}

void Historico::adicionarExame(Exame *exam)
{
    list->insert(index, *exam);
    index = index++;
}

void Historico::removerExame(Exame *exam)
{
    list->removeAt(0);
}

void Historico::display()
{
    if(list->size() > 1){
        cout << endl;
        cout << "Exames" << endl;
        for(int i = 0; i<list->size(); i++){
            Exame aux = this->list->at(i);
            cout << "Data: " << aux.getData() << endl;
            cout << "Especialidade: " << aux.getEspecialidade() << endl;
            cout << "Endereco: " << aux.getEndereco() << endl;
            cout << "Resultado: " << aux.getResultado() << endl;
            cout << endl;
        }
    }
}

void Historico::notify()
{
    // 5. Publisher broadcasts
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}

void Historico::attach(Observer *obs)
{
    views.push_back(obs);
}

Historico *Historico::getInstance()
{
    if(instance == 0) {
        instance = new Historico();
        // get info by patient
    }
    return instance;
}

Historico *Observer::getHistorico() {
    return model;
}

Observer::Observer(Historico *mod) {
    model = mod;
    // 4. Observers register themselves with the Subject
    model->attach(this);
}


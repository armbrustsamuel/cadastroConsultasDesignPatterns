#include "mainwindow.h"
#include <QApplication>

#include "medico.h"
#include "paciente.h"
#include "consulta.h"
#include "exame.h"
#include "consultorio.h"
#include "pessoafactory.h"
#include "pessoafactory.cpp"
#include "alerta.h"

//remove (TEST)
#include <iostream>
using namespace std;

int main()//int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();

    pessoaFactory * factory;
    factory = new Factory();

    // Criar Paciente
    Pessoa * paciente =
            factory->createPessoa(tipoPessoa::paciente);
    paciente->setNome("Samuel");
    paciente->setGenero(Genero::masculino);

    // Crir um médico
    Pessoa * medico =
            factory->createPessoa(tipoPessoa::medico);
    medico->setNome("Arthur Afonso");
    medico->setGenero(Genero::masculino);

    // Criar exame
    Exame * visao = new Exame("04/04/2018", "oftalmologia", "Hospital Central");
    Exame * audicao = new Exame("01/04/2018", "otorrinolaringologia", "Consultorio Albernaz");

    // Criar consulta
    Consulta * consulta = Consulta::getInstance();

    // Adicionar paciente
    consulta->setPaciente(new Paciente(paciente));
    consulta->getPaciente()->setEnfermo("Diarreia");
    consulta->getPaciente()->descreverCaso();

    // Adiciona médico
    consulta->setMedico(new Medico(medico));
    consulta->getMedico()->setEspecialidade("Gastro");
    consulta->getMedico()->setPrescricao("Tomar bastante água");
    consulta->getMedico()->atender();

    // Criar histórico
    QList<Exame> *list = new QList<Exame>();
    list->insert(1,*audicao);

    Historico *historicoSamuel = new Historico();
    historicoSamuel->setList(list);

    consulta->getPaciente()->setHistorico(historicoSamuel);

    // Adicionar novo exame
    consulta->getPaciente()->getHistorico()->adicionarExame(visao);

    cout << "Paciente: " << consulta->getPaciente()->getNome() << endl;
    cout << "Médico: " << consulta->getMedico()->getNome() << endl;

    consulta->getPaciente()->getHistorico()->display();

    // Criando um alerta
    Alerta * alerta1 = new Alerta(
                consulta->getPaciente()->getNome(),
                consulta->getMedico()->getNome(),
                "04/04/2018",
                "Nova Consulta",
                "armbrust.samuel@gmail.com");

    alerta1->display();

    return 0;
}
